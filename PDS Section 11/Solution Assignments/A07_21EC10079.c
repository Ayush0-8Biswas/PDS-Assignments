/* Section - 11
 * Roll No.: 21EC10079
 * Name: Teerath Agarwal
 * Group No.: 8
 * Assignment No.: 7
 * Description: This program reads integers and find out all the pairs whose sum of odd valued digits have a difference between 5 and 20 but it is not divisible by 3.
*/

#include <stdio.h>

int main()
{
    /* Declaring the variables used */
    int n,a[20],b[20],temp1,temp2,temp3,temp4=0;

    /* Taking input data from the user */
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("n = %d\n", n);
    printf("Enter the numbers: ");
    for (int i=0; i<n; i++)
    scanf("%d",&a[i]);

    /* Printing numbers entered and calculating the sum of odd digits for each of them */
    printf("The numbers entered are: ");
    for (int i=0; i<n; i++)
    {
        temp1 = a[i];
        b[i] = 0;
        if (i<n-1) printf("%d, ", a[i]); else printf("%d\n\n", a[i]);
        
        while(temp1>0)
        {
            temp2 = temp1 % 10;
            if ((temp2 % 2) == 1) b[i] += temp2;
            temp1 /= 10;
        }
    }

    /* Printing the sum of odd digits for each number */
    printf("Sum of odd digits of each number:\n");
    for (int i=0; i<n; i++)
    {
        printf("%d -> %d\n",a[i],b[i]);
    }

    /* Finding and printing the required pairs of numbers */
    printf("\nRequired pairs of numbers:\n");
    for (int i=0; i<n; i++)
    {
        for (int j=i; j<n; j++)
        {
            temp3 = b[i] - b[j];
            if (temp3 < 0) temp3 *= (-1);
            if (temp3>=5 && temp3<=20 && ((temp3 % 3) != 0)) 
            {
                printf("(%d, %d)\n",a[i],a[j]);
                temp4++;
            }
        }
    }
    if (temp4 == 0) printf("No Such Pair!\n");

    return 0;
}