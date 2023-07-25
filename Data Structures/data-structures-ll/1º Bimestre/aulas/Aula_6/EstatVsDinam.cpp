#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

// Antes de tratarmos das constru��es de matrizes, vamos recapitular alguns conceitos
// apresentados com vetores. A forma mais simples de declararmos um vetor de inteiros em C
// � mostrada a seguir:
// int v[10];

// ou, se quisermos criar uma constante simb�lica para a dimens�o:

// #define N 10
// int v[N];

// Usando aloca��o din�mica, podemos determinar a dimens�o do vetor em tempo de execu��o:

#define N 5
int *v;

main() {
	v = (int*) malloc(N * sizeof(int));
	int i;
	for(i=0;i<N;i++) {
		scanf("%d",&v[i]);
		v[i] = v[i] + 1;
		printf("%d\n",v[i]);
	}
	free(v);
}

