#ifndef MSG_ASSERTS_H
#define MSG_ASSERTS_H
void check_arabic_to_roman(unsigned int input, char * expected, char * actual);
void check_roman_to_arabic(char * input, unsigned int expected, unsigned int actual);
void check_subtraction_result(char * minuend, char * subtrahend, char * expected, char * actual);
void check_addition_result(char * leftAddend, char * rightAddend, char * expectedSum, char * sumResult);
void check_NULL_roman_input(int arabicValue);
void check_empty_roman_input(int arabicValue);
void check_bad_value(int arabicValue, char * badValue);
#endif /* MSG_ASSERTS_H */
