#ifndef TYPES_H
#define TYPES_H

typedef enum
{
    success,
    failure
    
}Status;

typedef struct node
{
    int digit;
    struct node *left;
    struct node *right;
}NODE;

typedef struct 
{
    NODE *head;
    NODE *tail;
    int length;
    int sign;
}OPERAND;



#endif