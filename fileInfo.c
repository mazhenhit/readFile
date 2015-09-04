#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
	char content[50];
	struct List *pNext;
}List;

typedef struct List *FileInfo;


int getListLength(FileInfo p)
{
	int i= 0;

	while(p != NULL)
	{
		i++;
		p = p->pNext;
	}

	return i;
}
