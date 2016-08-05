#include <stdlib.h>
#include <roman_to_arabic.h>
#include <roman_utils.h>

int roman_to_arabic(char * romanNumeral)
{
	int romanLen = strlen(romanNumeral);
	int * arabicAddends = (int *) malloc(romanLen * sizeof(int));
	load_values(arabicAddends, romanNumeral);
	int arabic = compute_arabic_from_values(arabicAddends, romanLen);
	free (arabicAddends);
	return arabic;
}

