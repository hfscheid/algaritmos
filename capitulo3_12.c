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
			for(l = 1+k; l < j; l = l + k){
				array[l] = 0;
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

int main(int argc, char *argv[]){
	int *array = crivoDeEratostenes(atoi(argv[1]));
	printArray(array);
	return 0;
}