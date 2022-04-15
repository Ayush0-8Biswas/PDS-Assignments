/*

* Section 11

* Roll No. :- 21CH10023

* Name :- Dibyansh Sekhar Das

* Group No. :- 8

* Assignment :- 10

* Description :- to print the largest palindrome inside a string

*/

#include <stdio.h>
//gets length of string
int leng(char a[])
{
    int len=0;
    for (int i = 0; a[i]!='\0'; i++) len++;
    return len;
}

//to check if a substring is a palindrome
int pal(char a[], int i, int j)
{
    int x = i-1, y = j-1, flag = 1;
    int len = j-i+1;
    for (int k = 0; k<len/2; k++)
    {
        if ((a[x+k]!=a[y-k]) && (a[x+k]!=(a[y-k]+32)) && (a[x+k]!=(a[y-k]-32))) flag = 0;
    }
    return flag;
}

int main(){
char S[20];
int max1[50], max2[50], flag, maxd = 0, flag2=0, k=0, count =0;
printf("Enter your string S: \n");
scanf("%s", S);
printf("The palindrome substrings with their indices present in S are:\n");

//gets the length of the largest possible palindrome, stores it in maxd
for (int i = 1; i<leng(S); i++)
{
    for (int j = i+1; j<=leng(S); j++)
    {
        flag = pal(S, i, j);
        if (flag==1)
        {
            if((j-i)>maxd)
            {
                maxd = j-i;
            }
        }
    }
}

//prints all possible palindromes
for (int i = 1; i<leng(S); i++)
{
    for (int j = i+1; j<=leng(S); j++)
    {
        flag = pal(S, i, j);
        if (flag==1)
        {
            if ((j-i)==maxd)                   //stores the indices of every largest possible palindrome substrings in max1(for i) and max2(for j)
            {
                max1[k]=i-1;
                max2[k]=j-1;
                k++;
                count++;

            }
            flag2=1;
            printf("(%d, %d) ", i, j);
            for (int k = i-1; k<j; k++)
                printf("%c", S[k]);
            printf("\n");
        }

    }
}


printf("The largest possible palindrome");
if (count>1) printf("s are: \n");
else printf(" is: \n");

//prints the largest palindrome substrings whose indices are stored in max1 and max2
for (int i = 0 ; count > 0; i++)
{
    for (int j = max1[i]; j<=max2[i]; j++)
    {

        printf("%c", S[j]);
    }
    printf("\n");
    count--;
}
if (flag2==0) printf("No such palindromes exist");

return 0;
}
