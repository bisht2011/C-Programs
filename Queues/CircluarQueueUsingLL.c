#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
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
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}
void deque()
{
    struct node *temp;
    temp = front;
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is empty");
    }
    else if (front == rear) // checking whether the single element is left in the queue
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        printf("deleted data: %d\n", temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = front;
    printf("\n The elements in a Queue are : \n");
    if ((front == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
    }

    else
    {
        while (temp->next != front)
        {
            printf("data:%d\n", temp->data);
            temp = temp->next;
        }
        printf("data:%d\n", temp->data);
    }
}