#include <pathutils.hh>
using namespace pathutils;

#include <gtest/gtest.h>

// ============================================================================

TEST(path, split) {

    auto r1 = split("/home/user/documents/something.txt");
    ASSERT_EQ(r1.first,  "/home/user/documents");
    ASSERT_EQ(r1.second, "something.txt");

    auto r2 = split("/home/user/documents/");
    ASSERT_EQ(r2.first,  "/home/user/documents");
    ASSERT_EQ(r2.second, "");

    auto r3 = split("something.txt");
    ASSERT_EQ(r3.first,  "");
    ASSERT_EQ(r3.second, "something.txt");

    auto r4 = split("/something.txt");
    ASSERT_EQ(r4.first,  "/");
    ASSERT_EQ(r4.second, "something.txt");
}


