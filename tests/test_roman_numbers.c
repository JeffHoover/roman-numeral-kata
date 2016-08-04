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

START_TEST (to_arabic)
{
     int expected [] = {1, 2, 3, 5, 4, 6, 7, 8, 10, 50, 100, 500, 1000};
     char * test_value [] = {"I", "II", "III", "V", "IV",
                             "VI", "VII", "VIII", "X",
                             "L", "C", "D", "M"};
     printf("\n");
     for (int ii=0; ii < sizeof(expected)/sizeof(int); ii++) {
         int actual = roman_to_arabic(test_value[ii]);
         ck_assert_msg(actual == expected[ii],
                 ANSI_COLOR_RED
                 "\nconvert_roman_to_arabic(%s) expected %d but was %d\n"
                 ANSI_COLOR_RESET,
                 test_value[ii], expected[ii], actual);
         printf(ANSI_COLOR_GREEN "convert_roman_to_arabic(%s) = %d\n" ANSI_COLOR_RESET , test_value[ii], actual); 
     }
     printf("\n");
}
END_TEST

START_TEST (to_roman)
{
}
END_TEST

Suite * roman_suite (void)
{
  Suite *s = suite_create ("Roman Numeral Unit Tests");

  TCase *tc_to_roman = tcase_create ("ArabicToRoman");
  tcase_add_test (tc_to_roman, to_roman);
  suite_add_tcase (s, tc_to_roman);

  TCase *tc_to_arabic = tcase_create ("RomanToArabic");
  tcase_add_test (tc_to_arabic, to_arabic);
  suite_add_tcase (s, tc_to_arabic);

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

