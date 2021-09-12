#include "strutils.hh"

#include <sstream>
#include <algorithm>

namespace strutils {

// ============================================================================

std::string upper (const std::string& a_String) {

    std::string str(a_String);
    for (auto& c : str) {
        c = ::toupper(c);
    }

    return str;
}

std::string lower (const std::string& a_String) {

    std::string str(a_String);
    for (auto& c : str) {
        c = ::tolower(c);
    }

    return str;
}

// ============================================================================

bool startswith (const std::string& a_String,
                 const std::string& a_Pattern)
{
    return (a_String.find(a_Pattern) == 0);
}

bool endswith (const std::string& a_String,
               const std::string& a_Pattern)
{
    const size_t N = a_String.length() - a_Pattern.length();
    return (a_String.rfind(a_Pattern) == N);
}

// ============================================================================

std::string replace (const std::string& a_String,
                     const std::string& a_Old,
                     const std::string& a_New)
{
    // Find the substrng
    auto p = a_String.find(a_Old);

    // Not found, terminate
    if (p == std::string::npos) {
        return a_String;
    }

    // Recurse
    std::string str = a_String.substr(0, p) + a_New;
    str += replace(a_String.substr(p + a_Old.length()), a_Old, a_New);

    return str;
}

// ============================================================================

std::string lstrip (const std::string& a_String,
                    const std::string& a_Chars)
{
    auto p = a_String.find_first_not_of(a_Chars);

    // None found.
    if (p == std::string::npos) {
        return std::string();
    }

    return a_String.substr(p);
}

std::string rstrip (const std::string& a_String,
                    const std::string& a_Chars)
{
    auto p = a_String.find_last_not_of(a_Chars);

    // None found.
    if (p == std::string::npos) {
        return std::string();
    }

    return a_String.substr(0, p+1);
}

std::string strip (const std::string& a_String,
                   const std::string& a_Chars)
{
    return rstrip(lstrip(a_String, a_Chars), a_Chars);
}

// ============================================================================

std::vector<std::string> split (const std::string& a_String,
                                const std::string& a_Sep,
                                size_t a_MaxSplit)
{
    std::vector<std::string> parts;

    // Split by whitespace
    if (a_Sep.empty()) {

        std::string word;
        std::stringstream ss(a_String);

        // Read "words"
        for (size_t i=0;; ++i) {

            // Split limit reached
            if (a_MaxSplit > 0 && i >= a_MaxSplit) {
                parts.push_back(lstrip(std::string(
                    std::istreambuf_iterator<char>(ss), {}))
                );
                break;
            }

            // Get a word
            if (ss >> word) {
                parts.push_back(word);
            } else {
                break;
            }
        }
    }

    // Split by a delimiter string
    else {

        auto N = a_Sep.length();

        std::string::size_type p = 0;
        std::string::size_type q = 0;

        // Find delimiters
        for (size_t i=0;; ++i) {

            // Split limit reached
            if (a_MaxSplit > 0 && i >= a_MaxSplit) {
                parts.push_back(a_String.substr(p));
                break;
            }

            // Find next delimiter
            q = a_String.find(a_Sep, p);
            if (q == std::string::npos) {
                parts.push_back(a_String.substr(p));
                break;
            }

            // Copy substring
            parts.push_back(a_String.substr(p, q - p));
            p = q + N;
        }
    }

    return parts;
}

std::vector<std::string> rsplit (const std::string& a_String,
                                 const std::string& a_Sep,
                                 size_t a_MaxSplit)
{    
    std::vector<std::string> parts;

    // Reverse strings
    std::string revString = a_String;
    std::string revSep    = a_Sep;

    std::reverse(revString.begin(), revString.end());
    std::reverse(revSep.begin(),    revSep.end());

    // Do the split
    parts = split(revString, revSep, a_MaxSplit);

    // Reverse parts
    for (auto& part : parts) {
        std::reverse(part.begin(), part.end());
    }

    // Reverse the part order
    std::reverse(parts.begin(), parts.end());
    return parts;
}

std::vector<std::string> splitlines (const std::string& a_String) {
    std::vector<std::string> lines;

    std::stringstream ss(a_String);
    std::string line;

    while (std::getline(ss, line, '\n')) {
        lines.push_back(line);
    }

    return lines;
}

// ============================================================================

std::string join (const std::string& a_Sep,
                  const std::vector<std::string>& a_Parts)
{
    size_t N = a_Parts.size();
    if (N == 0) {
        return std::string();
    }

    std::string joined;
    for (size_t i=0;;) {

        joined += a_Parts[i];

        if (++i >= N) {
            break;
        }

        joined += a_Sep;
    }

    return joined;
}

// ============================================================================

std::string ljust (const std::string& a_String, size_t a_Count) {

    // Pad length
    ssize_t pad = a_Count - a_String.length();

    if (pad > 0) {
        return std::string(pad, ' ') + a_String;
    } else {
        return a_String;
    }
}

std::string rjust (const std::string& a_String, size_t a_Count) {

    // Pad length
    ssize_t pad = a_Count - a_String.length();

    if (pad > 0) {
        return a_String + std::string(pad, ' ');
    } else {
        return a_String;
    }
}

// ============================================================================

}; // strutils

