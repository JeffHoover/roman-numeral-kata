#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arabic_to_roman.h>
void arabic_to_roman (unsigned int arabicValue, char * romanValue)
{
    romanValue[0] = 0;

    if (arabicValue >= 5)
    {
        strcat(romanValue, "V");
        arabicValue -= 5;
    }

    if (arabicValue >= 4)
    {
        strcat(romanValue, "IV");
        arabicValue -= 4;
    }
    for (int ii=0; ii< arabicValue; ii++)
    {
        strcat(romanValue, "I");
    }
}

