#include <stdio.h>
#define MAX 4
int queue[MAX];
int front = -1, rear = -1;
int main()
{
    int choice, value, i;

        printf("\n--- LINEAR QUEUE ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (rear == MAX - 1)
                {
                    printf("Queue Overflow!\n");
                }
                else
                {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    if (front == -1)
                        front = 0;
                    rear++;
                    queue[rear] = value;

                    printf("Inserted successfully.\n");
                }
                break;

            case 2:

                if (front == -1 || front > rear)
                {
                    printf("Queue Underflow!\n");
                }
                else
                {
                    printf("Deleted element: %d\n", queue[front]);
                    front++;

                    if (front > rear)
                    {
                        front = -1;
                        rear = -1;
                    }
                }
                break;

            case 3:
                  if (front == -1)
                {
                    printf("Queue is Empty!\n");
                }
                else
                {
                    printf("Queue elements: ");
                    for (i = front; i <= rear; i++)
                    {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
