#ifndef PATHUTILS_HH
#define PATHUTILS_HH

#include <string>
#include <vector>
#include <utility>

#include <cstddef>

namespace pathutils {

// ============================================================================

static const std::string separator("/");

// ============================================================================

/// Splits the path into directory name and file name
std::pair<std::string, std::string> split (const std::string& str);

/// Splits file name into base name and extension
std::pair<std::string, std::string> splitext (const std::string& str);

/// Joins parts of the path
std::string join (const std::vector<std::string>& chunks);

/// Returns true when the path is absolute
bool isabs (const std::string& str);

// ============================================================================

}; // strutils

#endif // PATHUTILS_HH
