
#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

struct lista {
		int info;
		struct lista* prox;
	};

typedef struct lista Lista;

/* fun��o de inicializa��o: retorna uma lista vazia */
Lista* inicializa (void)
{
	return NULL;
}

// l = inicializa(); /* inicia lista vazia */

/* inser��o no in�cio: retorna a lista atualizada */
Lista* insere_inicio (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	Lista* aux = l;
	do {
		aux = aux->prox;
	} while (aux->prox != NULL);
	printf("%d", aux->info);
	
	novo->info = i;
	novo->prox = NULL;
	aux->prox = novo;
	return l;
}

/* inser��o no in�cio: retorna a lista atualizada */
Lista* insere_fim (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->info = i;
	novo->prox = l;
	return novo;
}

/* fun��o imprime: imprime valores dos elementos */
void imprime (Lista* l)
{
	Lista* p; /* vari�vel auxiliar para percorrer a lista */
	
	for (p = l; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
		
	puts("");
}

/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
int vazia (Lista* l)
{
	if (l == NULL)
		return 1;
	else
		return 0;
}

/* fun��o busca: busca um elemento na lista */
Lista* busca (Lista* l, int v)
{
	Lista* p;
	
	for (p=l; p!=NULL; p=p->prox)
		if (p->info == v)
			return p;
	return NULL; /* n�o achou o elemento */
}

/* fun��o retira: retira elemento da lista */
//Lista* retira (Lista* l, int v) {
//}

//	l = insere(l, 23); /* insere na lista o elemento 23 */
//	l = insere(l, 45); /* insere na lista o elemento 45 */
//	l = insere(l, 56); /* insere na lista o elemento 56 */
//	l = insere(l, 78); /* insere na lista o elemento 78 */

Lista* retira_meio (Lista* l, int v) {
	Lista* aux, *ant;
	aux = l;
	
	while(aux->prox->info == v){
		ant = aux;
		aux = aux->prox;
	};
	//printf("\n%d", ant->info);
	//printf("\n%d", aux->info);
	
	ant->prox = aux->prox;
	
	free(aux);
	
	return l;	
}


//	l = insere(l, 23); /* insere na lista o elemento 23 */
//	l = insere(l, 45); /* insere na lista o elemento 45 */
//	l = insere(l, 56); /* insere na lista o elemento 56 */
//	l = insere(l, 78); /* insere na lista o elemento 78 */

Lista* retira_inicio (Lista* l) {
	Lista* aux, *aux1;
	aux = l;
	
	do {
		aux = aux->prox;
	} while (aux->prox->prox != NULL);
	printf("%d",aux->info);
	aux1 = aux->prox;
	free(aux1);
	aux->prox = NULL;
	return l;
}

//	l = insere(l, 23); /* insere na lista o elemento 23 */
//	l = insere(l, 45); /* insere na lista o elemento 45 */
//	l = insere(l, 56); /* insere na lista o elemento 56 */
//	l = insere(l, 78); /* insere na lista o elemento 78 */

Lista* retira_fim (Lista* l) {
	Lista* aux;
	aux = l->prox;
	free(l);
	l = aux;
	return l;
}

void libera (Lista* l)
{
	Lista* p = l;

	while (p != NULL) {
		Lista* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento */
	
		free(p); /* libera a mem�ria apontada por p */
		p = t; /* faz p apontar para o pr�ximo */
	}
}

int main (void) {
	Lista* l; /* declara uma lista n�o iniciada */
	l = inicializa(); /* inicia lista vazia */
	l = insere_fim(l, 23); /* insere na lista o elemento 23 */
	l = insere_fim(l, 45); /* insere na lista o elemento 45 */
	l = insere_fim(l, 56); /* insere na lista o elemento 56 */
	l = insere_fim(l, 78); /* insere na lista o elemento 78 */
	imprime(l); /* imprimir�: 78 56 45 23 */

	l = retira_meio (l, 56);

	l = insere_inicio(l, 81); /* insere na lista o elemento 78 */
	
	
	imprime(l); /* imprimir�: 78 56 45 23 */
	//l = retira(l, 78);
	imprime(l); /* imprimir�: 56 45 23 */
	//l = retira(l, 45);
	imprime(l); /* imprimir�: 56 23 */
	libera(l);
	return 0;
}
