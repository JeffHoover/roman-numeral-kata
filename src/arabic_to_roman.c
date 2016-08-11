#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arabic_to_roman.h>

unsigned int incrementalValue[] = {1000, 900, 400, 100, 90, 50, 40, 10, 9, 5, 4 };
char * romanDigit[] = {"M","CM", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV"};

void arabic_to_roman (unsigned int arabicValue, char * romanResult)
{
  // TODO - handle error case of null, 0, negative
    romanResult[0] = 0;

    for (unsigned int ii=0; ii< sizeof(incrementalValue)/sizeof(int); ii++)
    {
      compute_roman_digit(&arabicValue, incrementalValue[ii], romanDigit[ii], romanResult);
    }

// TODO - extract out to appendZeroToThreeTrailingIs(...)?
    for (unsigned int ii=0; ii< arabicValue; ii++)
    {
        strcat(romanResult, "I");
    }
}

// TODO - extract to roman_utils.c?
void compute_roman_digit(unsigned int *arabicValue, unsigned int incrementalValue, char * romanDigit, char * romanValue)
{
    if (*arabicValue >= incrementalValue)
    {
        strcat(romanValue, romanDigit);
        *arabicValue -= incrementalValue;
        compute_roman_digit(arabicValue, incrementalValue, romanDigit, romanValue);
    }
}

