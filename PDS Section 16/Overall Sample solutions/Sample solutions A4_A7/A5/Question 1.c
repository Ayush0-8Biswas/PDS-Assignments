// Program 1

#include<stdio.h>
#include<math.h>

int checkDigit(int,int); //Function declaration
int isZazzy(int,int); //Function declaration

int main()
{
    //First, input the two numbers, say the input are stored in variables n and m respectively.
    long long int n, m;
    printf("Enter two numbers.\n");
    scanf("%lld%lld", &n, &m);

    //Next proceed to compute for Zazzy pair if and only if the two numbers satisfy conditions a and b of the question.
    int flag = 0;
    if(checkDigit(n,m) == 1)
    {
        //Now check whether the two numbers are Zazzy or not
        if(isZazzy(n,m) == 1)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    else
    {
        flag = 0;
    }

    //Now if flag == 1, then numbers are Zazzy, so print accordingly, else print not Zazzy.
    printf((flag == 1) ? "Numbers form a Zazzy pair.\n" : "Numbers do not form a Zazzy pair.\n");
    return 0;
} //end of main()

int checkDigit(int n, int m)
{
    //Returns 1 if two numbers passed as parameters are of equal length and even number of digits, 0 otherwise
    int length_n = 0, length_m = 0; // length_n : Stores number of digits in n , length_m : Stores number of digits in m

    for (int i = 0; n > 0; n /= 10) // Computing the number of digits in n
        length_n++;
    for (int i = 0; m > 0; m /= 10) // Computing the number of digits in m
        length_m++;

    return (length_n == length_m) ? (length_n % 2 == 0) ? 1 : 0 : 0; // (n and m are of same length) ? {(number of digits is even) ? return 1 : return 0} : return 0
}

int isZazzy(int n, int m)
{
    //Returns 1 if n and m passed as parameters form a Zazzy pair, 0 otherwise
    int length = 0, copy = n, num = 0; // length : Stores number of digits of n and m , copy : Stores a copy of n's value , num : Stores reversed form of last half of m

    for (int i = 0; copy > 0; copy /= 10) // Computing the number of digits in n and m
        length++;
    for (int i = length; i > length / 2; i--) // Computing reversed form of last half of m and storing it in num
    {
        num = num * 10 + m % 10;
        m /= 10;
    }

    return (num == n / (int)pow(10, length / 2)) ? 1 : 0; // If num equals first half of m return 1 ,else return 0
}
