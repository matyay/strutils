#include <strutils.hh>
using namespace strutils;

#include <gtest/gtest.h>

// ============================================================================

TEST(replace, single) {

    const std::string str = "A quick brown fox and an ox";

    auto res = replace(str, "fox", "horse");
    ASSERT_EQ(res, "A quick brown horse and an ox");
}

TEST(replace, first) {

    const std::string str = "A quick brown fox";

    auto res = replace(str, "A", "The");
    ASSERT_EQ(res, "The quick brown fox");
}

TEST(replace, last) {

    const std::string str = "A quick brown fox";

    auto res = replace(str, "fox", "mule");
    ASSERT_EQ(res, "A quick brown mule");
}

TEST(replace, multiple) {

    const std::string str = "A quick brown fox and another fox";

    auto res = replace(str, "fox", "dog");
    ASSERT_EQ(res, "A quick brown dog and another dog");
}

TEST(replace, nested) {

    const std::string str = "A quick brown fox";

    auto res = replace(str, "fox", "dog'o'fox");
    ASSERT_EQ(res, "A quick brown dog'o'fox");
}

