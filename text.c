#define _CRT_SECURE_NO_WARNINGS

#include "fu.h"


void TestSList1()
{
	SLTNode* plist = NULL;

	SListPushBuck(&plist, 1);
	SListPushBuck(&plist, 2);
	SListPushBuck(&plist, 3);
	SListPushBuck(&plist, 4);

	SListPushFront(&plist, 9);
	SListPrint(plist);
	//printf('\n');
	plist = SlistFind(plist, 2);
	SListPrint(plist);

	SListDestory(&plist);
}

void TestSList2()
{
	SLTNode* plist = NULL;

	SListPushBuck(&plist, 1);
	SListPushBuck(&plist, 2);
	SListPushBuck(&plist, 3);
	SListPushBuck(&plist, 4);
	SListPushBuck(&plist, 5);
	SListPushBuck(&plist, 6);
	SListPushBuck(&plist, 7);
	SListRevise(&plist,4, 20);
	//SListPopFront(&plist);
	
	//SListPopBack(&plist);
	SListInsert(&plist, 1, 15);

	SListPrint(plist);
	printf("\n");
	//SListPrint(SlistFind(plist, 5));

}



int main()
{
	TestSList1();
	//TestSList2();
	return 0;
}