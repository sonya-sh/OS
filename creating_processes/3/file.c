#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	printf("исполняется file\n");
	printf("PID 2: %d\n", getpid());
	return 0;
}

