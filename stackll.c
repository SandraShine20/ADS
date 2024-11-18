#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *Next;
} node;

node *top = NULL, *new, *temp, *prev;

void display()
{
    for (temp = top; temp != NULL; temp = temp->Next)
    {
        printf("%d\t", temp->data);
    }
}

void create()
{
    int n;
    printf("Enter Number of elements in stack : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Data : ");
        new = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &new->data);
        new->Next = NULL;
        if (top == NULL)
        {
            top = new;
        }
        else
        {
            new->Next = top;
            top = new;
        }
    }
    display();
}

void insert()
{
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter The data : ");
    scanf("%d", &new->data);
    new->Next = NULL;

    // Top Insert
    if (top == NULL)
    {
        top = new;
    }
    else
    {
        new->Next = top;
        top = new;
    }
    display();
}
void delete()
{
    // Top Delete
    temp = top;
    top = temp->Next;
    display();

    free(temp);
}

void search()
{
    int srch, flag;
    printf("Enter the element to be searched : ");
    scanf("%d", &srch);
    temp = top;
    do
    {
        if (temp->data == srch)
        {
            printf("The data is found in the LinkedList!");
            flag = 1;
            break;
        }
        temp = temp->Next;
    } while (temp != NULL);
    if (flag != 1)
        printf("The Data is Not Found in the LinkedList!");
}
void main()
{
    int c;
    while (1)
    {
        printf("\n1. Create a stack\n2. Display the stack\n3. Insert Elements into the stack\n4. Delete \n5. Search a Data\n6. End\nChoose : ");
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
        case 5:
            search();
            break;
        case 6:
            break;
        default:
            printf("Instructions Unclear");
            break;
        }
        if (c == 6)
            break;
    }
}