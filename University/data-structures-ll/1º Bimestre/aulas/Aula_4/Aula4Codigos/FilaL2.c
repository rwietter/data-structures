#include <stdio.h>

// O n� da lista duplamente encadeada para armazenar valores reais pode ser dado por:
struct no2 {
	float info;
	struct no2* ant;
	struct no2* prox;
};
typedef struct no2 No2;

// A estrutura da fila dupla agrupa os ponteiros para o in�cio e o fim da lista:
struct fila2 {
	No2* ini;
	No2* fim;
};
typedef struct fila2 Fila2;

// Interessa-nos discutir as fun��es para inserir e retirar elementos. As demais s�o
// praticamente id�nticas �s de fila simples. Podemos inserir um novo elemento em
// qualquer extremidade da fila. Portanto, precisamos de duas fun��es auxiliares de lista:
// para inserir no in�cio e para inserir no fim. Ambas as fun��es s�o simples e j� foram
// exaustivamente discutidas para o caso da lista simples. No caso da lista duplamente
// encadeada, a diferen�a consiste em termos que atualizar tamb�m o encadeamento para o
// elemento anterior. Uma poss�vel implementa��o dessas fun��es � mostrada a seguir.
// Essas fun��es retornam, respectivamente, o novo n� inicial e final.

/* fun��o auxiliar: insere no in�cio */
No2* ins2_ini (No2* ini, float v) {
	No2* p = (No2*) malloc(sizeof(No2));
	p->info = v;
	p->prox = ini;
	p->ant = NULL;
	if (ini != NULL) /* verifica se lista n�o estava vazia */
		ini->ant = p;
	return p;
}

/* fun��o auxiliar: insere no fim */
No2* ins2_fim (No2* fim, float v) {
	No2* p = (No2*) malloc(sizeof(No2));
	p->info = v;
	p->prox = NULL;
	p->ant = fim;
	if (fim != NULL) /* verifica se lista n�o estava vazia */
		fim->prox = p;
	return p;
}

// Uma poss�vel implementa��o das fun��es para remover o elemento do in�cio ou do fim
// � mostrada a seguir. Essas fun��es tamb�m retornam, respectivamente, o novo n�
// inicial e final.

/* fun��o auxiliar: retira do in�cio */
No2* ret2_ini (No2* ini) {
	No2* p = ini->prox;
	if (p != NULL) /* verifica se lista n�o ficou vazia */
		p->ant = NULL;
	free(ini);
	return p;
}

/* fun��o auxiliar: retira do fim */
No2* ret2_fim (No2* fim) {
	No2* p = fim->ant;
	if (p != NULL) /* verifica se lista n�o ficou vazia */
		p->prox = NULL;
	free(fim);
	return p;
}

// A fun��o cria aloca a estrutura da fila e inicializa a lista como sendo vazia.

Fila2* cria (void)
{
	Fila2* f = (Fila2*) malloc(sizeof(Fila2));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

// As fun��es que manipulam a fila fazem uso dessas fun��es de lista, atualizando os
// ponteiros ini e fim quando necess�rio.

void insere_ini (Fila2* f, float v) {
	f->ini = ins2_ini(f->ini,v);
	if (f->fim==NULL) /* fila antes vazia? */
		f->fim = f->ini;
}

void insere_fim (Fila2* f, float v) {
	f->fim = ins2_fim(f->fim,v);
	if (f->ini==NULL) /* fila antes vazia? */
		f->ini = f->fim;
}

// A fila estar� vazia se a lista estiver vazia:

int vazia (Fila2* f)
{
	return (f->ini==NULL);
}

float retira_ini (Fila2* f) {
	float v;
	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1); /* aborta programa */
	}
	v = f->ini->info;
	f->ini = ret2_ini(f->ini);
	if (f->ini == NULL) /* fila ficou vazia? */
		f->fim = NULL;
	return v;
}

float retira_fim (Fila2* f) {
	float v;
	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1); /* aborta programa */
	}
	v = f->fim->info;
	f->fim = ret2_fim(f->fim);
	if (f->fim == NULL) /* fila ficou vazia? */
		f->ini = NULL;
	return v;
}

main () {
	Fila2* fi = cria();
	insere_ini (fi, 10.5);
	insere_fim (fi, 11.5);
}
