#ifndef ROMAN_UTILS_H
#define ROMAN_UTILS_H

int get_value_for(char roman);
void load_values(int * values, char *roman);
int compute_arabic_from_values(int * values, int romanLen);
#endif /* ROMAN_UTILS_H */
