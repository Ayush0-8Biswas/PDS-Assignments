/*program to find the sum of infinite series and multiplying
the sum with k with a random number k and checking whether it is
a prime number or not*/

#include<stdio.h>
#include<math.h>
int main()
{
    //varible declaration
    int n,k,c=0,p, FLAG=1,i;
    float x=0.0,d=0.0;

    //taking input from the user
    printf("INPUT:\n");
    printf("n=");
    scanf("%d",&n);
    printf("k=");
    scanf("%d",&k);

    //calculation of the sum of series and printing it
    for(int i=1;i<=n;i++)
    {
        d=(i*(i+1))*(i+(i+1));
        x=x+(pow((i*(i+1)),3))/(pow(d,2));
    }
    printf("\nOUTPUT:\n");
    printf("%0.3f\n",x);

    x = floorf(x * 1000) / 1000;
    printf("%0.3f*k=%0.3f\n",x,(x*k));
    //to multiply and round of the value

    p=floor(x*k);
    printf("Floor(%0.3f)=%d\n",(x*k),p);
    //checking for prime number and printing the same
    for(i=2;i<=sqrt(p);i++)
   {
      if(p%i == 0)
      {
         FLAG = 0;
         break;
      }
   }
   if(FLAG == 1)
      printf("Prime Number",p);
   else
      printf("Not Prime",p);

    return 0;

    //program completed
}
