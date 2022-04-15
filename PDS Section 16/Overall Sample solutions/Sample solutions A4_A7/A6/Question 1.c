

#include<stdio.h>       //HEADER FILE FOR INPUT-OUTPUT
int seq(int);               //FUNCTION DECLARATION FOR COMPUTING THE VALUE OF A(N)
int main()            //MAIN() FUNCTION
{
   //DECLARATION OF VARIABLES
   int n=0;             //INPUT VARIABLES
   long int A=0;         //OUTPUT VARIABLES

   //INPUT
   printf("\nENTER THE VALUE OF n (NO. OF TERM) AND IT MUST BE LESS THAN 20 : ");
   scanf("%d",&n);
   while(n>20)          //FOR MAINTAINNG THE VALUE OF N LESS THAN 20
   {
       printf("\nOUT OF RANGE!!!\n\n");
       printf("\nENTER THE VALUE OF n (NO. OF TERM) AND IT MUST BE LESS THAN 20 : ");
       scanf("%d",&n);
   }

   //COMPUTATION
   for(int i = 0; i<= n ;i++)
   {
        //CALLING THE RECURSIVE FUNCTION TO PRINT THE SERIES ONE BY ONE
        printf("%d  ",seq(i));
   }

   printf("\n");


   return 0;      //RETURNING A VALUE
}
int seq(int n)     //FUNCTION DEFINATION FOR COMPUTING THE VALUE OF A(N)
{
    if(n==0)            //BASE CASE
    {
       return 1;
    }
    else if (n==1)      //BASE CASE
    {
       return 1;
    }
    else
    {
        return((2* seq(n-1))+(3*seq(n-2)));  //CALLING THE FUMCTION RECURSIVELY  TO FIND THE SERIES
    }

}





