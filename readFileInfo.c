#include <sdtio.h>
#include <stdlib.h>

int main()
{
	int a;
	int i;
	FILE *fd;

	if((fd = fopen("text.txt", 'r')) == NULL)
	{
		return -1;
	}

	while((read = getline()))
	{
	}

	return 0;
}


