#include <strutils.hh>
using namespace strutils;

#include <gtest/gtest.h>

// ============================================================================

TEST(lstrip, nothing) {

    const std::string str = "A quick brown fox.";

    auto res = lstrip(str);
    ASSERT_EQ(res, "A quick brown fox.");
}

TEST(lstrip, whitespace) {

    const std::string str = " \t A quick brown fox.";

    auto res = lstrip(str);
    ASSERT_EQ(res, "A quick brown fox.");
}

TEST(rstrip, nothing) {

    const std::string str = "A quick brown fox.";

    auto res = rstrip(str);
    ASSERT_EQ(res, "A quick brown fox.");
}

TEST(rstrip, whitespace) {

    const std::string str = "A quick brown fox. \t\n";

    auto res = rstrip(str);
    ASSERT_EQ(res, "A quick brown fox.");
}

TEST(strip, whitespace) {

    const std::string str = " \t  A quick brown fox. \t\n \r";

    auto res = strip(str);
    ASSERT_EQ(res, "A quick brown fox.");
}

