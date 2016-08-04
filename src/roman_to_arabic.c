#include <stdio.h>
#include <string.h>
#include <roman_to_arabic.h>

int roman_to_arabic(char * value)
{
  int arabic = 0;
  for (int ii=0; ii< strlen(value); ii++)
  {
    char current = *(value + ii);
    if (current == 'I')
      {
        arabic++;
      }
    if (current == 'V')
      {
        arabic+=5;
      }
  }
  return arabic;
}

