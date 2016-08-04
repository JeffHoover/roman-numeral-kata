#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <roman_to_arabic.h>

void *malloc(size_t size);

int compute_arabic_from_values(int * values, int romanLen);
int compute_arabic_from_values(int * values, int romanLen)
{
  int arabic = 0;
  for (int ii=0; ii< romanLen; ii++)
  {
     arabic += values[ii];
  }
  return arabic;
}

void load_values(int * values, char *roman);
void load_values(int * values, char *roman)
{
  for (int ii=0; ii< strlen(roman); ii++)
  {
    char current = *(roman + ii);
    if (current == 'I')
      {
        values[ii]= 1;
      }
    if (current == 'V')
      {
        values[ii]= 5;
      }
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

