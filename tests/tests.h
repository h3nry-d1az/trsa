#ifndef __TRSA_TESTS__
#define __TRSA_TESTS__

#include <stdio.h>

#define WHITE "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

int assert_test(int n, char s[], int c)
{
    if (c)
    {
        printf("%sTest %d (%s): PASSED.%s\n", GREEN, n, s, WHITE);
        return 1;
    }
    else
    {
        printf("%sTest %d (%s): FAILED.%s\n", RED, n, s, WHITE);
        return 0;
    }
}

#endif // ! __TRSA_TESTS__