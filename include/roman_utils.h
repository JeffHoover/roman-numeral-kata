#ifndef ROMAN_UTILS_H
#define ROMAN_UTILS_H

int get_value_for(char roman);
void find_arabic_addends(int * arabicAddends, char *romanNumeral);
int compute_arabic_from_addends(int * arabicAddends, int numberOfRomanDigits);

#endif /* ROMAN_UTILS_H */
