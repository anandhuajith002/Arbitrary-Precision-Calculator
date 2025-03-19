#include <stdio.h>
#include "types.h"
#include "addition.h"
#include "operation.h"
#include"subtraction.h"


Status addition(OPERAND *OP1,OPERAND *OP2,OPERAND *RES)
{
    int carry=0,num1,num2,res;
    NODE *p1=OP1->tail,*p2=OP2->tail;
    clearOperand(RES);
    if(OP1->sign==-1 && OP2->sign==1 || OP1->sign==-1 && OP2->sign==1)
    {
        subtraction(OP1,OP2,RES);
        return success;
    }
    else if(OP1->sign==-1 && OP2->sign==-1)
    {
        RES->sign=-1;
    }

    while(p1!=NULL || p2!=NULL)
    {
        
        if(p1==NULL)
        {
            num1=0;
            num2=p2->digit;
        }
        else if(p2==NULL)   
        {
            num1=p1->digit;
            num2=0;
        }
        else
        {
            num1=p1->digit;
            num2=p2->digit;
        }
        
        res=addTwo(num1,num2,&carry);
        
        insertToNodeFirst(RES,res);
        
        
        if(p1!=NULL)
        p1=p1->left;
            
        if(p2!=NULL)
        p2=p2->left;
    }
    if(carry==1)
    {
        insertToNodeFirst(RES,1);
    }
    return success;
}

int addTwo(int n1,int n2,int* carry)
{
    int sum=n1+n2+*carry;
    *carry=sum/10;
    sum=sum%10;
    return sum;
}

