#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	char content[100];
	ListNode *pNext;
};

void addToTail(ListNode **pHead, char *str);

int main()
{
	FILE *fd;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	Listnode *fileContent = NULL;
	Listnode *pTemp;

	if((fd = fopen("test.txt", "r")) == NULL)
	{
		return -1;
	}

	while((read = getline(&line, &len, fd)) != -1)
	{
		printf("The read is %zu\n", read);
		printf("%s\n", line);
		addToTail(&fileContent, line);
	}

	if(line)
		free(line);

	pTemp = fileContent;
	while(pTemp != NULL)
	{
		printf("the pTemp now is %d\n", pTemp->content);
		pTemp = pTemp->pNext;
	}

	return 0;
}

void addToTail(ListNode **pHead, char *str)
{
	ListNode *pNew =  new ListNode();
	pNew->content = str;
	pNew->pNext = NULL;
	
	if(*head == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode *pNode = *pHead;
		
		while(pNode->pNext != NULL)
		{
			pNode = pNode->pNext;
		}
		
		pNode->pNext = pNew;
	}
}


