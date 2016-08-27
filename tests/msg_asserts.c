#include <stdio.h>
#include <check.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void check_arabic_to_roman(const unsigned int input, const char *expected, const char *actual)
{
    ck_assert_msg(strcmp(actual, expected) == 0,
		  ANSI_COLOR_RED
		  "\nconvert_arabic_to_roman(%d) expected %s but was %s\n"
		  ANSI_COLOR_RESET, input, expected, actual);

    printf(ANSI_COLOR_GREEN "convert_arabic_to_roman(%d) = %s\n"
	   ANSI_COLOR_RESET, input, actual);
}

void check_roman_to_arabic(const char *input, const unsigned int expected,
			   const unsigned int actual)
{
    ck_assert_msg(actual == expected,
		  ANSI_COLOR_RED
		  "\nconvert_roman_to_arabic(%s) expected %d but was %d\n"
		  ANSI_COLOR_RESET, input, expected, actual);

    printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(%s) = %d\n"
	   ANSI_COLOR_RESET, input, actual);
}

void check_subtraction_result(const char *minuend, const char *subtrahend, const char *expected,
			      const char *actual)
{
    ck_assert_msg(strcmp(expected, actual) == 0,
		  ANSI_COLOR_RED
		  "\n%s - %s expected %s but was %s\n"
		  ANSI_COLOR_RESET, minuend, subtrahend, expected, actual);

    printf(ANSI_COLOR_GREEN "%s - %s = %s\n" ANSI_COLOR_RESET, minuend,
	   subtrahend, actual);
}

void check_addition_result(const char *leftAddend, const char *rightAddend,
			   const char *expectedSum, const char *sumResult)
{
    ck_assert_msg(strcmp(expectedSum, sumResult) == 0,
		  ANSI_COLOR_RED
		  "\n%s + %s expected %s but was %s\n"
		  ANSI_COLOR_RESET,
		  leftAddend, rightAddend, expectedSum, sumResult);

    printf(ANSI_COLOR_GREEN "%s + %s = %s\n" ANSI_COLOR_RESET, leftAddend,
	   rightAddend, sumResult);
}

void check_NULL_roman_input(const int arabicValue)
{
    int expectedFailure = -1;

    ck_assert_msg(arabicValue == expectedFailure,
		  ANSI_COLOR_RED
		  "\nconvert_roman_to_arabic(NULL) expected %d but was %d\n"
		  ANSI_COLOR_RESET, expectedFailure, arabicValue);
    printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(NULL) = %d\n"
	   ANSI_COLOR_RESET, arabicValue);
}

void check_empty_roman_input(const int arabicValue)
{
    int expectedFailure = -1;
    ck_assert_msg(arabicValue == expectedFailure,
		  ANSI_COLOR_RED
		  "\nconvert_roman_to_arabic(\"\") expected %d but was %d\n"
		  ANSI_COLOR_RESET, expectedFailure, arabicValue);
    printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(\"\") = %d\n"
	   ANSI_COLOR_RESET, arabicValue);
}

void check_bad_value(const int arabicValue, const char *badValue)
{
    int expectedFailure = -1;
    ck_assert_msg(arabicValue == expectedFailure,
		  ANSI_COLOR_RED
		  "\nconvert_roman_to_arabic(%s) expected %d but was %d\n"
		  ANSI_COLOR_RESET, badValue, expectedFailure, arabicValue);
    printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(%s) = %d\n"
	   ANSI_COLOR_RESET, badValue, arabicValue);
}

