
/*
*   Section 11
*   Roll NO         : 21CS10047
*   Name            : Omair Alam
*   Group No        : 4
*   Assignment No   : 06
*   Description     : 3 digit numbers, prime numbers, and largest of them
*/
#include <stdio.h>

main()
{
    int given;
    printf("Give a number of 3 digits at least(ie greater than 100)\n");
    scanf("\n%d",&given);
    printf("\n");
    int num=given;
    printf("%d\n",given);
    int term;
    int prime;
    int lprime=0;//largest prime
    int i;
    while (num>99)
    {
        term=num%1000;
        prime=1;
        printf("%d, ",term);
        for (i=2;i<=term/2;++i)
        {
            if (term%i==0) prime=0;
        }
        if (prime==1)
        {
            if(term>lprime) lprime=term;
        }

        num=num/10;
    }
    if (lprime==0) printf("\nNo prime numbers");
    else printf("\nLargest prime=%d", lprime);
}
