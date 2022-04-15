// Program 3

#include <stdio.h>

int main()
{
    // n : To store size of pattern as required by user
    int n;

    // Prompting user for input and storing it in n
    printf ("Enter a number for the size of pattern you want.\n");
    scanf ("%d", &n);
    printf("\nThe pattern of size %d :\n\n", n);

    // To print the 1st row of stars (top edge of outer square)
    for (int i = 0; i <= 2 * n; i++)
        printf ("* ");
    printf ("\n");

    // looping to print rows 2 to n+1(e.g.5)
    for (int i = 0; i < n; i++)
    {
        // To print the 1st column of stars (left edge of outer square)
        printf ("* ");

        // To print triangular blank space on TOP-LEFT part of pattern OUTSIDE the inner square
        for (int j = n - 1; j > i; j--)
            printf ("  ");

        // To print TOP-LEFT part of inner square
        printf ("* ");

        // To print triangular blank space on TOP-LEFT part of pattern INSIDE the inner square
        for (int j = 0; j < i; j++)
            printf ((i + j != 2 * n - 3) ? "  " : "* "); // i+j = 2n-3 only for the central point of pattern

        // To print triangular blank space on TOP-RIGHT part of pattern INSIDE the inner square
        for (int j = 1; j < i; j++)
            printf ("  ");

        // To print TOP-RIGHT part of inner square
        printf ((i != 0) ? "* " : ""); // Exception on 2nd row : there is only one star

        // To print triangular blank space on TOP-RIGHT part of pattern OUTSIDE the inner square
        for (int j = n - 1; j > i; j--)
            printf ("  ");

        // To print the last column of stars (right edge of outer square)
        printf ("*\n");
    }

    // looping to print rows n+2(e.g.6) to 2n(e.g.8)
    for (int i = 1; i < n; i++)
    {
        // To print the 1st column of stars (left edge of outer square)
        printf ("* ");

        // To print triangular blank space on BOTTOM-LEFT part of pattern OUTSIDE the inner square
        for (int j = 0; j < i; j++)
            printf ("  ");

        // To print BOTTOM-LEFT part of inner square
        printf ("* ");

        // To print triangular blank space on BOTTOM-LEFT part of pattern INSIDE the inner square
        for (int j = n - 1; j > i; j--)
            printf ("  ");

        // To print triangular blank space on BOTTOM-RIGHT part of pattern INSIDE the inner square
        for (int j = n - 2; j > i; j--)
            printf ("  ");

        // To print BOTTOM-RIGHT part of inner square
        printf ((i != n - 1) ? "* " : ""); // Exception on penultimate row : there is only one star

        // To print triangular blank space on BOTTOM-RIGHT part of pattern OUTSIDE the inner square
        for (int j = 0; j < i; j++)
            printf ("  ");

        // To print the last column of stars (right edge of outer square)
        printf ("*\n");
    }

    // To print the last row of stars (bottom edge of outer square)
    for (int i = 0; i <= 2 * n; i++)
        printf ("* ");
    printf("\n");

    return 0;
}
