#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *Next;
} node;

node *top = NULL, *new, *temp, *prev;
int n;

void display()
{
    for (temp = top; temp != NULL; temp = temp->Next)
    {
        printf("%d\t", temp->data);
    }
}

void create()
{
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

int underflow()
{
    return (top == NULL) ? 1 : 0;
}

int Overflow()

{
    int count = 0;
    temp = top;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }
    return (count == n) ? 1 : 0;
}
void insert()
{
    if (Overflow()==1)
    {
    printf("stack overflow\n");
    }
    else
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
}
void delete()
{
    if (underflow() == 1)
    {
        printf("Stack Underflow\n");

    }
    else{
    // Top Delete
    temp = top;
    top = temp->Next;
    display();

    free(temp);
    }
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
            printf("The data is found in the stack!");
            flag = 1;
            break;
        }
        temp = temp->Next;
    } while (temp != NULL);
    if (flag != 1)
        printf("The Data is Not Found in the stack!");
}

void main()
{
    int c;
    while (1)
    {
        printf("\n0. Exit\n1. Create a stack\n2. Display the stack\n3. Insert Elements into the stack\n4. Delete \n5. Search a Data\nChoose : ");
        scanf("%d", &c);
        if (c == 0)
            break;
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
        default:
            printf("Instructions Unclear");
            break;
        }
        if (c == 6)
            break;
    }
}