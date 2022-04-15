/*a program to input n integers from the keyboard and store them within an array. Declare
another array of size n and copy the contents of the first array into the second array as per the
following rules:*/

#include<stdio.h>
#include<math.h>

int main()
{
    //variable initialization
    int n;double sum=0.0;
    double sq=0.0;

    //taking the array size
    printf("Input array size=");
    scanf("%d",&n);

    //array declartion
    int a[n],b[n];
    printf("enter array elements\n");

    //taking array input
    for(int i=0;i<n;i++)
    {
        printf("Enter the element A[%d]=",i);
        scanf("%d",&a[i]);

    }

    //performing the calculations
    for(int i=0;i<n;i++)
    {
        //swapping if even
        if((i+1)%2==0)
        {
            b[n-i]=a[i];
            

        }

        //calculated for non-even digits
        else
        {
            for(int j=i+1;j<n;j++)
            {
                sum=sum+pow(a[j],2);

            }
            
            //taking square root and rounding off
            sq=round(sqrt(sum));
            
            b[i]=a[i]*sq;
            sum=0.0;

            
        }
        
    }

    // printing the new array
    printf("\n The new array :");
    for (int i=0;i<n;i++)
    {
        printf("\nElement B[%d]=%d",i,b[i]);
    }
    
    // completion of the program
    return 0;
}