/*
* Section 11
* Roll No : 21EC10019
* Name : Deepak Nanda
* Group No.: 6
* Assignment No : 06
* Description :Breaking into 3 digit and checking prime
*/
#include<stdio.h>
#include<math.h>
int main()
{

    int n,t,p,i,a=0;
    printf("Enter an integer greater than 100: \n");               //Entering Value
    scanf("%d",&n);
    printf("Entered no.:<%d> \n",n);
    while (n>=100){
        t=n%1000;
        printf("%d ,",t);
        n=n/10;
        p=0;
        for(i=2;i<t;i++){
            if(t%i==0){                                           //Checking for prime
                p=1;
            }
        }
        if(p==0){                                                 //Comparing
            if(a<t){
                a=t;
            }
        }
    }
    if(a>0){
        printf("\nLargest prime is %d",a);
    }
    if(a==0){                                                      //Printing the value
        printf("\nNone is prime");
    }
    return 0;
}










