#include <stdio.h>
#include <stdlib.h>

struct Node{
int data;
struct Node *next;
struct Node *prev;
};

//Function to insert into linked list
void insert(struct Node **head, struct Node **rear, int dat)
{
    //Check first if list is empty
    if(*head == NULL && *rear == NULL)
    {
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data=dat;
        temp->next=NULL;
        temp->prev=NULL;

        *head=temp;
        *rear=temp;
    }
    else
    {
        struct Node *traverse = *head;
        //Choose the appropriate location
        while(traverse->data<dat)
        {
            if(traverse == *rear){
            break;
            }
            traverse=traverse->next;
        }

        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data=dat;
        temp->next=NULL;
        temp->prev=NULL;

        if(traverse == *head)
        {
            traverse->prev=temp;
            temp->next=*head;
            *head=temp;
        }
        else if(traverse == *rear && traverse->data<dat)
        {
            //Add to rear
            traverse->next=temp;
            temp->prev=traverse;
            *rear = temp;

        }
        else{

            struct Node*t1 = traverse->prev;
            t1->next=temp;
            temp->prev=t1;
            temp->next=traverse;
            traverse->prev=temp;
            //No change in rear pointer
        }
    }

}

void printList(struct Node **head)
{
    struct Node *temp=*head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}

int minDist(struct Node **head, struct Node **rear, int dat)
{
    //First check from front
    int fr = 0, rr = 0;
    struct Node *temp = *head;
    int flag = 0;

    while(temp->data <= dat || temp!=NULL)
    {
        fr++;
        if(temp->data == dat)
        {
            flag = 1;
            break;
        }
        temp=temp->next;
    }

    //Check if element not all present
    if(flag == 0)
    {
        return -1;
    }

    temp = *rear;
    flag = 0;
    while(temp->data <= dat || temp!=NULL)
    {
        rr++;
        if(temp->data == dat)
        {
            flag = 1;
            break;
        }
        temp=temp->prev;
    }

    return (fr<=rr?fr:rr);

}

int main()
{
    //Define the pointer that points to the head and rear of linked list
    struct Node *head = NULL;
    struct Node *rear = NULL;

    printf("Welcome\n");
    int choice,temp;
    //Infinite loop that continuously takes in user input
    while(1)
    {
        printf("Enter choice\n1.Insert\n2.Find minimum distance\n3.Display\n4.Exit");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter data\n");
            scanf("%d",&temp);
            insert(&head,&rear,temp);
            break;

        case 2:
            printf("Enter data to be searched\n");
            scanf("%d",&temp);
            int res = minDist(&head,&rear,temp);
            if(res == -1)
            {
                printf("Data not present\n");
            }
            else
            {
                printf("The minimum search distance is %d\n",res);
            }
            break;

        case 3:
            printList(&head);
            break;

        case 4:
            printf("Thank you\n");
            return 0; //Exit from program

        default:
            printf("Wrong input. Please enter again\n");

        }
    }
}
