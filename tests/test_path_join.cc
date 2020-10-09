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
}


