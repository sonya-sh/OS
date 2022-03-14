/*

Создание потоков с помощью pthreads. Создаёт несколько потоков, каждый из которых выводит на экран разную строку "привет, я процесс №ХХХ" 10 раз. 
Компиляция:  gcc -std=c99 1.c -o 1 -lpthread
Запуск:  ./1 n  (n - количество потоков, вводимое пользователем)

*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void* handler(void *data);

int main(int argc, char *argv[]) {
	
	void *data = NULL;
	int n_threads = atoi(argv[1]);
	pthread_t id;

	for (int j = 0; j < n_threads; j++) {
		
		pthread_create(&id, NULL, handler, data);
		pthread_join(id, NULL);
	}
	return 0;
}

void* handler(void *data) {
	pid_t gettid(void);
	for (int i = 0; i < 10; i++) {
		printf("привет, я процесс №%d\n", gettid());
	}
	printf("\n");
	pthread_exit(0);
}

