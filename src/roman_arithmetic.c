#include "roman_arithmetic.h"
#include "arabic_to_roman.h"
#include "roman_to_arabic.h"

void add(const char *leftAddend, const char *rightAddend, char *sum)
{
    // Originally, I didn't inline the roman_to_arabic calls below. I think I like this better.
    // (Same in subtract function below.)
    arabic_to_roman(roman_to_arabic(leftAddend) + roman_to_arabic(rightAddend),
		    sum);
}

void subtract(const char *minuend, const char *subtrahend,
	      char *differenceResult)
{
    arabic_to_roman(roman_to_arabic(minuend) - roman_to_arabic(subtrahend),
		    differenceResult);
}
