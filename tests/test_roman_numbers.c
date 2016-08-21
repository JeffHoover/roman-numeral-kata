#include <roman_utils.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <arabic_to_roman.h>
#include <roman_to_arabic.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define VALID_DATA_COUNT 40 

// If I wanted to spend more time,
// I would make it easier to eyeball the arabic/roman pairs. That might be a big-ish refactor.
// The way I am leaving it, the 4 rows of arrray values map 1:1 between arabic and roman, which isn't too bad.
int arabic_values [VALID_DATA_COUNT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                        24, 40, 47, 50, 67, 74, 90, 99,
                        100, 202, 330, 400, 482, 500, 900, 1000,
                        2001, 3030, 4000, 0};

char * roman_values [VALID_DATA_COUNT] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
                                          "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", 
                         "XXIV", "XL", "XLVII", "L", "LXVII", "LXXIV", "XC", "XCIX",
                          "C","CCII", "CCCXXX", "CD", "CDLXXXII", "CDC", "CM", "M",
                          "MMI", "MMMXXX", "INPUT_OUT_OF_RANGE", "INPUT_OUT_OF_RANGE"};

START_TEST (subtraction)
{
     char * expectedDifference = "III";
     char * minuend = "IV";
     char * subtrahend = "I";
     char differenceResult [20];
     subtract (minuend, subtrahend, (char *) differenceResult);

     // If I wanted to spend more time,
     // I would try to extract some of the stuff below into a function that reads better
     // same for all the ck_assert_msg calls in this file.
     ck_assert_msg(strcmp(expectedDifference, differenceResult) == 0,
                 ANSI_COLOR_RED
                 "\n%s - %s expected %s but was %s\n"
                 ANSI_COLOR_RESET,
                 minuend, subtrahend, expectedDifference, differenceResult);

     printf(ANSI_COLOR_GREEN "%s - %s = %s\n" ANSI_COLOR_RESET, minuend, subtrahend, differenceResult);
     printf("\n");

}
END_TEST

START_TEST (addition)
{
     char * expectedSum = "II";
     char * leftAddend = "I";
     char * rightAddend = "I";
     char sumResult [20]; // This might be a few bytes too big. I'm ok with that.

     printf("\n");
     add (leftAddend, rightAddend, (char *) sumResult);

     ck_assert_msg(strcmp(expectedSum, sumResult) == 0,
                 ANSI_COLOR_RED
                 "%s + %s expected %s but was %s\n"
                 ANSI_COLOR_RESET,
                 leftAddend, rightAddend, expectedSum, sumResult);

     printf(ANSI_COLOR_GREEN "%s + %s = %s\n" ANSI_COLOR_RESET, leftAddend, rightAddend, sumResult);
}
END_TEST

void check_result(unsigned int input, char * expected, char * actual, char * funcName){
    ck_assert_msg(strcmp(actual, expected) == 0,
        ANSI_COLOR_RED
        "%s(%d) expected %s but was %s\n"
             ANSI_COLOR_RESET,
             funcName, input, expected, actual);

     printf(ANSI_COLOR_GREEN "%s(%d) = %s\n" ANSI_COLOR_RESET , funcName, input, actual);
}

START_TEST (to_roman)
{
    // This might be a few bytes too big. I'm ok with that.
    // Longest roman numeral in test is "MMMMDCCCXCIV". Error message is 18 long.
    char romanResult[20];

    arabic_to_roman(arabic_values[_i], romanResult);

    check_result(arabic_values[_i], roman_values[_i], romanResult, "convert_arabic_to_roman" );
}
END_TEST

void check_result_i(char * input, unsigned int expected, unsigned int actual, char * funcName){
    ck_assert_msg(actual == expected,
        ANSI_COLOR_RED
        "%s(%s) expected %d but was %d\n"
             ANSI_COLOR_RESET,
             funcName, input, expected, actual);

     printf(ANSI_COLOR_GREEN "%s(%s) = %d\n" ANSI_COLOR_RESET , funcName, input, actual);
}

START_TEST (to_arabic)
{
     int arabicValue = roman_to_arabic(roman_values[_i]);

     check_result_i(roman_values[_i], arabic_values[_i], arabicValue, "convert_roman_to_arabic");
}
END_TEST

START_TEST (to_arabic_bad_data)
{
     int expectedFailure = -1;

     int arabicValue = roman_to_arabic(NULL);
     ck_assert_msg(arabicValue == expectedFailure,
             ANSI_COLOR_RED
             "convert_roman_to_arabic(NULL) expected %d but was %d\n"
             ANSI_COLOR_RESET,
             expectedFailure, arabicValue);
     printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(NULL) = %d\n" ANSI_COLOR_RESET, arabicValue); 

     arabicValue = roman_to_arabic("");
     ck_assert_msg(arabicValue == expectedFailure,
             ANSI_COLOR_RED
             "convert_roman_to_arabic(\"\") expected %d but was %d\n"
             ANSI_COLOR_RESET,
             expectedFailure, arabicValue);
     printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(\"\") = %d\n" ANSI_COLOR_RESET, arabicValue); 

/*
     char * badValue = "bad_value";
     arabicValue = roman_to_arabic(badValue);
     ck_assert_msg(arabicValue == expectedFailure,
             ANSI_COLOR_RED
             "convert_roman_to_arabic(%s) expected %d but was %d\n"
             ANSI_COLOR_RESET,
             badValue, expectedFailure, arabicValue);
     printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(%s) = %d\n" ANSI_COLOR_RESET, badValue, arabicValue); 

     badValue = "XVRRR";
     arabicValue = roman_to_arabic(badValue);
     ck_assert_msg(arabicValue == expectedFailure,
             ANSI_COLOR_RED
             "convert_roman_to_arabic(%s) expected %d but was %d\n"
             ANSI_COLOR_RESET,
             badValue, expectedFailure, arabicValue);
     printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(%s) = %d\n" ANSI_COLOR_RESET, badValue, arabicValue); 
*/
}
END_TEST

Suite * roman_suite (void)
{
  Suite *s = suite_create ("Roman Numeral Unit Tests");

  TCase *tc_to_arabic = tcase_create ("RomanToArabic");
  tcase_add_loop_test(tc_to_arabic, to_arabic, 0, VALID_DATA_COUNT - 2);
  suite_add_tcase (s, tc_to_arabic);

  TCase *tc_to_roman = tcase_create ("ArabicToRoman");
  tcase_add_loop_test(tc_to_roman, to_roman, 0, VALID_DATA_COUNT);
  suite_add_tcase (s, tc_to_roman);

  TCase *tc_to_arabic_bad_data = tcase_create ("RomanToArabic_bad_data");
  tcase_add_test(tc_to_arabic_bad_data, to_arabic_bad_data);
  suite_add_tcase (s, tc_to_arabic_bad_data);

  TCase *tc_addition = tcase_create ("Addition");
  tcase_add_test (tc_addition, addition);
  suite_add_tcase (s, tc_addition);

  TCase *tc_subtraction = tcase_create ("Subtraction");
  tcase_add_test (tc_subtraction, subtraction);
  suite_add_tcase (s, tc_subtraction);

  return s;
}



void srunner_set_fork_status (SRunner * sr, enum fork_status fstat);

int main(void)
{
  int number_tests_failed;
  Suite *s = roman_suite ();
  SRunner *sr = srunner_create (s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all (sr, CK_NORMAL);
  number_tests_failed = srunner_ntests_failed (sr);
  srunner_free (sr);
  return (number_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

