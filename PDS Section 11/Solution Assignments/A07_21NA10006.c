/*
Section 11
Roll No- 21NA10006
Name-Akshita Bajaj
Group No. 5
Assignment No.07
Description - Non Duplicate Pairs
*/
#include<stdio.h>
int main()
{
    int n,i,d,j,t=0;
    printf("Enter the number \n");
    scanf("%d",&n);
    printf("The number is %d\n",n);
    int a[n],a1[n],b[n];
    printf("Enter the elements of the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The elements are\n");
    for(i=0;i<n;i++)
    {
        a1[i]=a[i];/*array for calculation of sum of digits*/
        printf("%d,",a[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        int s=0;
        while(a1[i]>0)
        {
            d=a1[i]%10;
            if(d%2!=0)
            {
               s=s+d;/*Sum of odd digits*/
            }
            a1[i]=a1[i]/10;
        }
        b[i]=s;
    }
    printf("The array element and the sum of its odd digits are\n");
    for(i=0;i<n;i++)
    {
        printf("%d,%d \n",a[i],b[i]);
    }
    printf("The non duplicate pairs are\n");
    for(i=0;i<n;i++)
    {
        int p=0;
        for(j=0;j<n;j++)
        {
            p=b[j]-b[i];/*difference of odd digits of two numbers*/
            if(p>=5 && p<=20 && p%3!=0)/*checking conditions*/
            {
                printf("(%d,%d)\n",a[j],a[i]);
            }
            else
            {
                t=t+1;
            }
        }
    }
    if(t==n*n)
    {
        printf("No such pairs\n");
    }
    return 0;
}
