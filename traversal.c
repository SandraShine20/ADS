#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct tree_node{
    int data;
    struct node* Rchild;
    struct node* Lchild;
} node;


node *root, *new, *temp, *prev;

void main(){
    int num,i,value;
    printf("Enter the number of nodes: ");
    scanf("%d",&num);
    root=(node*)malloc(sizeof(node));
    printf("Enter the root value: ");
    scanf("%d",&root->data);
    root->Lchild=NULL;
    root->Rchild=NULL;

    for(i=0;i<num-1;i++)
    {
        new=(node*)malloc(sizeof(node));
        printf("Enter the value: ");
        scanf("%d",&new->data);
        new->Lchild=NULL;
        new->Rchild=NULL;
        if(new->data < root->data){
            if (root->Lchild==NULL){
                root->Lchild=new;
            }
            else{
                temp=root->Lchild;
                while(temp!=NULL){
                    if(new->data<temp->data){
                        prev=temp;
                        temp=temp->Lchild;
                    }
                    else{
                        prev=temp;
                        temp=temp->Rchild;
                    }
                }
            }
            
        }

        else{
            if (root->Rchild==NULL){
                root->Rchild=new;
            }
            else{
                temp=root->Lchild;
                while(temp!=NULL){
                    if(new->data<temp->data){
                        prev=temp;
                        temp=temp->Lchild;
                    }
                    else{
                        prev=temp;
                        temp=temp->Rchild;
                    }
                }
            }
        }
        }
    }
    
