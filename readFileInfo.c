#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	char content[100];
	struct ListNode *pNext;
}ListNode;

ListNode *addToTail(ListNode *pHead, char *str);

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
		printf("The read is %zu\n", read);
		printf("%s\n", line);
		fileContent = addToTail(fileContent, line);
	}

	if(line)
		free(line);

	pTemp = fileContent;
	while(pTemp != NULL)
	{
		printf("the pTemp now is %s\n", pTemp->content);
		pTemp = pTemp->pNext;
	}

	return 0;
}

ListNode *addToTail(ListNode *pHead, char *str)
{
	ListNode *pNew = (ListNode *)malloc(sizeof(ListNode)); 
	snprintf(pNew->content, 100, "%s", str);
	pNew->pNext = NULL;
	
	if(pHead == NULL)
	{
		pHead = pNew;
	}
	else
	{
		ListNode *pNode = pHead;
		
		while(pNode->pNext != NULL)
		{
			pNode = pNode->pNext;
		}
		
		pNode->pNext = pNew;
	}
	return pHead;
}


