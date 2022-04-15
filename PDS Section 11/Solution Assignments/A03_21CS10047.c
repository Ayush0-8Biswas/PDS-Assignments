/*
*   Section 11
*   Roll NO         : 21CS10047
*   Name            : Omair Alam
*   Group No        : 4
*   Assignment No   : 03
*   Description     : Check if distinct and operate on them if not
*/


#include <stdio.h>

/*take 5 int input as
d1 d2 d3 d4 d5
print all
check if distinct
if not distinct, print so and end
if distinc, largest smallest sum median*/

main(){
    int d1,d2,d3,d4,d5,temp;
    printf("Enter your data\n");
    scanf("%d%d%d%d%d",&d1,&d2,&d3,&d4,&d5);
    printf("\n%d %d %d %d %d",d1,d2,d3,d4,d5);
    if (d1==d2 || d1==d3 || d1==d4 || d1==d5 ||
        d2==d3 || d2==d4 || d2==d5 ||
        d3==d4 || d3==d5 ||
        d4==d5)printf("\nNot distinct\n");

    else{
        if (d5<d4) temp=d4, d4=d5, d5=temp;
        if (d4<d3) temp=d3, d3=d4, d4=temp;
        if (d3<d2) temp=d2, d2=d3, d3=temp;
        if (d2<d1) temp=d1, d1=d2, d2=temp;

        if (d5<d4) temp=d4, d4=d5, d5=temp;
        if (d4<d3) temp=d3, d3=d4, d4=temp;
        if (d3<d2) temp=d2, d2=d3, d3=temp;

        if (d5<d4) temp=d4, d4=d5, d5=temp;
        if (d4<d3) temp=d3, d3=d4, d4=temp;

        if (d5<d4) temp=d4, d4=d5, d5=temp;

        printf("\nLargest:%d\n",d5);
        printf("Smallest:%d\n", d1);
        printf("Sum:%d\n", d1+d2+d3+d4+d5);
        printf("Median:%d\n", d3);

    }
}

/*test cases
7 9 23 1 5
3 7 19 -1 8
4 1 9 11 9
-2 8 0 -1 -9
*/
