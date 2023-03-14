/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
    StackNode *max;
    StackNode *min;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)){ 
            newNode->next = NULL;
            stack->max = newNode;
            stack->min = newNode;
        }
        
        else if(value > stack->max->data){ 
            newNode->next = stack->_top;
            stack->max = newNode;
        }
        else if(value < stack->min->data){
            newNode->next = stack->_top;
            stack->min = newNode;
        }
        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

unsigned stack_max(Stack *stack){
    return stack->max->data;
}

unsigned stack_min(Stack *stack){
    return stack->min->data;
}
int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);
    int n,x;
    char cmd[252];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", cmd);
        
        if(strcmp(cmd, "push")==0){
            scanf("%d", &x);
            stack_push(&myStack, x);
        }
        else if (strcmp(cmd, "pop") == 0) {
            stack_pop(&myStack);
        }
        else if(strcmp(cmd, "top")==0){
            int top = stack_top(&myStack);
            printf("%d", top);
        }
         else if(strcmp(cmd, "min")==0){
            int min = stack_min(&myStack);
            printf("%d", min);
        }
         else if(strcmp(cmd, "max")==0){
            int max = stack_max(&myStack);
            printf("%d", max);
        }
    }
    return 0;
}