// Problema 5
// Para um dado n�mero inteiro n > 1, o menor inteiro d > 1 que divide n � chamado de fator primo. � poss�vel
// determinar a fatora��o prima de n achando-se o fator primo de substituindo n pelo quociente n / d, repetindo
// essa opera��o at� que n seja igual a 1. Utilizando um dos TADs vistos em sala (Lista, Pilha ou Fila) para
// auxili�-lo na manipula��o de dados, implemente uma fun��o que compute a fatora��o prima de um n�mero
// imprimindo os seus fatores em ordem decrescente. Por exemplo, para n=3960, dever� ser impresso 11 * 5 * 3
// * 3 * 2 * 2 * 2. Justifique a escolha do TAD utilizado.

#include <stdio.h>

int primo (int n) {
	if (n <= 2)
		return 1;
	int i;	
	for(i=2;i<n;i++)	
		if((n%i)==0)
			return 0;
	return 1;		
}

void fatoracao(int n) {
	int vprim[10] = {2,3,5,7,11,13,17}, *prim = vprim;
	int div = 0;
	do {
		if((n % *prim) == 0) { // achei fator primo
			printf("\nfator %d multiplicidade 1", *prim);
			div = n / *prim;
			n = div;
		}
		else
			*prim++;
	} while(n>=1);	
}

main() {
	//printf("%d\n",primo(5));
	//printf("%d\n",primo(6));
	//int i;
	//for(i=2;i<5;i++)
	//fatoracao(5);
	fatoracao(33960);
	//fatoracao(3960);
}
