#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
	
int main() {
	srand(time(NULL));
	int size_mass, max = -1000, min = 1000;
	printf("enter array z\size: ");
	scanf("%i", &size_mass);
	int* mass = (int*)malloc(sizeof(int) * size_mass);
	for (int i = 0; i<size_mass; i++) {
		*mass = rand() % 90 - 40;
		if (*mass > max) max = *mass;
		if (*mass < min) min = *mass;
		printf(" %i,", *mass);
	}
	printf("\nmax: %i min: %i, diff = %i\n", max, min, max - min);
	int a[2][10], otv;
	for (int i = 0; i< 10; i++) {
		a[0][i] = rand() % 100;
		a[1][i] = rand() % 100;
		otv = a[0][i] + a[1][i];
		printf("%i, %i, sum = %i\n", a[0][i], a[1][i], otv);
	}
	free(mass);
}
