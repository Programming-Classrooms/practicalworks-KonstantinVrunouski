#include <gtest/gtest.h>
#include <fstream>
#include <stdexcept>
#include "../Source/func.hpp"


TEST(FileCheckTest, ValidFile) {
    std::ifstream file("src/files/numbers.txt");
    EXPECT_NO_THROW(checkFile(file, "src/files/numbers.txt"));
}

TEST(ToUpperTest, BasicConversion) {
    EXPECT_EQ(toUpper("hello"), "HELLO");
    EXPECT_EQ(toUpper("WoRlD"), "WORLD");
    EXPECT_EQ(toUpper("123abc"), "123ABC");
}

TEST(IsDigitTest, ValidDigits) {
    EXPECT_TRUE(isDigit("123"));
    EXPECT_TRUE(isDigit("-456"));
    EXPECT_FALSE(isDigit("abc"));
    EXPECT_FALSE(isDigit("123a"));
}

TEST(GetSizeForArrNumbersTest, ValidSizeCalculation) {
    std::string text = "1, 2, 3, 4, 5";
    std::string delimiters = ", ";
    EXPECT_EQ(getSizeForArrNumbers(text, delimiters), 5);

    text = "10 20 30";
    delimiters = " ";
    EXPECT_EQ(getSizeForArrNumbers(text, delimiters), 3);
}

TEST(GetSizeForArrNumbersTest, NoNumbers) {
    std::string text = "abc";
    std::string delimiters = " ";
    EXPECT_EQ(getSizeForArrNumbers(text, delimiters), 0);
}

TEST(FillingArrTest, BasicFill) {
    int32_t arr[5] = {0};
    std::string text = "1, 2, 3, 4, 5";
    std::string delims = ", ";
    EXPECT_NO_THROW(fillingArr(arr, text, delims));
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[4], 5);
}

TEST(FillingArrTest, EmptyInput) {
    int32_t arr[5] = {0};
    std::string text = "";
    std::string delims = ",";
    EXPECT_THROW(fillingArr(arr, text, delims), std::out_of_range);
}

TEST(QSortStringTest, BasicSort) {
    std::string arr[5] = {"hello", "world", "this", "is", "a"};
    qsortString(arr, 0, 4);
    EXPECT_EQ(arr[0], "hello");
    EXPECT_EQ(arr[1], "a");
    EXPECT_EQ(arr[4], "world");
}

TEST(QSortStringTest, EmptyInput) {
    std::string arr[1] = {""};
    qsortString(arr, 0, 0);
    EXPECT_EQ(arr[0], "");
}

TEST(IsWordTest, BasicChecks) {
    EXPECT_TRUE(isWord("Hello"));
    EXPECT_TRUE(isWord("World"));
    EXPECT_FALSE(isWord("123abc"));
    EXPECT_FALSE(isWord("2A3BC"));
}

TEST(GetSizeForArrSurenamesTest, BasicCount) {
    std::string text = "John, Alice, Bob";
    std::string delimiters = ", ";
    EXPECT_EQ(getSizeForArrSurenames(text, delimiters), 3);

    text = "Ann  Ben  Chris";
    delimiters = " ";
    EXPECT_EQ(getSizeForArrSurenames(text, delimiters), 3);
}

TEST(CompForStructTest, BasicComparison) {
    Employee emp1{"Doe", 2};
    Employee emp2{"Smith", 3};

    EXPECT_FALSE(compForStructToLower(emp1, emp2));
    EXPECT_TRUE(compForStructToLower(emp2, emp1));
    EXPECT_FALSE(compForStructToUpper(emp2, emp1));
    EXPECT_TRUE(compForStructToUpper(emp1, emp2));
}

TEST(CopySortArraysTest, BasicCopy) {
    int32_t mainArr[5] = {2, 5, 1, 4, 3};
    int32_t sortArr[5] = {0};

    EXPECT_NO_THROW(copySortArrays(mainArr, sortArr, 5));

    // Expect even numbers first, followed by odd numbers
    EXPECT_EQ(sortArr[0], 2);
    EXPECT_EQ(sortArr[1], 4);
    EXPECT_EQ(sortArr[2], 5);
    EXPECT_EQ(sortArr[3], 1);
    EXPECT_EQ(sortArr[4], 3);
}

TEST(CopySortArraysTest, EmptyArray) {
    int32_t mainArr[1] = {0};
    int32_t sortArr[1] = {0};

    EXPECT_THROW(copySortArrays(mainArr, sortArr, 0), std::out_of_range);
}

TEST(FillingArrOfStructTest, BasicFill) {
    Employee employees[3];
    int32_t children[3] = {1, 2, 3};
    std::string surnames[3] = {"Doe", "Smith", "Johnson"};

    EXPECT_NO_THROW(fillingArrOfStruct(employees, children, surnames, 3, 3));

    // Ensure struct array is correctly populated
    EXPECT_EQ(employees[0].surname, "Doe");
    EXPECT_EQ(employees[0].childrenAmount, 1);

    EXPECT_EQ(employees[1].surname, "Smith");
    EXPECT_EQ(employees[1].childrenAmount, 2);

    EXPECT_EQ(employees[2].surname, "Johnson");
    EXPECT_EQ(employees[2].childrenAmount, 3);
}

TEST(FillingArrOfStructTest, InvalidArguments) {
    Employee employees[1];
    int32_t children[1] = {1};
    std::string surnames[1] = {"Doe"};

    // Empty arrays should throw an exception
    EXPECT_THROW(fillingArrOfStruct(employees, children, surnames, 0, 0), std::invalid_argument);
}


TEST(PrintArrTest, EmptyArray) {
    int32_t arr[1] = {0};

    // Redirect cout to a stringstream for testing output
    testing::internal::CaptureStdout();
    EXPECT_THROW(printArr(arr, 0), std::out_of_range);
    std::string output = testing::internal::GetCapturedStdout();

    // Verify no output was produced
    EXPECT_TRUE(output.empty());
}

TEST(FileOperationsTest, WriteAndReadBinaryFile) {
    std::string filename = "src/files/result.bin";

    // Sample data
    Employee employees[2] = {{"Doe", 2}, {"Smith", 3}};

    // Write to binary file
    {
        std::ofstream fout(filename, std::ios::binary);
        ASSERT_TRUE(fout.is_open());
        EXPECT_NO_THROW(writeArrOfStructToBin(fout, employees, 2));
        fout.close();
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
