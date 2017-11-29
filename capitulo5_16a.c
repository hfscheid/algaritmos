#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int* calculaDivisores(int x){
	int j = x/2;
	int *array = malloc(j * sizeof(int) + 1);
	int i, k = 1;

	for(i = 2; i < j; i++){
		if(x % i == 0){
			array[k] = i;
			k++;
		}
	}
	array[0] = k;
	return array;
}

int comparaDivisores(int *divisores_a, int *divisores_b){
	int i, max;

	if(divisores_a[0] > divisores_b[0])
		max = divisores_b[0];
	else
		max = divisores_a[0];

	for(i = 1; i < max; i++){
		if(divisores_a[i] == divisores_b[i])
			return 1;
	}

	return 0;
}

int primosEntreSi(int a, int b){
	int *divisores_a = calculaDivisores(a);
	int *divisores_b = calculaDivisores(b);
	if(comparaDivisores(divisores_a, divisores_b) == 1)
		return 0;
	else
		return 1;
}

void calculaInverso(int a, int p){
	int result = (int)pow((float)a, (float)p-2) % p;
	printf("O inverso de %d modulo %d é: %d\n", a, p, result);
}

int main(){
	int a, p;
	printf("Entre com o valor desejado: ");
	scanf("%d", &a);
	printf("Entre com o modulo: ");
	scanf("%d", &p);
	if(primosEntreSi(a, p) == 1)
		calculaInverso(a, p);
	else
		printf("Não há inverso de %d módulo %d (números não são coprimos)\n", a, p);
	
}