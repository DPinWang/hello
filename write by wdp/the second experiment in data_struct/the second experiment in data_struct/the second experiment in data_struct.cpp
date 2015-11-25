// the second experiment in data_struct.cpp : �������̨Ӧ�ó������ڵ㡣
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
typedef int ElemType; //����Ԫ�����Ͷ���

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

//����ȳ�����

char filename[20];

/*--------------------page 19 on textbook ----------------------------------*/
status IntiaList(SqList **L);
status DestroyList(SqList ** L, char *filename);
status ClearList(SqList &L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType & e);
status LocateElem(SqList L,ElemType e); //�򻯹�
status PriorElem(SqList L,ElemType cur,ElemType & pre_e);
status NextElem(SqList L,ElemType cur,ElemType & next_e);
status ListInsert(SqList & L,int i,ElemType e);

status ListDelete(SqList & L, int i, ElemType & e);
status ListTrabverse(SqList L, char *filename);  //�򻯹�
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
		printf("    ��ѡ����Ĳ���[0~12]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			//printf("\n----IntiaList���ܴ�ʵ�֣�\n");
			if (IntiaList(&L) == OK) printf("���Ա����ɹ���\n");
			else printf("���Ա���ʧ�ܣ�\n");
			getchar(); getchar();
			break;
		case 2:
			printf("\n----DestroyList���ܴ�ʵ�֣�\n");
			getchar(); 
			printf("����������Ҫ�����ı�����֣�\n");
			scanf_s("%s", filename);
			getchar();
			result = DestroyList(&L, filename);
			if (result == ERROR)
				printf("�����������\n");
			else
				printf("���ٳɹ���\n");
			getchar();
			break;
		case 3:
			printf("\n----ClearList���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 4:
			printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 5:
			printf("\n----ListLength���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 6:
			printf("\n----GetElem���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 7:
			printf("\n----LocateElem���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 8:
			printf("\n----PriorElem���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 9:
			printf("\n----NextElem���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 10:
			printf("\n----ListInsert���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 11:
			printf("\n----ListDelete���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 12:
			getchar();
			printf("����������Ҫ�����ı�����֣�\n");
			scanf_s("%s", filename);
			result = ListTrabverse(L, filename);
			if (result == ERROR)
				printf("�����������\n");
			else if (result == FALSE)
				printf("�˱��ǿձ�\n");
			getchar();
			getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");

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

