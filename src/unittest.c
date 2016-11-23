/**
 * @file   unittest.c
 *
 * ASM Software Unittest Framework
 * (c) 2016 by Matthias Arndt <marndt@asmsoftware.de>
 *
 * The MIT License applies. Check COPYING for details.
 *
 * @brief   framework implementation
 * @details The functions are meant to be called through the associated macros.
 */

/**
 * @addtogroup ASMSoftware_Unittest
 * @{
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*-----------------------------------------------
 * internal variables
 *-----------------------------------------------
 */

/**
 * @brief internal unittest state
 */
typedef struct
{
    int16_t test_nr;   /*!< number of testcases for testcase headlines */
    int16_t passed;    /*!< number of passed tests */
    int16_t failed;    /*!< number of failed tests */
    char comment[512]; /*!< temporary storage for testcase comment */
} Unittest;

static Unittest UT;  /*!< tracks the internal unittest state */

static time_t rawtime;        /*!< internal variable to create time stamps */
static struct tm * timeinfo;  /*!< decoding information for timestamp */

/*-----------------------------------------------
 * public variables
 *-----------------------------------------------
 */

int UT_Result = 0;


void UT_Begin(const char *headline, const char *filename)
{
    UT.passed = 0;
    UT.failed = 0;
    UT.test_nr = 1;

    /* get current date and time */
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    /* print header */
    printf("----  Unittest  -----------------------------------------------\n");
    printf("FILE: %s\n", filename);
    printf("DATE: %s", asctime(timeinfo));
    printf("---------------------------------------------------------------\n");
    printf("%s\n", headline);
    printf("---------------------------------------------------------------\n");
    printf("\n");
}


void UT_End(void)
{
    /* compute success rate: */
    float rate = 100.0f;

    if(UT.failed > 0)
    {
        const float sum_tests = (float)UT.passed + (float)UT.failed;
        rate = ((float)UT.passed / sum_tests) * 100.0f;
    }

    /* print footer */
    printf("---------------------------------------------------------------\n");
    printf("Passed tests ....: %d\n", UT.passed);
    printf("Failed tests ....: %d\n", UT.failed);
    printf("Success rate ....: %3.2f%%\n", rate);
    printf("---------------------------------------------------------------\n");
    if(UT.failed != 0)
    {
        printf("Test result NOT OK!\n");
        UT_Result = UT.failed;
    }
    else
    {
        printf("Test result OK!\n");
    }
    return;
}


void UT_Testcase(const char *headline)
{
    printf("== %d. %s\n\n", UT.test_nr, headline);
    UT.test_nr++;
    return;
}

void UT_Description(const char *desc)
{
    printf("%s\n\n", desc);
    return;
}

void UT_Precondition(const char *cond_desc)
{
    printf("PRECONDITION: %s\n", cond_desc);
    return;
}

void UT_Test(const bool test_cond, const char *cond_desc)
{     
    printf("TEST: %s   ", cond_desc);



    if(test_cond == true)
    {
        UT.passed++;
        printf("passed\n");
    }
    else
    {
        UT.failed++;
        printf("failed\n");
    }

    if(strlen(UT.comment) > 0)
    {
        printf("\"%s\"\n\n", UT.comment);
        memset(UT.comment, '\0',sizeof(UT.comment) ); // empty comment after processing
    }

    printf("\n");

    return;
}

void UT_SetComment(const char *comment)
{
    #define MIN(x, y) (((x) < (y)) ? (x) : (y))

    const size_t len_comment = MIN(sizeof(UT.comment), strlen(comment));

    memset(UT.comment, '\0',sizeof(UT.comment) ); // empty comment
    strncpy(UT.comment, comment, len_comment);  // copy string

    return;
}

/** @} */
