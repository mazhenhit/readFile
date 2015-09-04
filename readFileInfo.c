#include <sdtio.h>
#include <stdlib.h>

FileInfo fileContent;

int main()
{
	int a;
	int i;
	FILE *fd;
	char *line = NULL;
	ssize_t len = 0;
	FileInfo temp = fileContent;

	if((fd = fopen("text.txt", 'r')) == NULL)
	{
		return -1;
	}

	while((read = getline(&line, &len, fd)) != -1)
	{
		//line is the content
		if(temp == NULL)
		{
			fileContent = (FileInfo)malloc(sizeof(FileInfo));
			temp = fileContent;
			temp->content = line;
			temp->pNext = NULL:
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

	return 0;
}


