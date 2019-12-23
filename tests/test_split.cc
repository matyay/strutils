#include <strutils.hh>
using namespace strutils;

#include <gtest/gtest.h>

// ============================================================================

TEST(split, whitespace) {

    const std::string str = " A  quick   brown fox  jumps  ";

    auto res = split(str);
    ASSERT_EQ(res.size(), 5);
    ASSERT_EQ(res[0], "A");
    ASSERT_EQ(res[1], "quick");
    ASSERT_EQ(res[2], "brown");
    ASSERT_EQ(res[3], "fox");
    ASSERT_EQ(res[4], "jumps");
}

TEST(split, whitespace_limit) {

    const std::string str = " A  quick   brown fox  jumps  ";

    auto res = split(str, std::string(), 2);
    ASSERT_EQ(res.size(), 3);
    ASSERT_EQ(res[0], "A");
    ASSERT_EQ(res[1], "quick");
    ASSERT_EQ(res[2], "brown fox  jumps  ");
}

TEST(split, comma) {

    const std::string str = ",A,quick,brown,fox,,jumps,";

    auto res = split(str, ",");
    ASSERT_EQ(res.size(), 8);
    ASSERT_EQ(res[0], "");
    ASSERT_EQ(res[1], "A");
    ASSERT_EQ(res[2], "quick");
    ASSERT_EQ(res[3], "brown");
    ASSERT_EQ(res[4], "fox");
    ASSERT_EQ(res[5], "");
    ASSERT_EQ(res[6], "jumps");
    ASSERT_EQ(res[7], "");
}

TEST(split, comma_limit) {

    const std::string str = ",A,quick,brown,fox,,jumps,";

    auto res = split(str, ",", 4);
    ASSERT_EQ(res.size(), 5);
    ASSERT_EQ(res[0], "");
    ASSERT_EQ(res[1], "A");
    ASSERT_EQ(res[2], "quick");
    ASSERT_EQ(res[3], "brown");
    ASSERT_EQ(res[4], "fox,,jumps,");
}

TEST(split, token) {

    const std::string str = "A<>quick<>brown<><>fox<>jumps<>";

    auto res = split(str, "<>");
    ASSERT_EQ(res.size(), 7);
    ASSERT_EQ(res[0], "A");
    ASSERT_EQ(res[1], "quick");
    ASSERT_EQ(res[2], "brown");
    ASSERT_EQ(res[3], "");
    ASSERT_EQ(res[4], "fox");
    ASSERT_EQ(res[5], "jumps");
    ASSERT_EQ(res[6], "");
}

// ==========================================================================

TEST(rsplit, comma) {

    const std::string str = ",A,quick,brown,fox,,jumps,";

    auto res = rsplit(str, ",");
    ASSERT_EQ(res.size(), 8);
    ASSERT_EQ(res[0], "");
    ASSERT_EQ(res[1], "A");
    ASSERT_EQ(res[2], "quick");
    ASSERT_EQ(res[3], "brown");
    ASSERT_EQ(res[4], "fox");
    ASSERT_EQ(res[5], "");
    ASSERT_EQ(res[6], "jumps");
    ASSERT_EQ(res[7], "");
}

TEST(rsplit, comma_limit) {

    const std::string str = ",A,quick,brown,fox,,jumps,";

    auto res = rsplit(str, ",", 4);
    ASSERT_EQ(res.size(), 5);
    ASSERT_EQ(res[0], ",A,quick,brown");
    ASSERT_EQ(res[1], "fox");
    ASSERT_EQ(res[2], "");
    ASSERT_EQ(res[3], "jumps");
    ASSERT_EQ(res[4], "");
}

TEST(rsplit, token) {

    const std::string str = "A<>quick<>brown<><>fox<>jumps<>";

    auto res = rsplit(str, "<>");
    ASSERT_EQ(res.size(), 7);
    ASSERT_EQ(res[0], "A");
    ASSERT_EQ(res[1], "quick");
    ASSERT_EQ(res[2], "brown");
    ASSERT_EQ(res[3], "");
    ASSERT_EQ(res[4], "fox");
    ASSERT_EQ(res[5], "jumps");
    ASSERT_EQ(res[6], "");
}


// ==========================================================================

TEST(splitlines, lines) {

    const std::string str = "A\nquick\nbrown\nfox.\n\n";

    auto res = splitlines(str);
    ASSERT_EQ(res.size(), 5);
    ASSERT_EQ(res[0], "A");
    ASSERT_EQ(res[1], "quick");
    ASSERT_EQ(res[2], "brown");
    ASSERT_EQ(res[3], "fox.");
    ASSERT_EQ(res[4], "");
}

