#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	FILE *fd;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	ListNode *fileContent = NULL;
	ListNode *pTemp;

	if((fd = fopen("test.txt", "r")) == NULL)
	{
		return -1;
	}

	while((read = getline(&line, &len, fd)) != -1)
	{
		addToTail(&fileContent, line);
	}

	if(line)
		free(line);

	pTemp = fileContent;
	while(pTemp != NULL)
	{
		printf("%s", pTemp->content);
		pTemp = pTemp->pNext;
	}

	return 0;
}


