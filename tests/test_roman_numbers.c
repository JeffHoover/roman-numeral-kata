#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "msg_asserts.h"
#include "roman_arithmetic.h"
#include "arabic_to_roman.h"
#include "roman_to_arabic.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define DATA_COUNT 40

// If I wanted to spend more time,
// I would make it easier to eyeball the arabic/roman pairs. That might be a big-ish refactor.
// The way I am leaving it, the 4 rows of arrray values map 1:1 between arabic and roman, which isn't too bad.
int arabic_values[DATA_COUNT] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    24, 40, 47, 50, 67, 74, 90, 99,
    100, 202, 330, 400, 482, 500, 900, 1000,
    2001, 3030, 4000, 0
};

char *roman_values[DATA_COUNT] =
    { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
    "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX",
    "XXIV", "XL", "XLVII", "L", "LXVII", "LXXIV", "XC", "XCIX",
    "C", "CCII", "CCCXXX", "CD", "CDLXXXII", "CDC", "CM", "M",
    "MMI", "MMMXXX", "INPUT_OUT_OF_RANGE", "INPUT_OUT_OF_RANGE"
};


START_TEST(subtraction)
{
    char *minuend = "IV";
    char *subtrahend = "I";
    char differenceResult[20];

    subtract(minuend, subtrahend, (char *)differenceResult);

    check_subtraction_result(minuend, subtrahend, "III", differenceResult);


    minuend = "I";
    subtrahend = "C";
    subtract(minuend, subtrahend, (char *)differenceResult);

    check_subtraction_result(minuend, subtrahend, "INPUT_OUT_OF_RANGE", differenceResult);

    printf("\n");
}
END_TEST


START_TEST(addition)
{
    char *leftAddend = "I";
    char *rightAddend = "I";
    char sumResult[20];		// This might be a few bytes too big. I'm ok with that.

    printf("\n");
    add(leftAddend, rightAddend, (char *)sumResult);

    check_addition_result(leftAddend, rightAddend, "II", sumResult);


    leftAddend = "MMM";
    rightAddend = "MMM";
    add(leftAddend, rightAddend, (char *)sumResult);

    check_addition_result(leftAddend, rightAddend, "INPUT_OUT_OF_RANGE", sumResult);
}
END_TEST


START_TEST(round_trip)
{
    // Should not be a for loop test, but I'm doing this instead of
    // initializing a pair of 3999 value string arrays for test data.
    char romanResult[20];
    for (int ii=1; ii<=3999; ii++) {
       arabic_to_roman(ii, romanResult);
       int arabicValue = roman_to_arabic(romanResult);
       ck_assert_msg(arabicValue == ii, ANSI_COLOR_RED "\nfailed round trip of %d = %s"
                                        ANSI_COLOR_RESET, ii, romanResult);
    }
}
END_TEST

START_TEST(to_roman)
{
    // This might be a few bytes too big. I'm ok with that.
    char romanResult[20];

    arabic_to_roman(arabic_values[_i], romanResult);

    check_arabic_to_roman(arabic_values[_i], roman_values[_i], romanResult);
}
END_TEST

START_TEST(to_arabic_misc)
{
    int result = 0;

    result = roman_to_arabic("IIX");
    check_roman_to_arabic("IIX", -1, result);

    result = roman_to_arabic("VVXI");
    check_roman_to_arabic("VVXI", -1, result);

    result = roman_to_arabic("ID");
    check_roman_to_arabic("ID", -1, result);

    result = roman_to_arabic("IM");
    check_roman_to_arabic("IM", -1, result);

    result = roman_to_arabic("VL");
    check_roman_to_arabic("VL", -1, result);

    result = roman_to_arabic("VC");
    check_roman_to_arabic("VC", -1, result);

    result = roman_to_arabic("VD");
    check_roman_to_arabic("VD", -1, result);

    result = roman_to_arabic("VM");
    check_roman_to_arabic("VM", -1, result);


    result = roman_to_arabic("XD");
    check_roman_to_arabic("XD", -1, result);

    result = roman_to_arabic("XM");
    check_roman_to_arabic("XM", -1, result);


    result = roman_to_arabic("LD");
    check_roman_to_arabic("LD", -1, result);

    result = roman_to_arabic("LM");
    check_roman_to_arabic("LM", -1, result);

}
END_TEST

START_TEST(to_arabic_repeat)
{
    int result = 0;

    result = roman_to_arabic("VV");
    check_roman_to_arabic("VV", -1, result);

    result = roman_to_arabic("LL");
    check_roman_to_arabic("LL", -1, result);

    result = roman_to_arabic("DD");
    check_roman_to_arabic("DD", -1, result);


    result = roman_to_arabic("IIII");
    check_roman_to_arabic("IIII", -1, result);

    result = roman_to_arabic("XXXX");
    check_roman_to_arabic("XXXX", -1, result);

    result = roman_to_arabic("CCCC");
    check_roman_to_arabic("CCCC", -1, result);

    result = roman_to_arabic("MMMM");
    check_roman_to_arabic("MMMM", -1, result);
}
END_TEST


START_TEST(to_arabic)
{
    int arabicValue = roman_to_arabic(roman_values[_i]);

    check_roman_to_arabic(roman_values[_i], arabic_values[_i], arabicValue);
}
END_TEST


START_TEST(to_arabic_null)
{
    int arabicValue = roman_to_arabic(NULL);

    check_NULL_roman_input(arabicValue);
}
END_TEST


START_TEST(to_arabic_empty)
{
    int arabicValue = roman_to_arabic("");

    check_empty_roman_input(arabicValue);
}
END_TEST


START_TEST(to_arabic_bad_data)
{
    char * badValue = "bad_value";

    int arabicValue = roman_to_arabic(badValue);

    check_bad_value(arabicValue, badValue);
}
END_TEST


START_TEST(to_arabic_bad_chars)
{
    char * badValue = "XVRRR";

    int arabicValue = roman_to_arabic(badValue);

    check_bad_value(arabicValue, badValue);
}
END_TEST


Suite *roman_suite(void)
{
    Suite *suite = suite_create("Roman Numeral Unit Tests");

    TCase *tc_round_trip = tcase_create("RoundTrip");
    tcase_add_test(tc_round_trip, round_trip);
    suite_add_tcase(suite, tc_round_trip);

    TCase *tc_to_roman = tcase_create("ArabicToRoman");
    tcase_add_loop_test(tc_to_roman, to_roman, 0, DATA_COUNT);
    suite_add_tcase(suite, tc_to_roman);

    TCase *tc_to_arabic = tcase_create("RomanToArabic");
    tcase_add_loop_test(tc_to_arabic, to_arabic, 0, DATA_COUNT - 2); // Don't use 2 INPUT_OUT_OF_RANGE as to_arabic input
    suite_add_tcase(suite, tc_to_arabic);

    tc_to_arabic = tcase_create("RomanToArabicRepeat");
    tcase_add_test(tc_to_arabic, to_arabic_repeat);
    suite_add_tcase(suite, tc_to_arabic);

    tc_to_arabic = tcase_create("RomanToArabicMisc");
    tcase_add_test(tc_to_arabic, to_arabic_misc);
    suite_add_tcase(suite, tc_to_arabic);

    TCase *tc_to_arabic_bad_data = tcase_create("RomanToArabic_bad_data");
    tcase_add_test(tc_to_arabic_bad_data, to_arabic_bad_data);
    suite_add_tcase(suite, tc_to_arabic_bad_data);

    TCase *tc_to_arabic_null = tcase_create("RomanToArabic_null_data");
    tcase_add_test(tc_to_arabic_null, to_arabic_null);
    suite_add_tcase(suite, tc_to_arabic_null);

    TCase *tc_to_arabic_empty = tcase_create("RomanToArabic_empty");
    tcase_add_test(tc_to_arabic_empty, to_arabic_empty);
    suite_add_tcase(suite, tc_to_arabic_empty);

    TCase *tc_to_arabic_bad_chars = tcase_create("RomanToArabic_bad_chars");
    tcase_add_test(tc_to_arabic_bad_chars, to_arabic_bad_chars);
    suite_add_tcase(suite, tc_to_arabic_bad_chars);

    TCase *tc_addition = tcase_create("Addition");
    tcase_add_test(tc_addition, addition);
    suite_add_tcase(suite, tc_addition);

    TCase *tc_subtraction = tcase_create("Subtraction");
    tcase_add_test(tc_subtraction, subtraction);
    suite_add_tcase(suite, tc_subtraction);

    return suite;
}

void srunner_set_fork_status(SRunner * runner, enum fork_status fstat);

int main(void)
{
    int number_tests_failed;
    Suite *s = roman_suite();
    SRunner *runner = srunner_create(s);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    number_tests_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (number_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

