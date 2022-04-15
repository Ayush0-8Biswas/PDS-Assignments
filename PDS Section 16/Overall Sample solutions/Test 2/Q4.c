// Program 4

#include <stdio.h>
#include <math.h>

void theithSymbol(int [], int);
int main()
{
    int n;
    printf("Enter the number of rows you want(n).\n");
    scanf("%d", &n);
    int size = (int)pow(2, n), arr[size];
    arr[0] = 0;
    for (int i = 1; i < size; i++)
        arr[i] = 2;
    printf("\nThe required rows are:\n");
    theithSymbol(arr, n);
    return 0;
}
void theithSymbol(int a[], int n)
{
    static int count = 1;
    int i = 0;
    printf("\nValue of Row %d: ", count++);
    for (; a[i] != 2; i++)
        printf("%d ", a[i]);
    if (count > n)
        return;
    for (int j = i - 1; j >= 0; j--)
    {
        a[2 * j + 1] = (a[j]) ? 0 : 1;
        a[2 * j] = a[j];
    }
    theithSymbol(a, n);
}
