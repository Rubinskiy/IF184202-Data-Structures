#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long long total;
// node struct
typedef struct Stackduck_t
{
    long long height;
    long long peak;
} duck;

int main()
{
    long long testcase;
    scanf("%lld", &testcase);

    struct Stackduck_t duck[1000001];

    int temp;

    for (int i = 0; i < testcase; i++)
    {
        scanf("%d", &duck[i].height);
        duck[i].peak = 1;

        if (i > 0)
        {
            temp = i - 1;
            while (duck[i].height >= duck[temp].height && temp >= 0)
            {
                duck[i].peak += duck[temp].peak;
                temp -= duck[temp].peak;
            }
        }
        total += duck[i].peak;
    }
    printf("%lld", total);
    return 0;
}
