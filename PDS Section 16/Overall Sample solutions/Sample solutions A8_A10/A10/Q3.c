//This code is kept on the simpler side. For maintaining the sorted linked list, you can refer to Q1 of A10.

#include <stdio.h>
#include <stdbool.h>

#include <math.h>

#define MAX_PRICE 5000

typedef struct NestedBucket NestedBucket;
typedef struct Bucket Bucket;

struct NestedBucket {
    NestedBucket *next;
    int item_id;
    int price;


};

struct Bucket {
    Bucket *next;

    NestedBucket *nested_list;

    int range;
};


void print_list(Bucket *head) {
    if(head == NULL) {
        printf("Bucket is empty");
    } 
    Bucket *current = head;

    // iterate through each bucket
    while(current != NULL) {
        printf("Bucket %d:\n", current->range/500);
        printf("Lower Limit: %d", current->range-499);
        printf("Upper Limit: %d", current->range);

        printf("Items:");

        NestedBucket *list = current->nested_list;
        // iterate through each node in the nested Bucket
        while(list!=NULL){
            printf("(%d,%d)", list->item_id, list->price);
        }

        current = current->next;
        printf("\n");	
    }
}

void insert(Bucket *head, int itemID, int Price) {
    int ceil_price = ceil(Price / 500); // ceil of the price divided by 500
    

    Bucket *current = head;
    // find the bucket which has the following ceil value
    while (ceil_price != current->range / 500);
    {
        current = current->next;
    }
    
    NestedBucket *nested_head = current-> nested_list; // create a temp variable for the nested list head

    NestedBucket *new_node = (struct NestedBucket*) malloc(sizeof(struct NestedBucket)); // create a new nested list node

    new_node->item_id = itemID; // set its id 
    new_node->price = Price; // set its price
    new_node->next = NULL; // set the next element
    
    // add the new node to the nested Bucket
    if (nested_head == NULL) {
        nested_head  = new_node;
    }else {
        while(nested_head->next != NULL) {
            nested_head = nested_head->next;
        }
        nested_head->next = new_node;
    }
    

}


int main() {
    Bucket *head = NULL;
    Bucket *current = head;

    // add bucket nodes to the head for all ranges till MAX_PRICE
    for(int i=0;i<MAX_PRICE/500;i++){
        // create a new bucket 
        Bucket *new_node = (struct Bucket*) malloc(sizeof(Bucket));
        
        // initialise nested list as NULL and range for the bucket
        new_node->nested_list = NULL;
        new_node-> range = (i+1) * 500; 
        new_node->next = NULL;
        
        // form a linked list of bucket nodes
        if(current == NULL){
            head = new_node;
            current = new_node;
        }else {
            current->next = new_node;
            current = new_node;
        }
    }

    printf("Please enter the information requested:");

    bool t = true;
    int id, price;

    int c;
    while(t) {
        // take user input of item id and price
        printf("Please enter item id and price: \n");
        scanf("%d %d", &id, &price);
        
        // add it to the bucket using insert function 
        insert(head, id, price);
        
        // ask user if they want to enter more numbers
        printf("Please enter 0 to exit or 1 to continue: \n");
        scanf("%d", &c);

        if (c){
            t = false; // breal the while look if 0 is entered
        } 
    }

    print_list(head); // print the list with head

    return 0;
}