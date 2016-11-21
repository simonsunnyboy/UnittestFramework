/**
 * @file   unittest.h
 *
 * ASM Software Unittest Framework
 * (c) 2016 by Matthias Arndt <marndt@asmsoftware.de>
 *
 * The MIT License applies. Check COPYING for details.
 *
 * @brief  test implementation of using the framework
 */

#ifndef UNITTEST_H
    #define UNITTEST_H

    #include <stdint.h>
    #include <stdbool.h>

    /**
     * @brief return code to be used by the caller, 0 for success, number of failed test otherwise
     */
    extern int UT_Result;

    /*-----------------------------------------------
     * macros for use by the user
     *-----------------------------------------------
     */

    #define UT_BEGIN(headline)   UT_Begin(headline, __FILE__)    /*!< start of unittest output */
    #define UT_END()             UT_End()                        /*!< end of unittest output */

    #define UT_TESTCASE(headline) UT_Testcase(headline)          /*!< start of test case */
    #define UT_DESCRIPTION(text)  UT_Description(text)           /*! description for testcase */

    #define UT_PRECONDITION(cond) cond; UT_Precondition(#cond)  /*!< set precondition for test case */
    #define UT_TEST(cond)         UT_Test((cond), #cond)        /*!< test and document condition */

    #define UT_COMMENT(comment)   UT_SetComment(comment)         /*!< annotate test or precondition with commentary */

    /*-----------------------------------------------
     * internal definitions
     *-----------------------------------------------
     */

    void UT_Begin(const char *headline, const char *filename);
    void UT_End(void);
    void UT_Testcase(const char *headline);
    void UT_Description(const char *desc);
    void UT_Precondition(const char *cond_desc);
    void UT_Test(const bool test_cond, const char *cond_desc);
    void UT_SetComment(const char *comment);

#endif
