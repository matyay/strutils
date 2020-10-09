#include <pathutils.hh>
using namespace pathutils;

#include <gtest/gtest.h>

// ============================================================================

TEST(path, join) {

    auto r1 = join({"home", "user", "data"});
    ASSERT_EQ(r1, "home/user/data");

    auto r2 = join({"home/", "/user", "/data/", "important/docs"});
    ASSERT_EQ(r2, "home/user/data/important/docs");
    
    auto r3 = join({"/home", "user", "data"});
    ASSERT_EQ(r3, "/home/user/data");

    auto r4 = join({"/home", "", "user"});
    ASSERT_EQ(r4, "/home/user");

    auto r5 = join({"", "user", "data"});
    ASSERT_EQ(r5, "user/data");

    auto r6 = join({"/home/user", "data", "very/important/docs", "doc.txt"});
    ASSERT_EQ(r6, "/home/user/data/very/important/docs/doc.txt");
}


