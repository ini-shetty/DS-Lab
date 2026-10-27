
#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

void insert(int ele)
{
    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Queue is Full!\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = ele;
    printf("%d inserted successfully.\n", ele);
}

void dequeue()
{
    int item;

    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }

    item = queue[front];
    printf("Deleted element: %d\n", item);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Circular Queue: ");
    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;
        else if (i == MAX - 1)
            i = 0;
        else
            i++;
    }

    printf("\n");
}

int main()
{
    int ch, value;
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
    while (1)
    {

        printf("Enter your choice: ");

        if (scanf("%d", &ch) != 1)
            return 1;

        switch (ch)
        {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1)
                    return 1;
                insert(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
