// the second experiment in data_struct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct LNode{
	ElemType elem;
	struct LNode *next;
}LNode;

typedef struct SqList{
	char listName[20];
	int length;
	struct SqList *next;
	LNode *Lnext;
}SqList;

//后进先出链表

char filename[20];

/*--------------------page 19 on textbook ----------------------------------*/
status IntiaList(SqList **L);
status DestroyList(SqList ** L, char *filename);
status ClearList(SqList &L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType & e);
status LocateElem(SqList L,ElemType e); //简化过
status PriorElem(SqList L,ElemType cur,ElemType & pre_e);
status NextElem(SqList L,ElemType cur,ElemType & next_e);
status ListInsert(SqList & L,int i,ElemType e);

status ListDelete(SqList & L, int i, ElemType & e);
status ListTrabverse(SqList L, char *filename);  //简化过
								 /*------------------------------------------------------*/
int main(void) {
	SqList *L = NULL;

	int op = 1;
	status result = 0;

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
		scanf("%d", &op);
		switch (op) {
		case 1:
			//printf("\n----IntiaList功能待实现！\n");
			if (IntiaList(&L) == OK) printf("线性表创建成功！\n");
			else printf("线性表创建失败！\n");
			getchar(); getchar();
			break;
		case 2:
			printf("\n----DestroyList功能待实现！\n");
			getchar(); 
			printf("请输入你想要操作的表的名字：\n");
			scanf_s("%s", filename);
			getchar();
			result = DestroyList(&L, filename);
			if (result == ERROR)
				printf("表名输入错误！\n");
			else
				printf("销毁成功！\n");
			getchar();
			break;
		case 3:
			printf("\n----ClearList功能待实现！\n");
			getchar(); getchar();
			break;
		case 4:
			printf("\n----ListEmpty功能待实现！\n");
			getchar(); getchar();
			break;
		case 5:
			printf("\n----ListLength功能待实现！\n");
			getchar(); getchar();
			break;
		case 6:
			printf("\n----GetElem功能待实现！\n");
			getchar(); getchar();
			break;
		case 7:
			printf("\n----LocateElem功能待实现！\n");
			getchar(); getchar();
			break;
		case 8:
			printf("\n----PriorElem功能待实现！\n");
			getchar(); getchar();
			break;
		case 9:
			printf("\n----NextElem功能待实现！\n");
			getchar(); getchar();
			break;
		case 10:
			printf("\n----ListInsert功能待实现！\n");
			getchar(); getchar();
			break;
		case 11:
			printf("\n----ListDelete功能待实现！\n");
			getchar(); getchar();
			break;
		case 12:
			getchar();
			printf("请输入你想要操作的表的名字：\n");
			scanf_s("%s", filename);
			result = ListTrabverse(L, filename);
			if (result == ERROR)
				printf("表名输入错误！\n");
			else if (result == FALSE)
				printf("此表是空表！\n");
			getchar();
			getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");

	return 0;
}//end of main()

 /*--------------------page 23 on textbook ----------------------------------*/
status IntiaList(SqList ** L) {
	/*FILE *fp;
	SqList *p = *L;

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Error!\n");
		return ERROR;
	}

	while (!feof(fp))
	{
		p = p->next;
		p = (SqList*)malloc(sizeof(SqList));
		fread(&p, sizeof(SqList), 1, fp);
	}
	*/
	SqList *p = *L;
	p = (SqList*)malloc(sizeof(SqList));
	p->Lnext = NULL;
	p->next = NULL;
	return OK;
}

//case 2
status DestroyList(SqList **L, char *filename)
{
	SqList *head = *L, *ps = NULL;
	LNode *pl = NULL;

	ps = head->next;
	while (ps != NULL && (strcmp(ps->listName, filename) == 0))
	{
		ps = ps->next;
	}
	if (ps == NULL)
		return FALSE;
	pl = ps->Lnext;
	while (pl != NULL)
	{
		ps->Lnext = pl->next;
		free(pl);
		pl = ps->Lnext;
	}
	return OK;
}

//case 3
status 
//case 12
status ListTrabverse(SqList *L, char *filename) {
	SqList *head = L, *ps = NULL;
	LNode *pl = NULL;

	ps = head->next;
	while (strcmp(ps->listName, filename) != 0&&ps != NULL)
		ps = ps->next;
	if (ps == NULL)
		return ERROR;
	else if (ps->Lnext = NULL)
		return FALSE;
	pl = ps->Lnext;
	while (pl != NULL)
	{
		printf("%d ", pl->elem);
		pl = pl->next;
	}
	putchar('\n');
	return OK;
}

//case

