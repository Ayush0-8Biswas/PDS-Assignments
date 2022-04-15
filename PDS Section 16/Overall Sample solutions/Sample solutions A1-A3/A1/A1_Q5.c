/*
If a five-digit number is taken as input through the keyboard, write a C program to print the
difference of the sum of the last three digits from the sum of the first two digits of the number.
Also use one single integer variable to generate the reverse of the last three digits and print
that single integer [Hint: Use positional notation for decimal numbers to generate the reverse
number.].
Example:
Input:
97321
Output:
Difference = 10 (sum of (9,7) - sum of (3,2,1))
Reverse number = 123 (as a single integer)
*/

#include <stdio.h>
#include <math.h>

int main()

{
    int Number,n1,n2,n3,n4,n5,Diff; //declaring variables

    printf("Enter the 5 digit number:\n"); //prompt the user to input values
    scanf("%d",&Number); //capture and store input

    //calulations below
    n1=floor(Number/10000);
    Number-=10000*n1;

    n2=floor(Number/1000);
    Number-=1000*n2;

    n3=floor(Number/100);
    Number-=100*n3;

    n4=floor(Number/10);
    Number-=10*n4;

    n5=Number;
    Diff=n1+n2-(n3+n4+n5);

    printf("Difference: %d\n",Diff);
    printf("Reverse Number: %d%d%d",n5,n4,n3);

    return 0;
}
