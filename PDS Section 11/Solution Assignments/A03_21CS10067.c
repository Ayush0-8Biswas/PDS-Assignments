/*
*  Section 11
*  Roll no : 21CS10067
*  Name : SWADHIN SATYAPRAKASH MAJHI
*  Group no.: 6
*  Assignment no : 03
*  Description : To find the largest,smallest,sum,median of distint five number
*/
#include<stdio.h>
int main()
{
    int a,b,c,d,e;               

    /*scan and print the 5 integer*/
    printf("\nEnter any five integer");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    printf("\nThe five integer are %d,%d,%d,%d,%d",a,b,c,d,e);

    /*condition for not distint or not*/
    if ((a==b)||(a==c)||(a==d)||(a==e)||(b==c)||(b==d)||(b==e)||(c==d)||(c==e)||(d==e))
    printf("\n NOT DISTINCT");

    else
    {
       /*rest of the program */

       int n1,n2,n3,n4,n5 ;   
        /* here n1 is largest 
         *  n2 is second largest
         *  n3 is third largest and median also
         *  n4 is four largest
         *  n5 is smallest*/

        /*for largest*/
        n1=a;
        if(b>n1)
        n1=b;
        if(c>n1)
        n1=c;
        if(d>n1)
        n1=d;
        if(e>n1)
        n1=e;

        /*for second largest*/
        if(a!=n1)
        n2=a;
        if((b!=n1)&&(b>n2))
        n2=b;
        if((c!=n1)&&(c>n2))
        n2=c;
        if((d!=n1)&&(d>n2))
        n2=d;
        if((e!=n1)&&(e>n2))
        n2=e;

        /*for third largest or median*/
        if((a!=n1)&&(a!=n2))
        n3=a;
        if((b!=n1)&&(b!=n2)&&(b>n3))
        n3=b;
        if((c!=n1)&&(c!=n2)&&(c>n3))
        n3=c;
        if((d!=n1)&&(d!=n2)&&(d>n3))
        n3=d;
        if((e!=n1)&&(e!=n2)&&(e>n3))
        n3=e;

        /*for the smallest integer*/
        n5=a;
        if(b<n5)
        n5=b;
        if(c<n5)
        n5=c;
        if(d<n5)
        n5=d;
        if(e<n5)
        n5=e;

        /*for sum of five number*/
        int sum;
        sum=a+b+c+d+e;

        /*execution of remaing program*/

        printf("\nLargest of five number is %d",n1);      /*The largest number*/
        printf("\n Smallest of five number is %d",n5);    /*the smallest number */
        printf("\nSum of five number is %d",sum);         /* the sum */
        printf("\nThe median of five number is %d",n3);   /* the median*/

    }

    
    return 0;
}