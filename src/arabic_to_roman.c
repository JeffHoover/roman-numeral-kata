#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arabic_to_roman.h>
void arabic_to_roman (unsigned int arabicValue, char * romanValue)
{
    romanValue[0] = 0;

    int incrementalValue[] = {10, 9, 5, 4 };
    char * romanDigit[] = {"X", "IX", "V", "IV"};

    for (int ii=0; ii< sizeof(incrementalValue)/sizeof(int); ii++)
    {
      if (arabicValue >= incrementalValue[ii])
      {
          strcat(romanValue, romanDigit[ii]);
          arabicValue -= incrementalValue[ii];
      }
    }

    for (int ii=0; ii< arabicValue; ii++)
    {
        strcat(romanValue, "I");
    }
}

