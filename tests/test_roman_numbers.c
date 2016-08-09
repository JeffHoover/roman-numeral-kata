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
    int arabic_values [] = {1, 3, 4};
    char * roman_values [] = {"I", "III", "IV"};
    for (int ii=0; ii< sizeof(arabic_values)/sizeof(int); ii++)
    {
        char romanResult[20];
        char * romanBuffer = arabic_to_roman(arabic_values[ii]);
        strcpy(romanResult, romanBuffer);
        free(romanBuffer);
        ck_assert_msg(strcmp(romanResult, roman_values[ii])==0,
            ANSI_COLOR_RED
            "\nconvert_arabic_to_roman(%d) expected %s but was %s\n"
                 ANSI_COLOR_RESET,
                 arabic_values[ii], roman_values[ii], romanResult);
         printf(ANSI_COLOR_GREEN "convert_arabic_to_roman(%d) = %s\n" ANSI_COLOR_RESET ,
                arabic_values[ii], romanResult);
     }
     printf("\n");
}
END_TEST

START_TEST (to_arabic)
{
     char * roman_values [] = {"I", "II", "III", "V", "IV",
                             "VI", "VII", "VIII", "IX", "X", "XXIV",
                             "L", "LXVII", "XCIX", "C", "D", "M", "MMMM", 
                              "MMMMDCCXCIV","MMMMCMXCIX"};
     int arabic_values [] = {1, 2, 3, 5, 4, 6, 7, 8, 9, 10, 24, 50, 67, 99, 100, 500,
                       1000, 4000, 4794, 4999};
     printf("\n");
     for (int ii=0; ii < sizeof(arabic_values)/sizeof(int); ii++) {
         int arabicValue = roman_to_arabic(roman_values[ii]);
         ck_assert_msg(arabicValue == arabic_values[ii],
                 ANSI_COLOR_RED
                 "\nconvert_roman_to_arabic(%s) expected %d but was %d\n"
                 ANSI_COLOR_RESET,
                 roman_values[ii], arabic_values[ii], arabicValue);
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

