#ifndef MSG_ASSERTS_H
#define MSG_ASSERTS_H

void check_result(unsigned int input, char * expected, char * actual, char * funcName);
void check_result_i(char * input, unsigned int expected, unsigned int actual, char * funcName);
void check_subtraction_result(char * minuend, char * subtrahend, char * expected, char * actual);
void check_addition_result(char * leftAddend, char * rightAddend, char * expectedSum, char * sumResult);
#endif /* MSG_ASSERTS_H */
