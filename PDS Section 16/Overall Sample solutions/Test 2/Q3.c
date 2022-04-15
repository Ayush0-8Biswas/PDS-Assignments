

#include<stdio.h>   		//HEADER FILE FOR INPUT-OUTPUT
#include<math.h>            //HEADER FILE FOR SQRT ,POW FUNCTION
struct Circle               //STRUCTURE FOR STORING DATA OF CIRCLE, RADIUS AND COORDINATES OF ITS CENTRE
{
    int R,x,y;
}C1,C2;
struct Triangle             //STRUCTURE FOR STORING DATA OF TRIANGLE, PERPENDICULAR, BASE ,HYPOTENUSE
{
    int P,B,H;
}T;
int check_circle(struct Circle,struct Circle);          //FUNCTION PROTOTYPE FOR CHECKING THE TWO CIRCLES
int check_traingle(struct Circle,struct Triangle);      //FUNCTION PROTOTYPE FOR CHECKING THE TRAINGLE CONDITIONS
int main()         		//MAIN() FUNCTION
{
   //DECLARATION OF VARIABLES
   char ch='y';         //INPUT VARIABLES
   int i=0;             //INPUT VARIABLES
   int rc=5;            //COMPUTATIONAL VARIABLES
   //OUTPUT VARIABLES

   while(ch!='n')
   {
       printf("\n\t\t\t\t\t\tMENU");
       printf("\n1.CHECK CIRCLES");
       printf("\n2.CHECK TRIANGLES\n");
       scanf("%d",&i);              //INPTTING CHOICE FROM USER
       switch(i)
       {
           case 1:printf("\n\tENTER THE DATA OF CIRCLE 1");
                  printf("\nRADIUS : ");
                  scanf("%d",&C1.R);
                  printf("\nX COORDINATE OF CENTRE : ");
                  scanf("%d",&C1.x);
                  printf("\nY COORDINATE OF CENTER : ");
                  scanf("%d",&C1.y);
                  printf("\n\tENTER THE DATA OF CIRCLE 2");
                  printf("\nRADIUS : ");
                  scanf("%d",&C2.R);
                  printf("\nX COORDINATE OF CENTRE : ");
                  scanf("%d",&C2.x);
                  printf("\nY COORDINATE OF CENTER : ");
                  scanf("%d",&C2.y);
                  rc=check_circle(C1,C2);               //STORING THE RETURN VALUE TO PRINT THE CORECRT VALUE
                  switch(rc)
                  {
                      case 2:printf("\nCIRCLE 1 AND CIRCLE 2 ARE INTERSECTING.");
                             break;
                      case 1:printf("\nCIRCLE 1 AND CIRCLE 2 ARE TOUCHING EACH OTHER.");
                             break;
                      case 0:printf("\nCIRCLE 1 AND CIRCLE 2 ARE NOT TOUCHIG EACH OTHER.");
                             break;
                  }
                  break;
           case 2:printf("\n\tENTER THE DATA OF CIRCLE ");
                  printf("\nRADIUS : ");
                  scanf("%d",&C1.R);
                  printf("\n\tENTER THE DATA OF TRIANGLE");
                  printf("\nPERPENDICULAR : ");
                  scanf("%d",&T.P);
                  printf("\nBASE : ");
                  scanf("%d",&T.B);
                  printf("\nHYPOTENUSE : ");
                  scanf("%d",&T.H);
                  rc=check_traingle(C1,T);                  //STORING THE RETURN VALUE IN RC TO PRINT CORRECT RESULT
                  switch(rc)
                  {
                      case 2:printf("\nTRAINGLE IS NOT A RIGHT ANGLED TRIAGLE.");
                             break;
                      case 1:printf("\nTHE AREA OF THE TRIANGLE AND CIRCLE IS EQUAL.");
                             break;
                      case 0:printf("\nTHE AREA OF THE TRIANGLE AND CIRCLE IS NOT EQUAL");
                             break;
                  }
                  break;
           default:printf("\nWRONG INPUT")       ;

       }
       printf("\nDO YOU WANT TO CONTINUE?[n WILL END THIS PROGRAM]");
       printf("\nENETR WHAT YOU WANT, IF NOT WANT TO CONTINUE PRESS n(CASE SENSITIVE):");
       scanf(" %ch",&ch);
   }
   printf("\n");            //LINE BRAEK TO DISTINGUISH BETWEEN MY CODE OUTPUT AND COMPILER  MESSAGE OUTPUT
   return 0;      //RETURNING A VALUE
}
int check_circle(struct Circle C1,struct Circle C2)       //FUNCTION DEFINE FOR CHECKING THE TWO CIRCLES
{
    int d=0;            //FOR CALCULATING DISTANCE
    d=sqrt(pow(C1.x-C2.x,2)+pow(C1.y-C2.y,2));      //CALCULATING DISTANCE
    if(d<C1.R+C2.R)
    {
        return 2;           //CIRCLES INTERSECTING
    }
    else if(d==C1.R+C2.R)
    {
        return 1;       //CIRCLES TOUCHING
    }
    else if(d>C1.R+C2.R)
    {
        return 0;           //CIRCLES NOT TOUCHING
    }
}
int check_traingle(struct Circle C,struct Triangle T)           //FUNCTION DEFINE FOR CHECKING THE TRAINGLE CONDITIONS
{
    int p=0,b=0,h=0;        //FOR STORING H^2,B^2,P^2
    p=T.P*T.P;
    b=T.B*T.B;
    h=T.H*T.H;
    if(h==(b+p))        //CHECKING WHTEHR IT IS RIGHT ANGLED OR NOT
    {
        int A1=0,A2=0,A3=0,A=0;
        A1=(T.P+T.B-T.H);
        A2=A1/2;
        A3=pow(A2,2);
        A=3.14*A3;

        int AC=0;
        if(A==AC)
        {
            return 1;       //AREA OF TRIANGLE AND CIRCLE EQUAL
        }
        else
        {
            return 0;       //AREA OF CIRCLE AND TRAINGLE NOT EQUAL
        }
    }
    else
    {
        return 2;       //TRANGLE NOT RIGHT ANGLED
    }
}



