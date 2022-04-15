/*
* SECTION 11
* ROLL NO: 21CS10067
* NAME: SWADHIN SATYAPRAKASH MAJHI
* GROUP NO. 6
* TEST PROBLEM NO. : 02
* DESCRIPTION: TO READ TWO STRING AND SEE WHETHER IT SATISY THE FOLLOWING CONDITION.
*/
#include<stdio.h>
int main()
{
    char A[100],B[100];
    printf("\nWRITE THE STRING A:\n");
    scanf("%s",A);
    printf("\nWRITE THE STRING B:\n");
    scanf("%s",B);

    printf("\nTHE STRING A IS %s",A);
    printf("\nTHE STRING B IS %s",B);

     /* DETERMINING CHARACTER AND FREQUENCY IN STRING A.*/
    
    int i,j,k=0,l=0,AF[100],BF[100],flag=0;
    char AU[100],BU[100];

     for ( i = 0; A[i]!='\0'; i++)
     {
         if (A[i]>=65&&A[i]<=90)
         {
             A[i]=A[i]+32;
         }

         for ( j = 0; j<k; j++)
         {
             if (AU[j]==A[i])
             {
                 flag=1;
                 break;
             }
             
         }
         if (flag==0)
         {
             AU[k]=A[i];
             AF[k]=1;
             k++;

         }
         if (flag==1)
         {
             AF[j]=AF[j]+1;
             flag=0;
         }
         
         
         
     }

     printf("\n\nTHE STRING A WITH EVERY CHAR (FREQUENCY)\n");
     
      for ( i = 0; i <k; i++)
      {
          printf(" %c (%d times) ,",AU[i],AF[i]);
      }

    /* CHARACTER AND FREQUENCY DETERMINATION OF STRING B*/
    flag=0;
     for ( i = 0; B[i]!='\0'; i++)
     {
         if (B[i]>=65&&B[i]<=90)
         {
             B[i]=B[i]+32;
         }

         for ( j = 0; j<l; j++)
         {
             if (BU[j]==B[i])
             {
                 flag=1;
                 break;
             }
             
         }
         if (flag==0)
         {
             BU[l]=B[i];
             BF[l]=1;
             l++;

         }
         if (flag==1)
         {
             BF[j]=BF[j]+1;
             flag=0;
         }
         
         
         
     }

     printf("\n\nTHE STRING B WITH EVERY CHAR (FREQUENCY)\n");
     
      for ( i = 0; i <l; i++)
      {
          printf(" %c (%d times) ,",BU[i],BF[i]);
      }
      
     /* FINAL COMPARISION INBETWEEN STRING FOR THE LAST CONDITION*/

     int x=0;

      for ( i = 0; i <l; i++)
      {
          for ( j = 0; j <k; j++)
          {
              if (AU[j]==BU[i])
              {
                  if (AF[j]>BF[i])
                  {
                      x++;
                  }
                  
              }
              
          }
          
          
      }
      
      if (x!=l)
      {
          printf("\n\nNO IT DONOT SATISFY THE CONDITION");
      }
      if (x==l)
      {
          printf("\n\nYES IT SATISY THE CONDITION");
      }
      


  return 0;
}