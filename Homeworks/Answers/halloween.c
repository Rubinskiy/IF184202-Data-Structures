#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackNode_t
{
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t
{
    StackNode *_top;
    unsigned _size;
} Stack;

void init(Stack *stack);
void stack_push(Stack *stack, int trucks);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
bool stack_isEmpty(Stack *stack);

void init(Stack *stack)
{
    stack->_top = NULL;
    stack->_size = 0;
}

void stack_push(Stack *stack, int trucks)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode)
    {
        stack->_size++;
        newNode->data = trucks;

        if (stack_isEmpty(stack))
            newNode->next = NULL;
        else
            newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack)
{
    if (!stack_isEmpty(stack))
    {
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

bool stack_isEmpty(Stack *stack)
{
    return (stack->_top == NULL);
}

int main()
{
    int n, trucks[101];
    Stack myStack;
    init(&myStack);

    while (scanf("%d", &n) && n != 0)
    {
        int counter = 0, i = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &trucks[i]);
        }
        while (i < n)
        {
            while (!stack_isEmpty(&myStack) && stack_top(&myStack) == counter + 1)
            {
                counter++;
                stack_pop(&myStack);
            }
            if (trucks[i] != counter + 1)
                stack_push(&myStack, trucks[i]);
            else
                counter++;
            i++;
        }
        while (!stack_isEmpty(&myStack) && stack_top(&myStack) == counter + 1)
        {
            counter++;
            stack_pop(&myStack);
        }
        puts(counter == n ? "yes\n" : "no\n");
    }
    return 0;
}