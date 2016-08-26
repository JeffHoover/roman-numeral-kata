#include <string.h>
#include "arabic_to_roman.h"

static void appendZeroToThreeTrailingIdigits(const int arabicValue, char *romanResult);
static void compute_roman_digit(unsigned int *arabicValue,
			 const unsigned int incrementalValue, char *romanDigit,
			 char *romanValue);

unsigned int incrementalValue[] =
    { 1000, 900, 400, 100, 90, 50, 40, 10, 9, 5, 4 };
char *romanDigit[] =
    { "M", "CM", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV" };

void arabic_to_roman(unsigned int arabicValue, char *romanResult)
{
    if (arabicValue < 1 || arabicValue > 3999) {
	// TODO - Check if romanResult is too short? 
	strcpy(romanResult, "INPUT_OUT_OF_RANGE");
	return;
    }

    romanResult[0] = 0;

    for (unsigned int ii = 0; ii < sizeof(incrementalValue) / sizeof(int); ii++) {
	compute_roman_digit(&arabicValue, incrementalValue[ii], romanDigit[ii],
			    romanResult);
    }

    appendZeroToThreeTrailingIdigits(arabicValue, romanResult);
}

static void appendZeroToThreeTrailingIdigits(const int arabicValue, char *romanResult)
{
    for (int ii = 0; ii < arabicValue; ii++) {
	strcat(romanResult, "I");
    }
}

static void compute_roman_digit(unsigned int *arabicValue,
			 const unsigned int incrementalValue, char *romanDigit,
			 char *romanValue)
{
    if (*arabicValue >= incrementalValue) {
	strcat(romanValue, romanDigit);
	*arabicValue -= incrementalValue;
	compute_roman_digit(arabicValue, incrementalValue, romanDigit,
			    romanValue);
    }
}

