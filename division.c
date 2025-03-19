#include<stdio.h>
#include "types.h"
#include "operation.h"
#include "subtraction.h"
#include "division.h"
#include"multipication.h"
#include<stdlib.h>

Status division(OPERAND *OP1,OPERAND *OP2,OPERAND *RES)
{
    long long int count=0;
    remFrontZero(OP2);
    if(checkGreater(OP1,OP2)==-1 )
    {
        insertToNodeFirst(RES,0);
        return success;
    }
    if(OP2->head->digit==0)
    {
        printf("[INFO]: division by zero error");
        return success;
    }
    
    
    OPERAND temp;
    assignNULL(&temp,NULL,NULL);
    copyOperand(&temp,OP1);
    printNumber(&temp);

    while(checkGreater(&temp,OP2)!= -1)
    {
        printf("*");
        subtraction(&temp,OP2,RES);
        clearOperand(&temp);
        copyOperand(&temp,RES);
        printNumber(&temp);
        clearOperand(RES);
        count++;

    }
    char str[100];
    itoa(count,str,10);
    insertElements(RES,str);


}