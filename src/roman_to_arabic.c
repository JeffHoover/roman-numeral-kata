#include <stdlib.h>
#include <roman_to_arabic.h>
#include <roman_utils.h>
#include <string.h>

int roman_to_arabic(char * romanNumeral)
{
	int numberOfRomanDigits = strlen(romanNumeral);

	int * arabicAddends = (int *) malloc(numberOfRomanDigits * sizeof(int));
	find_arabic_addends(arabicAddends, romanNumeral);

	int arabicValue = compute_arabic_from_addends(arabicAddends, numberOfRomanDigits);
	free (arabicAddends);
	return arabicValue;
}

