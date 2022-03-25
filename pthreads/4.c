/*

 Программа, аналогичная 3.с , но с оптимизацией использования мьютексов.
 Изменён алгоритм рассчёта для уменьшения накладных расходов на синхронизацию.
 (  работает быстрее, чем 3.с :)  )

 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

long int sum = 0;
pthread_mutex_t sumLock;

void* handler(void *data);

int main(int argc, char *argv[]) {

	void *data = NULL;
	int NUM_THREADS = atoi(argv[1]);
	pthread_t threads[NUM_THREADS];
	pthread_mutex_init(&sumLock, NULL); // инициализация мьютекса

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_create(&threads[i], NULL, handler, data);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	printf("Сумма: %ld\n", sum);
	pthread_mutex_destroy(&sumLock); // уничтожение мьютекса
	pthread_exit(0);
}

// реализовано промежуточное хранение результатов
// и более редкое обращение к общей памяти
void* handler(void *data) {
	long tmp = 0;
	for (int a = 0; a < 10; a++) {
		printf("поток № %ld\n", syscall(SYS_gettid));
		for (long int b = 0; b < 1000000; b++) {
			tmp = tmp + 1;
		}
	}
	pthread_mutex_lock(&sumLock); // захват мьютекса
	sum = sum + tmp;
	pthread_mutex_unlock(&sumLock); // освобождение мьютекса
	pthread_exit(0);
}





