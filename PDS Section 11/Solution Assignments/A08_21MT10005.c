/*
* Section 11
* Roll No : 21MT10005
* Name : Anurag Kumar Singh
* Group No.: 5
* Assignment No : 08
* Description : string operation using arrays.
*/
#include<stdio.h>
int main()
{
    char st[50];
    char st_fin[50];
    int i,j,k;
    scanf("%s",&st);
    printf("The string read in: %s\n",st);
    for(i=0;st[i]!='\0';i++)
    {
        if((st[i]>='A')&&(st[i]<='Z'))                             //it converts each uppercase to lower case//
            st[i]=st[i]+32;
    }
    for (i=0,j;st[i]!= '\0'; ++i)
    {
      while ((!(st[i]>= 'a')&&(st[i] <= 'z'))&&!(st[i] == '\0'))     //correcting the array by removing any character other than vowel or consonants//
      {
         for (j=i;st[j]!='\0';++j)
         {
            st[j]=st[j+1];
         }
         st[j]='\0';
      }
    }
    for(i=0;st[i]!= '\0';i++)
  	{
  		for(j =i+1;st[j]!= '\0';j++)                                   //removing duplicate terms and storing them in the same array//
  		{
  			if(st[j]==st[i])
			{
  				for(k=j;st[k]!= '\0';k++)
				{
					st[k]=st[k+1];
				}
 			}
		}
	}
	i=0;int x=0;
	while(st[i]!= '\0')
	{
	    if((st[i]=='a')||(st[i]=='e')||(st[i]=='i')||(st[i]=='o')||(st[i]=='u'))
        {
            st_fin[x++]=st[i];                                                       //first set of characters should be vowels//
        }                                                                            //forming final array with string beginning with vowels//
        i++;
	}
	i=0;
	while(st[i]!= '\0')
	{
	    if((st[i]!='a')&&(st[i]!='e')&&(st[i]!='i')&&(st[i]!='o')&&(st[i]!='u'))
        {
            st_fin[x++]=st[i];                                                         //adding the consonant characters to the string//
        }
        i++;
	}
    if (st[0]=='\0')
        printf("No Alphabet in String");                                                //prints valid message if no alphabets were taken in input//
    else
    {
        printf("The new string is: ");
        for(i=0;st_fin[i]!='\0';i++)
        {
            printf("%c",st_fin[i]);                                                     //finally printing the new string//
        }
    }
}
