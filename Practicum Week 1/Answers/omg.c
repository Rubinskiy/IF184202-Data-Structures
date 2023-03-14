#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    //! StackNode newNode = (StackNode) malloc(sizeof(StackNode));
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    //when using malloc, declare [newNode] as a pointer, which points to the location that is going to be cleared with malloc
    //use (StackNode*) to specify that the pointer assigned is to point to a StackNode data type

    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

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

int main() {
    Stack stacky;
    stack_init(&stacky);

    int n, m;
    char command[100] = { 0 };
    //! always pre-initialize strings, because any unitialized element will result
    //! in a flag. (WRN: C6054. Sting might not be zero-terminated)

    // scanf for n
    int output[100] = { 0 };

    scanf(" %d", &n);
    int counter = 0;

    for (int i = 0; i < n; i++) {

        // scanf for command
        scanf(" %s", command);
        //! somehow, in the compiler, receiving any whitespace results in a flag
        
        if (strcmp(command, "Clue") == 0) {
            stack_push(&stacky, 1);
            counter++;
        } else if (strcmp(command, "No") == 0) {
            scanf(" %s", command);
            //scanning "Clue"

            stack_push(&stacky, 0);
        }
    }

    // scanf for m
    scanf(" %d", &m);

    for (int i = 0; i < m; i++) {

        scanf(" %s", command);
        //! somehow, in the compiler, receiving any whitespace results in a flag

        if (strcmp(command, "Out") == 0) {
            int topNum = stack_top(&stacky);
            if (topNum == 1) {
                output[i] = 0;
                counter--;
            }
            else if (topNum == 0) {
                output[i] = -1;
            }
            stack_pop(&stacky);
        } else if (strcmp(command, "Count") == 0) {
            scanf(" %s", command);
            //scanning "them"

            if (counter >= 5) { 
                output[i] = 1;
            } else {
                output[i] = 2;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        if (output[i] == -1) {
            continue;
        }
        else if (output[i] == 0) {
            printf("I'm going crazy, right?\n");
        }
        else if (output[i] == 1) {
            printf("He's the one that's living in my system\n");
        }
        else if (output[i] == 2) {
            printf("They keep on asking me, \"Who is he?\"\n");
        }
    }
    return 0;
}
