#include <stdio.h>

void main()
{
    int size, ch;
    printf("Enter no of Vertices : ");
    scanf("%d", &size);

    int edge[size][size];
    int vertex[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter the vertex : ");
        scanf("%d", &vertex[i]);
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            edge[i][j]=edge[j][i]=0;
            printf("enter do you want edge between (%d,%d)\n1:yes 2.No:", vertex[i], vertex[j]);
            scanf("%d", &ch);
            if (ch == 1)
            {
                printf("enter the weight of (%d,%d) : ", vertex[i], vertex[j]);
                scanf("%d", &edge[i][j]);
                edge[j][i]=edge[i][j];
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d : ",vertex[i]);
        for (int j = 0; j < size; j++)
        {
            if (edge[i][j]!=0)
            {
                printf("%d ",vertex[j]);
            }
        }
        printf("\n");
    }
}