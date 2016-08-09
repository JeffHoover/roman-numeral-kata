#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arabic_to_roman.h>


// TODO - Could I pass arabicValue as an int and return it?
// TODO - What's a better name than 'process'
void process(unsigned int *arabicValue, unsigned int incrementalValue, char * romanDigit, char * romanValue);
void process(unsigned int *arabicValue, unsigned int incrementalValue, char * romanDigit, char * romanValue)
{
    if (*arabicValue >= incrementalValue)
    {
        strcat(romanValue, romanDigit);
        *arabicValue -= incrementalValue;
        process(arabicValue, incrementalValue, romanDigit, romanValue);
    }
}

unsigned int incrementalValue[] = {10, 9, 5, 4 };
char * romanDigit[] = {"X", "IX", "V", "IV"};

void arabic_to_roman (unsigned int arabicValue, char * romanValue)
{
    romanValue[0] = 0;

    for (int ii=0; ii< sizeof(incrementalValue)/sizeof(int); ii++)
    {
      process (&arabicValue, incrementalValue[ii], romanDigit[ii], romanValue);
    }

    for (unsigned int ii=0; ii< arabicValue; ii++)
    {
        strcat(romanValue, "I");
    }
}

