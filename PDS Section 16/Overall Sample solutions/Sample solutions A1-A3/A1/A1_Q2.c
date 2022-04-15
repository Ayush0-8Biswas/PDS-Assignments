/*
The office in which you are working has decided to contribute a part of your salary towards a
special fund contribution. Your contribution is calculated as the addition of 10% of your basic
pay and 5% of your Dearness Allowance (DA). Write a program to take input two integers as
your basic pay and as your DA and display the fund contribution.
Example:
Input: Basic Pay: 1000
DA : 200
Output: Fund contribution: 110 (10% of 1000 + 5% of 200)
*/

#include<stdio.h>
int main()
{
    float basic,da,c; //declaring variables here
    
    printf("basic pay: "); //prompt user to input value
    scanf("%f",&basic);//taking input for basic salary
    
    printf("DA: "); //prompt user to input value
    scanf("%f",&da);//taking input for da
    
    c = (basic*0.1)+(da*0.05);//calculating contribution and storing in variable c
    
    printf("\nFund Contribution = %f (10%% of %f+ 5%% of %f)",c,basic,da);//printing the contribution

    return 0;
}
