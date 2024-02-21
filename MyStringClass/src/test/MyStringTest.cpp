#include <gtest/gtest.h>
#include "../MyString/MyString.hpp"


TEST(testCaseConstructors, testDefultConstructor)
{
    MyString str("Avas");
    EXPECT_EQ(str.getLength(), 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}