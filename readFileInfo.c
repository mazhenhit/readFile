#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileInfo.h"

FileInfo fileContent = NULL;

int main()
{
	int a;
	int i = 0;
	FILE *fd;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FileInfo temp = fileContent;

	if((fd = fopen("test.txt", "r")) == NULL)
	{
		return -1;
	}

	while((read = getline(&line, &len, fd)) != -1)
	{
		i++;
		printf("The read is %zu\n", read);
		printf("%s\n", line);
		if(temp == NULL)
		{
			printf("enter temp == NULL, i is %d\n", i);
			fileContent = (FileInfo)malloc(sizeof(FileInfo));
			temp = fileContent;
			snprintf(temp->content, 100, "%s", line);
			temp->num = i;
			temp->pNext = NULL;
			printf("the fileContent is %s\n", fileContent->content);
			printf("the length is %d\n", getListLength(fileContent));
		}
		else
		{
			printf("entern temp != NULL, i is %d\n", i);
			FileInfo p = (FileInfo)malloc(sizeof(FileInfo));
			snprintf(p->content, 100, "%s", line);
			p->num = i;
			p->pNext = NULL;
			temp->pNext = p;
			temp = p;
			printf("the temp now is %s\n", temp->content);
			printf("the length is %d\n", getListLength(fileContent));
		}

	}

	if(line)
		free(line);

	temp = fileContent;
	while(temp != NULL)
	{
		printf("the temp now is %d\n", temp->num);
		temp = temp->pNext;
	}

	return 0;
}


