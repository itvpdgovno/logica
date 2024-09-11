#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define arraysize 10000

void main(void){
	clock_t start, end; // объявляем переменные для определения времени выполнения
	int i = 0, j = 0, r;
	char* a = (char*)malloc(arraysize * arraysize);
	char* b = (char*)malloc(arraysize * arraysize);
	int* c = (int*)malloc(arraysize * arraysize*sizeof(int));
	int elem_c;
	//char a[arraysize][arraysize], b[arraysize][arraysize], c[arraysize][arraysize], elem_c;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < arraysize)
	{
		while (j < arraysize)
		{
			*(a + i * arraysize + j) = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < arraysize)
	{
		while (j < arraysize)
		{
			*(b + i * arraysize + j) = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	start = clock();
	for (i = 0; i < arraysize; i++)
	{
		for (j = 0; j < arraysize; j++)
		{
			elem_c = 0;
			for (r = 0; r < arraysize; r++)
			{
				elem_c = (int) elem_c + *(a + i * arraysize + r) * *(b + i * arraysize + j);
				*(c + i * arraysize + j) = elem_c;
			}
		}
	}
	end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Time spent:%lf s", time_spent);
	free(a);
	free(b);
	free(c);
}


