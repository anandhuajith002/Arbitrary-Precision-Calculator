#include<stdio.h>
#include "types.h"
#include "operation.h"
#include "multipication.h"
#include "addition.h"


Status multiplication(OPERAND *OP1,OPERAND *OP2,OPERAND *RES)
{

    
    OPERAND ans,temp;
    int count=0,i,sign;
    assignNULL(&ans,&temp,NULL);
    NODE *p1=OP1->tail,*p2=OP2->tail;
    if(p1==NULL)
    {
        printf("[INFO]: Multiplication not possible\n");
        return failure;
    }

    if(OP1->sign==-1 && OP2->sign==1 || OP1->sign==1 && OP2->sign==-1)
    {
        sign=-1;
        
    }

    while(p2!=NULL)
    {
        multiplySingle(&ans,p1,p2->digit);
        i=count;
        while(i!=0)
        {
            insertToNodeLast(&ans,0);
            i--;
        }
       
        copyOperand(&temp,RES);
        addition(&ans,&temp,RES);
    
        
        clearOperand(&ans);
        clearOperand(&temp);

        count++;
        p2=p2->left;
    }
    remFrontZero(RES);
    if(sign ==-1)
    {
        RES->sign=-1;
    }

}
Status multiplySingle(OPERAND *ans,NODE *first,int val)
{
    int carry=0,res;
    while(first!=NULL)
    {
        res=(first->digit*val)+carry;
        if(res>9)
        {
            res=res/10;
            carry=1;
        }
        else
            carry=0;
        insertToNodeFirst(ans,res);
        first=first->left;
    }
    if(carry==1)
    {
        insertToNodeFirst(ans,1);
    }
    return success;
}


Status copyOperand(OPERAND *dest, OPERAND *src) 
{
    NODE *p = src->head;
    while (p) {
        insertToNodeLast(dest, p->digit);
        p = p->right;
    }
    dest->length=src->length;
    dest->sign=src->sign;
}