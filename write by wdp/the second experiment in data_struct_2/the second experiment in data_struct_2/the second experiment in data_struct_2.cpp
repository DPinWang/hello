// the second experiment in data_struct_2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "targetver.h"


#include <stdio.h>
#include <stdlib.h>

/* Linear Table On Sequence Structure */
#include <malloc.h>
#include <string.h>

/*--------------------page 10 on textbook ----------------------------------*/
#define TRUE 1
#define FALSE 0
#define OK 2
#define ERROR -3
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

					  /*--------------------page 22 on textbook ----------------------------------*/

#define FILE_MAX_NUM 5
#define FILE_NAME_MAX 20

char file_name[FILE_MAX_NUM][FILE_NAME_MAX] = { "list1.dat", "list2.dat", "list3.dat", "list4.dat", "list5.dat"};

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode;

typedef struct LinkList {
	char filename[FILE_NAME_MAX];
	LNode *Lnext;
	struct LinkList *next;
}LinkList;

/*-----------page 19 on textbook ----------------------------------*/
status InitiaList(LinkList *L);
/*status DestroyList(LinkList **L, char *pfilename);
status ClearList(LinkList **L, char *pfilename);
status ListEmpty(LinkList *L, char *pfilename);
status ListLength(LinkList *L, char *pfilename, int *here_length);
status GetElem(LinkList *L, int i, ElemType *e, char *pfilename);
status LocateElem(LinkList *L, ElemType e, int *i, char *pfilename); 
status PriorElem(LinkList *L, ElemType cur, ElemType *pre_e, char *pfilename);
status NextElem(LinkList *L, ElemType cur, ElemType *next_e, char *pfilename);
*/
status ListInsert(LinkList *L, int i, ElemType e, char *pfilename);
//status ListDelete(LinkList **L, int i, ElemType *e, char *pfilename);
status ListTrabverse(LinkList L, char *pfilename);  //�򻯹�
//private function
//status saveList(LinkList *L);
/*---------------------------------------------------- - */
int main()
{
	LinkList List;
	LinkList *L = &List;

	int op = 1, i = 0;
	int key = 1;

	int loc = 0;
	int cho_num = 0;
	char cho_do;
	status result = ERROR;

	int here_length = 0;

	ElemType e = 0, cur_e = 0, prev_e = 0, next_e = 0;

	while (key) {
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
		getchar();
		switch (op) {
		case 1:
			//InitiaList
			if (InitiaList(&List) == ERROR)
			{
				printf("�ļ�δ��ȫ�򿪣��Ƿ����������Y or N");
				cho_do = getchar();
				getchar();
				if ((cho_do == 'n') || (cho_do == 'N'))
				{
					key = 0;
				}
			}
			else
			{
				printf("���Ա��ʼ���ɹ���\n");
			}
			getchar();
			break;
		/*case 2:
			//DestroyList
			printf("��������Ҫ�����ı����ţ�\n");
			for (i = 0; i < FILE_MAX_NUM; i++)
			{
				printf("%d %s\n", i, file_name[i]);
			}
			scanf_s("%d", &cho_num);
			getchar();
			result = DestroyList(&L, file_name[cho_num]);
			if (result == ERROR)
			{
				printf("�� %s �����ڣ�\n", file_name[cho_num]);
			}
			else
			{
				printf("�� %s ���ٳɹ���\n", file_name[cho_num]);
			}
			getchar();
			break;
		case 3:
			//ClearList
			printf("��������Ҫ�����ı����ţ�\n");
			for (i = 0; i < FILE_MAX_NUM; i++)
			{
				printf("%d %s\n", i, file_name[i]);
			}
			scanf_s("%d", &cho_num);
			getchar();
			result = ClearList(&L, file_name[cho_num]);
			if (result == ERROR)
			{
				printf("�� %s �����ڣ�\n", file_name[cho_num]);
			}
			else
			{
				printf("�� %s ��ճɹ���\n", file_name[cho_num]);
			}
			getchar();
			break;
		case 4:
			//ListEmpty
			printf("��������Ҫ�����ı����ţ�\n");
			for (i = 0; i < FILE_MAX_NUM; i++)
			{
				printf("%d %s\n", i, file_name[i]);
			}
			scanf_s("%d", &cho_num);
			getchar();
			result = ListEmpty(L, file_name[cho_num]);
			if (result == ERROR)
			{
				printf("�� %s �����ڣ�\n", file_name[cho_num]);
			}
			else if(result == TRUE)
			{
				printf("�� %s �ǿձ�\n", file_name[cho_num]);
			}
			else
			{
				printf("�� %s ���ǿձ�\n", file_name[cho_num]);
			}
			getchar();
			break;
		case 5:
			//ListLength
			printf("��������Ҫ�����ı����ţ�\n");
			for (i = 0; i < FILE_MAX_NUM; i++)
			{
				printf("%d %s\n", i, file_name[i]);
			}
			scanf_s("%d", &cho_num);
			getchar();
			result = ListLength(L, file_name[cho_num], &here_length);
			if (result == ERROR)
			{
				printf("�� %s �����ڣ�\n", file_name[cho_num]);
			}
			else
			{
				printf("���Ա�ĳ���Ϊ %d\n", here_length);
			}
			getchar();
			break;
		case 6:
			//GetElem
			printf("��������Ҫ�����ı����ţ�\n");
			for (i = 0; i < FILE_MAX_NUM; i++)
			{
				printf("%d %s\n", i, file_name[i]);
			}
			scanf_s("%d", &cho_num);
			getchar();
			//�˴���getchar������ֵ��ע��
			printf("��������Ҫ��ѯ������λ�ã�\n");
			scanf_s("%d", &loc);
			getchar();
			result = GetElem(L, loc, &e, file_name[cho_num]);
			//status GetElem(LinkList *L, int i, ElemType *e, char *pfilename)
			if (result == ERROR)
			{
				printf("�� %s �����ڣ�\n", file_name[cho_num]);
			}
			else if (result == FALSE)
			{
				printf("��ѯλ�ó�������\n");
			}
			else
			{
				printf("λ��Ϊ %d �������ǣ� %d��\n", loc, e);
			}
			getchar();
			break;
		case 7:
			//LocateElem
			printf("��������Ҫ�����ı����ţ�\n");
			for (i = 0; i < FILE_MAX_NUM; i++)
			{
				printf("%d %s\n", i, file_name[i]);
			}
			scanf_s("%d", &cho_num);
			getchar();
			//�˴���getchar������ֵ��ע��
			printf("��������Ҫ��ѯ������\n");
			scanf_s("%d", &e);
			getchar();
			result = LocateElem(L, e, &loc, file_name[cho_num]);
			//status LocateElem(LinkList *L, ElemType e, int *i, char *pfilename)
			if (result == ERROR)
			{
				printf("�� %s �����ڣ�\n", file_name[cho_num]);
			}
			else if (result == FALSE)
			{
				printf("����û��������֣�\n");
			}
			else
			{
				printf("���� %d �ڱ��е�λ���ǣ� %d ��\n", e, loc);
			}
			getchar();
			break;
		case 8:
			//PriorElem
			printf("��������Ҫ�����ı����ţ�\n");
			for (i = 0; i < FILE_MAX_NUM; i++)
			{
				printf("%d %s\n", i, file_name[i]);
			}
			scanf_s("%d", &cho_num);
			getchar();
			//�˴���getchar������ֵ��ע��
			printf("��������Ҫ��ѯ������\n");
			scanf_s("%d", &e);
			getchar();
			result = PriorElem(L, e, &prev_e, file_name[cho_num]);
			//status PriorElem(LinkList *L, ElemType cur, ElemType *pre_e, char *pfilename)
			if (result == ERROR)
			{
				printf("�� %s �����ڣ�\n", file_name[cho_num]);
			}
			else if (result == INFEASTABLE)
			{
				printf("�� %d �Ǳ��еĵ�һ�����֣�\n", e);
			}
			else if (result == FALSE)
			{
				printf("����û��������֣�\n");
			}
			else
			{
				printf("���� %d �ڱ��е�ǰһ�����ǣ� %d ��\n", e, prev_e);
			}
			getchar();
			break;
		case 9:
			//NextElem
			printf("��������Ҫ�����ı����ţ�\n");
			for (i = 0; i < FILE_MAX_NUM; i++)
			{
				printf("%d %s\n", i, file_name[i]);
			}
			scanf_s("%d", &cho_num);
			//getchar();
			//�˴���getchar������ֵ��ע��
			printf("��������Ҫ��ѯ������\n");
			scanf_s("%d", &e);
			getchar();
			result = NextElem(L, e, &next_e, file_name[cho_num]);
			if (result == ERROR)
			{
				printf("�� %s �����ڣ�\n", file_name[cho_num]);
			}
			else if (result == INFEASTABLE)
			{
				printf("�� %d �Ǳ��е����һ�����֣�\n", e);
			}
			else if (result == FALSE)
			{
				printf("����û��������֣�\n");
			}
			else
			{
				printf("���� %d �ڱ��е�ǰһ�����ǣ� %d ��\n", e, next_e);
			}
			getchar();
			break;
			*/
		case 10:
			//ListInsert
			//status ListInsert(LinkList **L, int i, ElemType e, char *pfilename);
			printf("��������Ҫ�����ı����ţ�\n");
			for (i = 0; i < FILE_MAX_NUM; i++)
			{
				printf("%d %s\n", i, file_name[i]);
			}
			scanf_s("%d", &cho_num);
			getchar();
			//�˴���getchar�п��ܲ�������
			printf("������Ҫ��������֣�\n");
			scanf_s("%d", &e);
			printf("������Ҫ���뵽���е�λ�ã�\n");
			scanf_s("%d", &loc);
			getchar();

			result = ListInsert(&List, loc, e, file_name[cho_num]);
			if (result == ERROR)
			{
				printf("�� %s �����ڣ�\n", file_name[cho_num]);
			}
			else if (result == INFEASTABLE)
			{
				printf("����λ�ó�������\n");
			}
			else
			{
				printf("����ɹ���\n");
			}
			getchar();
			break;
		/*case 11:
			//ListDelete
			//status ListDelete(LinkList **L, int i, ElemType *e, char *pfilename)
			printf("��������Ҫ�����ı����ţ�\n");
			for (i = 0; i < FILE_MAX_NUM; i++)
			{
				printf("%d %s\n", i, file_name[i]);
			}
			scanf_s("%d", &cho_num);
			getchar();
			//�˴����ܲ�������
			printf("������Ҫɾ�����е�λ�ã�\n");
			scanf_s("%d", &loc);
			getchar();

			result = ListDelete(&L, loc, &e, file_name[cho_num]);
			if (result == ERROR)
			{
				printf("�� %s �����ڣ�\n", file_name[cho_num]);
			}
			else if (result == INFEASTABLE)
			{
				printf("ɾ����λ�ó�������\n");
			}
			else
			{
				printf("����ɹ���\n");
			}
			getchar();
			break;
			*/
		case 12:
			//ListTraverse
			printf("��������Ҫ�����ı����ţ�\n");
			for (i = 0; i < FILE_MAX_NUM; i++)
			{
				printf("%d %s\n", i, file_name[i]);
			}
			scanf_s("%d", &cho_num);
			getchar();

			result = ListTrabverse(List, file_name[cho_num]);
			if (result == ERROR)
			{
				printf("�� %s �����ڣ�\n", file_name[cho_num]);
			}
			else
			{
				printf("����������\n");
			}
			getchar();
			break;
		/*case 0:
			//Exit
			printf("�Ƿ��˳���Y or N\n");
			cho_do = getchar();
			getchar();

			if ((cho_do == 'Y') || (cho_do == 'y'))
			{
				printf("�Ƿ񱣴����ݣ�Y or N\n");
				cho_do = getchar();
				
				if ((cho_do == 'Y') || (cho_do == 'y'))
				{
					result = saveList(L);
					if (result == OK)
					{
						printf("����ɹ���\n");
					}
					else
					{
						printf("����ʧ�ܣ�\n");
					}
				}
				key = 0;
				break;
			}
			break;
			*/
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");

	return 0;
}//end of main()

status InitiaList(LinkList *L)
{
	int i = 0;
	int type = 0;

	FILE *fp = NULL;
	LinkList *phead = L, *pl;
	LNode *ps = NULL;

	pl = phead->next;
	while (i < FILE_MAX_NUM)
	{
		if ((fp = fopen(file_name[i], "r")) == NULL)
		{
			printf("�ļ� %s ��ʧ�ܣ�\n", file_name[i]);
			fopen(file_name[i], "w");
			fclose(fp);
			i++;
			type = 1;
			break;
		}
		printf("�ļ� %s �򿪳ɹ���\n", file_name[i]);
		pl = (LinkList *)malloc(sizeof(LinkList));
		strcpy_s(pl->filename, file_name[i]);
		pl->next = NULL;
		//pl->Lnext = ps;

		while (!feof(fp))
		{
			ps = (LNode *)malloc(sizeof(LNode));
			fread(&(ps->data), sizeof(ElemType), 1, fp);
			ps->next = NULL;
			ps = ps->next;
		}
		fclose(fp);

		pl = pl->next;
		i++;
	}
	pl = phead->next;
	while (pl != NULL)
	{
		printf("test %s\n", pl->filename);
	}
	if (type)
		return ERROR;
	else
		return OK;
}

/*status DestroyList(LinkList **L, char *pfilename)
{
	LinkList *pl_prev = *L;
	LinkList *pl = pl_prev->next;
	LNode *ps = NULL;

	while (pl != NULL && (strcmp(pl->filename, pfilename) != 0))
	{
		pl_prev = pl_prev->next;
		pl = pl_prev->next;
	}
	if (pl == NULL)
		return ERROR;

	ps = pl->Lnext;
	while (ps != NULL)
	{
		pl->Lnext = ps->next;
		free(ps);
		ps = pl->Lnext;
	}
	pl_prev->next = pl->next;
	free(pl);

	return OK;
}

status ListEmpty(LinkList *L, char *pfilename)
{
	LinkList *pl = L->next;
	LNode *ps = NULL;

	while (pl != NULL && (strcmp(pl->filename, pfilename) != 0))
		pl = pl->next;

	if (pl == NULL)
		return ERROR;//�ޱ�

	ps = pl->Lnext;
	if (ps != NULL)
		return TRUE;//�ǿ�

	return FALSE;//Ϊ��
}

status ClearList(LinkList **L, char *pfilename)
{
	LinkList *pl = *L;
	LNode *ps = NULL, *ps_next = NULL;

	while (pl != NULL && (strcmp(pl->filename, pfilename) != 0))
		pl = pl->next;

	if (pl == NULL)
		return ERROR;

	ps = pl->Lnext;
	while (ps != NULL)
	{
		ps_next = ps->next;
		free(ps);
		ps = ps_next;
	}

	return OK;
}

status ListLength(LinkList *L, char *pfilename, int *here_length)
{
	int count = 0;
	LinkList *pl = L->next;
	LNode *ps = NULL;
	
	while (pl != NULL && (strcmp(pl->filename, pfilename) != 0))
		pl = pl->next;

	if (pl == NULL)
		return ERROR;
	ps = pl->Lnext;
	while (ps != NULL)
	{
		count++;
		ps = ps->next;
	}

	(*here_length) = count;

	return OK;
}

status GetElem(LinkList *L, int i, ElemType *e, char *pfilename)
{
	int it = 0;

	LinkList *pl = L->next;
	LNode *ps = NULL;

	while (pl != NULL && (strcmp(pl->filename, pfilename) != 0))
		pl = pl->next;

	if (pl == NULL)
		return ERROR;
	ps = pl->Lnext;
	while (ps != NULL&&it < i)
	{
		ps = ps->next;
		it++;
	}
	if (ps == NULL)
		return FALSE; //i̫��
	(*e) = ps->data;

	return OK;
}

status LocateElem(LinkList *L, ElemType e, int *i, char *pfilename)
{
	int it = 0;
	LinkList *pl = L->next;
	LNode *ps = NULL;

	while (pl != NULL && (strcmp(pl->filename, pfilename) != 0))
		pl = pl->next;

	if (pl == NULL)
		return ERROR;
	ps = pl->Lnext;

	while (ps != NULL)
	{
		if (ps->data == e)
			break;
		it++;
		ps = ps->next;
	}
	if (ps == NULL)
		return FALSE; //û��e
	(*i) = it + 1;
	return OK;
}

status PriorElem(LinkList *L, ElemType cur, ElemType *pre_e, char *pfilename)
{
	LinkList *pl = L->next;
	LNode *ps = NULL, *ps_next = NULL;

	while (pl != NULL && (strcmp(pl->filename, pfilename) != 0))
		pl = pl->next;

	if (pl == NULL)
		return ERROR;//�ļ�������

	ps = pl->Lnext;
	if (ps->data == cur||ps == NULL)
		return INFEASTABLE; //��֮ǰ������
	ps_next = ps ->next;
	while (ps_next != NULL)
	{
		if (ps_next->data == cur)
			break;
		ps = ps_next;
		ps_next = ps_next->next;
	}
	if (ps_next == NULL)
		return FALSE;//û���ҵ�
	(*pre_e) = ps->data;
	return OK;
}

status NextElem(LinkList *L, ElemType cur, ElemType *next_e, char *pfilename)
{
	LinkList *pl = L->next;
	LNode *ps = NULL, *ps_next = NULL;

	while (pl != NULL && (strcmp(pl->filename, pfilename) != 0))
		pl = pl->next;

	if (pl == NULL)
		return ERROR;

	ps = pl->Lnext;
	while (ps != NULL)
	{
		if (ps->data == cur)
			break;
		ps = ps->next;
	}

	if (ps == NULL)
		return FALSE;//�Ҳ���
	if (ps->next == NULL)
		return INFEASTABLE;
	(*next_e) = ps->next->data;
	return OK;
}
*/
status ListInsert(LinkList *L, int i, ElemType e, char *pfilename)
{
	int it = 0;
	LinkList *pl = L->next;
	LNode *ps = NULL, *ps_prev = NULL, *pcur = NULL;

	while (pl != NULL && (strcmp(pl->filename, pfilename) != 0))
		pl = pl->next;

	if (pl == NULL)
		return ERROR; //��������

	pcur = (LNode *)malloc(sizeof(LNode));
	pcur->next = NULL;
	pcur->data = e;

	ps = pl->Lnext;
	if (i == 1)
	{
		pcur->next = ps->next;
		ps->next = pcur;
	}
	else
	{
		while (it < i&&ps != NULL)
		{
			ps_prev = ps;
			ps = ps->next;
			it++;
		}
		if (ps == NULL)
			return INFEASTABLE;
		pcur->next = ps;
		ps_prev->next = pcur;
	}
	return OK;
}

/*status ListDelete(LinkList **L, int i, ElemType *e, char *pfilename)
{
	int it = 0;
	LinkList *pl = (*L)->next;
	LNode *ps = NULL, *ps_prev = NULL, *pcur = NULL;

	while (pl != NULL && (strcmp(pl->filename, pfilename) != 0))
		pl = pl->next;

	if (pl == NULL)
		return ERROR;

	ps = pl->Lnext;
	if (i == 1)
	{
		pl->Lnext = ps->next;
		(*e) = ps->data;
		free(ps);
	}
	else
	{
		while (it < i&&ps != NULL)
		{
			it++;
			ps_prev = ps;
			ps = ps->next;
		}
		if (ps == NULL)
			return INFEASTABLE;//i̫��
		(*e) = ps->data;
		ps_prev->next = ps->next;
		free(ps);
	}
	return OK;
}
*/
status ListTrabverse(LinkList L, char *pfilename)
{
	LinkList *pl = L.next;
	LNode *ps = NULL;

	while (pl != NULL && (strcmp(pl->filename, pfilename) != 0))
		pl = pl->next;

	if (pl == NULL)
		return ERROR;
	ps = pl->Lnext;
	while (ps != NULL)
	{
		printf("%d ", ps->data);
		ps = ps->next;
	}
	return OK;
}

/*status saveList(LinkList *L)
{
	LinkList *pl = L->next;
	LNode *ps = NULL;

	FILE *fp = NULL;
	int i = 0;

	while (i < FILE_MAX_NUM)
	{
		pl = L->next;
		while (pl != NULL)
		{
			if (strcmp(pl->filename, file_name[i]) == 0)
				break;
			pl = pl->next;
		}
		if (pl == NULL)
			return FALSE;

		if ((fp = fopen(file_name[i], "w")) == NULL)
			return ERROR;
		
		ps = pl->Lnext;
		while (ps != NULL)
		{
			fwrite(&(ps->data), sizeof(ElemType), 1, fp);
			ps = ps->next;
		}

		i++;
	}

	return OK;
}*/