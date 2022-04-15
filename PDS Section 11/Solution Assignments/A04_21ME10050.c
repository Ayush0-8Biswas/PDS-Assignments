/*
* Section 11
* Rollno:21ME10050
* Name:Mayukh Banerjee
* Group no:5
* Assignment no:04
* Description:Larger between sum(divisible by 2 or 3 or 5) and sum(not divisible by them) with some set conditions
*/

#include <stdio.h>
main()
{
   int num,sum1=0,sum2=0,i;
   for(i=1;i<=10;i++)
   {
       /*receiving numbers*/
       printf("Enter a no:\n");
       scanf("%d",&num);
       if (num>0)
       {
           printf("No entered:%d \n",num);
           /*nos divisible by 2,3,5*/
           if (num%2==0 || num%3==0 || num%5==0)
           {
               sum1=sum1+num;
           }
           /*nos not divisible by 2,3,5*/
           else if(num%2!=0 && num%3!=0 && num%5!=0)
           {
               sum2=sum2+num;
           }
       }

       else break;

   }
   /*Printing the details*/
   printf("  \n");
   printf("\nSum1(divisible)=%d \n",sum1);
   printf("  \n");
   printf("\nSum2(Not divisible)=%d \n",sum2);
   printf("  \n");
   if (sum1==sum2)
   {
       printf("BOTH SUMS ARE EQUAL");

   }
   else if (sum1>sum2)
   {
       printf("SUM 1(DIVISIBLE) is larger");
   }
   else printf("SUM 2(NOT DIVISIBLE) is larger");
   printf("  \n");

}
