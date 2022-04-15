/*
*Section 11
*Roll No-21MI10036
*Name-Nimisha Gupta
*Group 5
*Assignment No-5
*Description-to evaluate the sum of the series
*/
#include<stdio.h>
main()
{   float x,sum=0.0,term=1.0,t=1.0;
    int n,i;
    /*reading values of x and n*/
    printf("Enter a floating point value of x and integer n\n");
    scanf("%f",&x);scanf("%d",&n);
    while(x<=0||x>1||n<=0)
    { printf("Invalid input\n");
      printf("Enter a floating point value of x and integer n\n");
       scanf("%f",&x);scanf("%d",&n);
    }
    printf("Value of x=%f and n=%d\n",x,n);
    /*calculating the series*/
    for(i=1;i<=n;i++)
    { printf("Interim sum=%f and interim term =%f\n",sum,term);
      sum+=term;
      t*=-(x/i);
      term=(i+1)*t;
    }
    printf("Final value of sum=%f\n",sum);
}
