/*
*     Section 11
*     Roll No  :  21AE10011
*     Name    :  Bhanupriya Gupta
*     Group No.: 4
*     Test Problem No : 01
*     Description : Find and compare frequency of unique characters in two strings considering uppercase and lowercase as same
*/
#include <stdio.h>
int main(void)
{
    char a[128], b[128];
    int i, alen, blen, a1[128]={0}, b1[128]={0};

    //input and print strings a and b//
    printf("Enter a : ");
    scanf("%s",a);
    printf("Enter b : ");
    scanf("%s",b);
    printf("a : %s\n",a);
    printf("b : %s\n",b);

    // find length of strings, convert lowercase to uppercase, store frequency in a1 and b1//
    for(i=0; a[i]!='\0';- i++){
        if(a[i]>='A' && a[i]<='Z') a[i]=a[i]+'a'-'A';
        a1[a[i]]++;
    }
    alen=i;

    for(i=0; b[i]!='\0'; i++){
        if(b[i]>='A' && b[i]<='Z') b[i]=b[i]+'a'-'A';
        b1[b[i]]++;
    }
    blen=i;

    // print frequency of unique characters in a and b//
    printf("Frequency of each character in a : \n");
    for(i=0; i<128; i++){
        if(a1[i]!=0){
            printf("%c = %d\n",(char)i, a1[i]);
        }
    }
    printf("\n");

    printf("Frequency of each character in b : \n");
    int flag=0;
    for(i=0; i<128; i++){
        if(b1[i]!=0){
            printf("%c = %d\n",(char)i, b1[i]);
        }
        //compare frequency in a and b//
        if(b1[i]<a1[i] || b1[i]==0){
            flag++;
        }
    }
    printf("\n");


    if(flag==128){
        printf("Yes, every character present in B is present in A strictly more number of times than in B\n");
    }
    else{
        printf("No, every character present in B is not present in A strictly more number of times than in B\n");
    }


    return 0;
}
