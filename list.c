struct ListNode
{
	int value;
	ListNode *pNext;
};

void removeNode(ListNode **pHead, int value)
{
	ListNode *toBeDelete = NULL;
	ListNode *pNode = *pHead;
	
	if(*pHead == NULL || pHead == NULL)
	{
		return;
	}
	
	if(*pHead->value == value)
	{
		toBeDelete = *pHead;
		*pHead = *pHead->pNext;
	}
	else
	{
		while(pNode->pNext->value != value && pNode->pNext->pNext != NULL)
		{
			pNode = pNode->pNext;			
		}
		
		if(pNode->pNext != NULL && pNode->pNext->value == value)
			toBeDelete = pNode;
		
		if(toBeDelete != NULL)
			free(toBeDelete);
	}
}