/********deleting a node from a Linked list of 5 nodes******/
#include<stdio.h>
#include<stdlib.h>
#define NODES 5

typedef struct node
{
    int data;
    struct node *link;
}sll;


void insert(int data,sll **head);
void display(sll **head);
void delete_node(int pos,sll **head);


int main()
{
    sll *head=NULL;
    int i=0,data,pos;
    
    while(i++ < NODES)
    {
        printf("Enter the data:");
        scanf("%d",&data);
        insert(data,&head);
    }
    display(&head);
    printf("Enter the position to delete the node:");
    scanf("%d",&pos);
    delete_node(pos,&head);
    display(&head);
    
 return 0;   
}

void insert(int data,sll **head)
{
    sll *new=(sll *)malloc(sizeof(sll));
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
        }
        else
        {
        sll *temp=*head;
        while(temp->link != NULL)
        {
            temp=temp->link;
        }
        temp->link=new;
        }
    }
}

void display(sll **head)
{
    sll *temp = *head;
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
     printf("List contains:\n");
     while(temp != NULL)
     {
         printf("%d ",temp->data);
         temp=temp->link;
     }
     printf("\n");
    }
}

void delete_node(int pos,sll **head)
{
    sll *temp = *head, *nextnode;
    int i=1;
    if(*head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        if(pos==1)
        {
            nextnode = *head;
            *head = (*head)->link;
            free(nextnode);
        }
        else
        {
        while(i < pos-1)
        {
            temp = temp->link;
            i++;
        }
        nextnode = temp->link;
        temp->link=nextnode->link;
        free(nextnode);
        }
    }
}



