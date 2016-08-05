#include <roman_utils.h>
#include <string.h>

int lookup_addend_for(char romanDigit)
{
	switch(romanDigit) {
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
			return 0;
	}
}

void find_arabic_addends(int * arabicAddends, char *romanNumeral)
{
	for (int ii=0; ii< strlen(romanNumeral); ii++)
	{
		arabicAddends[ii] = lookup_addend_for(*(romanNumeral + ii));
	}
}

int compute_arabic_from_addends(int * arabicAddends, int numberOfRomanDigits)
{
	if (numberOfRomanDigits < 1)
	{
		return 0;
	}

	int arabicValue = arabicAddends[numberOfRomanDigits-1];
	for (int ii=0; ii< numberOfRomanDigits-1; ii++)
	{
		if (arabicAddends[ii] < arabicAddends[ii+1])
		{
			arabicValue -= arabicAddends[ii];
		}
		else
		{
			arabicValue += arabicAddends[ii];
		}
	}
	return arabicValue;
}
