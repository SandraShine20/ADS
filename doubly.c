#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *Next;
} node;

node *head = NULL, *tail = NULL, *new, *current, *temp, *prev;

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
        new->prev = NULL;
        if (head == NULL)
        {
            head = new;
            tail = new;
            current = new;
        }
        else
        {

            current->Next = new;
            new->prev = current;
            tail = new;
            current = new;
        }
    }
}

void display()
{
    for (temp = head; temp != NULL; temp = temp->Next)
    {
        printf("%d\t", temp->data);
    }
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
    new->prev = NULL;
    if (c == 1)
    {
        // Top Insert
        if (head == NULL)
        {
            head = new;
            tail = new;
            current = new;
        }
        else
        {

            head->prev = new;
            new->Next = head;
            head = new;
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
        }
        else
        {
            current->Next = new;
            new->prev = current;
            tail = new;
            current = new;
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
        }
        else
        {
            temp = head;
            for (int i = 1; i < pos; i++)
            {
                temp = temp->Next;
            }

            if (temp->Next == NULL)
            {
                temp->Next = new;
                new->prev = temp;
                tail = new;
                current = new;
            }
            else
            {

                temp->prev->Next = new;
                new->Next = temp;
                new->prev = temp->prev;
                temp->prev = new;
            }
        }
        display();
    }
}
void delete()
{
    int c, p;
    printf("Data to be Deleted \n1. From the Top\n2. From the Bottom\n3. In Between\nChoose(1/2/3): ");
    scanf("%d", &c);
    if (c == 1)
    {
        // Top Delete
        temp = head;
        head->Next->prev = NULL;
        head = head->Next;
        display();
    }
    else if (c == 2)
    {
        // Bottom Delete
        temp = tail;
        tail->prev->Next = NULL;
        tail = tail->prev;
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
            for (int i = 1; i < p; i++)
            {
                temp = temp->Next;
            }

            if (temp == head)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                temp->prev->Next = temp->Next;
                temp->Next->prev = temp->prev;
            }
            display();
        }
    }

    free(temp);
}

void search()
{
    int srch, flag=0;
    printf("Enter the element to be searched : ");
    scanf("%d", &srch);
    temp = head;
    do
    {
        if (temp->data == srch)
        {
            printf("The data is found in the LinkedList!");
            flag = 1;
            break;
        }
        temp = temp->Next;
    } while (temp != tail);
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