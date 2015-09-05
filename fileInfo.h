#ifndef _FILEINFO_H_
#define _FILEINFO_H_

typedef struct List
{
	char content[100];
	int num;
	struct List *pNext;
}List;

typedef struct List *FileInfo;

int getListLength(FileInfo p);

#endif
