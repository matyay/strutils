#ifndef STRUTILS_HH
#define STRUTILS_HH

#include <string>
#include <vector>

#include <cstddef>

namespace strutils {

// ============================================================================

/// Converts a string to uppercase
std::string upper (const std::string& a_String);

/// Converts a string to lowercase
std::string lower (const std::string& a_String);

/// Returns true when a string begins with the pattern
bool startswith (const std::string& a_String,
                 const std::string& a_Pattern);

/// Returns true when a string ends with the pattern
bool endswith   (const std::string& a_String,
                 const std::string& a_Pattern);

/// Replaces all occurences of the "old" pattern with the "new" one.
std::string replace (const std::string& a_String,
                     const std::string& a_Old,
                     const std::string& a_New);

/// Strips the given characters from the left side of the string
std::string lstrip  (const std::string& a_String,
                     const std::string& a_Chars = std::string(" \r\n\t"));

/// Strips the given characters from the right side of the string
std::string rstrip  (const std::string& a_String,
                     const std::string& a_Chars = std::string(" \r\n\t"));

/// Strips separator characters from both sides of the string
std::string strip   (const std::string& a_String,
                     const std::string& a_Chars = std::string(" \r\n\t"));

/// Splits the string up to N times using the separator string or whitespace
/// if the separator is empty. Starts from the left side
std::vector<std::string> split   (const std::string& a_String,
                                  const std::string& a_Sep = std::string(),
                                  size_t a_MaxSplit = 0);

/// Splits the string up to N times using the separator string or whitespace
/// if the separator is empty. Starts from the right side
std::vector<std::string> rsplit  (const std::string& a_String,
                                  const std::string& a_Sep = std::string(),
                                  size_t a_MaxSplit = 0);

/// Splits the string into lines
std::vector<std::string> splitlines (const std::string& a_String);

/// Joins a list of strings by inserting the separator string between them
std::string join (const std::string& a_Sep,
                  const std::vector<std::string>& a_Parts);

/// Justifies the string to the left
std::string ljust (const std::string& a_String, size_t a_Count);

/// Justifies the string to the right
std::string rjust (const std::string& a_String, size_t a_Count);

// ============================================================================

}; // strutils

#endif // STRUTILS_HH
