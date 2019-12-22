#include <strutils.hh>
using namespace strutils;

#include <gtest/gtest.h>

// ============================================================================

TEST(conv, upper) {

    const std::string str = "A quick brown fox";

    auto res = upper(str);
    ASSERT_EQ(res, "A QUICK BROWN FOX");
}

TEST(conv, lower) {

    const std::string str = "A Quick Brown Fox";

    auto res = lower(str);
    ASSERT_EQ(res, "a quick brown fox");
}

TEST(match, startswith) {

    const std::string str = "The quick brown fox";
    ASSERT_EQ(startswith(str, "The"), true);
    ASSERT_EQ(startswith(str, "A"), false);
}

TEST(match, endswith) {

    const std::string str = "The quick brown fox";
    ASSERT_EQ(endswith(str, "fox"), true);
    ASSERT_EQ(endswith(str, "dog"), false);
}

TEST(pad, ljust) {

    const std::string str = "A fox";

    auto res1 = ljust(str, 10);
    ASSERT_EQ(res1, "     A fox");
    auto res2 = ljust(str, 4);
    ASSERT_EQ(res2, "A fox");
}

TEST(pad, rjust) {

    const std::string str = "A fox";

    auto res1 = rjust(str, 10);
    ASSERT_EQ(res1, "A fox     ");
    auto res2 = rjust(str, 4);
    ASSERT_EQ(res2, "A fox");
}

