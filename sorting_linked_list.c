/*Program to sort a single linked list in increasing order*/

#include<stdio.h>
#include<stdlib.h>

#define NO_NODES 5

typedef struct node
{
    int data;
    struct node *link;
}sll;


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


void sort_Linkedlist(sll  **head)
{
    sll *temp, *min, *ptr;
    int item;
    if(*head==NULL)
    {
        printf("List isempty\n");
    }
    else
    {
        temp = *head;
        while(temp->link != NULL)
        {
            min = temp;
            ptr = temp->link;
            while(ptr != NULL)
            {
                if(ptr->data < min->data)
                {
                    min = ptr;
                }
                ptr = ptr->link;
            }
            if(temp != min)
            {
                item = temp->data;
                temp->data = min->data;
                min->data = item;
            }
            temp = temp->link;
        }
    }
}

int main()
{
    sll *head=NULL;
    int data,i=0;
    while(i++ < NO_NODES)
    {
    printf("Enter the data:");
    scanf("%d",&data);
    insert(data,&head);
    }
    printf("Before sorting:\n");
    display(&head);
    sort_Linkedlist(&head);
    printf("After sorting:\n");
    display(&head);
    
    return 0;
}







