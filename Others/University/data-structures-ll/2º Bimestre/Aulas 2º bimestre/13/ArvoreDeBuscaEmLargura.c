// Busca em largura
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/bfs.html

#include <stdio.h>
#include <stdlib.h>

/* V�rtices de grafos s�o representados por objetos do tipo vertex. */
#define vertex int

typedef struct node *link;

struct graph {
   int V; 
   int A; 
   link *adj; 
};

typedef struct graph *Graph;

struct node { 
   vertex w; 
   link next; 
};

static link NEWnode( vertex w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

Graph GRAPHinit( int V) { 
   vertex v;	
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->A++;
}

// Busca em largura
// Um algoritmo de busca � um algoritmo que percorre um grafo andando pelos arcos de um v�rtice a outro.  
// Depois de visitar a ponta inicial de um arco, o algoritmo percorre o arco e visita sua ponta final.  
// Cada arco � percorrido no m�ximo uma vez.
// H� muitas maneiras de organizar uma busca.  Cada estrat�gia de busca � caracterizada pela ordem em que os 
// v�rtices s�o visitados. Essa estrat�gia est� intimamente relacionada com os conceitos de dist�ncia e caminho m�nimo.

// Algoritmo de busca em largura
// A busca em largura come�a por um v�rtice, digamos s, especificado pelo usu�rio.  O algoritmo visita s, 
// depois visita todos os vizinhos de s, depois todos os vizinhos dos vizinhos, e assim por diante.

// O algoritmo numera os v�rtices, em sequ�ncia, na ordem em que eles s�o descobertos (ou seja, visitados 
// pela primeira vez).  Para fazer isso, o algoritmo usa uma fila (= queue) de v�rtices.  No come�o de cada itera��o, 
// a fila cont�m v�rtices que j� foram numerados mas t�m vizinhos ainda n�o numerados.  O processo iterativo consiste 
// no seguinte:

// enquanto a fila n�o estiver vazia
// 		retire um v�rtice v da fila
// 			para cada vizinho w de v
// 				se w n�o est� numerado
// 					ent�o numere w
// 						ponha w na fila
// No come�o da primeira itera��o, a fila cont�m o v�rtice s, com n�mero 0, e nada mais.

// A fila de v�rtices � manipulada pelas fun��es auxiliares QUEUEinit(), QUEUEput(), QUEUEget(), QUEUEempty() e QUEUEfree().  
// A primeira cria uma fila vazia, a segunda coloca um v�rtice na fila, a terceira tira um v�rtice da fila, a quarta 
// verifica se a fila est� vazia, e a �ltima libera o espa�o ocupado pela fila.
// A numera��o dos v�rtices � registrada num vetor  num[]  indexado pelos v�rtices.  Se v � o k-�simo v�rtice 
// descoberto ent�o num[v] recebe o valor k.	

static int num[1000];
static vertex pa[1000];

/* A fun��o GRAPHbfs() implementa o algoritmo de busca em largura. Ela visita todos os v�rtices do grafo G 
que est�o ao alcance do v�rtice s e registra num vetor num[] a ordem em que os v�rtices s�o descobertos. Esta 
vers�o da fun��o sup�e que o grafo G � representado por listas de adjac�ncia.  (C�digo inspirado no programa 
18.9 de Sedgewick.) */
int fila[1000], f_fila, r_fila;

int QUEUEget (void) {
   //printf("QUEUEget %d\n", fila[f_fila]); 	
   return fila[f_fila++];
}

void QUEUEput (int y) {
   //printf("QUEUEput %d\n", y); 		
   fila[r_fila++] = y;
}

int QUEUEempty (void) {
	if (f_fila > r_fila)
		return 0;
	return 1;	 
}

void QUEUEinit(int trash) {
	f_fila = 0;
	r_fila = 0;
}

void QUEUEfree(void) {
	f_fila = 0;
	r_fila = 0;
} 

void GRAPHtree( Graph G, vertex s) 
{ 
   int cnt = 0;
   vertex v;
   for (v = 0; v < G->V; ++v)
      num[v] = pa[v] = -1;
   QUEUEinit( G->V);
   num[s] = cnt++; 
   pa[s] = -1;
   QUEUEput( s); 

   while (QUEUEempty( ) != 0) {
      vertex v = QUEUEget( ); 
      link a;
      for (a = G->adj[v]; a != NULL; a = a->next)
         if (num[a->w] == -1) {
            num[a->w] = cnt++; 
            pa[a->w] = v;
            QUEUEput( a->w); 
         }
   }
   QUEUEfree( ); 
}

main() {
	Graph G = GRAPHinit(7); 
 	GRAPHinsertArc(G, 0, 2);
 	GRAPHinsertArc(G, 0, 4);
 	GRAPHinsertArc(G, 0, 3);
 	GRAPHinsertArc(G, 2, 4);
 	GRAPHinsertArc(G, 3, 4);
 	GRAPHinsertArc(G, 3, 5);
 	GRAPHinsertArc(G, 4, 5);
 	GRAPHinsertArc(G, 5, 1);
 	GRAPHinsertArc(G, 1, 2);
 	GRAPHinsertArc(G, 1, 4);
 	GRAPHinsertArc(G, 5, 6);
	GRAPHtree(G, 0); 	
	int i;
	for (i = 0; i < 7; i++)
		printf("Nodo %d pai %d\n", i, pa[i]); 
}


