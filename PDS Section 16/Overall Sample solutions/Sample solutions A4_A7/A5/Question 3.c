// Program 3

#include <stdio.h>

int overlap(float [ ], float [ ]);
int inside (float [ ], float, float);

int main()
{
    // Stores the co-ordinates of the diagonal points of each of the three rectangles.
    float arr1[4], arr2[4], arr3[4];

    // Prompting user for input of co-ordinates of the diagonal points of each of the three rectangles.
    printf("Enter the co-ordinates of the diagonal points of the first rectangle.\n");
    for (int i = 0; i < 4; i++)
        scanf("%f", &arr1[i]);
    printf("Enter the co-ordinates of the diagonal points of the second rectangle.\n");
    for (int i = 0; i < 4; i++)
        scanf("%f", &arr2[i]);
    printf("Enter the co-ordinates of the diagonal points of the third rectangle.\n");
    for (int i = 0; i < 4; i++)
        scanf("%f", &arr3[i]);

    // Computing if the three rectangles overlap and storing result in respective variables.
    // rij : Stores whether rectangle i and rectangle j overlap. If they overlap rij equals 1, else equals 0
    int r12 = overlap(arr1, arr2), r23 = overlap(arr2, arr3), r31 = overlap(arr3, arr1);

    // Printing final result of overlapping of rectangles.
    // Since rij can take only 0 or 1, only if r12 = r23 = r31 = 1, will below condition be satisfied.
    if (r12 * r23 * r31 == 1)
        printf("All three rectangles overlap.\n");
    // If all three rectangles don't overlap with each other
    else
    {
        printf((r12 == 1) ? "Rectangles 1 and 2 overlap.\n" : "Rectangles 1 and 2 do NOT overlap.\n");
        printf((r23 == 1) ? "Rectangles 2 and 3 overlap.\n" : "Rectangles 2 and 3 do NOT overlap.\n");
        printf((r31 == 1) ? "Rectangles 3 and 1 overlap.\n" : "Rectangles 3 and 1 do NOT overlap.\n");
    }

    return 0;
}

// Returns 1 if rectangles given by a and b overlap.
int overlap(float a[ ], float b[ ])
{
    return (inside(a, b[0], b[1]) || inside(a, b[0], b[3]) || inside(a, b[2], b[3]) || inside(a, b[2], b[1])) ? 1 : 0;
    // If any of the 4 vertices of rectangles given by b[] lies inside rectangle given by a[], the rectangles are overlapping.
    // So, we check using inside() function for each of the 4 vertices of b[], and even if one of them is true, the rectangles are overlapping.
}

// Returns 1 if point with co-ordinates (x,y) lies inside rectangle given by a[], else gives 0.
int inside (float a[ ], float x, float y)
{
    return ((x - a[0]) * (x - a[2]) <= 0) ? ((y - a[1]) * (y - a[3]) <= 0) ? 1 : 0 : 0;
    // (x - a[0]) * (x - a[2]) <= 0 only if x lies between a[0] and a[2] (both inclusive) --> Condition 1
    // (y - a[1]) * (y - a[3]) <= 0 only if y lies between a[1] and a[3] (both inclusive) --> Condition 2
    // If conditions 1 and 2 are satisfied, (x,y) lies inside or on rectangle given by a[].
}
