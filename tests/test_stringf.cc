#include <stringf.hh>

#include <gtest/gtest.h>

// ============================================================================

TEST(stringf, formatting) {

    std::string s = stringf("test %02d %s %.3f", 10, "str", 3.14f);
    ASSERT_EQ(s, "test 10 str 3.140");
}

TEST(stringf, alloc) {

    const std::string msg("this is a very long message. this is a very long message. this is a very long message. this is a very long message. this is a very long message. this is a very long message.");

    std::string s = stringf("%s", msg.c_str());
    ASSERT_EQ(s, msg);
}
