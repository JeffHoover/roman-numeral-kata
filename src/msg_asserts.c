#include <check.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#include <stdio.h>

void check_result(unsigned int input, char *expected, char *actual,
		  char *funcName)
{
    ck_assert_msg(strcmp(actual, expected) == 0,
		  ANSI_COLOR_RED
		  "%s(%d) expected %s but was %s\n"
		  ANSI_COLOR_RESET, funcName, input, expected, actual);

    printf(ANSI_COLOR_GREEN "%s(%d) = %s\n" ANSI_COLOR_RESET, funcName, input,
	   actual);
}

void check_result_i(char *input, unsigned int expected, unsigned int actual,
		    char *funcName)
{
    ck_assert_msg(actual == expected,
		  ANSI_COLOR_RED
		  "%s(%s) expected %d but was %d\n"
		  ANSI_COLOR_RESET, funcName, input, expected, actual);

    printf(ANSI_COLOR_GREEN "%s(%s) = %d\n" ANSI_COLOR_RESET, funcName, input,
	   actual);
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
