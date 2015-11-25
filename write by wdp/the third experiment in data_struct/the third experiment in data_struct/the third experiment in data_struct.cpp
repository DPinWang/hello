// the third experiment in data_struct.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 2
#define ERROR -3
#define INFEASIBLE -1
#define OVERFLOW -2

#define STACK_INIT_SIZE 100
#define STACKINCREASEMENT 10

typedef int SElemType;
typedef int status;

typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

status InitStack(SqStack &S);
status DestroyStack(SqStack &S);
status ClearList(SqStack &S);
status StackEmpty(SqStack S);
int StackLength(SqStack S);
status GetTop(SqStack S, SElemType &e);
status Push(SqStack &S, SElemType e);
status Pop(SqStack &S, SElemType &e);
status StackTraverse(SqStack S);


int main(void) {
	SqStack S;

	status result = 0;
	int key = 1;

	int op = 1, i = 0;
	SElemType e = 0;

	while (key) {
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("------------------------------------------------------\n");
		printf("    	  1. InitStack        6. GetTop\n");
		printf("    	  2. DestroyStack     7. Push\n");
		printf("    	  3. ClearStack       8. Pop \n");
		printf("    	  4. StackEmpty       9. StackTraverse\n");
		printf("    	  5. StackLength      0. Exit\n");
		printf("------------------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~12]:");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 1:
			//status InitStack(SqStack &S);
			result = InitStack(S);
			if (result == FALSE)
			{
				printf("ջ ��ʼ��ʧ�ܣ�\n");
			}
			else
			{
				printf("ջ ��ʼ���ɹ���\n");
			}
			getchar();
			break;
		case 2:
			//status DestroyStack(SqStack &S);
			result = DestroyStack(S);
			if (result == FALSE)
			{
				printf("ջ δ���٣�\n");
			}
			else
			{
				printf("ջ �����٣�\n");
			}
			getchar();
			break;
		case 3:
			//status ClearList(SqStack &S);
			printf("ջ����գ�\n");
			getchar();
			break;
		case 4:
			//status StackEmpty(SqStack S);
			result = StackEmpty(S);
			if (result == FALSE)
			{
				printf("ջ Ϊ�գ�\n");
			}
			else
			{
				printf("ջ ��Ϊ�գ�\n");
			}
			getchar();
			break;
		case 5:
			//int StackLength(SqStack S);
			printf("ջ ����Ϊ %d\n", StackLength(S));
			getchar();
			break;
		case 6:
			//status GetTop(SqStack S, SElemType &e);
			result = GetTop(S, e);
			if (result == FALSE)
			{
				printf("ջ Ϊ�գ�\n");
			}
			else
			{
				printf("ջ  ջ����Ԫ��Ϊ %d��\n", e);
			}
			getchar();
			break;
		case 7:
			//status Push(SqStack &S, SElemType e);
			printf("��������Ҫ��ջ�����֣�\n");
			scanf_s("%d", &e);
			getchar();
			result = Push(S, e);
			if (result == OVERFLOW)
			{
				printf("ջ �����\n");
			}
			else
			{
				printf("ջ ��ջ�ɹ���\n");
			}
			getchar();
			break;
		case 8:
			//status Pop(SqStack &S, SElemType &e);
			result = Pop(S, e);
			if (result == FALSE)
			{
				printf("ջ Ϊ�գ�\n");
			}
			else if (result == ERROR)
			{
				printf("ջ Ϊ��ջ��\n");
			}
			else
			{
				printf("ջ ��ջ�ɹ� Ԫ��Ϊ %d��\n", e);
			}
			getchar();
			break;
		case 9:
			//status StackTraverse(SqStack S);
			result = StackTraverse(S);
			if (result == FALSE)
			{
				printf("ջ δ��ʼ����\n");
			}
			else if(result == ERROR)
			{
				printf("ջ Ϊ�գ�\n");
			}
			else
			{
				printf("ջ ����������\n");
			}
			getchar();
			break;
		case 0:
			key = 0;
			break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");

	return 0;
}

status InitStack(SqStack &S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));

	if (!S.base)
		return FALSE;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

status DestroyStack(SqStack &S)
{
	free(S.base);
	if (!S.base)
	{
		return FALSE;
	}
	else
		return OK;
}

status ClearList(SqStack &S)
{
	S.top = S.base;
	return OK;
}

status StackEmpty(SqStack S)
{
	if (S.base != S.top)
		return OK;
	else
		return ERROR;
}

int StackLength(SqStack S)
{
	return (S.top - S.base);
}

status GetTop(SqStack S, SElemType &e)
{
	if (!S.base)
		return FALSE;
	e = *(S.top-1);
	return OK;
}

status Push(SqStack &S, SElemType e)
{

	if (S.base - S.top >= S.stacksize) //ջ��
	{
		S.base = (SElemType *)malloc((STACK_INIT_SIZE + STACKINCREASEMENT) * sizeof(SElemType));
		if (!S.base)
			return OVERFLOW;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREASEMENT;
	}
	(*S.top) = e;
	S.top++;
	return OK;
}

status Pop(SqStack &S, SElemType &e)
{
	if (!S.base)
		return FALSE;
	else if (S.base == S.top)
		return ERROR;
	e = *(S.top - 1);
	S.top--;
	return OK;
}

status StackTraverse(SqStack S)
{
	if (!S.base)
		return FALSE;

	if (S.top == S.base)
		return ERROR;
	SElemType *p = S.top - 1;
	while (p != S.base)
	{
		printf("%d ", *p);
		p--;
	}
	printf("%d\n", *p);

	return OK;
}
