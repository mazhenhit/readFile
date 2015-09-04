all:fileInfo.o readFileInfo.o
	gcc -o all fileInfo.o readFileInfo.c

fileInfo.o:fileInfo.c
	gcc -c fileInfo.c

readFileInfo.o:readFileInfo.c
	gcc -c readFileInfo.c

clean:
	rm -rf all *.o
