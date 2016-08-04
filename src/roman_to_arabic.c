#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <roman_to_arabic.h>

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

void load_values(int * values, char *roman);
void load_values(int * values, char *roman)
{
  for (int ii=0; ii< strlen(roman); ii++)
  {
    int currentVal = 0;
    char current = *(roman + ii);
    if (current == 'I')
      {
        currentVal = 1;
      }
    else if (current == 'V')
      {
        currentVal = 5;
      }
    else if (current == 'X')
      {
        currentVal = 10;
      }
    values[ii] = currentVal;
  }
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

