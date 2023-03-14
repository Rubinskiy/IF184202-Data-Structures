#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000000

int queue[MAX_SIZE];
int front = 0, rear = 0;

void enqueue(int x)
{
    if (rear == MAX_SIZE)
    {
        printf("Queue is full.\n");
        exit(1);
    }
    queue[rear++] = x;
}

void dequeue()
{
    if (front == rear)
    {
        return; // empty queue
    }
    front++;
}

int front_elem()
{
    if (front == rear)
    {
        printf("Empty!\n");
        exit(1);
    }
    return queue[front];
}

int main()
{
    int t, query, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &query);
        switch (query)
        {
        case 1:
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("%d\n", front_elem());
            break;
        }
    }
    return 0;
}