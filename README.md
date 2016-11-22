# ASM Software Unittest Framework

(c) 2016 by Matthias Arndt <marndt@asmsoftware.de>

The MIT License applies to this project. Please refer to the file COPYING
for details.

## Abstract

This is a small framework to implement unittests for software written in C.
There are existing projects that offer much more functionality, this one
focuses on simple usability and textual output of statistics.

Main reason to implement this framework was that cunit was too complicated
in usage and no other small free frameworks could be found.

## System requirements

- Cmake to build the example project
- a C99 compliant C compiler but a C90 one will do if stdint.h and stdbool.h
  are supplied
- any operating system of your choice

## Using the test framework

A test should be a subfunction or the main function of an appropriate test
executable.

Use the macros defined in unittest.h and link your project with unittest.c

Wrap the Test with UT_BEGIN and UT_END macros for proper structuring.
Most commands should describe themselves.

It is allowed to start another test for entirely different content with the
UT_BEGIN macro if the last test finished with the UT_END macro.

## The MIT License (MIT)

Copyright (c) 2016 Matthias Arndt <marndt@asmsoftware.de>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
