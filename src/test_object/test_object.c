/**
 * @file   test_object.c
 *
 * ASM Software Unittest Framework
 * (c) 2016 by Matthias Arndt <marndt@asmsoftware.de>
 *
 * The MIT License applies. Check COPYING for details.
 *
 * @brief  example test object implementation
 */

/**
 * @addtogroup Example_Unittest
 * @{
 */

#include <stdint.h>

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

/** @} */
