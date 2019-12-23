#include <strutils.hh>
using namespace strutils;

#include <gtest/gtest.h>

// ============================================================================

TEST(join, single) {

    std::vector<std::string> parts = {
        "A quick brown fox"
    };

    auto res = join(" ", parts);
    ASSERT_EQ(res, "A quick brown fox");
}

TEST(join, multiple) {

    std::vector<std::string> parts = {
        "A", "quick", "brown", "fox"
    };

    auto res = join(" ", parts);
    ASSERT_EQ(res, "A quick brown fox");
}

