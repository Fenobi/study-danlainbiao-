#define _CRT_SECURE_NO_WARNINGS

#include "fu.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
}

SLTNode* BuyListNode(SLTDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fil\n");
		exit(-1);
	}

	newnode->date = x;
	newnode->next = NULL;

	return newnode;
}

void SListPushBuck(SLTNode** pphead, SLTDateType x)//注意是二级指针！
{
	//插入
	/*SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));

	newnode->date = x;
	newnode->next = NULL;*/

	SLTNode* newnode = BuyListNode(x);


	//第一个节点不找尾
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		//找到尾节点
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDateType x)
{
	SLTNode* newnode = BuyListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;

}

void SListPopBack(SLTNode** pphead)
{
	assert(*pphead != NULL);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		tail = NULL;

		prev->next = NULL;

	/*	SLTNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;*/
	}
}

void SListPopFront(SLTNode** pphead)
{
	assert(*pphead != NULL);
	
	SLTNode* next = *pphead;
	(*pphead) = (*pphead)->next;
	free(next);

}

SLTNode* SlistFind(SLTNode* phead, SLTDateType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->date == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SListRevise(SLTNode** pphead,int pos, SLTDateType x)
{
	SLTNode* cur = SlistFind(*pphead, pos);
	if (cur)
	{
		cur->date = x;
	}
}

//在pos之后插入一个节点（简单）
void SListInsertAfter(int pos, SLTDateType x)
{

}


void SListInsert(SLTNode** pphead, int pos, SLTDateType x)
{
	SLTNode* newnode = BuyListNode(x);
	SLTNode* cur = SlistFind(*pphead, pos);
	if (*pphead == cur)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		//找到pos的前一个位置
		SLTNode* posPrev = *pphead;
		while (posPrev->next != cur)
		{
			posPrev = posPrev->next;
		}

		posPrev->next = newnode;
		newnode->next = cur;

	}
}

