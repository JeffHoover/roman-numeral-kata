#include <roman_utils.h>
#include <string.h>

int get_value_for(char roman)
{
  switch(roman) {
    case 'I':
       return 1;
    case 'V':
       return 5;
    case 'X':
       return 10;
    case 'L':
       return 50;
    case 'C':
       return 100;
    case 'D':
       return 500;
    case 'M':
       return 1000;
    default:
       return 0;
    }
}

void load_values(int * values, char *roman)
{
  for (int ii=0; ii< strlen(roman); ii++)
  {
    int currentVal = 0;
    values[ii] = get_value_for(*(roman + ii));
  }
}

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
