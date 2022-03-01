/*********Implementation of  queue using sll*********/


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}queue;


void enque(int data,queue **front_arg,queue **rear_arg);
void display(queue **front_arg);
void deque(queue **front_arg);
void front_element(queue **front_arg,queue **rear_arg);

int main()
{
    queue *front=NULL, *rear=NULL;
    
    enque(10,&front,&rear);
    enque(20,&front,&rear);
    enque(30,&front,&rear);
    display(&front);
    front_element(&front,&rear);
    deque(&front);
    deque(&front);
    display(&front);
    deque(&front);
    display(&front);

    return 0;
}

void enque(int data,queue **front_arg,queue **rear_arg)
{
    queue *new=(queue *)malloc(sizeof(queue));
    if(new==NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
     new->data=data;
     new->link=NULL;
     
     if(*front_arg==NULL && *rear_arg==NULL)
     {
       *front_arg = new;
       *rear_arg = new;
     }
     else
     {
         (*rear_arg)->link = new;
         *rear_arg = new;
     }
     printf("The enqued element is %d\n",(*rear_arg)->data);
    }
}


void display(queue **front_arg)
{
    queue *temp = *front_arg;
    
    if(*front_arg==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The queue contains:\n");
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

void deque(queue **front_arg)
{
    queue *temp = *front_arg;
    if(*front_arg==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The dequed element is %d\n",(*front_arg)->data);
        *front_arg = (*front_arg)->link;
        free(temp);
    }
}

void front_element(queue **front_arg,queue **rear_arg)
{
     if(*front_arg==NULL && *rear_arg==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The first element in the queue is %d\n",(*front_arg)->data);
    }
}




