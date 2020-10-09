#include <pathutils.hh>
using namespace pathutils;

#include <gtest/gtest.h>

// ============================================================================

TEST(path, splitext) {

    auto r1 = splitext("/home/user/documents/something.txt");
    ASSERT_EQ(r1.first,  "/home/user/documents/something");
    ASSERT_EQ(r1.second, "txt");

    auto r2 = splitext("/home/user/documents/");
    ASSERT_EQ(r2.first,  "/home/user/documents/");
    ASSERT_EQ(r2.second, "");

    auto r3 = splitext("something.txt");
    ASSERT_EQ(r3.first,  "something");
    ASSERT_EQ(r3.second, "txt");
}
