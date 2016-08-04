#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <roman_to_arabic.h>

int get_value_for(char roman);
int get_value_for(char roman)
{
  if (roman == 'I')
    {
      return 1;
    }
  else if (roman == 'V')
    {
      return 5;
    }
  else if (roman == 'X')
    {
      return 10;
    }
  else if (roman == 'L')
    {
      return 50;
    }
  else if (roman == 'C')
    {
      return 100;
    }
  return 0;
}

void load_values(int * values, char *roman);
void load_values(int * values, char *roman)
{
  for (int ii=0; ii< strlen(roman); ii++)
  {
    int currentVal = 0;
    values[ii] = get_value_for(*(roman + ii));
  }
}

int compute_arabic_from_values(int * values, int romanLen);
int compute_arabic_from_values(int * values, int romanLen)
{
  if (romanLen < 1)
     return 0;

  int arabic = values[romanLen-1];
  for (int ii=0; ii< romanLen-1; ii++)
  {
     if (values[ii] < values[ii+1])
     {
         arabic -= values[ii];
     }
     else
     {
         arabic += values[ii];
     }
  }
  return arabic;
}

int roman_to_arabic(char * roman)
{
  int romanLen = strlen(roman);
  int * values = (int *) malloc(romanLen * sizeof(int));
  load_values(values, roman);
  int arabic = compute_arabic_from_values(values, romanLen);
  free (values);
  return arabic;
}

