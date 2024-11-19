#include<stdio.h>
void display(int ar[],int n);
void insert(int ar[],int n);
void delet(int ar[],int n);
void search(int ar[],int n);
void sort(int ar[],int n);
void main()
{
 int cas,n,i,cn;
 printf("enter no of elements:\n");
 scanf("%d",&n);
 int array[n];
 
 printf("enter array elements\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&array[i]);
 }
 do
 {
 printf("1.display.\n2.insertion.\n3.deletion.\n4.searching.\n5.sorting.\n");
 printf("select function:\n");
 scanf("%d",&cas);
 
 switch(cas)
 {
  case 1:display(array,n);
         break;
  case 2:insert(array,n);
         break;
  case 3:delet(array,n);
         break;
  case 4:search(array,n);
         break;
  case 5:sort(array,n);
         break;
  default :printf("no options selected.\n");
  
 }
 printf("do u want to continue:Y=1,N=0\n");
 scanf("%d",&cn);
 }while(cn==1);
}

void display(int ar[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   printf("%d\n",ar[i]);
  }
}

void insert(int ar[],int n)
{
  int i,el,pos,j;
  printf("Enter the element to be inserted:");
  scanf("%d",&el);
  printf("Enter the position:");
  scanf("%d",&pos);
  n=n+1;
  for(i=n-1;i>=pos-1;i--)
  {
     ar[i+1]=ar[i];
  }
  ar[pos-1]=el;
  for(j=0;j<n;j++)
  {
   printf("%d\n",ar[j]);
  }
}

void delet(int ar[],int n)
{ 

  int x,i;
  printf("Enter the position of the element to be deleted:");
  scanf("%d",&x);
  for(i=x;i<=n-1;i++)
  ar[i]=ar[i+1];
  n--;
  for(i=0;i<n;i++)
  printf("%d",ar[i]);
}

void search(int ar[],int n)
{
 int i,el;
 printf("enter the element to search:\n");
 scanf("%d",&el);
 for(i=0;i<=n;i++)
 {
  if(ar[i]!=el)
    continue;
  else
  printf("element found at %d position\n",i+1);
 }
}

void sort(int ar[],int n)
{
 int i,j,temp;
  for(i=0;i<n;i++)
  {
  for(j=0;j<n;j++)
  {
   if(ar[j]>ar[j+1])
   {
    temp=ar[j+1];
    ar[j+1]=ar[j];
    ar[j]=temp;
   }
  }
  }
  for(i=0;i<n;i++)
  {
   printf("%d\n",ar[i]);
  }
}























