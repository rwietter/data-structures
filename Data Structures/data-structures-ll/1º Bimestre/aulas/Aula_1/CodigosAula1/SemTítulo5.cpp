//Um n�mero ser� quadrado perfeito quando respeitar 
//a regra de forma��o: n2= a. Nessa regra, n � 
//qualquer n�mero inteiro positivo e a � o 
//n�mero quadrado perfeito.

#include <stdio.h>
#include <math.h>

int n, a;

main() {
	scanf("%d",&a);
	n = sqrt(a);
	if ((n*n) == a) // n2= a
		printf("%d eh um quadrado perfeito",n);
	else
		puts("nao eh");	
}
