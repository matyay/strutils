#include "pathutils.hh"

namespace pathutils {

// ============================================================================

std::pair<std::string, std::string> split (const std::string& str) {

    // Find the last path separator
    size_t pos = str.find_last_of(separator);

    // No path
    if (pos == std::string::npos) {
        return std::make_pair(std::string(), str);
    }

    // This is a file on root
    if (pos == 0) {
        return std::make_pair(
            std::string(separator),
            str.substr(1, str.length() - 1)
        );
    }

    // Normal split
    return std::make_pair(
        str.substr(0, pos),
        str.substr(pos+1, str.length() - (pos+1))
    );
}

std::pair<std::string, std::string> splitext (const std::string& str) {

    // Find the last dot
    size_t pos = str.find_last_of(".");

    // No dot
    if (pos == std::string::npos) {
        return std::make_pair(str, std::string());
    }

    // Normal split
    return std::make_pair(
        str.substr(0, pos),
        str.substr(pos+1, str.length() - (pos+1))
    );
}

// ============================================================================

std::string join (const std::vector<std::string>& chunks) {

    std::string path;

    // Join rest of the chunks using the separator. Strip separators from them
    for (size_t i=0; i<chunks.size(); ++i) {
        auto&  chunk = chunks[i];
        size_t len   = chunk.length();

        // Find the first and last separator
        ssize_t p0 = chunk.find_first_of(separator);
        ssize_t p1 = chunk.find_last_of(separator);

        // Set to full span if none found
        if (p0 == (ssize_t)std::string::npos) p0 = -1;
        if (p1 == (ssize_t)std::string::npos) p1 = len;

        // Handle single separator case
        if (p0 == p1) {
            if (p0 == 0) {
                p1 = len;
            }
            else if (p1 == (ssize_t)(len - 1)) {
                p0 = 0;
            }
            else {
                p0 = -1;
                p1 = len;
            }
        }

        // Join the chunk
        if (i == 0) {
            path += chunk.substr(0, p1);
        } else {
            path += separator + chunk.substr(p0 + 1, p1 - p0 - 1);
        }
    }

    return path;
}

// ============================================================================

bool isabs (const std::string& str) {
    return !str.empty() && (str[0] == separator[0]);
}

// ============================================================================

}; // pathutils
