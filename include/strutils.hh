#ifndef STRUTILS_HH
#define STRUTILS_HH

#include <string>
#include <vector>

#include <cstddef>

namespace strutils {

// ============================================================================

std::string replace (const std::string& a_String,
                     const std::string& a_Old,
                     const std::string& a_New);


std::string lstrip  (const std::string& a_String,
                     const std::string& a_Chars);

std::string rstrip  (const std::string& a_String,
                     const std::string& a_Chars);

std::string strip   (const std::string& a_String,
                     const std::string& a_Chars);


std::vector<std::string> lsplit  (const std::string& a_String,
                                  const std::string& a_Sep = std::string(),
                                  ssize_t a_MaxSplit = -1);

std::vector<std::string> rsplit  (const std::string& a_String,
                                  const std::string& a_Sep = std::string(),
                                  ssize_t a_MaxSplit = -1);

std::vector<std::string> split   (const std::string& a_String,
                                  const std::string& a_Sep = std::string(),
                                  ssize_t a_MaxSplit = -1);

// ============================================================================

}; // strutils

#endif // STRUTILS_HH
