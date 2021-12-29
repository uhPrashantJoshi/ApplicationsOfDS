// PROGRAM TO FIND MIN AND MAX PRIME NUMBER IN A SINGLY LINKED LIST
#include <stdio.h>
#include <stdlib.h>
void insert();
void display();
void check();
int checkprime(int);
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int main(int argc, char **argv)
{
    int choice, ele;
    char ch;
    do
    {
        printf("\n1.INSERT\n2.DISPLAY\n3.CHECK\n4.EXIT\n");
        printf("\nENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            /* code */
            check();
            break;
        case 4:
            /* code */
            exit(0);
            break;
        }
    } while (ch!=5);
}

void insert()
{
    struct node *newnode, *temp;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("ENTER THE DATA : ");
    scanf("%d", &item);
    newnode->data = item;
    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}

void display()
{
    struct node *ptr = NULL;
    ptr = head;

    if (ptr == NULL)
    {
        printf("NOTHING TO PRINT\n");
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int checkprime(int ele)
{
    int flag = 0;
    for (int i = 2; i <= ele / 2; ++i)
    {
        if (ele % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0 && ele!=1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void check()
{
    struct node *temp1;
    temp1 = head;
    int small = 999999;
    int large = 0;
    if (head = NULL)
    {
        printf("NO NODES IN THE LIST");
    }
    else
    {
        while (temp1 != NULL)
        {
            if (checkprime(temp1->data))
            {
                if (temp1->data < small)
                {
                    small = temp1->data;
                }
                if (temp1->data > large)
                {
                    large = temp1->data;
                }
            }
            temp1 = temp1->next;
        }
    }
    if(small == 999999 || large == 0)
    {
        printf("\nNO PRIME NUMBER IN THE LIST");
        return;
    }
    printf("\nMINIMUM = %d", small);
    printf("\nMAXIMUM = %d", large);
    printf("\n");
}
