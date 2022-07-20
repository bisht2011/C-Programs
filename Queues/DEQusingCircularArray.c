#include <stdio.h>
#include <stdlib.h>
#define size 5
int deque[size];
int f = -1, r = -1;

void EnqueFront(int x);
void EnqueRear(int x);
void DequeFront();
void DequeRear();
void display();
int main()
{
    int menu = 1;
    int choice;
    int num;
    while (menu == 1)
    {
        printf("enter the choice\n 1.EnqueFront 2.EnqueRear 3.display 4.DequeFront 5.DequeRear 6.exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the value u want to enter");
            scanf("%d", &num);
            EnqueFront(num);
            break;
        case 2:
            printf("enter the value u want to enter");
            scanf("%d", &num);
            EnqueRear(num);
            break;

        case 3:
            display();
            break;
        case 4:
            DequeFront();

            break;
        case 5:
            DequeRear();
            break;
        case 6:
            printf("thankyou");
            menu = 2;
            break;
        }
    }
    return 0;
}

//  insert_front function will insert the value from the front
void EnqueFront(int x)
{
    if ((f == 0 && r == size - 1) || (f == r + 1))
    {
        printf("Overflow");
    }
    else if ((f == -1) && (r == -1))
    {
        f = r = 0;
        deque[f] = x;
    }
    else if (f == 0)
    {
        f = size - 1;
        deque[f] = x;
    }
    else
    {
        f = f - 1;
        deque[f] = x;
    }
}

// insert_rear function will insert the value from the rear
void EnqueRear(int x)
{
    if ((f == 0 && r == size - 1) || (f == r + 1))
    {
        printf("Overflow");
    }
    else if ((f == -1) && (r == -1))
    {
        f = r = 0;
        deque[r] = x;
    }

    else
    {
        r = (r + 1) % size;
        deque[r] = x;
    }
}

// display function prints all the value of deque.
void display()
{
    int i = f;
    while (i != r)
    {
        printf("elements are: %d\n", deque[i]);
        i = (i + 1) % size;
    }
    printf("elements are: %d\n", deque[i]);
}

// getfront function retrieves the first value of the deque.
void getfront()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else
    {
        printf("\nThe value of the element at front is: %d", deque[f]);
    }
}

// getrear function retrieves the last value of the deque.
void getrear()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else
    {
        printf("\nThe value of the element at rear is %d", deque[r]);
    }
}

// delete_front() function deletes the element from the front
void DequeFront()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else if (f == r)
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = -1;
        r = -1;
    }
    else
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = (f + 1) % size;
    }
}

// delete_rear() function deletes the element from the rear
void DequeRear()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else if (f == r)
    {
        printf("\nThe deleted element is %d", deque[r]);
        f = -1;
        r = -1;
    }
    else
    {
        printf("\nThe deleted element is %d", deque[r]);
        r = (r + 1) % size;
    }
}