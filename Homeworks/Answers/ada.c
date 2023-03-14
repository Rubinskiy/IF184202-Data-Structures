#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int outputs[10000];

// add integer to array outputs
void addOutput(int data)
{
    int i = 0;
    while (outputs[i] != 0)
    {
        i++;
    }
    outputs[i] = data;
}

// print the outputs array
void printOutput()
{
    int i = 0;
    while (outputs[i] != 0)
    {
        if (outputs[i] == 101)
        {
            printf("No Job For Ada?");
        }
        else
        {
            printf("%d", outputs[i]);
        }
        if (outputs[i + 1] != 0)
        {
            printf("\n");
        }
        i++;
    }
}

// make the queue using arrays
int queue[1000001];
int head = 0;
int tail = 0;

// function to push back
void pushBack(int data)
{
    queue[tail] = data;
    tail++;
}

// function to push front
void pushFront(int data)
{
    for (int i = tail; i > head; i--)
    {
        queue[i] = queue[i - 1];
    }
    queue[head] = data;
    tail++;
}

// function to pop back
void popBack()
{
    if (head == tail)
    {
        addOutput(101);
    }
    else
    {
        addOutput(queue[tail - 1]);
        tail--;
    }
}

// function to pop front
void popFront()
{
    if (head == tail)
    {
        addOutput(101);
    }
    else
    {
        addOutput(queue[head]);
        head++;
    }
}

// function to reverse the queue
void reverse()
{
    int temp;
    for (int i = 0; i < (tail - head) / 2; i++)
    {
        temp = queue[head + i];
        queue[head + i] = queue[tail - 1 - i];
        queue[tail - 1 - i] = temp;
    }
}

int main()
{
    int testcase;
    scanf("%d", &testcase);
    char command[10];
    int data;
    for (int i = 0; i < testcase; i++)
    {
        scanf("%s", command);
        if (strcmp(command, "back") == 0)
        {
            popBack();
        }
        else if (strcmp(command, "front") == 0)
        {
            popFront();
        }
        else if (strcmp(command, "reverse") == 0)
        {
            reverse();
        }
        else if (strcmp(command, "push_back") == 0)
        {
            scanf("%d", &data);
            pushBack(data);
        }
        else if (strcmp(command, "toFront") == 0)
        {
            scanf("%d", &data);
            pushFront(data);
        }
    }
    printOutput();
    return 0;
}