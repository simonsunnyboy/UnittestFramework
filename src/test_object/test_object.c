/**
 * @file   test_object.c
 *
 * ASM Software Unittest Framework
 * (c) 2016 by Matthias Arndt <marndt@asmsoftware.de>
 *
 * The MIT License applies. Check COPYING for details.
 *
 * @brief  test implementation of using the framework
 */

#include <stdint.h>

#include "unittest.h"

/**
 * @brief test function computing the maximum of 2 numbers
 * @param a
 * @param b
 * @return a if a > b otherwise b
 */
int16_t Max(const int16_t a, const int16_t b)
{
    if(a > b)
    {
        return a;
    }

    return b;
}

/**
 * @brief main function for Unittest example
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv)
{
    int16_t a,b;

    UT_BEGIN("Example for ASM Software Unittest Framework");

    UT_TESTCASE("Hand picked examples");
    UT_DESCRIPTION("Some arbitrary value pairs are tested.");

    UT_PRECONDITION(a = 1);
    UT_PRECONDITION(b = 2);

    UT_COMMENT("b > a");
    UT_TEST(Max(a,b) == 2);

    UT_PRECONDITION(a = 100);
    UT_PRECONDITION(b = 20);
    UT_COMMENT("a > b");
    UT_TEST(Max(a,b) == 100);

    UT_END();

    return UT_Result;
}
