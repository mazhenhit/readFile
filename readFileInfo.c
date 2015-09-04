#include <stdio.h>
#include <stdlib.h>
#include "fileInfo.h"

FileInfo fileContent;

int main()
{
	int a;
	int i;
	FILE *fd;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FileInfo temp = fileContent;

	if((fd = fopen("text.txt", "r")) == NULL)
	{
		return -1;
	}

	while((read = getline(&line, &len, fd)) != -1)
	{
		if(temp == NULL)
		{
			fileContent = (FileInfo)malloc(sizeof(FileInfo));
			temp = fileContent;
			temp->content = line;
			temp->pNext = NULL;
		}
		else
		{
			FileInfo p = (FileInfo)malloc(sizeof(FileInfo));
			p->content = line;
			p->pNext = NULL;
			temp->pNext = p;
			temp = p;
		}
	}

	if(line)
		free(line);


	return 0;
}


