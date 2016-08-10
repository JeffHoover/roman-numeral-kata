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

START_TEST (to_roman)
{
    int arabic_values [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 40};
    char * expected_roman_values [] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", "XL"};

    char romanResult[20]; // TODO - 20 is probably a little big. Longest roman numeral in test is "MMMMDCCXCIV"
    for (int ii=0; ii< sizeof(arabic_values)/sizeof(int); ii++)
    {
        arabic_to_roman(arabic_values[ii], romanResult);
        ck_assert_msg(strcmp(romanResult, expected_roman_values[ii])==0,
// TODO: can I extract any of the stuff below into a function that reads better?
            ANSI_COLOR_RED
            "\nconvert_arabic_to_roman(%d) expected %s but was %s\n"
                 ANSI_COLOR_RESET,
                 arabic_values[ii], expected_roman_values[ii], romanResult);
         printf(ANSI_COLOR_GREEN "convert_arabic_to_roman(%d) = %s\n" ANSI_COLOR_RESET ,
                arabic_values[ii], romanResult);
     }
     printf("\n");
}
END_TEST

START_TEST (to_arabic)
{
// TODO: Can I have one set of roman and arabic values and have locals
// like "expected_roman_values" point to the one copy?
// Not until at least both algorithms are finished.
     char * roman_values [] = {"I", "II", "III", "V", "IV",
                             "VI", "VII", "VIII", "IX", "X", "XXIV",
                             "L", "LXVII", "XCIX", "C", "D", "M", "MMMM", 
                              "MMMMDCCXCIV","MMMMCMXCIX"};
     int expected_arabic_values [] = {1, 2, 3, 5, 4, 6, 7, 8, 9, 10, 24, 50, 67, 99, 100, 500,
                       1000, 4000, 4794, 4999};
     printf("\n");
     for (int ii=0; ii < sizeof(expected_arabic_values)/sizeof(int); ii++) {
         int arabicValue = roman_to_arabic(roman_values[ii]);
// TODO: Can I make extract any here, as above?
         ck_assert_msg(arabicValue == expected_arabic_values[ii],
                 ANSI_COLOR_RED
                 "\nconvert_roman_to_arabic(%s) expected %d but was %d\n"
                 ANSI_COLOR_RESET,
                 roman_values[ii], expected_arabic_values[ii], arabicValue);
         printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(%s) = %d\n" ANSI_COLOR_RESET, roman_values[ii], arabicValue); 
     }
     printf("\n");
}
END_TEST

Suite * roman_suite (void)
{
  Suite *s = suite_create ("Roman Numeral Unit Tests");

  TCase *tc_to_arabic = tcase_create ("RomanToArabic");
  tcase_add_test (tc_to_arabic, to_arabic);
  suite_add_tcase (s, tc_to_arabic);

  TCase *tc_to_roman = tcase_create ("ArabicToRoman");
  tcase_add_test (tc_to_roman, to_roman);
  suite_add_tcase (s, tc_to_roman);

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

