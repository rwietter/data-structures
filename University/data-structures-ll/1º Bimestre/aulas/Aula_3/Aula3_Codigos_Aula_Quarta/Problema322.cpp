//Escrever uma fun��o que receba como par�metro uma pilha. 
//A fun��o deve retornar o maior elemento da pilha. 
//A passagem deve ser por valor ou refer�ncia?

#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

// O n� da lista para armazenar valores reais pode ser dado por:
struct no {
	float info;
	struct no* prox;
};
typedef struct no No;

// A estrutura da pilha � ent�o simplesmente:
struct pilha {
	No* prim;
};
typedef struct pilha Pilha;

// A fun��o cria aloca a estrutura da pilha e inicializa a lista como sendo vazia.
Pilha* cria (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

// O primeiro elemento da lista representa o topo da pilha. Cada novo elemento � inserido
// no in�cio da lista e, conseq�entemente, sempre que solicitado, retiramos o elemento
// tamb�m do in�cio da lista. Desta forma, precisamos de duas fun��es auxiliares da lista:
// para inserir no in�cio e para remover do in�cio. Ambas as fun��es retornam o novo
// primeiro n� da lista.

/* fun��o auxiliar: insere no in�cio */
No* ins_ini (No* l, float v)
{
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;
	return p;
}

// As fun��es que manipulam a pilha fazem uso dessas fun��es de lista:
void push (Pilha* p, float v)
{
	p->prim = ins_ini(p->prim,v);
}

//Escrever uma fun��o que receba como par�metro uma pilha. 
//A fun��o deve retornar o maior elemento da pilha. 
//A passagem deve ser por valor ou refer�ncia?
float maior_da_pilha (Pilha* p) {
	No* q;
	printf("\nImprime:\n");
	float maior = p->prim->info;
	
	q=p->prim;
	do {
		//printf("%f\n",q->info);
		if (q->info > maior)
			maior = q->info;
		q=q->prox;
	} while (q!=NULL);	   
	return maior;
}

main () {
	Pilha *p;
	p = cria();
	push(p, 4);
	push(p, 6);
	push(p, 8);
	printf("\nO maior elemento da pilha eh %f", maior_da_pilha (p));
}

		//printf("%f\n",q->info);
	/*do {
		int aux = pop(p);
	} while (p != NULL);*/

