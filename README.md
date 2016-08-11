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


#Directory Structure:

.
├── include
│   ├── arabic_to_roman.h
│   ├── roman_to_arabic.h
│   └── roman_utils.h
├── lib
├── README.md
├── src
│   ├── arabic_to_roman.c
│   ├── arabic_to_roman.o
│   ├── makefile
│   ├── obj
│   │   ├── arabic_to_roman.o
│   │   ├── roman.o
│   │   ├── roman_to_arabic.o
│   │   └── roman_utils.o
│   ├── roman
│   ├── roman.c
│   ├── roman_to_arabic.c
│   ├── roman_to_arabic.o
│   ├── roman_utils.c
│   ├── roman_utils.o
│   └── test
└── tests
    ├── obj
    │   └── test_roman_numbers.o
    └── test_roman_numbers.c

