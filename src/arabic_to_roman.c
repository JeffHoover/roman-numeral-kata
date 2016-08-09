#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arabic_to_roman.h>

char * arabic_to_roman(unsigned int arabicValue)
{
    char * romanValue = (char *) malloc(arabicValue + 1);
    for (int ii=0; ii< arabicValue; ii++)
    {
        romanValue[ii] = 'I';
    }
    romanValue[arabicValue] = 0;
    return romanValue;
}

