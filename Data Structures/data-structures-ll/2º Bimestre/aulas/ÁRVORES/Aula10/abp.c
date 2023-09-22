#include <stdio.h>
#include <stdlib.h>

//O tipo da �rvore bin�ria pode ent�o ser dado por:
struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};
typedef struct arv Arv;

//A �rvore � representada pelo ponteiro para o n� raiz. A �rvore vazia � inicializada
//atribuindo-se NULL a vari�vel que representa a �rvore. Uma fun��o simples de
//inicializa��o � mostrada abaixo:
Arv* init (void)
{
	return NULL;
}

//Uma vez constru�da uma �rvore de busca, podemos imprimir os valores da �rvore em
//ordem crescente percorrendo os n�s em ordem sim�trica:
void imprime (Arv* a)
{
	if (a != NULL) {
		imprime(a->esq);
		printf("%d\n",a->info);
		imprime(a->dir);
	}
}

//Essas s�o fun��es an�logas �s vistas para �rvores bin�rias comuns, pois n�o exploram a
//propriedade de ordena��o das �rvores de busca. No entanto, as opera��es que nos
//interessa analisar em detalhes s�o:
//� busca: fun��o que busca um elemento na �rvore;
//� insere: fun��o que insere um novo elemento na �rvore;
//� retira: fun��o que retira um elemento da �rvore.

//Opera��o de busca
//A opera��o para buscar um elemento na �rvore explora a propriedade de ordena��o da
//�rvore, tendo um desempenho computacional proporcional a sua altura (O(log n) para o
//caso de �rvore balanceada). Uma implementa��o da fun��o de busca � dada por:
Arv* busca (Arv* r, int v)
{
	if (r == NULL) return NULL;
	else if (r->info > v) return busca (r->esq, v);
	else if (r->info < v) return busca (r->dir, v);
	else return r;
}

//Opera��o de inser��o
//A opera��o de inser��o adiciona um elemento na �rvore na posi��o correta para que a
//propriedade fundamental seja mantida. Para inserir um valor v em uma �rvore usamos
//sua estrutura recursiva, e a ordena��o especificada na propriedade fundamental. Se a
//(sub-) �rvore � vazia, deve ser substitu�da por uma �rvore cujo �nico n� (o n� raiz)
//cont�m o valor v. Se a �rvore n�o � vazia, comparamos v com o valor na raiz da �rvore,
//e inserimos v na sae ou na sad, conforme o resultado da compara��o. A fun��o abaixo
//ilustra a implementa��o dessa opera��o. A fun��o tem como valor de retorno o eventual
//novo n� raiz da (sub-) �rvore.
Arv* insere (Arv* a, int v)
{
	if (a==NULL) {
		a = (Arv*)malloc(sizeof(Arv));
		a->info = v;
		a->esq = a->dir = NULL;
	}
	else if (v < a->info)
		a->esq = insere(a->esq,v);
	else /* v < a->info */
		a->dir = insere(a->dir,v);
	return a;
}

//O c�digo abaixo ilustra a implementa��o da fun��o para retirar um elemento da �rvore
//bin�ria de busca. A fun��o tem como valor de retorno a eventual nova raiz da (sub-)
//�rvore.
Arv* retira (Arv* r, int v)
{
	if (r == NULL)
		return NULL;
	else if (r->info > v)
		r->esq = retira(r->esq, v);
	else if (r->info < v)
		r->dir = retira(r->dir, v);
	else { /* achou o elemento */
		if (r->esq == NULL && r->dir == NULL) { /* elemento sem filhos */
			free (r);
			r = NULL;
		}		
		else if (r->esq == NULL) { /* s� tem filho � direita */
			Arv* t = r;
			r = r->dir;
			free (t);
		}
		else if (r->dir == NULL) { /* s� tem filho � esquerda */
			Arv* t = r;
			r = r->esq;
			free (t);
		}
		else { /* tem os dois filhos */
			Arv* pai = r;
			Arv* f = r->esq;
			while (f->dir != NULL) {
				pai = f;
				f = f->dir;
			}
			r->info = f->info; /* troca as informa��es */
			f->info = v;
			r->esq = retira(r->esq,v);
		}	
	}
	return r;
}
