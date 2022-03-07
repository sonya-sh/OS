/*

Выводит идентификатор текущего и родительского процесса

*/


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	printf("PID дочернего процесса: %d\n", getpid());
	printf("PID родительского процесса: %d\n", getppid());
	return 0;
}


