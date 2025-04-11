#include <stdio.h>
#include "types.h"
#include "subtraction.h"
#include "operation.h"
#include"addition.h"

Status subtraction(OPERAND *OP1,OPERAND *OP2,OPERAND *RES)
{
    int borrow=0,num1,num2,res;
    NODE *p1=OP1->tail,*p2=OP2->tail;

    if(OP1->sign==1 && OP2->sign==-1)
    {
        OP1->sign=0;
        OP2->sign=0;
        addition(OP1,OP2,RES);
        return success;
    }
    else if(OP1->sign==-1 && OP2->sign==1)
    {
        OP1->sign=0;
        OP2->sign=0;
        RES->sign=-1;
        addition(OP1,OP2,RES);
        return success;
    }
    
    

    
    if(checkGreater(OP1,OP2)==0)
    {
        RES->sign=1;
        insertToNodeFirst(RES,0);
        return success;
    }
    else if(checkGreater(OP1,OP2)==-1)
    {
        printf("*\n");
        RES->sign=-1;
        p2=OP1->tail;
        p1=OP2->tail;

    }
    while(p1!=NULL)
    {
        if(p2==NULL)   
        {
            num1=p1->digit;
            num2=0;
        }
        else
        {
            num1=p1->digit;
            num2=p2->digit;
        }

        res=subTwo(num1,num2,&borrow);
        insertToNodeFirst(RES,res);
        
        p1=p1->left;
        if(p2!=NULL)
            p2=p2->left;
    }

    remFrontZero(RES);
    NODE *temp=RES->head;
    RES->length=0;
    while(temp!=NULL)
    {
        temp=temp->right;
        RES->length++;

    }
    return success;
}
int subTwo(int n1,int n2,int *brw)
{
    int res=n1-n2-*brw;
    if(res<0)
    {
        res+=10;
        *brw=1;
    }
    else
    {
        *brw=0;
    }
    return res;
}


int checkGreater(OPERAND *OP1,OPERAND *OP2)
{
    NODE *List1=OP1->head;
    NODE *List2=OP2->head;

    
    if(OP1->length>OP2->length)
        return 1;

    else if(OP1->length<OP2->length)
        return -1;
    
    else
    {
        List1=OP1->head;
        List2=OP2->head;
        while(List1!=NULL && List2!=NULL)
        {
            if(List1->digit<List2->digit)
            {
                return -1;
            }
            else if(List1->digit>List2->digit)
            {
                return 1;
            }
            else
            {
                List1=List1->right;
                List2=List2->right;
            }
        }
        return 0;
    }

    
}
