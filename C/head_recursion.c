#include <stdio.h>

/* head reursion. 
 *first traverse rest of the list, then print value at current node */ 

struct node 
{
    Node *head; 
    int data; 
    Node *right; 
}

void traverse1(Node* head)
{
    if (head != NULL)
    {
        traverse1(head->next); 
        printf("%d", head->data); 
    }
}

/* tail recursion
 * first traverse rest of the list, then print value */ 

void traverse2(Node* head)
{
    if (head != NULL)
    {
        printf("%d", head->data); 
        traverse2(head->next); 
    }
}

int main()
{
    traverse1(); 
}