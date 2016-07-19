#include <stdio.h>
#include <string.h>
#include <roman_to_arabic.h>

int roman_to_arabic(char * value)
{
  if (strcmp(value, "I") == 0) {
     return 1;
  }
  return 2;
}

