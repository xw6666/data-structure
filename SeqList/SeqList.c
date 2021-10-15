#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps == NULL)
	{
		printf("malloc ß∞‹\n");
		exit(-1);
	}
}