#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Declare the various structure designs for the respective nodes
    struct leftNode{
    int val;
    struct leftNode *left;
    };

    struct rightNode{
    int val;
    struct rightNode *right;
    };

    struct headNode{
    struct leftNode *left;
    struct rightNode *right;
    };

    //Declare one node of type head
    struct headNode *head=(struct headNode*)malloc(sizeof(struct headNode));
    head->left=NULL;
    head->right=NULL;

    //Start taking input. Take input till '-1' is pressed. Assume first input is always not '-1'
    int n,dir;
    printf("Take input numbers. Press -1 to terminate:\n");
    do{
        scanf("%d",&n);
        if(n!=-1){
            printf("Enter direction:\n");
            scanf("%d",&dir);
            //Create new node as per direction
            //If left direction
            if(dir==0){
                    printf("On left\n");
                struct leftNode *temp=(struct leftNode*)malloc(sizeof(struct leftNode));
                temp->val=n;
                temp->left=NULL;

                //Go to the end of left sub chain
                if(head->left==NULL) //first node
                {
                    head->left=temp;
                }
                else{

                struct leftNode *temp1=(struct leftNode*)malloc(sizeof(struct leftNode));
                temp1=head->left;

                while(temp1->left!=NULL){
                        temp1=temp1->left;

                }
                temp1->left=temp;
                }


            }
            else{ //right direction
                    printf("On right\n");
                struct rightNode *temp=(struct rightNode*)malloc(sizeof(struct rightNode));
                temp->val=n;
                temp->right=NULL;

                //Go to the end of left sub chain
                if(head->right==NULL) //first node
                {
                    head->right=temp;
                }
                else{

                struct rightNode *temp1=(struct rightNode*)malloc(sizeof(struct rightNode));
                temp1=head->right;

                while(temp1->right!=NULL){
                        temp1=temp1->right;

                }
                temp1->right=temp;
                }
            }

            //Take input again
            printf("Take input numbers. Press -1 to terminate:\n");
        }
    }while(n!=-1);

    //Now print the left sub-chain
    printf("Left sub-chain:");
    struct leftNode *l = (struct leftNode*)malloc(sizeof(struct leftNode));
    l=head->left;
    while(l!=NULL){
    printf("%d->",l->val);
    l=l->left;
    }
    printf("NULL\n");

    //Now print the right sub-chain
    printf("Right sub-chain:");
    struct rightNode *r = (struct rightNode*)malloc(sizeof(struct rightNode));
    r=head->right;
    while(r!=NULL){
    printf("%d->",r->val);
    r=r->right;
    }
    printf("NULL\n");


    return 0;
}
