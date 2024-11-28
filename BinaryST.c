// import header files
#include <stdio.h>
#include <stdlib.h>

// Structure creation for nodes of tree
typedef struct Tree_Node
{
    int data;
    struct Tree_Node *Rchild;
    struct Tree_Node *Lchild;
} node;

// Declaring variables
node *root = NULL, *new, *temp, *prt;
int lim;

// creating a Binary Search Tree
void Create()
{
    // User input for limit
    printf("Enter limit of your Tree : ");
    scanf("%d", &lim);

    // insertion of Nodes
    while (lim > 0)
    {
        {
            // Memory allocation
            new = (node *)malloc(sizeof(node));
            new->Rchild = NULL;
            new->Lchild = NULL;

            printf("Enter your data : ");
            scanf("%d", &new->data);

            // If Root is NULL
            if (root == NULL)
                root = new;

            else
            {
                temp = root;

                // Finding where to Insert the node
                while (temp != NULL)
                {
                    prt = temp;
                    if (temp->data < new->data)
                        temp = temp->Rchild;

                    else
                        temp = temp->Lchild;
                }

                // Insert the node
                if (new->data < prt->data)
                    prt->Lchild = new;
                else
                    prt->Rchild = new;
            }
        }
        lim--;
    }
}

// traversing a Binary Search Tree
// 3 Types : Pre Order, Post Order, In order

void in_order(node *root)
{
    // Function Exit at Null  Root Value
    if (root == NULL)
        return;

    // Traversing the Left Subtree
    in_order(root->Lchild);

    // printing the Value
    printf("%d\t", root->data);

    // Traversing the Left Subtree
    in_order(root->Rchild);
}

void pre_order(node *root)
{
    // temp=root;
    // Function Exit at Null  Root Value
    if (root == NULL)
        return;

    // printing the Value
    printf("%d\t", root->data);

    // Traversing the Left Subtree
    pre_order(root->Lchild);

    // Traversing the Left Subtree
    pre_order(root->Rchild);
}

void post_order(node *root)
{
    // temp=root;
    // Function Exit at Null  Root Value
    if (root == NULL)
        return;

    // Traversing the Left Subtree
    post_order(root->Lchild);

    // Traversing the Left Subtree
    post_order(root->Rchild);

    // printing the Value
    printf("%d\t", root->data);
}

// Insertion
void Insert(root)
{
    new = (node *)malloc(sizeof(node));
    new->Rchild = NULL;
    new->Lchild = NULL;
    printf("Enter the data in the Tree Node : ");
    scanf("%d", &new->data);

    if (root == NULL)
        root=new;

    else
    {
        if(root==NULL)
        return;

        if(new->data > root->data)
        {

        }
    }
}

// Main Function
void main()
{
    int choice;
    while (1)
    {
        printf("\n0. Exit\n1. Create\n2. In Order Traversal\n3. Pre Order Traversal\n4. post Order Traversal\nChoose : \t");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            Create();
            break;
        case 2:
            in_order(root);
            break;
        case 3:
            pre_order(root);
            break;
        case 4:
            post_order(root);
            break;
        default:
            printf("Instructions Unclear!");
            break;
        }
    }
}