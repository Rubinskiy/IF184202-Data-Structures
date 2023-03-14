#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// make a queue program where the first line of input contains 10^6 queries, each of them contains the following commands:
// back - print the number from the back and then erase it
// front - print the number from the front and then erase it
// reverse - reverse all the elements in the array
// push_back N - add element N to the back
// toFront N - add element N to the front
// all numbers (N) will be between 0 and 100
// for each back and front query print the appropriate number
// check everytime if the queue is empty and if it is, print "No Job For Ada?"

char outputs[10000];

// node struct
typedef struct Queue_t{
    int data;
    struct Queue_t *next;
}Queue;

// global variable
Queue *head = NULL;
Queue *tail = NULL;

// function to create a new node
Queue *createNode(int data){
    Queue *newNode = (Queue *)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to push back
void pushBack(int data){
    Queue *temp = createNode(data);
    if(!head){
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// function to push front
void pushFront(int data){
    Queue *temp = createNode(data);
    if(!head){
        head = tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

// function to pop back
void popBack(){
    if(!head){
        printf("No Job For Ada?");
    } else if(head == tail){
        printf("%d", head->data);
        free(head);
        head = tail = NULL;
    } else {
        Queue *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        printf("%d", tail->data);
        free(tail);
        tail = temp;
        tail->next = NULL;
    }
}

// function to pop front
void popFront(){
    if(!head){
        printf("No Job For Ada?");
    } else if(head == tail){
        printf("%d", head->data);
        free(head);
        head = tail = NULL;
    } else {
        Queue *temp = head->next;
        printf("%d", head->data);
        free(head);
        head = temp;
    }
}

// function to reverse the queue
void reverse(){
    if(!head){
        printf("No Job For Ada?");
    } else if(head == tail){
        printf("%d", head->data);
        free(head);
        head = tail = NULL;
    } else {
        Queue *curr = head;
        Queue *prev = NULL;
        Queue *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail = head;
        head = prev;
    }
}

// function to print the queue
void printQueue(){
    Queue *curr = head;
    while(curr){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("%d", curr->data);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char command[10];
        scanf("%s", command);
        if(strcmp(command, "back") == 0){
            popBack();
        } else if(strcmp(command, "front") == 0){
            popFront();
        } else if(strcmp(command, "reverse") == 0){
            reverse();
        } else if(strcmp(command, "push_back") == 0){
            int data;
            scanf("%d", &data);
            pushBack(data);
        } else if(strcmp(command, "push_front") == 0){
            int data;
            scanf("%d", &data);
            pushFront(data);
        }
    }
    return 0;
}