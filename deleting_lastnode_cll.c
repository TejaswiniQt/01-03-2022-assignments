/***********Removing last node from circular LL*******/

#include<stdio.h>
#include<stdlib.h>

#define NODES 5

typedef struct node
{
    int data;
    struct node *link;
}cll;



void insert(int data,cll **head)
{
    cll *temp;
    cll *new=(cll *)malloc(sizeof(cll));
    if(new==NULL)
    {
        printf("Memory is not allocated\n");
    }
    else
    {
        new->data=data;
        new->link=NULL;
    if(*head==NULL)
    {
        *head=new;
        temp=new;
    }
    else
    {
       temp->link = new;
       temp = new;
    }
    temp->link = *head;
  }
}

void display(cll **head)
{
    cll *temp=*head;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("List contains:\n");
        while(temp->link != *head)
        {
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("%d ",temp->data);
        printf("\n");
    }
}


void deleting_lastnode(cll **head)
{
    cll *temp = *head, *delete;
    if(*head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp->link->link != *head)
        {
            temp=temp->link;
        }
        delete=temp->link;
        temp->link = *head;
        printf("Deleted node is: %d\n",delete->data);
        delete->link=NULL;
        free(delete);
    }
}

int main()
{
    cll *head=NULL;
    int data,i=0;
    while(i++ < NODES)
    {
    printf("Enter the data:");
    scanf("%d",&data);
    insert(data,&head);
    }
    display(&head);
    deleting_lastnode(&head);
    display(&head);
    
    return 0;
}
