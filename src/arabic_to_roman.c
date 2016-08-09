#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arabic_to_roman.h>

char * arabic_to_roman(unsigned int arabicValue)
{
    // TODO - Malloc size is going to end up way too large.
    char * romanValue = (char *) malloc(arabicValue + 1);
    romanValue[0] = 0;
    if (arabicValue >= 4)
    {
        strcat(romanValue, "IV");
        arabicValue -= 4;
    }
    for (int ii=0; ii< arabicValue; ii++)
    {
        strcat(romanValue, "I");
    }
    return romanValue;
}

