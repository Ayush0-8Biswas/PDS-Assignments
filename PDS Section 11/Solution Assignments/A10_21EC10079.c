/* Section - 11
 * Roll No.: 21EC10079
 * Name: Teerath Agarwal
 * Group No.: 8
 * Assignment No.: 10
 * Description: This program finds and prints the palindrome substrings of given string of length greater than 1. It also finds which one has maximum length.
*/

#include <stdio.h>

/* Function pal() check if the substring is palindrome or not */
int pal(char x[], int st, int ed)
{
    st--;
    int k = (ed-st)/2;
    ed--;
    int check=1;
    for (int i=0; i<k; i++)
    if (x[st+i]!=x[ed-i]) check=0;
    return check;
}

int main()
{
    /* Declaring the variables used */
    int length,i_n[400],j_n[400],count=0,max=-1,check=0;
    char S[30];

    /* Taking input string from the user, printing it, finding its length and converting capital letters to small letters */
    printf("Enter the string 'S': ");
    scanf("%s",S);
    printf("String 'S' is: %s\n\n",S);
    for (length=0; S[length]!='\0'; length++)
    if (S[length]>64 && S[length]<91) S[length] += 32;

    /* Finding palindrome substrings */
    printf("Palindrome substrings in S with their i,j indices are:");
    for (int i=0; i<length-1; i++)
    for (int j=i+1; j<length; j++)
    {
        /* Here, 'check' is used to know if any result is found or not and array i_n[] and j_n[] store the i,j value of each palindrome */
        if (pal(S,i+1,j+1))
        {
            check = 1;
            i_n[count] = i;
            j_n[count] = j;
            count++;
            printf("\ni = %d, j = %d, Palindrome substring -> ", i+1, j+1);
            for (int k=i; k<=j; k++) printf("%c",S[k]);
        }
    }

    /* Printing maximum length substring */
    if (check)
    {
        printf("\n\nPalindrome substrings of maximum length are:\n");
        for (int a=0; a<count; a++)
        if (max<(j_n[a]-i_n[a])) max=j_n[a]-i_n[a];
        for (int a=0; a<count; a++)
        if (max==(j_n[a]-i_n[a]))
        {
            for (int k=i_n[a]; k<=j_n[a]; k++) printf("%c",S[k]);
            printf(" -> i = %d, j = %d\n", i_n[a]+1, j_n[a]+1);
        }
    }
    else printf("\n\nNo such\n");
    printf("\n");

    return 0;
}