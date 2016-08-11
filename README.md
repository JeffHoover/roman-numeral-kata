#Roman Numeral Calculator Kata  

https://drive.google.com/a/pillartechnology.com/file/d/0Bz26C0WuteyRSG1yY1g2ZTNKVmM/view?usp=sharing  

- Ubuntu Linux 14.04

- The C programming language

- GNU GCC compiler tool chain

- GNU Make

- Check unit testing framework ( https://libcheck.github.io/check/ )

- git

Additionally, I use valgrind http://valgrind.org/ to detect subtle errors with memory management etc.

# Information on Tests:

The file ./tests/test_roman_numbers.c has four test cases in a single test suite "Roman Numeral Unit Tests":
"RomanToArabic"
"ArabicToRoman”
“Addition”
“Subtraction”

Each test case covers all the test data for that operation and writes results to the console.
An example of each type of output is:

convert_roman_to_arabic(I) = 1
convert_arabic_to_roman(1) = I
I + I = II
IV - I = III

Using ansi color escape sequences, passing output is shown in green and failing output is shown in red.

#Usage:

cd src

make


# Most Useful Make Targets:

- all (cleans all binaries, builds implementation and tests, runs tests including valgrind)

- check (runs tests including valgrind)

# Other Make Targets:

- clean (cleans all binaries)

- test (builds tests)

- roman (builds the implementation)


#If I wanted to spend more time, I would address:

- Find and use a tool that can reformat .c files and fix indentation. Currently different files have different indentations.

- Not all functions are probably in the right .c files.

- I may have circular includes. I have used the #ifndef / #define strategy to protect myself from it. But I'd also fix it.

- I'd package the implementation in a library (.a file) and provide a minimal .h file.


 
