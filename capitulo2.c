#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void fermat(double n){
	if((int)n % 2 == 0){
		printf("O número é par\n");
		return;
	}

	double x = floor(sqrt(n));
	double isPrime = (n+1)/2;

	if(pow(x, 2.0) == n){
		printf("%lf é raiz quadrada de %lf\n", x, n);
		return;
	}
	else{
		double y = 0.1;
		while(1){
			x = x + 1;
			y = sqrt(pow(x, 2.0)-n);
			if(x == isPrime){
				printf("%lf é primo\n", n);
				return;
			}
			if(y*10 == (int)y*10){
				printf("dois fatores são: %lf, %lf\n", x + y, x - y);
				return;
			}
		}

	}
}
int main(){
	double value;
	printf("Entre com o número a ser fatorado: ");
	scanf("%lf", &value);
	fermat(value);
	return 0;
}
