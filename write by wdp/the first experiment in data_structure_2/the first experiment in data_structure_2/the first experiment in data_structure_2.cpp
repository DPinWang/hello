// the first experiment in data_structure_2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//2015_11_11
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
typedef int ElemType; //����Ԫ�����Ͷ���

					  /*--------------------page 22 on textbook ----------------------------------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define MAXINPUT 20 //filename ����󳤶�

char filename[5][MAXINPUT] = {
	"List1.dat","List2.dat", "List3.dat", "List4.dat", "List5.dat"
};
int num = 0;
int key1 = 0;

typedef struct {  //˳���˳��ṹ���Ķ���
	ElemType * elem;
	int length;
	int listsize;
}SqList;
/*--------------------page 19 on textbook ----------------------------------*/
status IntiaList(SqList & L);
status IntiaList_file(SqList &L);

/*write by wdp*/
status DestroyList(SqList & L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L, int i, ElemType & e);
status LocateElem(SqList L, ElemType e); //�򻯹�
status PriorElem(SqList L, ElemType cur, ElemType & pre_e);
status NextElem(SqList L, ElemType cur, ElemType & next_e);
status ListInsert(SqList & L, int i, ElemType e);
status ListDelete(SqList & L, int i, ElemType & e);

status ListTrabverse(SqList L);  //�򻯹�

//private functon
status saveFile(SqList L);
								 /*------------------------------------------------------*/
int main(void) {
	SqList L;
	char getChoose;
	int choose = 1;

	/*char *p;
	scanf_s("%s", p);*/
	
	while (choose) {
		char key;
		printf("�Ƿ���Ҫ���ļ����в���? Y or N\n");
		key = getchar();
		getchar();
		if (key == 'Y' || key == 'y')
			key1 = 1;
		else
			key1 = 0;

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
			printf("    ��ѡ����Ĳ���[0~12]:");
			scanf_s("%d", &op);
			switch (op) {
			case 1:
				//printf("\n----IntiaList���ܴ�ʵ�֣�\n");
				if (key1)
				{
					if (IntiaList_file(L) == OK)
					{
						printf("�ļ����ش����ɹ���\n");
						if (!L.elem)
							printf("���Ա���ʧ��\n");
						else
						{
							printf("���Ա����ɹ�\n");
						}
					}
					else 
						printf("�ļ�����ʧ�ܣ�\n");
					getchar(); getchar();
					break;
				}
				else
				{
					if (IntiaList(L) == OK) printf("���Ա����ɹ���\n");
					else printf("���Ա���ʧ�ܣ�\n");
					getchar(); getchar();
					break;
				}
			case 2:
				//printf("\n----DestroyList���ܴ�ʵ�֣�\n");
				if (DestroyList(L) == OK)
					printf("���Ա����ٳɹ���\n");
				else
					printf("���Ա�����ʧ�ܣ�\n");
				getchar(); getchar();
				break;
			case 3:
				if (ClearList(L) == OK)
					printf("���Ա���ճɹ���\n");
				//printf("\n----ClearList���ܴ�ʵ�֣�\n");
				else
					printf("���Ա����ʧ�ܣ�\n");
				getchar(); getchar();
				break;
			case 4:
				//printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
				if (ListEmpty(L) == OK)
					printf("���Ա�Ϊ�գ�\n");
				else
					printf("���Ա�Ϊ�գ�\n");
				getchar(); getchar();
				break;
			case 5:
				//printf("\n----ListLength���ܴ�ʵ�֣�\n");
				printf("���Ա�ĳ���Ϊ%d\n", ListLength(L));
				getchar(); getchar();
				break;
			case 6:
				//printf("\n----GetElem���ܴ�ʵ�֣�\n");
				getchar();
				printf("���������Ա���Ҫ��ѯ��λ�õ��±꣺\n");
				scanf_s("%d", &i);
				getchar();
				if (GetElem(L, i, e) == OK)
				{
					printf("��ѯ�ɹ���\n");
					printf("��ѯ���Ϊ%d\n", e);
				}
				else
					printf("��ѯʧ�ܣ�\n");
				getchar();
				break;
			case 7:
				getchar();
				//printf("\n----LocateElem���ܴ�ʵ�֣�\n");
				printf("������Ҫ��ѯ������\n");
				scanf_s("%d", &i);
				if (LocateElem(L, i) == OK)
					printf("��ѯ�ɹ���\n");
				else
					printf("��ѯʧ�ܣ�\n");
				getchar(); getchar();
				break;
			case 8:
				//printf("\n----PriorElem���ܴ�ʵ�֣�\n");
				getchar();
				printf("����������Ҫ��ѯǰһ�����ĵ�ǰ����\n");
				scanf_s("%d", &cur_e);
				getchar();
				if (PriorElem(L, cur_e, prev_e) == OK)
					printf("��ѯ���Ϊ��%d\n", prev_e);
				else
					printf("��ѯʧ�ܣ�\n");
				getchar();
				break;
			case 9:
				//printf("\n----NextElem���ܴ�ʵ�֣�\n");
				getchar();
				printf("����������Ҫ��ѯǰһ�����ĵ�ǰ����\n");
				scanf_s("%d", &cur_e);
				if (NextElem(L, cur_e, next_e) == OK)
					printf("��ѯ���Ϊ��%d\n", next_e);
				else
					printf("��ѯʧ�ܣ�\n");
				getchar(); getchar();
				break;
			case 10:
				//printf("\n----ListInsert���ܴ�ʵ�֣�\n");
				getchar();
				printf("����������Ҫ��������ݣ�\n");
				scanf_s("%d", &e);
				printf("����������Ҫ�������ݵ�λ�ã�\n");
				scanf_s("%d", &i);
				int h;
				h = ListInsert(L, i, e);
				if (h == OK)
					printf("����ɹ���\n");
				else if (h == ERROR)
					printf("����ʧ�ܣ�\n");
				else
					printf("����ռ�ʧ��\n");
				getchar(); getchar();
				break;
			case 11:
				getchar();
				//printf("\n----ListDelete���ܴ�ʵ�֣�\n");
				printf("����������Ҫɾ��������λ�ã�\n");
				int i11;
				scanf_s("%d", &i11);
				if (ListDelete(L, i11, e) == OK)
				{
					printf("ɾ���ɹ���\nɾ��������Ϊ%d\n", e);
				}
				else
					printf("ɾ��ʧ�ܣ�\n");
				getchar();
				getchar();
				break;
			case 12:
				//printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");
				if (L.length == 0)
					printf("���Ա�Ϊ�ձ�\n");
				if (ListTrabverse(L) == ERROR) printf("���Ա�δ��ʼ����\n");
				getchar(); getchar();
				break;
			case 0:
				printf("�Ƿ���Ҫ�������ݣ�Y or N\n");
				getchar();
				char save_or_not;

				save_or_not = getchar();
				getchar();
				if (save_or_not == 'Y' || save_or_not == 'y')
				{
					if (saveFile(L) == OK)
						printf("����ɹ���\n");
					else
						printf("����ʧ�ܣ�\n");
				}
				break;
			}//end of switch
		}//end of while
		printf("�Ƿ����ʹ�ô�ϵͳ��Y or N\n");
		getChoose = getchar();
		getchar();
		if (getChoose == 'N' || getChoose == 'n')
			break;
	}

	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
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

status IntiaList_file(SqList &L)
{
	FILE * fp = NULL;
	int i = 0, it = 0;
	
	for (it = 0; it < 5; it++)
		printf("%d %s\n", it + 1, filename[it]);
	printf("��ѡ��Ҫ�������ļ����:\n");
	scanf_s("%d", &num);

	char *p = filename[num - 1];
	
	if ((fp = fopen(p, "r")) == NULL)
	{
		fopen(p, "w");
		printf("Error!\n");
		fclose(fp);
		return ERROR;
	}
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	while (!feof(fp))
	{
		fread(&(L.elem[i]), 1, sizeof(ElemType), fp);
		i++;
	}
	L.length = i - 1;
	L.listsize = LIST_INIT_SIZE;
	fclose(fp);

	return OK;
}

status ListTrabverse(SqList L) {
	if (!L.elem)
		return ERROR;
	int i;
	printf("\n-------------------- all elements ------------------------------\n");
	for (i = 0; i<L.length; i++) printf("%d ", L.elem[i]);
	printf("\n------------------------- end ----------------------------------\n");
	return OK;
}

/*write by wdp*/
status DestroyList(SqList &L)
{
	L.length = 0;
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
	e = L.elem[i - 1];
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
	printf("%d �����Ա��е�λ���� %d\n", e, ++i);
	//������ʦ�������Ĳ����뷵��ֵ�޶��ˣ�����ֻ�ܹ��ڴ˴���������½�
	return OK;
}

status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
	int i = 0;
	while (i < L.length)
	{
		if (L.elem[i] == cur_e)
		{
			if (i == 0)
				return ERROR;
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
	if (i < 1 || i >L.length + 1)
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
	if (L.length != 0)
	{
		int j = 0;
		for (j = L.length; j >= i; j--)
			L.elem[j] = L.elem[j - 1];
	}

	L.elem[i - 1] = e;
	L.length += 1;

	return OK;
}

status ListDelete(SqList &L, int i, ElemType &e)
{
	if (!L.elem)
		return ERROR;
	int j = i - 1;
	e = L.elem[i - 1];
	while (j < L.length - 1)
	{
		L.elem[j] = L.elem[j + 1];
		j++;
	}
	L.length -= 1;

	return OK;
}

status saveFile(SqList L)
{
	FILE *fp = NULL;
	int i = 0;
	if (key1)
	{
		fp = fopen(filename[num - 1], "w");
		i = 0;
		while (i < L.length)
		{
			fwrite(&(L.elem[i]), sizeof(ElemType), 1, fp);
			i++;
		}
		fclose(fp);
		return OK;
	}
	else
	{
		for (i = 0; i < 5; i++)
			printf("%d %s\n", i + 1, filename[i]);
		printf("��������Ҫ�������ݵ��ļ����ţ�\n");
		int hereChoose = 0;
		scanf_s("%d", &hereChoose);
		getchar();
		if ((fp = fopen(filename[hereChoose - 1], "w")) == NULL)
			return ERROR;
		i = 0;
		while (i < L.length)
		{
			fwrite(&(L.elem[i]), sizeof(ElemType), 1, fp);
			i++;
		}
		fclose(fp);
		return OK;
	}
}