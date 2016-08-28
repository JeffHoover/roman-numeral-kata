#ifndef MSG_ASSERTS_H
#define MSG_ASSERTS_H
void check_arabic_to_roman(const unsigned int input, const char * expected, const char * actual);
void check_roman_to_arabic(const char * input, const unsigned int expected, const unsigned int actual);
void check_subtraction_result(const char * minuend, const char * subtrahend, const char * expected, const char * actual);
void check_addition_result(const char * leftAddend, const char * rightAddend, const char * expectedSum, const char * sumResult);
void check_NULL_roman_input(const int arabicValue);
void check_empty_roman_input(const int arabicValue);
void check_bad_value(const int arabicValue, const char * badValue);

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#endif /* MSG_ASSERTS_H */
