#include <roman_utils.h>
#include <string.h>

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
