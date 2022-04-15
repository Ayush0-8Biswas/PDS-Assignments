#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>



void binary(int n,int arr[],int count)
{
	int j;
	for (j=7;j>=0;j--)
	{
		arr[8*count+j]=n%2;
		n=n/2;
	}
}

void print(int n)
{
	if (n<26) printf("%c",(n+65));
	else if (n<52) printf("%c",(n+71));
	else if (n<62) printf("%c",(n-4));

}

void part2(int n, int no[],int count)
{
	int j;
	for (j=5;j>=0;j--)
	{
		no[6*count+j]=n%2;
		n=n/2;
	}
}

int reverse(char c)
{
	if (isupper(c)) 
	{
		int temp=(int)c-65;	
		return (temp);
	}
	if (islower(c)) 
	{
		int temp=(int)c-71;	
		return (temp);
	}
	else
	{
		int temp=(int)c+4;	
		return (temp);
	}
}
int main()
{
	char string[100];
	int k, count=0,i=0;
	printf("Give the input String: ");
	gets(string);
	int arr[8*strlen(string)],le=8*strlen(string),special=0;
	

	printf("The Encrypted String: ");
	while (string[i]!='\0') 
	{
		binary((int)string[i],&arr[0],count);
		i++;
		count++;
	}
	for (i=0;i<le/6;i++)
	{
		int temp=0;
		for (k=0;k<6;k++) temp+=arr[6*i+k]*pow(2,5-k);
		print(temp);
	}
	
	for (i=0;i<le%6;i++) special+=arr[le/6+i]*pow(2,(le%6-1)-i);
	if (le%6!=0) print(special);
	printf("\n");
	
	printf("\nGive Encrypted String: ");
	char noo[100];
	gets(noo);
	int no[6*strlen(noo)],ple=6*strlen(noo),special2=0;
	

	printf("The Decrypted String: ");
	for (i=0;i<strlen(noo);i++) 
	{
		int temp=reverse(noo[i]);	
		part2(temp,&no[0],i);
	}
	for (i=0;i<ple/8;i++)
	{
		int temp=0;
		for (k=0;k<8;k++) temp+=no[8*i+k]*pow(2,7-k);
		printf("%c",(char)temp);
	}
	
	for (i=0;i<le%8;i++) special2+=no[ple/8+i]*pow(2,(ple%8-1)-i);
	if (ple%8!=0) printf("%c",(char)special2);
	printf("\n");
	return 0;
}
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
			
	
