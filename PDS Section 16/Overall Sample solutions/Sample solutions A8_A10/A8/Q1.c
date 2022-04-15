#include <stdio.h>
/*

 arbitrary number of words
*/
int main()

{

    char arr1[100];
    int i=0,j=0;
    char c;
    printf("Enter String:");
    c=getchar();
    while( c!='\n' && c!='\r')
    {
        arr1[i++]=c;
        c=getchar();
    }
    arr1[i]='\0';
    printf("\n%s\n",arr1);
    j=i;
    for (i=0;i<j;i++)
    {
        if( ( ( arr1[i]>='A' &&  arr1[i]<='Z' ) || (arr1[i]>='a' &&  arr1[i]<='z') ) && ( arr1[i]!='\r' && arr1[i]!='\0') || arr1[i]==' ' )
        {
            printf("%c",arr1[i]);

        }
    }

}
