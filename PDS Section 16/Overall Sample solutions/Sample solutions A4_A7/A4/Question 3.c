/*program to play the game of buckets*/
#include<stdio.h>
#include<math.h>

int main()
{
    //taking buckets input
   int n;
   printf("Enter Number of Buckets:");
   scanf("%d",&n);
   int a[n];

   //array input
   printf("Enter Positive Number of Balls for Each %d Buckets:",n);
   for (int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }

   //calucaltion of iterations
   int nr=0,y=1;
    while (1)
    {
        printf("——–Iteration-%d———\n",y);
        int l=1,b;
        for (int i=0; i < n; i++)
        {
            if (a[i]>0)
            {
                b=a[i];
                break;
            }
        }
        for (int i=1;i<n;i++)
        {
            if (a[i]<=0)
            {
                continue;
            }
            else if (a[i]<b)
            {
                l=1;
                b=a[i];
            }
            else if (a[i]==b)
            {
                l++;
            }
        }
        nr=nr+l;
        for (int j=0;j<n;j++)
        {
            a[j]=a[j]-b;
        }
        printf("Number of Buckets with least number of Balls = %d\n", l);
        printf("Number of balls in the Remaining Buckets = ");
        y++;
        for (int k = 0; k < n; k++)
        {
            if (a[k]<=0)
            {
                continue;
            }
            printf(" %d", a[k]);
        }
        if (nr>=n)
        {
            printf("NIL[END]");
            break;
        }
        printf("\n");
        printf("\n");
    }

    //program completed
    return 0;
}