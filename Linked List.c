#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *display(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);
struct node *sort_ll(struct node *);

void main()
{
    int ch,x;
    do
    {
        printf("Select the operation you want to perform:\n ");
        printf("1.create\n 2.insert_begin 3.insert_end\n 4.insert_before\n 5.insert_after\n 6.display\n 7.delete_begin 8.delete_end\n 9.delete_after\n 10.delete_node\n 11.delete_list\n 12.sort_ll\n 13.exit\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                start=create(start);
                printf("The list is created\n");
                break;
            case 2:
                start=insert_beg(start);
                break;
            case 3:
                start=insert_end(start);
                break;
            case 4:
                start=insert_before(start);
                break;
            case 5:
                start=insert_after(start);
                break;
            case 6:
                start=display(start);
                break;
            case 7:
                start=delete_beg(start);
                break;
            case 8:
                start=delete_end(start);
                break;
            case 9:
                start=delete_after(start);
                break;
            case 10:
                start=delete_node(start);
                break;
            case 11:
                start=delete_list(start);
                break;
            case 12:
                start=sort_ll(start);
                break;
        }
    } while(ch!=13);
    getch();
}

struct node *create(struct node *start)
{
    struct node *nn, *ptr;
    int x;
    printf(" Enter -1 to stop\n ");
    printf("Enter a no::\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        nn = (struct node *)malloc(sizeof(struct node));
        nn->data=x;
        if(start==NULL)
        {
            nn->next=NULL;
            start=nn;
        }
        else
        {
            nn->next=NULL;
            ptr=start;
            while(ptr->next!= NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=nn;
        }
        printf("Enter a no::\n");
        scanf("%d",&x);
    }
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *nn;
    int x;
    printf("Enter a no.:\n ");
    scanf("%d",&x);
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=x;
    nn->next=start;
    start=nn;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *nn,*ptr;
    int x;
    printf("Enter a no.:\n ");
    scanf("%d", &x);
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=x;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    nn->next=NULL;
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *nn,*pp,*ptr;
    int x,val;
    printf("Enter a no.:\n ");
    scanf("%d",&x);
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=x;
    printf("Enter the no. before which you want to enter the value\n");
    scanf("%d",&val);
    ptr=start;
    while(ptr->data!=val)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=nn;
    nn->next=ptr;
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *nn,*pp,*ptr;
    int x,val;
    printf("Enter a no::\n");
    scanf("%d",&x);
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=x;
    printf("Enter the no. after which you want to enter a value\n");
    scanf("%d",&val);
    pp=start;
    ptr=start;
    while(pp->data!=val)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=nn;
    nn->next=ptr;
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("Data is %d\n",ptr->data);
        ptr=ptr->next;
    }
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    printf("The data to be deleted is %d\n",ptr->data);
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr,*pp;
    ptr=start;
    pp=start;
    while(ptr->next!=NULL)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=NULL;
    printf("Node to be deleted is %d\n",ptr->data);
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start)
{
    int value;
    struct node *ptr,*pp;
    ptr=start;
    pp=start;
    printf("enter a value which you want to delete\n");
    scanf("%d",&value);
    while(pp->data!=value)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=ptr->next;
    printf("Deleted node is %d\n",ptr->data);
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start)
{
    int value;
    struct node *ptr,*pp;
    ptr=start;
    pp=start;
    printf("Enter a node you want to delete\n");
    scanf("%d",&value);
    while(ptr->data!=value)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=ptr->next;
    printf("Deleted node is %d\n",ptr->data);
    free(ptr);
    return start;
}

struct node *delete_list(struct node *start)
{
    while(start!= NULL)
    {
        printf("Data deleted %d\n",start->data);
        start=delete_beg(start);
    }
    return start;
}

struct node *sort_ll(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1=start;
    while(ptr1->next != NULL)
    {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
            if(ptr1->data>ptr2->data)
            {
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return start;
}