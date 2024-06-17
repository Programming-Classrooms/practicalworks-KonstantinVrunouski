#include <gtest/gtest.h>
#include "../MyString/MyString.hpp" // Assuming the header file for MyString is included correctly

// Fixture for MyString tests
class MyStringTest : public ::testing::Test {
protected:
    MyStringTest() {
        // Code executed before each test
    }

    ~MyStringTest() override {
        // Code executed after each test
    }

    void SetUp() override {
        // Code executed before each test, right before the test body is run
    }

    void TearDown() override {
        // Code executed after each test, right before the destructor is called
    }
};

// Test the default constructor
TEST_F(MyStringTest, DefaultConstructor) {
    MyString str;
    EXPECT_EQ(str.getLength(), 0);
    EXPECT_TRUE(str.isEmpty());
}

// Test the constructor with const char* parameter
TEST_F(MyStringTest, ConstructorFromCString) {
    const char* testStr = "Hello";
    MyString str(testStr);
    EXPECT_EQ(str.getLength(), std::strlen(testStr));
    EXPECT_FALSE(str.isEmpty());
    EXPECT_STREQ(str.getStr(), testStr);
}

// Test copy constructor
TEST_F(MyStringTest, CopyConstructor) {
    const char* testStr = "Hello";
    MyString original(testStr);
    MyString copied(original);

    EXPECT_EQ(copied.getLength(), original.getLength());
    EXPECT_FALSE(copied.isEmpty());
    EXPECT_STREQ(copied.getStr(), original.getStr());
}

// Test assignment operator
TEST_F(MyStringTest, AssignmentOperator) {
    const char* testStr1 = "Hello";
    const char* testStr2 = "World";
    MyString str1(testStr1);
    MyString str2(testStr2);

    str1 = str2;

    EXPECT_EQ(str1.getLength(), std::strlen(testStr2));
    EXPECT_FALSE(str1.isEmpty());
    EXPECT_STREQ(str1.getStr(), testStr2);
}

// Test concatenation operator
TEST_F(MyStringTest, ConcatenationOperator) {
    const char* testStr1 = "Hello";
    const char* testStr2 = " World";
    MyString str1(testStr1);
    MyString str2(testStr2);

    MyString concatenated = str1 + str2;

    EXPECT_EQ(concatenated.getLength(), std::strlen(testStr1) + std::strlen(testStr2));
    EXPECT_FALSE(concatenated.isEmpty());
    EXPECT_STREQ(concatenated.getStr(), "Hello World");
}

// Test comparison operators
TEST_F(MyStringTest, ComparisonOperators) {
    const char* testStr1 = "Hello";
    const char* testStr2 = "World";
    MyString str1(testStr1);
    MyString str2(testStr2);
    MyString str3(testStr1);

    EXPECT_TRUE(str1 == str3);
    EXPECT_TRUE(str1 != str2);
    EXPECT_TRUE(str1 < str2);
    EXPECT_TRUE(str2 > str1);
    EXPECT_TRUE(str1 <= str3);
    EXPECT_TRUE(str1 >= str3);
}

// Test conversion to lowercase
TEST_F(MyStringTest, StringToLower) {
    const char* testStr = "Hello";
    MyString str(testStr);

    str.stringToLow();

    EXPECT_STREQ(str.getStr(), "hello");
}

// Test conversion to uppercase
TEST_F(MyStringTest, StringToUpper) {
    const char* testStr = "Hello";
    MyString str(testStr);

    str.stringToUp();

    EXPECT_STREQ(str.getStr(), "HELLO");
}

// Test character count
TEST_F(MyStringTest, CharacterCount) {
    const char* testStr = "Hello";
    MyString str(testStr);

    EXPECT_EQ(str.count('l'), 2);
    EXPECT_EQ(str.count('z'), 0);
}

// Test findFirst and findLast methods
TEST_F(MyStringTest, FindMethods) {
    const char* testStr = "Hello";
    MyString str(testStr);

    EXPECT_EQ(str.findFirst('l'), 2);
    EXPECT_EQ(str.findLast('l'), 3);
    EXPECT_EQ(str.findFirst('z'), -1);
    EXPECT_EQ(str.findLast('z'), -1);
}

// Test subscript operator
TEST_F(MyStringTest, SubscriptOperator) {
    const char* testStr = "Hello";
    MyString str(testStr);

    EXPECT_EQ(str[0], 'H');
    EXPECT_EQ(str[4], 'o');
    EXPECT_THROW(str[5], std::invalid_argument); // Out of bounds access should throw
}

// Test input and output operators
TEST_F(MyStringTest, InputOutputOperators) {
    const char* testStr = "Hello";
    MyString str;

    std::istringstream input(testStr);
    input >> str;

    std::ostringstream output;
    output << str;

    EXPECT_STREQ(str.getStr(), testStr);
    EXPECT_EQ(output.str(), testStr);
}
