#include <stdlib.h>
#include <roman_to_arabic.h>
#include <roman_utils.h>

int roman_to_arabic(char * roman)
{
  int romanLen = strlen(roman);
  int * values = (int *) malloc(romanLen * sizeof(int));
  load_values(values, roman);
  int arabic = compute_arabic_from_values(values, romanLen);
  free (values);
  return arabic;
}

