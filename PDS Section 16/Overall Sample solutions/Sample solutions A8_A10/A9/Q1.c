#include<stdio.h>
#include<stdlib.h>
//Declaring Functions
int isSawtooth(int *arr,int n);

void position(int *arr,int *pos, int n);

void main(){

    //loop for re-running
    char c = 'Y';
    while(c =='Y'){

        //Variables for size of array and pointer of array
        int n,*p;

        //Taking user input
        printf("Enter n(>=3) : ");
        scanf("%d",&n);

        //Allocating memory to the array
        p=(int*)malloc(n*4);    // sizeof(int) wasn't working for some reason so i just put 4 bytes for size of int

        //Taking use input for array
        printf("Enter the elements of the array: ");

        for(int i=0;i<n;i++){
            scanf("%d",p+i);
        }

        //Checking if sawtooth array
        if(isSawtooth(p,n)){

            printf("The array is a strict Sawtooth array.\n");

        }
        else{   //if not, then finding the position in which it is violated
            int pos;
            printf("The array is not a strict sawtooth array.\n");
            position(p,&pos, n);
            printf("First Violating postion: %d\n",pos);
        }
        //Asking whether to re-run
        printf("Do you want to continue(Y/N): ");
        scanf(" %c", &c);
    }


}



int isSawtooth(int *arr,int n){

    int x,y,flag=1;

    for(int i=0;i<n-3;i++){

        x = arr[i+1] - arr[i];
        y = arr[i+2] - arr[i+1];

        if(x*y>=0){
            flag=0;   // if the product of differences is positive that means both have the same sign, so not sawtooth
            break;
        }
    }
    return flag;
}

void position(int *arr,int *pos, int n){
    int x,y;
    for(int i=0;i<n-2;i++){

        x=arr[i+1]-arr[i];
        y=arr[i+2]-arr[i+1];

        if(x*y>=0){     // Same logic as in is Sawtooth function
            *pos = i+3; // i+3 to convert from 0->n-1 to 1->n
            return;
        }
    }
    return;
}
