#include <stdio.h>

int n, n1 = 0, n2 = 0;
void clearset(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = 0;
}

int ispresent(int arr[], int size, int ele)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {

        if (arr[i] == ele)
        {
            flag = 1;
            return 1;
        }
    }
    if (flag == 0)
        return 0;
}

void display(int set[], int size)
{
    printf("set:{");
    for (int i = 0; i < size; i++)
    {
        printf("%d", set[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("}\n");
}

void makeSet(int uniset[], int set[], int n,int bitstr[])
{
    
    clearset(bitstr, n);
    for (int i = 0; i < n; i++)
    {
        if (ispresent(set, n, uniset[i]) == 1)
        {
            bitstr[i] = 1;
        }
        else
        {
            bitstr[i] = 0;
        }
    }
}

void Union(int set1[], int set2[], int n)
{
    int uni[n];
    for(int i=0;i<n;i++)
    {
        if(set1[i]==0 && set2[i]==0)
        {
            uni[i]=0;
        }
        else
        {
            uni[i]=1;
        }
    }
    printf("UNION ");
    display(uni,n);
}

void Intersec(int set1[], int set2[], int n,int inter[n])
{
    for(int i=0;i<n;i++)
    {
        if(set1[i]==1 && set2[i]==1)
        {
        inter[i]=1;
        }
        else
        {
            inter[i]=0;
        }
    }
}

void Diff(int set1[],int n,int inter[])
{
    int diff[n];
    for(int i=0;i<n;i++)
    {
        if(set1[i]==inter[i])
        {
            diff[i]=0;
        }
        else{
            diff[i]=1;
        }
    }
    printf("DIFFERENCE ");
    display(diff,n);
}


int main()
{
    int element, flag;
    printf("Enter No of elements in Universal Set : ");
    scanf("%d", &n);
    int universal[n], bitstr1[n], bitstr2[n];
    clearset(universal, n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter your %dth element : ", i + 1);
        scanf("%d", &element);

        if (ispresent(universal, n, element) == 0)
            universal[i] = element;
        else
        {
            printf("Sorry, Cant allow Duplicated values!\n");
            i--;
        }
    }

    printf("Enter No of elements in Set 1 : ");
    scanf("%d", &n1);
    int Set1[n1];
    if (n1 > n || n1 < 0)
        printf("size of set1 in greater than universal set! or invalid size \n");
    else
    {

        for (int i = 0; i < n1; i++)
        {
            printf("Enter your %dth element : ", i + 1);
            scanf("%d", &element);

            if (ispresent(Set1, n1, element) == 0 && ispresent(universal,n,element)==1)
                Set1[i] = element;
            else
            {
                printf("Sorry, Cant allow Duplicated values!\n");
                i--;
            }
        }
    }

    printf("Enter No of elements in Set 2 : ");
    scanf("%d", &n2);
    int Set2[n2];
    if (n2 > n || n2 < 0)
        printf("size of set2 in greater than universal set! or invalid size \n");
    else
    {

        for (int i = 0; i < n2; i++)
        {
            printf("Enter your %dth element : ", i + 1);
            scanf("%d", &element);

            if (ispresent(Set2, n2, element) == 0 && ispresent(universal,n,element)==1)
                Set2[i] = element;
            else
            {
                printf("Sorry, Cant allow Duplicated values!\n");
                i--;
            }
        }
    }

    printf("Universal ");
    display(universal, n);
    printf("1st ");
    display(Set1, n1);
    printf("2nd ");
    display(Set2, n2);



    printf("Bistring of 1st ");
    makeSet(universal, Set1, n,bitstr1);
    display(bitstr1,n);

    printf("Bitstring of 2nd ");
    makeSet(universal, Set2, n,bitstr2);
    display(bitstr2,n);

    int inter[n];
    Union(bitstr1,bitstr2,n);
    Intersec(bitstr1,bitstr2,n,inter);
    printf("INTERSECTION ");
    display(inter,n);
    Diff(bitstr1,n,inter);
}
