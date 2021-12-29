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

// function to insert element at the beginning of the linked list
void insert_beg()
{
    struct node *newnode;
    int item;

    newnode = (struct node *)malloc(sizeof(struct node)); // allocating memory to the new node

    printf("Enter the element tat you would like to insert at the end of the Linked List :");
    scanf("%d", &item);
    // accepting user values

    newnode->data = item;
    newnode->next = NULL;

    if (head == NULL)   // if no node prior
        head = newnode; // created node becomes first
    else
    {
        newnode->next = head;
        head = newnode; // slides the head pointer over to the newly created node and rest of the list is attached after the new node
    }
}

void delete_beg()
{
    int deleted_item;

    if (head == NULL)
        printf("There are no elements to be deleted");
    else if (head->next == NULL)
    {
        deleted_item = head->data;
        head = NULL;
        printf("Deleted item is : %d", deleted_item);
    }
    else
    {
        deleted_item = head->data;
        head = head->next;

        printf("Deleted item is : %d", deleted_item);
    }
}

// function to delete the last element of the list
void delete_end()
{
    int deleted_item;
    struct node *temp;

    if (head == NULL)
        printf("There are no elements to be deleted");

    else if (head->next == NULL)
    {

        deleted_item = head->data;
        head = NULL;
        printf("Deleted item : %d", deleted_item);
    }

    else
    {

        temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        deleted_item = temp->next->data;
        printf("Deleted item from the linked list is : %d", deleted_item);

        temp->next = NULL;
    }
}

void insert_btw()
{
    struct node *newnode, *temp;
    int choice, item, element;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the item : ");
    scanf("%d", &item);

    newnode->data = item;
    newnode->next = NULL;

    printf("Do you want to insert the element before or after an element?\n1.BEFORE\n2.AFTER\n3.GO BACK TO THE MAIN MENU \n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nEnter the element before which you want to insert this item : ");
        scanf("%d", &element);
        temp = head;
        if (head == NULL)
        {
            printf("\n\nThere is no linked list, you will be redirected to create one\n\n");
            insert_beg();
        }
        else if (head->data = element)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            while (temp->next->data != element)
            {
                temp = temp->next;
                if (temp->next = NULL)
                {
                    printf("\n\nelement not found\n\n");
                }
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        break;
    case 2:
        printf("Enter the element after which you want to insert this item : ");
        scanf("%d", &element);

        temp = head;
        if (head == NULL)
        {
            printf("\n\nThere is no linked list, you will be redirected to create one\n\n");
            insert_beg();
        }
        else
        {
            while (temp->data != element)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    printf("Element not found");
                }
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        break;

    default:
        return;
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

void delete_btw()
{
    int ele;
    struct node *temp, *del = NULL;

    printf("Enter the element that is to be deleted form the list : ");
    scanf("%d", &ele);

    if (head == NULL)
    {
        printf("The Linked List is empty, you will be redirected to the menu");
        return;
    }
    else if (head->data == ele)
    {
        printf("Deleted element is : %d\n\n", head->data);
        head = head->next;
    }

    else if (del == NULL)
    {
        printf("\n\nELEMENT NOT FOUND\n\n");
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->next->data = ele)
            {
                del = temp->next;
                temp->next = del->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        printf("Deleted item is %d", ele);
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

void reverse()
{
    struct node *prev, *temp, *next2;
    if (head == NULL)
        printf("There is no list to be reversed bro");
    else if (head->next == NULL)
        printf("There is only one element in the list, hence, reverse not possible bro");

    else
    {
        temp = head;
        while (temp != NULL)
        {
            next2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next2;
        }

        head->next = NULL;
        head = prev;
    }
}

void main()
{
    int ch;

    do
    {

        printf("===========================\nEnter your choice: \n1.INSERT AT THE BEGINNING\n2.INSERT AT THE END\n3.DELETE FIRST ELEMENT\n4.DELETE LAST ELEMENT\n5.DISPLAY\n6.INSERT IN BW\n7.DELETE SELECTED ELEMENT\n8.REVERSE\n9.LAST TO FIRST\n10.EXIT\n===========================\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            delete_beg();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            display();
            break;
        case 6:
            insert_btw();
            break;
        case 7:
            delete_btw();
            break;
        case 8:
            reverse();
            break;
        case 9:
            lastToFirst();
            break;
        default:
            exit(0);
        }

    } while (1);
}
