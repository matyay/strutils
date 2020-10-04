#include <strhash.hh>
using namespace strutils;

#include <gtest/gtest.h>

// ============================================================================

TEST(hash, calculation) {

    auto res = hash("stack-overflow");
    ASSERT_EQ(res, 0x335CC04A);
}
