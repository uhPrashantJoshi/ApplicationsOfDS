// PROGRAM TO FREQUENCY OF EACH ELEMENT
#include <stdio.h>
#include <stdlib.h>
void insert();
void display();
void checkFreq();
int count[100];
int element[100];
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
        printf("\n1.INSERT\n2.DISPLAY\n3.CHECK FREQ\n4.EXIT\n");
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
            checkFreq();
            break;
        case 4:
            /* code */
            exit(0);
            break;
        }
    } while (ch != 5);
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

void checkFreq()
{
    struct node *temp1, *temp2;
    int c = 0, i = 0, flag = 0, ele;
    temp1 = head;
    if (head == NULL)
    {
        printf("NO NODES IN THE LIST");
    }
    else
    {
        while (temp1 != NULL)
        {
            flag = 0;
            temp2 = temp1->next;
            for (int k = 0; k <= i; k++)
            {
                if (temp1->data == element[k])
                {
                    flag = 1;
                    break;
                }
            }
            if (temp2 != NULL )
            {
                if (flag == 0)
                {
                    do
                    {
                        if (temp1->data == temp2->data)
                        {
                            c++;
                        }
                        temp2 = temp2->next;
                    } while (temp2 != NULL);
                    element[i] = temp1->data;
                    count[i] = c + 1;
                    c = 0;
                    i++;
                }
            }
            else if(flag == 0)
            {
                element[i] = temp1->data;
                count[i] = c + 1;
                c = 0;
                i++;
            }

            temp1 = temp1->next;
        }
        for (int j = 0; j <= i - 1; j++)
        {
            printf("Freq(%d) = %d\n",element[j],count[j]);
        }
    }
}
