#Roman Numeral Calculator Kata  

https://drive.google.com/a/pillartechnology.com/file/d/0Bz26C0WuteyRSG1yY1g2ZTNKVmM/view?usp=sharing  

- Ubuntu Linux 14.04

- The C programming language

- GNU GCC compiler tool chain

- GNU Make

- Check unit testing framework ( https://libcheck.github.io/check/ )

- git


NOTE: check_roman.c has one test case that loops through values and expected results.
I find this readable, but it has the downside of not showing the number of data points tested:

    Running suite(s): Conversion to Roman Number Unit Tests
    100%: Checks: 1, Failures: 0, Errors: 0

As a compromise, I am printf()ing the value and expectation of each data point as it they are tested:
   convert(1) should be I


To build:  
  cd src  
  make  

To build and run tests:  
  cd src  
  make run-test  

To run tests:  
  cd src  
  ./test  
  
To run app:  
  cd src  
  roman  
  
├── include  
│   └── roman.h  
├── lib  
│   └──  
├── README.md  
├── src  
│   ├── makefile  
│   ├── obj  
│   │   └──  
│   ├── roman.c  
│   ├── romanfunc.c  
└── tests  
    ├── check_roman.c  
    └── obj  
        └──  


To build and run tests, including valgrind:

  cd src  
  make  

