#include "pathutils.hh"

namespace pathutils {

// ============================================================================

std::pair<std::string, std::string> split (const std::string& str) {

    // Find the last path separator
    size_t pos = str.rfind(separator);

    // No path
    if (pos == std::string::npos) {
        return std::make_pair(std::string(), str);
    }

    // This is a file on root
    if (pos == 0) {
        return std::make_pair(
            std::string(separator),
            str.substr(separator.length(), str.length() - separator.length())
        );
    }

    // Normal split
    return std::make_pair(
        str.substr(0, pos),
        str.substr(
            pos + separator.length(), str.length() - (pos + separator.length())
        )
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
    bool isFirst = true;

    // Join rest of the chunks using the separator. Strip separators from them
    for (auto& chunk : chunks) {
        size_t len = chunk.length();

        // Skip empty
        if (!len) {
            continue;
        }

        // Find the first and last separator
        size_t p0 = chunk.find(separator);
        size_t p1 = chunk.rfind(separator);

        // Skip separators only if they are at the string boundaries
        if (p0 == 0) {
            p0 = separator.length();
        } else {
            p0 = 0;
        }

        if (p1 != (len - separator.length())) {
            p1 = len;
        }

        // Join the chunk
        if (isFirst) {
            path += chunk.substr(0, p1);
        } else {
            path += separator + chunk.substr(p0, p1 - p0);
        }

        isFirst = false;
    }

    return path;
}

// ============================================================================

bool isabs (const std::string& str) {
    // FIXME: Not os-independent !
    return !str.empty() && (str.find(separator) == 0);
}

// ============================================================================

}; // pathutils
