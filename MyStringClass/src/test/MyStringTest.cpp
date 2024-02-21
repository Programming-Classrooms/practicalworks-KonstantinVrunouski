#include <gtest/gtest.h>
#include "../MyString/MyString.hpp"


TEST(testGetLength, GoodTest)
{
    MyString str("ESET NOD32");
    EXPECT_EQ(str.getLength(), 10);
}

TEST(testGetLength, BadTest)
{
    MyString str("Bebra649");
    EXPECT_NE(str.getLength(), 7);
}

TEST(testCount, goodTest)
{
    MyString str("bara bara bara");
    EXPECT_EQ(str.count('a'), 6);
    EXPECT_EQ(str.count('r'), 3);
    EXPECT_EQ(str.count('o'), 0);
}

TEST(testFindFirst, goodTest)
{
    MyString str("rerurn chizlo");
    EXPECT_EQ((str.findFirst('u')), 3);
    EXPECT_EQ((str.findFirst('n')), 5);
    EXPECT_EQ((str.findFirst('s')), -1);
}

TEST(testFindLast, goodTest)
{
    MyString str("unnunnun");
    EXPECT_EQ((str.findLast('u')), 6);
    EXPECT_EQ((str.findLast('n')), 7);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
