/*
Section: 11
Roll No: 21EE30033
Name: Vidunram A R
Group: 4
Test no: 1
Problem no: 1
Description: Print the smallest number grater than input number with distinct digits and >4 factors, along with its factors and digits which it does not contain
*/

#include <stdio.h>

int main()
{
    int n, m, p, facts, check, factors[10000], b[10];
    printf("Enter n: ");
    scanf("%d",&n);
    /*b contains digits of m*/
    m = n+1;
    facts = 0; check = 1;
    while (facts < 4 || check == 0)
    {

        facts = 0;
        check = 1;
        p = m;
        for (int i=0; i<10; i++) b[i] = -1;
        while (p>0)
        {
            for (int i=0; i<10; i++)
            {
                if (b[i] == p%10)
                {
                    check = 0;
                    break;
                }
                else if (b[i] == -1)
                {
                    b[i] = p%10;
                    break;
                }


            }


            if (check == 0) break;
            p /= 10;
        }

        for (int i=2; i<=m/2 ;i++)
        {
            if (m%i==0)
            {
                factors[facts] = i;
                facts += 1;
            }
        }

        if (facts>=4 && check!=0) break;
        m++;

    }
    /*Printing number m*/
    printf("\nSmallest number satisfying conditions: %d\n",m);
    /*Printing factors of */
    printf("Prime factors: ");
    for (int i=0; i<facts; i++) printf("%d ",factors[i]);
    printf("\n");
    /*Printing digits of m*/
    printf("Digits not present: ");
    p = 0;
    for (int i=0; i<10; i++)
    {
        check = 0;
        for (int j=0; j<10; j++)
        {
            if (b[j] == i)
            {
                check=1;
                break;
            }
        }
        if (check==0)
        {
            printf("%d ", i);
            p=1;
        }
    }
    if (p==0) printf("All digits present\n");

    return 0;
}
