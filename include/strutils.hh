#ifndef STRUTILS_HH
#define STRUTILS_HH

#include <string>
#include <vector>

#include <cstddef>

namespace strutils {

// ============================================================================

std::string upper (const std::string& a_String);

std::string lower (const std::string& a_String);


bool startswith (const std::string& a_String,
                 const std::string& a_Pattern);

bool endswith   (const std::string& a_String,
                 const std::string& a_Pattern);


std::string replace (const std::string& a_String,
                     const std::string& a_Old,
                     const std::string& a_New);


std::string lstrip  (const std::string& a_String,
                     const std::string& a_Chars = std::string(" \r\n\t"));

std::string rstrip  (const std::string& a_String,
                     const std::string& a_Chars = std::string(" \r\n\t"));

std::string strip   (const std::string& a_String,
                     const std::string& a_Chars = std::string(" \r\n\t"));


std::vector<std::string> split   (const std::string& a_String,
                                  const std::string& a_Sep = std::string(),
                                  size_t a_MaxSplit = 0);

std::vector<std::string> rsplit  (const std::string& a_String,
                                  const std::string& a_Sep = std::string(),
                                  size_t a_MaxSplit = 0);

std::vector<std::string> splitlines (const std::string& a_String);


std::string join (const std::string& a_Sep,
                  const std::vector<std::string>& a_Parts);


std::string ljust (const std::string& a_String, size_t a_Count);

std::string rjust (const std::string& a_String, size_t a_Count);

// ============================================================================

}; // strutils

#endif // STRUTILS_HH
