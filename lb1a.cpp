#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int size_mass, max = -1000, min = 1000, mama=0;
	printf("enter array z\size: ");
	scanf("%i",&size_mass);
//	int *mass = (int *)malloc(sizeof(int)*size_mass);
	int **bigmass = (int **)malloc(sizeof(int*)*size_mass);
	for (int i = 0;i<size_mass;i++){
		*(bigmass+i*sizeof(int*)) = (int *)malloc(sizeof(int)*size_mass);
	}
	for (int j = 0; j < size_mass;j++){
		for (int i = 0; i < size_mass; i++){
			*(*(bigmass+i*sizeof(int))+j*sizeof(int*)) = rand() % 50;
			if (*(*(bigmass+i*sizeof(int))+j*sizeof(int*))  > max) max = *(*(bigmass+i*sizeof(int))+j*sizeof(int*)) ;
			if (*(*(bigmass+i*sizeof(int))+j*sizeof(int*))  < min) min = *(*(bigmass+i*sizeof(int))+j*sizeof(int*)) ;
		///	if (*(*(bigmass+i*sizeof(int))+j*sizeof(int*)) % 3 == 0 ) mama++;
		//	printf(" %i,", *(*(bigmass+i*sizeof(int))+j*sizeof(int*)) );
		}
		printf("\n");
	}
	printf("\nmax: %i min: %i, diff = %i\n, count of mod 3", max, min, max-min,mama);
	/*int a[2][10], otv;
	for (int i = 0; i<10;i++){
		a[0][i] = rand() % 100;
		a[1][i] = rand() % 100;
		otv = a[0][i] + a[1][i];
		printf("%i, %i, sum = %i\n", a[0][i],a[1][i], otv);
	}*/
	free(bigmass);
}