#include <stdio.h>
#include <string.h>
#include <roman_to_arabic.h>

int roman_to_arabic(char * value)
{
  int arabic = 0;
  for (int ii=0; ii< strlen(value); ii++)
  {
    if (*(value + ii) == 'I')
      {
        arabic++;
      }
  }
  return arabic;
}

