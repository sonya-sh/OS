/*

Реализация программы из пункта 2 с помощью создания процесса с новым кодом (вызов exec)

*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	printf("исполняется third\n");
	printf("PID 1: %d\n", getpid());
	char *args[]={NULL}; 
        execvp("./file", args); // запускает файл file.c

	return 0;
}

