/*program using recursive functions to compute the binary 
equivalent for a given decimal fractional number.*/
#include<stdio.h>

//to convert integer to binary

static int c1 = 0;
static int c2 = 0;
void int_to_bin(int n,int a[])
{
    
    if(n==0)
    {
    a[c1]=0;
    }
    else
    {
        a[c1]=(n%2);
        c1++;
        int_to_bin(n/2,a);   //recursive call
    }
    

}

//to convert fractional part to array
void frac_to_bin(double n, int a[])
{
    
    
    n=n*2.0;
    if(n>1.0){
        a[c2]=1;
        n = (n-(int)n);
        c2++;
        frac_to_bin(n,a);}  //The recursive call
    else if(n==1.0)
    {
        a[c2]=1;    
    }
    else
    {
        a[c2]=0;
        c2++;
        frac_to_bin(n,a);
    }
    

}

//main function
int main()
{
    //inputing the value
    double n;
    printf("Enter a decimal number: ");
    scanf("%lf",&n);

    int a[16]; int b[16];
    double f=n-(int)n;
    int bd=(int)n;
    printf("integer part: %d\n",bd);
    printf("decimal part: %lf\n",f);
    printf("Binary Equivalent: \n");
    int_to_bin(bd,a);
    frac_to_bin(f,b);

    //Printing the binary equivalent of the integer part
    for (int i=c1-1;i>=0;i--)
    {
        printf("%d",a[i]);
    }

    printf(".");

    //Printing the binary equivalent of the fractional part
    for(int i=0;i<c2+1;i++)
    {
        printf("%d",b[i]);
    }

   
    
}

/*NOTE: Since you are all learning recursion now, it is okay if you use global/static variables. But as you write more 
        advanced codes later on, for recursion problems, try not to use global/static variables. Usig global/static variables
        does not go well with recursion. */