#include <stdio.h>
#include <stdlib.h>
#include "fileInfo.h"

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
