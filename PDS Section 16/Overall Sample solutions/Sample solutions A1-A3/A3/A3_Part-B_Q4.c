// Part B : Question 4

#include <stdio.h>

int main()
{
    // Variable Declaration
    // count : To keep track of number of multiples of n; num : To store user inputed numbers
    // max : To store maximum multiple of n; min : To store minimum multiple of n
    int n, k, count = 0, num, max = 0, min;

    // Prompting user for input and accepting input.
    printf("Enter 2 positive integers (n & k).\n");
    scanf("%d%d", &n, &k);

    min = 2000000000;

    // Loops continues until k multiples of n have been entered
    do
    {
        // Prompting user for input and accepting input
        printf("Enter another positive integer.\n");
        scanf("%d",&num);

        // If num is not a multiple of n, it skips all succeeding statements and goes to next iteration.
        if (num % n != 0)
            continue;

        // If num is greater than max, num replaces max
        max = (max < num) ? num : max;
        // If num is less than min, num replaces min
        min = (min > num) ? num : min;

        // If num is a multiple of n, it doesn't enter if condition (continue statement) and reaches this statement for increasing count of number of multiples of n.
        count++;
    }
    while(count < k);

    // Printing output for user.
    printf("\nMaximum multiple of (n) %d is %d", n, max);
    printf("\nMinimum multiple of (n) %d is %d", n, min);

    return 0;
}
