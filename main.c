#include<stdio.h>
#include "types.h"
#include "operation.h"
#include "addition.h"
#include "subtraction.h"
#include "multipication.h"
#include"division.h"


int main(int argc,char **argv)
{
    OPERAND OP1,OP2,RES;
    assignNULL(&OP1,&OP2,&RES);

    if(checkArgs(argc,argv)==failure)
    {
        printf("[INFO]: Wrong Arguments\n");
        return 1;
    }

    char operator = argv[2][0];

    if(insertElements(&OP1,argv[1])==failure)
    {
        printf("[INFO]: Adding 1st operand elements failed\n");
    }

    if(insertElements(&OP2,argv[3])==failure)
    {
        printf("[INFO]: Adding 2nd operand elements failed\n");
    }

    switch(operator)
    {
        case '+':
            addition(&OP1,&OP2,&RES);
            break;
        case '-':
            subtraction(&OP1,&OP2,&RES);
            break;
            
        case 'x':
            multiplication(&OP1,&OP2,&RES);
            break;

        case '/':
            division(&OP1,&OP2,&RES);
            break;            


        default:
            printf("[INFO]: Wrong Operator\n");
            break;
    }


    
    displayList(OP1);
    displayList(OP2);
    printNumber(&RES);
    
}