#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//define stack structure
struct stack {
    int data[MAX_SIZE]; //array to store stack elements
    int top; //top of stack
};

//function to create new stack 
struct stack *create_stack()
{
    struct stack *s = malloc(sizeof(struct stack));
    s->top = -1;//initially, stack is empty
    return s;
};

//function to check if stack is full
int is_full(struct stack *s)
{
    //stack is full if top index is equal to max size -1
    return s->top == MAX_SIZE - 1; 
}

//function to check if stack is empty
int is_empty(struct stack *s)
{
    //stack is empty if top index is equal to -1
    return s->top == -1; 
}

//function to push an element onto the stack
void push(struct stack *s, int data)
{
    //check if the stack is full
    if(is_full(s))
    {
        printf("Stack overflow!\n");
        return; 
    }
    //increment top index and add element to the top of stack 
    s->top++;
    s->data[s->top] = data;
}

//fct to pop element from stack
int pop(struct stack *s)
{
    //check if empty
    if (is_empty(s))
    {
        printf("stack underflow!\n");
        return -1; 
    }
    //get element at the top of stack and decrement the top index
    int data = s->data[s->top];
    s->top--;
    return data
}

//fct to return the element at the top fo the stack without removing it 
int peek(struct stack *s)
{
    //check if empty
    if (is_empty(s))
    {
        printf("stack empty\n");
        return -1;
    }
    //return element at the top of stack
    return s->data[s->top];
}

int main()
{
    struct stack *s = create_stack();
    push(s, 1);
    push(s, 2);
    push(s, 3);

    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));

    //stack should now be empty
    printf("Is empty: %d\n", is_empty(s));
    return 0; 
}