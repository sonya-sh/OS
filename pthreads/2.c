/*

 Программа, создающая несколько потоков (конкретное количество определяется через параметр командной строки). 
 Каждый поток в цикле увеличивает на 1 значение глобальной переменной программы. 
 В конце программы поток выводит на экран результат сложения. На каждый поток 1000000 операций сложения.

 Вывод о резултате: 
 Получаем неверный резултат, так как несколько потоков могут одновременно обращаться к одному и тому же элементу данных.
 Это происходит в результате переключения между потоками.
 Следовательно, текущий поток может быть отключен, прежде чем завершит свою работу, что влияет на корректность результата.

 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long int sum = 0;

void* handler(void *data);

int main(int argc, char *argv[]) {

	void *data = NULL;
	int NUM_THREADS = atoi(argv[1]);
	pthread_t threads[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_create(&threads[i], NULL, handler, data);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	printf("Сумма: %ld\n", sum);
	return 0;
}

void* handler(void *data) {
	for (long int j = 0; j < 1000000; j++) {
		sum++;
	}
	pthread_exit(0);
}

