#include <stdio.h>
#include <stdlib.h>
int ispresent(int ar[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (ar[i] == element)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
void display(int set[], int size)
{
    printf("set:{");
    for (int i = 0; i < size; i++)
    {
        printf("%d,", set[i]);
    }
    printf("}\n");
}
int main()
{
    int element, n, n1, n2;
    printf("enter the no of element in universal set:\n");
    scanf("%d", &n);
    int uniset[n];

    for (int i = 0; i < n; i++)
    {
        printf("enter the universal set element:\n");
        scanf("%d", &element);
        if (ispresent(uniset, n, element) == 1)
        {
            i--;
            printf("element already exists!\n");
        }
        else
        {
            uniset[i] = element;
        }
    }
    display(uniset, n);

    printf("enter the no of element in set1:\n");
    scanf("%d", &n1);
    printf("enter the no of element in set2:\n");
    scanf("%d", &n2);
    int set1[n1], set2[n2];
    if (n1 > n || n1 < 0)
        printf("size of set1 in greater than universal set! or invalid size \n");
    else
    {
        for (int i = 0; i < n1; i++)
        {
            printf("enter the set element:\n");
            scanf("%d", &element);
            if (ispresent(set1, n1, element) == 0 && ispresent(uniset, n, element) == 1)
            {
                set1[i] = element;
            }
            else
            {
                printf("element must not repeat and should be in the universal set\n");
                i--;
            }
        }
        display(set1, n1);
    }
}