

#include<stdio.h>   		//HEADER FILE FOR INPUT-OUTPUT
int F1(int , int);          //FUNCTION DECLARATION FOR THE FUNCTION THE RETURN THE ABSOLUTE DIFFERENCE
int F2(int [],int);        //FUNCTION DECLARATION FOR THE RECURSIVE FUNCTION TO PRINT THE ABS. DIFFENCE BETWEEN SUCCESSIVE ENTRY
int main()         		//MAIN() FUNCTION
{
   //DECLARATION OF VARIABLES
   int ar[100],n=0;         //INPUT VARIABLES

   //INPUT
   printf("\nENTER THE SIZE OF THE ARRAY(n) :");
   scanf("%d",&n);
   printf("\nENTER THE VALUES IN THE ARRAY:\n");
   for(int i=0;i<n;++i)
   {
       printf("Element %d : ",i+1);
       scanf("%d",&ar[i]);
   }
   F2(ar,n);                //CALLING THE FUNCTION TO PRINT THE ABS. DIFFERENCE BETWEEN SUCCCESSIVE ENTRY
   printf("\n");            //JUST PRINTING NEW LINE IN ORDER TO IMPROVE READIBILITY OF THE OUTPUT, JUST TO HAVE A LINE GAP BETWEEN
                            // OUTPUT AND THE EXECUTION MESSAGE
   return 0;      //RETURNING A VALUE
}
int F1(int a, int b)              //FUNCTION DEFINATION FOR THE FUNCTION THE RETURN THE ABSOLUTE DIFFERENCE
{
    return(b-a);                //RETURNING THE VALUE B-A WHERE A,B ARE SUCCESSIVE ENTRY IN THE ENTERED ARRAY AND B>A
}
int F2(int A[],int n)            //FUNCTION DEFINATION FOR THE RECURSIVE FUNCTION TO PRINT THE ABS. DIFFENCE BETWEEN SUCCESSIVE ENTRY
{
    static int i=0;             //STATIC SO THAT THE MEMORY LOCATION DOESN'T CHANGE,SO CHANGE IN THIS VALUE WILL BE REMEMBERED EVEN IN
                                // CALLING THE FUNCTION RECURSIVELY
    int absdif=0;
    if(i==n-1)                  //BASE CASE
        return 1;

    //CHECKING WHICH IS ONE GREATER OF THE SUCCESSIVE PAIR,AS F1 TAKES A,B SUCH THAT B>A ONLY
    if(A[i+1]>A[i])
        absdif=F1(A[i],A[i+1]);
    else
        absdif=F1(A[i+1],A[i]);

    //PRINTING THE ABS. DIFFERENCE BETWEEN SUCCESSIVE ENTRY
    printf("\nTHE ABSOLUTE DIFFERENCE OF %d AND %d IS :%d",A[i],A[i+1],absdif);
    ++i;                // CHANGING i IN ORDER TO MOVE IN THE ARRAY,SO THAT NEXT SUCCESSIVE DIFFERENCE CAN BE COMPUTED
    F2(A,n);            //CALLING F2 RECURSIVELY
}




