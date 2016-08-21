#include <roman_to_arabic.h>
#include <string.h>

int lookup_addend_for(char romanDigit);
void find_arabic_addends(int *arabicAddends, char *romanNumeral);
int compute_arabic_from_addends(int *arabicAddends, int numberOfRomanDigits);

int roman_to_arabic(char *romanNumeral)
{
    if (romanNumeral == NULL) {
	return -1;
    }

    for (unsigned int ii = 0; ii < strlen(romanNumeral); ii++) {
	if (strchr("IVXCLDM", romanNumeral[ii]) == NULL)
	    return -1;
    }

    int arabicAddends[20];	// Might be a few bytes too big. I'm ok with that.

    find_arabic_addends(arabicAddends, romanNumeral);

    return compute_arabic_from_addends(arabicAddends, strlen(romanNumeral));
}

int lookup_addend_for(char romanDigit)
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

void find_arabic_addends(int *arabicAddends, char *romanNumeral)
{
    if (arabicAddends == NULL || romanNumeral == NULL) {
	return;
    }

    for (unsigned int ii = 0; ii < strlen(romanNumeral); ii++) {
	arabicAddends[ii] = lookup_addend_for(*(romanNumeral + ii));
    }
}

int compute_arabic_from_addends(int *arabicAddends, int numberOfRomanDigits)
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
