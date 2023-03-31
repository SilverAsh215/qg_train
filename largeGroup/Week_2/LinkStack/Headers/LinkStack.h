#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//???
Status initLStack(LinkStack *s);//??????
Status isEmptyLStack(LinkStack *s);//?§Ø????????
Status getTopLStack(LinkStack *s,ElemType *e);//?????????
Status clearLStack(LinkStack *s);//????
Status destroyLStack(LinkStack *s);//?????
Status LStackLength(LinkStack *s,int *length);//????????
Status pushLStack(LinkStack *s,ElemType data);//???
Status popLStack(LinkStack *s,ElemType *data);//???


#endif 
