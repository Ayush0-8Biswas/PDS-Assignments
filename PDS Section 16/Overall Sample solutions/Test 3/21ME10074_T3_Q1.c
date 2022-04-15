#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Creating the function
int isNarcissistic(int n)
{
    int sum=0,m=n,k=n,no_of_digits=0; //Declaring required variables

    //Counting no of digits
    while(m!=0)
    {
        no_of_digits++;
        m=m/10;
    }

    //finding the sum of its digits,each raised to the power of the number of digits of the original number
    int i;
    while(n!=0)
    {
        i=n%10; //this is initializing the i as digit
        sum+=pow(i,no_of_digits);
        n=n/10; //n is now divided by 10
    }
    //sum is equal to k=n,ie, original no. then returning 1
    if(sum==k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n,m,no_of_digits=0;

    printf("Input:\n");
    scanf("%d",&n);

    m=n;
    //Finding no. of digits
    while(m!=0)
    {
        no_of_digits++;
        m=m/10;
    }

    //printing results accordingly
    if(no_of_digits%2==1)
    {
        printf("\nNumber of digits = odd\n");
    }
    else
    {
        printf("\nNumber of digits = even\n");
    }


    //if value returned is 1 then its a narcissistic no. else not narcissistic
    if(isNarcissistic(n)==1)
    {
        printf("Number is a Narcissistic number\n");
    }
    else
    {
        printf("Number is not a Narcissistic number\n");
    }

    return 0;
}
