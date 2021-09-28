#include "stringf.hh"

#include <cstddef>
#include <cstdarg>
#include <memory>
#include <stdexcept>

// ============================================================================

std::string vstringf (const std::string a_Format, va_list a_Args) {

    ssize_t bufSize = 120+1;
    va_list orgArgs;

    // Try formatting the string
    va_copy(orgArgs, a_Args);
    std::unique_ptr<char[]> buffer(new char[bufSize]);
    int res = vsnprintf(buffer.get(), bufSize, a_Format.c_str(), a_Args);

    // The buffer was too small. Re-allocate it and try again.
    if (res >= bufSize) {
        bufSize = res + 1;
        buffer.reset(new char[bufSize]);
        res = vsnprintf(buffer.get(), bufSize, a_Format.c_str(), orgArgs);
    }

    // Error
    if (res < 0) {
        throw std::runtime_error("vsnprintf() failed!");
    }

    // Convert to std::string
    return std::string(buffer.get());
}

std::string stringf (const std::string a_Format, ...) {
   
    va_list args;

    va_start(args, a_Format);
    std::string str = vstringf(a_Format, args);
    va_end(args);

    return str;
}

