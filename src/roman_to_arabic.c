#include <stdlib.h>
#include <roman_to_arabic.h>
#include <roman_utils.h>
#include <string.h>

int roman_to_arabic(char * romanNumeral)
{
  // TODO - handle error case of null, 0, negative
  int numberOfRomanDigits = strlen(romanNumeral);

  int arabicAddends [20];
  find_arabic_addends(arabicAddends, romanNumeral);

  int arabicValue = compute_arabic_from_addends(arabicAddends, numberOfRomanDigits);

  return arabicValue;
}

