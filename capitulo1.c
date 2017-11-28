#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_INT 2147483647

unsigned int euclides(int a, int b){
	int aux;

	if(b > a){
		aux = a;
		a = b;
		b = aux;
	}

	while(b != 0){
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

int main(){
	srand(time(NULL));

	int m;				// Número de testes
	int equals1 = 0;	// Número de testes cujo resultado é 1.
	int n;				// Variável utilizada para o loop;

	printf("Entre com o número de testes desejados: ");
	scanf("%d", &m);
	int mdc[m];			// Vetor com o resultado de cada teste.
	n = m-1;
	
	// Execução dos testes
	for(n; n >= 0; n--){
		mdc[n] = euclides(rand() % MAX_INT, rand() % MAX_INT);
		if(mdc[n] == 1)
			equals1++;
	}

	float quociente = (float)equals1 / m;	// Cálculo da probabilidade
	
	printf("\nProbabilidade de inteiros aleatórios serem co-primos: %f\n\n", quociente);
	return 0;
}
