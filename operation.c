#include<stdio.h>
#include"types.h"
#include"operation.h"
#include<ctype.h>
#include<stdlib.h>

Status displayList(OPERAND op)
{

    if(op.head==NULL)
    {
        printf("[INFO]: List empty\n");
        return failure;
    }
    else
    {
        NODE *temp = op.head;
        printf("head ");
        while(temp!=NULL)
        {
            printf("<-> %d ",temp->digit);
            temp=temp->right;
        }
        printf(" <-> tail\n");
    }
    return success;
}
Status printNumber(OPERAND *op)
{

    if(op->head==NULL)
    {
        printf("[INFO]: List empty\n");
        return failure;
    }
    else
    {
        printf("\n");
        if(op->sign==-1)
        {
            printf("-");
        }
        NODE *temp = op->head;
        while(temp!=NULL)
        {
            printf("%d",temp->digit);
            temp=temp->right;
        }
    }
    return success;
}

Status insertToNodeFirst(OPERAND *res,int data)
{
    NODE *new = createNode(data);
    if(res->head==NULL)
    {
        res->head=new;
        res->tail=new;
    }
    else
    {
        new->right=res->head;
        res->head->left=new;
        res->head=new;
    }
    return success;
}

Status insertToNodeLast(OPERAND *op,int num)
{
    NODE * new = createNode(num);
    if(op->head==NULL)
    {
        op->head = new;
        op->tail=new;
    }
    else
    {
        new->left=op->tail;
        op->tail->right=new;
        op->tail=new;
    }
    return success;
}

NODE * createNode(int data)
{
    NODE *new=malloc(sizeof(NODE));
    if(new==NULL)
    {
        return NULL;
    }
    new->digit=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}

Status insertElements(OPERAND *OP,char *arg_op)
{

    int i=0,num;
    if(arg_op[i]=='+' || arg_op[i]=='-')
    {
        if(arg_op[i]=='-')
        {
            OP->sign=-1;
        }
        else
        {
            OP->sign=1;
        }
        i++;
        
    } 
    if(i==0)
    {
        OP->sign=1;
    }

    while(arg_op[i]!='\0')
    {
        num=arg_op[i]-48;
        if(insertToNodeLast(OP,num)==failure)
        {
            return failure;
        }
        i++;
    }
    OP->length=i;
    return success;

}
Status clearOperand(OPERAND *op)
{
    NODE *temp=op->head,*prev;
    while(temp!=NULL)
    {
        prev=temp->right;
        free(temp);
        temp=prev;
    }
    op->head=NULL;
    op->tail=NULL;
}

Status checkArgs(int count, char **args)
{
    if(count!=4)
    {
        printf("==%d==",count);
        printf("[INFO]: Wrong Expression count\n");
        return failure;
    }

    if(checkOperand(args[1],args[3])==failure)
    {
        printf("[INFO]: Error Operand Format\n");
        return failure;
    }
    
    if(checkOperator(args[2])==failure)
    {
        printf("[INFO]: Error Operator\n");
        return failure;
    }

    
    return success;
}
Status checkOperand(char *op1,char *op2)
{
    int i=0;
    if(op1[i]=='+' || op1[i]=='-')
    {
        i++;
    }
    while(op1[i]!='\0')
    {
        if(isdigit(op1[i])==0)
            return failure;
        i++;
    }
    i=0;
    if(op2[i]=='+'|| op2[i]=='-')
    {
        i++;
    }
    while(op2[i]!='\0')
    {
        if(isdigit(op2[i])==0)
            return failure;
        i++;
    }
    return success;
}
Status checkOperator(char *op)
{
    if( ( op[0]=='+' || op[0] == '-' || op[0]=='x' || op[0]=='y' || op[0]=='^' || op[0]=='%' ) && op[1]=='\0')
    {
        return success;
    }
    else
    {
        return failure;
    }
}

Status remFrontZero(OPERAND *OP)
{
    if(OP->head==NULL)
    {
        printf("[INFO]: List empty\n");
        return failure;
    }
    else
    {
        
        NODE *temp = OP->head;
        while(temp!=NULL && temp->digit==0)
        {
            temp=temp->right;
        }
        if(temp!=NULL)
        {
            OP->head=temp;
        }
    }
    return success;
}

void assignNULL(OPERAND *OP1,OPERAND *OP2,OPERAND *OP3)
{
    if(OP1!=NULL)
    {
        OP1->head=NULL;
        OP1->tail=NULL;

    }
    if(OP2!=NULL)
    {
        OP2->head=NULL;
        OP2->tail=NULL;

    }
    if(OP3!=NULL)
    {
        OP3->head=NULL;
        OP3->tail=NULL;

    }
}