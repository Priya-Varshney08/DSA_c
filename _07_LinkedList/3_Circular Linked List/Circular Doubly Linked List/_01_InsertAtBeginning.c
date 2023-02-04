#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* addToEmpty(int data){
    struct node* p = (struct node *)malloc(sizeof(struct node));
    p->prev=p;
    p->data=data;
    p->next=p;
    return p;
}

void llTraversal(struct node *head)
{
    struct node *p = head;
    while (p->next != head)
    {
        printf("Element : %d\n", p->data);
        p = p->next;
    }
    printf("Element : %d\n", p->data);
}

struct node *InsertAtBeginning(struct node *head, int data)
{
    struct node *p = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->prev = p;
    ptr->next = head;
    p->next = ptr;
    head->prev = ptr;
    head = ptr;
    return head;
}

int main(){
    struct node* head = (struct node *)malloc(sizeof(struct node));
    struct node* tail = (struct node *)malloc(sizeof(struct node));

    head->prev = tail;
    head->data=25;
    head->next=tail;

    tail->prev = head;
    tail->data=56;
    tail->next=head;
    
    // head = addToEmpty(25);
    printf("Before :\n");
    llTraversal(head);
    printf("After :\n");
    head = InsertAtBeginning(head, 10);
    llTraversal(head);
    return 0;
}