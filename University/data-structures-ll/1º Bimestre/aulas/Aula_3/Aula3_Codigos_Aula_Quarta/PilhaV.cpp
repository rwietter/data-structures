// Implementa��o de pilha com vetor

#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

#define MAX 50

// A estrutura que representa o tipo pilha deve, portanto, ser composta pelo vetor e pelo
// n�mero de elementos armazenados.
struct pilha {
	int n;
	float vet[MAX];
};

typedef struct pilha Pilha;

// A fun��o para criar a pilha aloca dinamicamente essa estrutura e inicializa a pilha como
//sendo vazia, isto �, com o n�mero de elementos igual a zero.
Pilha* cria (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->n = 0; /* inicializa com zero elementos */
	return p;
}

// Para inserir um elemento na pilha, usamos a pr�xima posi��o livre do vetor. Devemos
// ainda assegurar que exista espa�o para a inser��o do novo elemento, tendo em vista que
// trata-se de um vetor com dimens�o fixa.
void push (Pilha* p, float v)
{
	if (p->n == MAX) { /* capacidade esgotada */
		printf("OVERFLOW - Capacidade da pilha estourou.\n");
		exit(1); /* aborta programa */
	}
	/* insere elemento na pr�xima posi��o livre */
	p->vet[p->n] = v;
	p->n++;
}	

int vazia (Pilha* p);

// A fun��o pop retira o elemento do topo da pilha, fornecendo seu valor como retorno.
// Podemos tamb�m verificar se a pilha est� ou n�o vazia.
float pop (Pilha* p)
{
	float v;
	if (vazia(p)) {
		printf("UNDERFLOW - Pilha vazia.\n");
		exit(1); /* aborta programa */
	}
	/* retira elemento do topo */
	v = p->vet[p->n-1];
	p->n--;
	return v;
}

// A fun��o mostra_pilha mostra todos os elementos da pilha
// Podemos tamb�m verificar se a pilha est� ou n�o vazia.
void mostra_pilha (Pilha* p)
{
	float v;
	if (vazia(p)) {
		printf("UNDERFLOW - Pilha vazia.\n");
		exit(1); /* aborta programa */
	}
	puts("MOSTRA PILHA:");
	int topo = p->n-1;
	do {
		/* retira elemento do topo */
		v = p->vet[topo];
		printf("%f\n",v);
		topo--;
	} while (topo != -1);
	printf("**** %d\n",topo);
}

/* imprime: vers�o com vetor */
void imprime (Pilha* p)
{
	int i;
	for (i=p->n-1; i>=0; i--)
		printf("%f\n",p->vet[i]);
}

// A fun��o que verifica se a pilha est� vazia pode ser dada por:
int vazia (Pilha* p)
{
	return (p->n == 0); // if (p->n == 0)
}

// Finalmente, a fun��o para liberar a mem�ria alocada pela pilha pode ser:
void libera (Pilha* p)
{
	free(p);
}

main () {
	Pilha *p;
	p = cria();
	push(p, 4);
	push(p, 6);
	push(p, 8);
	mostra_pilha(p);
	printf("\npop() %f\n",pop(p));
	push(p, 10);
	mostra_pilha(p);
}
