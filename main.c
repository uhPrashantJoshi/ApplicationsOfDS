#include <stdio.h>
#include <stdlib.h>
// creation of structure node of the linked list
struct node
{
    int data;
    struct node *next;
};

// assigning the head position to nothing
struct node *head = NULL;

// function to insert element at the end of the linked list
void insert_end()
{
    struct node *temp, *newnode;
    // initialization of node pointers
    int item;

    newnode = (struct node *)malloc(sizeof(struct node));
    // allocating memory for the new node

    printf("Enter the element tat you would like to insert at the end of the Linked List :");
    scanf("%d", &item);
    // accepting user data

    newnode->data = item;
    newnode->next = NULL;

    if (head == NULL)   // no element present prior
        head = newnode; // create assign head to the newly created node
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}


void lastToFirst()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("List is empty!!");
        return;
    }
    else if (head->next == NULL)
    {
        printf("Only one element!!");
        return;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next->next = head;
        head = temp->next;
        temp->next = NULL;

        return;
    }
}


void display()
{
    printf("Elements are : ");

    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    int ch;

    do
    {

        printf("===========================\nEnter your choice: \n1.INSERT AT THE END\n2.DISPLAY\n6.INSERT IN BW\n3.LAST TO FIRST\n4.EXIT\n===========================\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_end();
            break;
        case 2:
            display();
            break;
        case 3:
            lastToFirst();
            break;
        default:
            exit(0);
        }

    } while (1);
}
