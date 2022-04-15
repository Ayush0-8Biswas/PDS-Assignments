#include<stdio.h>
int noofwords(char *camel)//introducing the function1
{
    int cnt=0, i;//introducing variables of function 1
     for(i=0;camel[i]!='\0';i++)
     {
         if((int)camel[i]>=65&&(int)camel[i]<=90)//conditions for measuring the length
            cnt++;
     }
     return cnt;
}

void cameltoReverse(char *camel,char *t)//introducing function 2 to reverse the words
{
      int n=0, i, j;
      for(i=0;camel[i]!='\0';i++)
      n++;
      int pr=n,k=0;
      for(i=n-1;i>=0;i--)
      {
          if((int)camel[i]>=65&&(int)camel[i]<=90)
          {
              for(j=i;j<pr;j++)
              {
                t[k]=camel[j];
                k++;
              }
                t[k]=' ';
                k++;
              pr=i;
          }
          //conditions for reversing the camel words

      }
}

int main()//introducing main function
{
    char p[100],t[100];
    printf("Enter the string: ");
    scanf("%[^\n]%*c",p);//scanning the string
    printf("\nNumber of words: %d",noofwords(&p[0]));
    printf("\nReverse String: ");
    cameltoReverse(&p[0],&t[0]);
    printf("%s",t);
}
