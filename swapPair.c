    // PROGRAM TO SWAP ELEMENTS PAIRWISE
    #include <stdio.h>
    #include <stdlib.h>
    void insert();
    void display();
    void swap();
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
            printf("\n1.INSERT\n2.DISPLAY\n3.SWAP\n4.EXIT\n");
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
                swap();
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

    void swap()
    {
        struct node *temp1, *temp2;
        int temp;
        //temp1 for pointing to previous element
        //temp2 for pointing to next element
        if (head == NULL)
        {
            printf("NO NODES IN THE LIST");
        }
        else
        {
            temp1 = head; //points to first element in the list initially
            do
            {
                /* code */
                temp2 = temp1->next; //points to second element in the list for first loop
                //for swapping
                temp = temp1->data;    
                temp1->data = temp2->data;
                temp2->data = temp;
                //end of swpping
                if (temp2->next != NULL)
                {
                    temp1 = temp1->next->next;
                }
                else
                {
                    break;
                }
            } while (temp1->next!=NULL);
        }
    }
