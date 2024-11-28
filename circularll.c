#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *Next;
} node;

node *head = NULL, *new, *current, *temp, *tail, *dlt;

void create()
{
    int n;
    printf("Enter Number of Nodes : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Data : ");
        new = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &new->data);
        new->Next = NULL;
        if (head == NULL)
        {
            head = new;
            tail = new;
            current = new;
            new->Next = new;
        }
        else
        {
            current->Next = new;
            current = new;
            tail = new;
            new->Next = head;
        }
    }
}

void display()
{
    temp = head;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->Next;
    } while (temp != head);
}

void insert()
{
    int c;
    printf("Data to be inserted \n1. At the Top\n2. At the Bottom\n3. In Between\nChoose(1/2/3): ");
    scanf("%d", &c);
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter The data : ");
    scanf("%d", &new->data);
    new->Next = NULL;
    if (c == 1)
    {
        // Top Insert
        if (head == NULL)
        {
            head = new;
            tail = new;
            current = new;
            new->Next = new;
        }
        else
        {
            new->Next = head;
            head = new;
            tail->Next = new;
        }
        display();
    }
    else if (c == 2)
    {
        // Bottom Insert
        if (head == NULL)
        {
            head = new;
            tail = new;
            current = new;
            new->Next = new;
        }
        else
        {
            new->Next = tail->Next;
            current->Next = new;
            current = new;
            tail = new;
        }
        display();
    }
    else
    {
        // Between insert
        int element, pos;
        printf("enter the element position : ");
        scanf("%d", &pos);

        if (head == NULL)
        {
            head = new;
            tail = new;
            current = new;
            new->Next = new;
        }
        else
        {
            temp = head;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->Next;
            }

            if (temp->Next == NULL)
            {
                temp->Next = new;
                current = new;
            }
            else
            {

                new->Next = temp->Next;
                temp->Next = new;
            }
        }
        display();
    }
}
void delete()
{
    int c, p;
    printf("Data to be Deleted \n1. From the Top\n2. From the Bottom\n3. In Between\nChoose(1/2/3): ");
    scanf("%d", &p);
    if (p == 1)
    {
        // Top Delete
        dlt = head;
        tail->Next = head->Next;
        head = head->Next;
        display();
    }
    else if (p == 2)
    {
        // Bottom Delete
        dlt = tail;
        temp = head;
        while (temp->Next->Next != head)
        {
            temp = temp->Next;
        }
        temp->Next = tail->Next;
        tail = temp;
        current = temp;
        display();
    }
    else
    {

        // Between Delete
        printf("enter the position of element which u have to delete the element : ");
        scanf("%d", &p);

        temp = head;

        if (head == NULL)
        {
            printf("no elements in linked list\n");
        }
        else
        {
            for (int i = 1; i < p - 1; i++)
            {
                temp = temp->Next;
            }

            if (temp->Next == head)
            {
                dlt = temp;
                head = NULL;
                tail = NULL;
            }
            else if (temp->Next == tail)
            {
                dlt = tail;
                temp->Next = tail->Next;
                tail = temp;
                current = temp;
            }
            else
            {
                dlt = temp->Next;
                temp->Next = dlt->Next;
            }
            display();
        }
    }

    free(dlt);
}

void search()
{
    int srch, flag;
    printf("Enter the element to be searched : ");
    scanf("%d", &srch);
    temp = head;
    do
    {

        if (temp->data == srch)
        {
            printf("%d", *temp);
            printf("The data is found in the LinkedList!");
            flag = 1;
            break;
        }
        temp = temp->Next;
    } while (temp->Next != head);
    if (flag != 1)
        printf("The Data is Not Found in the LinkedList!");
}
void main()
{
    int c;
    while (1)
    {
        printf("\n1. Create a LL\n2. Display the LL\n3. Insert Elements into the LL\n4. Delete \n5. Search a Data\n6. End\nChoose : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 6:
            break;
        case 5:
            search();
            break;
        default:
            printf("Instructions Unclear");
            break;
        }
        if (c == 6)
            break;
    }
}