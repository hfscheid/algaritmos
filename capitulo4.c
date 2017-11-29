#include <stdlib.h>
#include <stdio.h>



int algoritmoDeExponenciacao(int a, int e, int n){
	int p = 1;
	while(e != 0){
		if(e % 2 != 0){
			p = (a*p) % n;
			e = (e-1)/2;
		}
		if(e % 2 == 0){
			e = e / 2;
		}
		a = (a*a) % n;
	}
	return p;
}


int main(){
	int a, e, n, p;

	printf("Entre com o a base da potência: ");
	scanf("%d", &a);
	printf("Entre com a potência: ");
	scanf("%d", &e);
	printf("Entre com o módulo: ");
	scanf("%d", &n);

	p = algoritmoDeExponenciacao(a, e, n);

	printf("%d elevado a %d e congruente a %d modulo %d.\n", a, e, p, n);
	return 0;
}