#include <stdio.h>

// Para essa implementa��o, os �ndices do vetor s�o incrementados de maneira que seus
// valores progridam �circularmente�. Desta forma, se temos 100 posi��es no vetor, os
// valores dos �ndices assumem os seguintes valores:

// 0, 1, 2, 3, �, 98, 99, 0, 1, 2, 3, �, 98, 99, 0, 1,�

// Podemos definir uma fun��o auxiliar respons�vel por incrementar o valor de um �ndice.
// Essa fun��o recebe o valor do �ndice atual e fornece com valor de retorno o �ndice
// incrementado, usando o incremento circular. Uma poss�vel implementa��o dessa fun��o
// �:

# define N 20

int incr (int i)
{
	if (i == N-1)
		return 0;
	else
		return i+1;
}

// Essa mesma fun��o pode ser implementada de uma forma mais compacta, usando o
// operador m�dulo:

int incrC(int i)
{
	return (i+1)%N;
}

// Com o uso do operador m�dulo, muitas vezes optamos inclusive por dispensar a fun��o
// auxiliar e escrever diretamente o incremento circular:
// ...
// i=(i+1)%N;
// ...

main() {
	int j=0; int i = 0;
	for(j=0;j<50;j++) {
		i = incrC(i);
		printf("%d\n",i);
	}
		
}
