#include<stdio.h>
#include<math.h>
int main(){
float s,price,GST; //  declaring variables
int v,day;         //declaring variables  
printf("give the value of day in which you want to calculate the required value of question\n"); 
printf("Consider Monday as Day 1, Tuesday as Day 2, ....., Sunday as Day 7\n");
scanf("%d",&day); //taking value from keyboard

switch(day){
    case 1: printf("the day is Monday\n give the value of number of vehicles spoted in highway \n");
            scanf("%d",&v);      //taking the value of day from keyboard
            s=v*0.33333;         //calculating amount of litres according to question
            printf("the amount of fuel sold on that day is %f litres \n",s);
            price=(s*120)*1.25; //calculating price according to queston
            printf("the cost of fuel sold that day is %f rupees \n",price);
            break;              //breaking the switch so that it dosent run further.

    case 2: printf("the day is Tuesday\n give the value of number of vehicles spoted in highway \n");
            scanf("%d",&v);
            s=pow(v,2)+v*2;
            printf("the amount of fuel sold on that day is %f litres\n",s);
            price=(s*120)*1.25;
            printf("the cost of fuel sold that day is %f rupees \n",price);
            break;

    case 3: printf("the day is Wednesday\n give the value of number of vehicles spoted in highway \n");
            scanf("%d",&v);
            s=floor((2*v)*0.142857); //it was only mentioned to give the lowest nearest integer for wednesday or else i would have added floor to every output.
            printf("the amount of fuel sold on that day is %3.0f litres\n",s);
            price=(s*120)*1.25;
            printf("the cost of fuel sold that day is %f rupees \n",price);
            break;

    case 4: printf("the day is Thursaday\n give the value of number of vehicles spoted in highway \n");
            scanf("%d",&v);
            s=pow(v,2)+v*2;
            printf("the amount of fuel sold on that day is %f litres\n",s);
            price=(s*120)*1.25;
            printf("the cost of fuel sold that day is %f rupees \n",price);
            break;

    case 5: printf("the day is Friday\n give the value of number of vehicles spoted in highway \n");
            scanf("%d",&v);
            s=pow(v,2)+v*2;
            printf("the amount of fuel sold on that day is %f litres\n",s);
            price=(s*120)*1.25;
            printf("the cost of fuel sold that day is %f rupees \n",price);
            break;

    case 6: printf("the day is Saturday\n give the value of number of vehicles spoted in highway \n");
            scanf("%d",&v);
            s=3*(pow(v,2)+2*v);
            printf("the amount of fuel sold on that day is %f litres\n",s);
            price=(s*120)*1.25;
            printf("the cost of fuel sold that day is %f rupees \n",price);
            break;

    case 7: printf("the day is Sunday\n give the value of number of vehicles spoted in highway \n");
            scanf("%d",&v);
            s=3*(pow(v,2)+2*v);
            printf("the amount of fuel sold on that day is %f litres\n",s);
            price=(s*120)*1.25;
            printf("the cost of fuel sold that day is %f rupees \n",price);
            break;
    default: printf("Such day dosent exist on earth, Please find a different planet......XD");
             break;

}
//THANK YOU HAVE A GOOD DAY!



return 0;
}