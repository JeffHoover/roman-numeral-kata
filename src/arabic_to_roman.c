#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arabic_to_roman.h>


// TODO - Could I pass arabicValue as an int and return it?
void compute_roman_digit(unsigned int *arabicValue, unsigned int incrementalValue, char * romanDigit, char * romanValue);
void compute_roman_digit(unsigned int *arabicValue, unsigned int incrementalValue, char * romanDigit, char * romanValue)
{
    if (*arabicValue >= incrementalValue)
    {
        strcat(romanValue, romanDigit);
        *arabicValue -= incrementalValue;
        compute_roman_digit(arabicValue, incrementalValue, romanDigit, romanValue);
    }
}

unsigned int incrementalValue[] = {40, 10, 9, 5, 4 };
char * romanDigit[] = {"XL", "X", "IX", "V", "IV"};

void arabic_to_roman (unsigned int arabicValue, char * romanResult)
{
    romanResult[0] = 0;

    for (int ii=0; ii< sizeof(incrementalValue)/sizeof(int); ii++)
    {
      compute_roman_digit(&arabicValue, incrementalValue[ii], romanDigit[ii], romanResult);
    }

    for (unsigned int ii=0; ii< arabicValue; ii++)
    {
        strcat(romanResult, "I");
    }
}

