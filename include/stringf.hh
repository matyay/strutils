#ifndef STRINGF_HH
#define STRINGF_HH

#include <string>

// ============================================================================

/// Returns formatted std::string using the sprintf style with arguments given
/// as a variable argument list
std::string vstringf (const std::string a_Format, va_list a_Args);

/// Returns formatted std::string using the sprintf style
std::string stringf  (const std::string a_Format, ...);

#endif
