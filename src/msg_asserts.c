#include <check.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#include <stdio.h>

void check_arabic_to_roman(unsigned int input, char *expected, char *actual)
{
    ck_assert_msg(strcmp(actual, expected) == 0,
		  ANSI_COLOR_RED
		  "convert_arabic_to_roman(%d) expected %s but was %s\n"
		  ANSI_COLOR_RESET, input, expected, actual);

    printf(ANSI_COLOR_GREEN "convert_arabic_to_roman(%d) = %s\n" ANSI_COLOR_RESET, input, actual);
}

void check_roman_to_arabic(char *input, unsigned int expected, unsigned int actual)
{
    ck_assert_msg(actual == expected,
		  ANSI_COLOR_RED
		  "convert_roman_to_arabic(%s) expected %d but was %d\n"
		  ANSI_COLOR_RESET, input, expected, actual);

    printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(%s) = %d\n" ANSI_COLOR_RESET, input, actual);
}

void check_subtraction_result(char *minuend, char *subtrahend, char *expected,
			      char *actual)
{

    ck_assert_msg(strcmp(expected, actual) == 0,
		  ANSI_COLOR_RED
		  "\n%s - %s expected %s but was %s\n"
		  ANSI_COLOR_RESET, minuend, subtrahend, expected, actual);

    printf(ANSI_COLOR_GREEN "%s - %s = %s\n" ANSI_COLOR_RESET, minuend,
	   subtrahend, actual);
}

void check_addition_result(char *leftAddend, char *rightAddend,
			   char *expectedSum, char *sumResult)
{

    ck_assert_msg(strcmp(expectedSum, sumResult) == 0,
		  ANSI_COLOR_RED
		  "%s + %s expected %s but was %s\n"
		  ANSI_COLOR_RESET,
		  leftAddend, rightAddend, expectedSum, sumResult);

    printf(ANSI_COLOR_GREEN "%s + %s = %s\n" ANSI_COLOR_RESET, leftAddend,
	   rightAddend, sumResult);
}

void check_NULL_roman_input(int arabicValue)
{
    int expectedFailure = -1;

    ck_assert_msg(arabicValue == expectedFailure,
		  ANSI_COLOR_RED
		  "convert_roman_to_arabic(NULL) expected %d but was %d\n"
		  ANSI_COLOR_RESET, expectedFailure, arabicValue);
    printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(NULL) = %d\n"
	   ANSI_COLOR_RESET, arabicValue);
}

void check_empty_roman_input(int arabicValue)
{
    int expectedFailure = -1;
    ck_assert_msg(arabicValue == expectedFailure,
		  ANSI_COLOR_RED
		  "convert_roman_to_arabic(\"\") expected %d but was %d\n"
		  ANSI_COLOR_RESET, expectedFailure, arabicValue);
    printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(\"\") = %d\n"
	   ANSI_COLOR_RESET, arabicValue);
}

void check_bad_value(int arabicValue, char *badValue)
{
    int expectedFailure = -1;
    ck_assert_msg(arabicValue == expectedFailure,
		  ANSI_COLOR_RED
		  "convert_roman_to_arabic(%s) expected %d but was %d\n"
		  ANSI_COLOR_RESET, badValue, expectedFailure, arabicValue);
    printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(%s) = %d\n"
	   ANSI_COLOR_RESET, badValue, arabicValue);
}
