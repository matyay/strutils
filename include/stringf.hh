#ifndef STRINGF_HH
#define STRINGF_HH

#include <string>

// ============================================================================

/// Returns formatted std::string using sprintf style
std::string vstringf (const std::string a_Format, va_list a_Args);
std::string stringf  (const std::string a_Format, ...);

#endif
