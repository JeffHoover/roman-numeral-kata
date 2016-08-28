#include <string.h>
#include <stdbool.h>
#include "roman_to_arabic.h"

static int lookup_addend_for(const char romanDigit);
static void find_arabic_addends(int *arabicAddends, const char *romanNumeral);
static int compute_arabic_from_addends(const int *arabicAddends,
				       const int numberOfRomanDigits);
static bool numeral_contains_illegal_repeat(const char *romanNumeral);
static bool numeral_contains_too_many_subtractives(const char *romanNumeral);
static bool subtractive_results_in_itself(const char *romanNumeral);

int roman_to_arabic(const char *romanNumeral)
{
    if (romanNumeral == NULL) {
	return -1;
    }

    for (unsigned int ii = 0; ii < strlen(romanNumeral); ii++) {
	if (strchr("IVXCLDM", romanNumeral[ii]) == NULL)
	    return -1;
    }

    if (numeral_contains_illegal_repeat(romanNumeral)) {
	return -1;
    }

    if (numeral_contains_too_many_subtractives(romanNumeral)) {
	return -1;
    }

    if (subtractive_results_in_itself(romanNumeral)) {
	return -1;
    }

    int arabicAddends[20];	// Might be a few bytes too big. I'm ok with that.

    find_arabic_addends(arabicAddends, romanNumeral);

    int answer =
	compute_arabic_from_addends(arabicAddends, strlen(romanNumeral));
    if (answer == 0 || answer > 3999) {
	return -1;
    }

    return answer;
}

static bool numeral_contains_illegal_repeat(const char *romanNumeral)
{
    if (strstr(romanNumeral, "VV") != NULL) {
	return true;
    }
    if (strstr(romanNumeral, "LL") != NULL) {
	return true;
    }
    if (strstr(romanNumeral, "DD") != NULL) {
	return true;
    }

    if (strstr(romanNumeral, "IIII") != NULL) {
	return true;
    }
    if (strstr(romanNumeral, "XXXX") != NULL) {
	return true;
    }
    if (strstr(romanNumeral, "CCCC") != NULL) {
	return true;
    }

    return false;
}

static bool left_digit_is_smaller(const char left, const char right);

static bool numeral_contains_too_many_subtractives(const char *romanNumeral)
{
    unsigned int numeralLen = strlen(romanNumeral);
    if (numeralLen < 3) {	// Shouldn't need this guard  ???
	return false;
    }

    for (unsigned int ii = 0; ii < numeralLen - 2; ii++) {
	if (left_digit_is_smaller(romanNumeral[ii], romanNumeral[ii + 2]) &&
	    left_digit_is_smaller(romanNumeral[ii + 1], romanNumeral[ii + 2])) {
	    return true;
	}
    }
    return false;
}

static bool subtractive_results_in_itself(const char *romanNumeral)
{

    for (unsigned int ii = 0; ii < strlen(romanNumeral) - 1; ii++) {
	int left = romanNumeral[ii];
	int right = romanNumeral[ii + 1];
	if (right - left == left) {
	    return true;
	}

    }
    return false;
}

static bool left_digit_is_smaller(const char left, const char right)
{
    int arabic_left = lookup_addend_for(left);
    int arabic_right = lookup_addend_for(right);
    return arabic_left < arabic_right;
}

static int lookup_addend_for(const char romanDigit)
{
    switch (romanDigit) {
    case 'I':
	return 1;
    case 'V':
	return 5;
    case 'X':
	return 10;
    case 'L':
	return 50;
    case 'C':
	return 100;
    case 'D':
	return 500;
    case 'M':
	return 1000;
    default:
	return -1;		// TODO - not covered by test?
    }
}

static void find_arabic_addends(int *arabicAddends, const char *romanNumeral)
{
    if (arabicAddends == NULL || romanNumeral == NULL) {
	return;
    }

    for (unsigned int ii = 0; ii < strlen(romanNumeral); ii++) {
	arabicAddends[ii] = lookup_addend_for(*(romanNumeral + ii));
    }
}

static int compute_arabic_from_addends(const int *arabicAddends,
				       const int numberOfRomanDigits)
{
    if (arabicAddends == NULL || numberOfRomanDigits < 1) {
	return -1;
    }

    int arabicValue = arabicAddends[numberOfRomanDigits - 1];
    for (int ii = 0; ii < numberOfRomanDigits - 1; ii++) {
	if (arabicAddends[ii] < arabicAddends[ii + 1]) {
	    arabicValue -= arabicAddends[ii];
	} else {
	    arabicValue += arabicAddends[ii];
	}
    }
    return arabicValue;
}
