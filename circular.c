#include<stdio.h>
int rear=-1,front=-1,queue[100],n;
void enq();
void deq();
void display();
void main()
{
int ch;
printf("enter the no. of elements in the queue");
scanf("%d",&n);
do
{
printf("choose an option:\n1.Enqueue\n2.Dequeue\n3.DISPLAY\n");
scanf("%d",&ch);

switch(ch)
{
case 1:enq();
break;
case 2:deq();
break;
case 3:display();
break;
default:printf("no option is selected");
} 

printf("do you want to continue y=1,n=0:\n");
scanf("%d",&ch);
}while(ch==1);

}


void enq()
{
    int item;
    if(rear==n-1 && front==0)
    {
        printf("queue is full!\n");
    }
    else
    {
        printf("enter the element to insert:\n");
        scanf("%d",&item);
        if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
            printf("front=%d\n",front);
            printf("rear=%d\n",rear);
            queue[rear]=item;
        }
        else if(rear==n-1 && front!=0)
        {
            rear=0;
            queue[rear]=item;
        }
        else
        {
        rear=rear+1;
        printf("rear=%d\n",rear);
        queue[rear]=item;
        }
        
    }
    display();
}

void deq()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty!\n");
    }
    else if(front==rear)
    {
        printf("deleted item:%d\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else if(front==n-1 && rear!=0)
    {
        printf("deleted item:%d\n",queue[front]);
        front=0;
    }
    else
    {
        printf("deleted item:%d\n",queue[front]);
        front=front+1;
    }
    display();
}

void display()
{
    printf("elements in queue\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }
}