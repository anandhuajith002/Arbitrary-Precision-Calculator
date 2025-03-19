#ifndef OPER_H
#define OPER_H

#include "types.h"


void assignNULL(OPERAND *OP1,OPERAND *OP2,OPERAND *RES);

Status checkArgs(int count, char **args);

Status checkOperator(char *op);

Status checkOperand(char *op1,char *op2);

Status insertElements(OPERAND *oplist,char *op);

Status insertToNodeLast(OPERAND *op,int num);

Status displayList(OPERAND op);

NODE * createNode(int data);

Status insertToNodeFirst(OPERAND *res,int data);

Status printNumber(OPERAND *op);

Status remFrontZero(OPERAND *OP);

Status clearOperand(OPERAND *op);

#endif