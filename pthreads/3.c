/*

 Программа, аналогичная 2.с , но использующая синхронизацию для получения верного резултата.
 Синхронизация ограничивает доступ к разделяемым ресурсам на время их использования каким-либо потоком. 

 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long int sum = 0;
pthread_mutex_t sumLock;

void* handler(void *data);

int main(int argc, char *argv[]) {

	void *data = NULL;
	int NUM_THREADS = atoi(argv[1]);
	pthread_t threads[NUM_THREADS];
	pthread_mutex_init(&sumLock, NULL);

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_create(&threads[i], NULL, handler, data);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	printf("Сумма: %ld\n", sum);
	pthread_mutex_destroy(&sumLock);
	pthread_exit(0);
}

void* handler(void *data) {

	for (long int j = 0; j < 1000000; j++) {
		pthread_mutex_lock(&sumLock);
		sum = sum + 1;
		pthread_mutex_unlock(&sumLock);
	}
	pthread_exit(0);
}


