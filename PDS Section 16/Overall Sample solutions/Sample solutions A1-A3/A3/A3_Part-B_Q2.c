/*Consider the following series of numbers, 4,8,14,22,32 . . . . This series follows a specific pattern.
Find out the pattern. Hence take a number ‘k’ as input and print the first k terms of the series
according to the rules of the pattern. Also take another integer ‘n’ as input and print the
difference between the (n+1)’th term and the n’th term of the series*/

#include<stdio.h>

int main()
{
    //taking k as input
    int k;
    printf("enter the value of k:");
    scanf("%d",&k);

    /*IMPORTANT OBSERVATION:IF WE LOOK AT THE DIFFERENCE BETWEEN THE SUCCESIVE TERMS,THE DIFFERENCES ARE IN AP.
    SINCE IN AN A.P. THE GENERAL TERM IS A LINEAR EXPRESSION IN N,THE GENERAL TERM IN THIS SERIES WILL BE OF THE FORM:
    A*N^2 +B*N+C.AFTER CALCULATING THE VALUE OF A,B AND C, THE GENERAL TERM(NTH TERM IS)=(N^2 +N +2) */

    //printing the first k terms as input
    for (int i=1;i<=k;i++)
    {
        int j=(i*i+i+2);
        printf("%d \n",j);
    }

    //taking n as input
    int n;
    printf("enter the value of n as input:");
    scanf("%d",&n);

    //to find the difference between the nth and (n+1)th term of the series
    int ta=n*n+n+2;
    int tb=(n+1)*(n+1)+(n+1)+2;
    int dif=tb-ta;
    printf("the difference between the %dth and %dth term is:%d",n,(n+1),dif);

}
