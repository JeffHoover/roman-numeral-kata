#include <roman_utils.h>
#include <arabic_to_roman.h>
#include <roman_to_arabic.h>
#include <string.h>
#include<stdio.h>

void add (char * leftAddend, char * rightAddend, char * sum)
{
// TODO - inline these?
    int leftArabic = roman_to_arabic(leftAddend);
    int rightArabic = roman_to_arabic(rightAddend);

    arabic_to_roman (leftArabic + rightArabic, sum);
}


void subtract (char * minuend, char * subtrahend, char * differenceResult)
{
// TODO - inline these?
    int minuendArabic = roman_to_arabic(minuend);
    int subtrahendArabic = roman_to_arabic(subtrahend);

    arabic_to_roman (minuendArabic - subtrahendArabic, differenceResult);
}


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
   for (unsigned int ii=0; ii< strlen(romanNumeral); ii++)
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
