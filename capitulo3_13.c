#include <stdlib.h>
#include <stdio.h>

int* newArray(int n){
	int i, j, k = 3;
	if(n % 2 == 0)
		j = n/2;
	else
		j = n/2 + 1;

	int *array = malloc(j*sizeof(int));

	array[0] = j;
	for(i = 1; i < j; i++){
		array[i] = k;
		k += 2;
	}

	return array;
}

void printArray(int *array){
	int n = array[0];
	int i;
	for(i = 1; i < n; i++){
		if(array[i] > 0)
			printf("%d ", array[i]);
	}
	printf("\n");
}

int* crivo(int *array){
	int i, j = array[0]/2, k, l;

	for(i = 1; i < j; i++){
		if(array[i] > 0){
			k = array[i];
			for(l = i+k; l < array[0]; l = l + k){
				if(array[l] > 0){
					array[l] = 0;
				}
			}
		}
	}
	return array;
}

int* crivoDeEratostenes(int n){
	int *array = newArray(n);
	array = crivo(array);
	return array;
}

int pi1(int *array){
	int i, j = array[0] - 1;
	int counter = 0;
	for(i = 1; i < j; i++){
		if(array[i] % 4 == 1)
			counter++;
	}
	return counter;
}

int pi3(int *array){
	int i, j = array[0] - 1;
	int counter = 0;
	for(i = 1; i < j; i++){
		if(array[i] % 4 == 3)
			counter++;
	}
	return counter;
}

void printTable(int pi_1, int pi_3){
	printf("pi_1: %d\tpi_3: %d\tratio: %f\n", pi_1, pi_3, (float)pi_1/(float)pi_3);
}

int main(int argc, char *argv[]){
	int *array;
	int pi_1 = 0, pi_3 = 0;
	int x = 3;
	while(!(pi_1 > pi_3)){
		array = crivoDeEratostenes(x);
		pi_1 = pi1(array);
		pi_3 = pi3(array);
		x++;
	}
	printf("menor valor de x para que pi_1 > pi_3: %d\n", x);
	return 0;
}