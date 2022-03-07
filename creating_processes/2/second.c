/*

Создаёт копии самой себя и выводит идентификатор текущего и родительского процесса

*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	if (fork() == 0) {
		printf("PID дочернего процесса: %d\n", getpid());
	} else {
		printf("PID родительского процесса: %d\n", getpid());
	}
	return 0;
}


