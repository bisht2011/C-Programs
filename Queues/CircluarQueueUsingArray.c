#include <stdio.h>
#define max 6
int queue[max];
int front = -1, rear = -1;

void enque(int x);
void deque();
void display();
int main()
{
    int menu = 1;
    int choice;
    int num;
    while (menu == 1)
    {
        printf("enter the choice\n 1.enque 2.deque 3.display 4.exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the value u want to enter");
            scanf("%d", &num);
            enque(num);
            break;
        case 2:
            deque();
            break;

        case 3:
            display();
            break;
        case 4:
            printf("thankyou");
            menu = 2;
            break;
        }
    }
    return 0;
}
void enque(int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % max == front)
    {
        printf("overflow");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = x;
    }
}
void deque()
{
    if (front == -1 && rear == -1)
    {
        printf("underflow");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("deleted item %d\n", queue[front]);
        front = (front + 1) % max;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty..");
    }
    else
    {
        printf("\nElements in a Queue are :\n");
        while (i != rear)
        {
            printf("data: %d\n", queue[i]);
            i = (i + 1) % max;
        }
        printf("data: %d\n", queue[i]);
    }
}