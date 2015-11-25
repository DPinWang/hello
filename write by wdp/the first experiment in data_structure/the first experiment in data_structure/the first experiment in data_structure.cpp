// the first experiment in data_structure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//2015_11_9
/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*--------------------page 10 on textbook ----------------------------------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //数据元素类型定义

					  /*--------------------page 22 on textbook ----------------------------------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct {  //顺序表（顺序结构）的定义
	ElemType * elem;
	int length;
	int listsize;
}SqList;
/*--------------------page 19 on textbook ----------------------------------*/
status IntiaList(SqList & L);

/*write by wdp*/
status DestroyList(SqList & L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType & e);
status LocateElem(SqList L,ElemType e); //简化过
status PriorElem(SqList L,ElemType cur,ElemType & pre_e);
status NextElem(SqList L,ElemType cur,ElemType & next_e);
status ListInsert(SqList & L,int i,ElemType e);
status ListDelete(SqList & L, int i, ElemType & e);

status ListTrabverse(SqList L);  //简化过

								 /*------------------------------------------------------*/
int main(void) {
	SqList L;
	int op = 1, i = 0;
	ElemType cur_e = 0, prev_e = 0, next_e = 0, e = 0;
	while (op) {
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("------------------------------------------------------\n");
		printf("    	  1. IntiaList       7. LocateElem\n");
		printf("    	  2. DestroyList     8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty      10. ListInsert\n");
		printf("    	  5. ListLength     11. ListDelete\n");
		printf("    	  6. GetElem        12. ListTrabverse\n");
		printf("    	  0. Exit\n");
		printf("------------------------------------------------------\n");
		printf("    请选择你的操作[0~12]:");
		scanf_s ("%d", &op);
		switch (op) {
		case 1:
			//printf("\n----IntiaList功能待实现！\n");
			if (IntiaList(L) == OK) printf("线性表创建成功！\n");
			else printf("线性表创建失败！\n");
			getchar(); getchar();
			break;
		case 2:
			//printf("\n----DestroyList功能待实现！\n");
			if (DestroyList(L) == OK)
				printf("线性表销毁成功！\n");
			else 
				printf("线性表销毁失败！\n");
			getchar(); getchar();
			break;
		case 3:
			if(ClearList(L) == OK)
				printf("线性表清空成功！\n");
			//printf("\n----ClearList功能待实现！\n");
			else
				printf("线性表清空失败！\n");
			getchar(); getchar();
			break;
		case 4:
			//printf("\n----ListEmpty功能待实现！\n");
			if (ListEmpty(L) == OK)
				printf("线性表为空！\n");
			else
				printf("线性表不为空！\n");
			getchar(); getchar();
			break;
		case 5:
			//printf("\n----ListLength功能待实现！\n");
			printf("线性表的长度为%d\n", ListLength(L));
			getchar(); getchar();
			break;
		case 6:
			//printf("\n----GetElem功能待实现！\n");
			getchar();
			printf("请输入线性表需要查询的位置的下标：\n");
			scanf_s("%d", &i);
			getchar();
			if (GetElem(L, i, e) == OK)
			{
				printf("查询成功！\n");
				printf("查询结果为%d\n", e);
			}
			else
				printf("查询失败！\n");
			getchar();
			break;
		case 7:
			getchar();
			//printf("\n----LocateElem功能待实现！\n");
			printf("请输入要查询的数：\n");
			scanf_s("%d", &i);
			if (LocateElem(L, i) == OK)
				printf("查询成功！\n");
			else
				printf("查询失败！\n");
			getchar(); getchar();
			break;
		case 8:
			//printf("\n----PriorElem功能待实现！\n");
			getchar();
			printf("请输入你想要查询前一个数的当前数的位置：\n");
			scanf_s("%d", &cur_e);
			getchar();
			if (PriorElem(L, cur_e, prev_e) == OK)
				printf("查询结果为：%d\n", prev_e);
			else
				printf("查询失败！\n");
			getchar();
			break;
		case 9:
			//printf("\n----NextElem功能待实现！\n");
			getchar();
			printf("请输入你想要查询前一个数的当前数的位置：\n");
			scanf_s("%d", &cur_e);
			if (NextElem(L, cur_e, next_e) == OK)
				printf("查询结果为：%d\n", next_e);
			else
				printf("查询失败！\n");
			getchar(); getchar();
			break;
		case 10:
			//printf("\n----ListInsert功能待实现！\n");
			getchar();
			printf("请输入你想要插入的数据：\n");
			scanf_s("%d", &e);
			printf("请输入你想要插入数据的位置：\n");
			scanf_s("%d", &i);
			if (ListInsert(L, i, e) == OK)
				printf("插入成功！\n");
			else
				printf("插入失败！\n");
			getchar(); getchar();
			break;
		case 11:
			getchar();
			//printf("\n----ListDelete功能待实现！\n");
			printf("请输入你想要删除的数的位置：\n");
			scanf_s("%d", &i);
			getchar();
			if (ListDelete(L, i, e) == OK)
			{
				printf("删除成功！\n删除的数字为%d\n", e);
			}
			else
				printf("删除失败！\n");
		    getchar();
			break;
		case 12:
			//printf("\n----ListTrabverse功能待实现！\n");
			if (!ListTrabverse(L)) printf("线性表是空表！\n");
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");

	return 0;
}//end of main()

 /*--------------------page 23 on textbook ----------------------------------*/
status IntiaList(SqList & L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}



status ListTrabverse(SqList L) {
	int i;
	printf("\n-------------------- all elements ------------------------------\n");
	for (i = 0; i<L.length; i++) printf("%d ", L.elem[i]);
	printf("\n------------------------- end ----------------------------------\n");
	return L.length;
}

/*write by wdp*/
status DestroyList(SqList &L)
{
	free(L.elem);
	return OK;
}

status ClearList(SqList &L)
{
	L.length = 0;
	return OK;
}

status ListEmpty(SqList L)
{
	if (L.length > 0)
		return FALSE;
	return  OK;
}

int ListLength(SqList L)
{
	if (!L.elem)
		return 0;
	return L.length;
}

status GetElem(SqList L, int i, ElemType &e)
{
	if (!L.elem)
		return ERROR;
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i-1];
	return OK;
}

status LocateElem(SqList L, ElemType e)
{
	int i = 0;
	while (i < L.length)
	{
		if (L.elem[i] == e)
			break;
		i++;
	}
	printf("%d 在线性表中的位置是 %d\n", e, ++i);
	//由于老师将函数的参数与返回值限定了，所以只能够在此处输出，请谅解
	return OK;
}

status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
	int i = 0; 
	while (i < L.length)
	{
		if (L.elem[i] == cur_e)
		{
			pre_e = L.elem[i - 1];
			break;
		}
		++i;
	}
	if (i == L.length)
		return FALSE;
	return OK;
}

status NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
	int i = 0;
	while (i < L.length)
	{
		if (L.elem[i] == cur_e)
			break;
		++i;
	}
	if (i == L.length)
		return FALSE;
	else if (i == L.length - 1)
		return FALSE;
	next_e = L.elem[++i];
	return OK;
}

status ListInsert(SqList &L, int i, ElemType e)
{
	if (i < 1 && i >L.length + 1)
		return ERROR;
	if (L.length >= L.listsize)
	{
		ElemType* newbase;
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			return OVERFLOW;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	if(L.length != 0)
	{
		int j = 0;
		for (j = L.length; j >= i; j--)
			L.elem[j] = L.elem[j - 1];
	}
	
	L.elem[i-1] = e;
	L.length += 1;

	return OK;
}

status ListDelete(SqList &L, int i, ElemType &e)
{
	int j = i - 1;
	e = L.elem[i - 1];
	while (j != L.length - 1)
		L.elem[j] = L.elem[j + 1];
	L.length -= 1;

	return OK;
}