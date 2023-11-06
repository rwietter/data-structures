#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <math.h> /* sqrt */
#include "D:\TESE\Dropbox\DRIVE_D\Aulas UFSM-FW\Programa��o e Estrutura 2019-2\Aula2\ponto.h"

// Como s� precisamos guardar as coordenadas 
// de um ponto, podemos definir a estrutura
// ponto da seguinte forma:
struct ponto {
	float x;
	float y;
};

Ponto *p;
float px, py;

// A fun��o que cria um ponto dinamicamente 
// deve alocar a estrutura que representa o
// ponto e inicializar os seus campos:
Ponto* cria (float x, float y) {
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));
	if (p == NULL) {
		printf("Mem�ria insuficiente!\n");
		exit(1);
	}
	p->x = x;
	p->y = y;
	return p;
}

// Para esse TAD, a fun��o que libera um ponto deve apenas liberar a estrutura que foi
// criada dinamicamente atrav�s da fun��o cria:
void libera (Ponto* p) {
	free(p);
}

// As fun��es para acessar e atribuir valores �s coordenadas de um ponto s�o de f�cil
// implementa��o, como pode ser visto a seguir.
void acessa (Ponto* p, float* x, float* y) {
	*x = p->x;
	*y = p->y;
}

void atribui (Ponto* p, float x, float y) {
	p->x = x;
	p->y = y;
}

// J� a opera��o para calcular a dist�ncia entre dois pontos pode ser implementada da
// seguinte forma:
float distancia (Ponto* p1, Ponto* p2) {
	float dx = p2->x - p1->x;
	float dy = p2->y - p1->y;
	return sqrt(dx*dx + dy*dy);
}

void soma (Ponto* p1, Ponto* p2, float aumento) {
	do {
		p2->x += 1;
		p2->y += 1;
	} while (distancia(p1, p2)<=aumento);
	return distancia(p1, p2);
}

void subtrai (Ponto* p1, Ponto* p2, float aumento) {
	do {
		p2->x -= 1;
		p2->y -= 1;
	} while (distancia(p1, p2)>=aumento);
	return distancia(p1, p2);
}



main() {
	/*p = cria(10,10);	
	// void acessa (Ponto* p, float* x, float* y) {
	acessa(p, &px, &py);
	printf("%f %f\n", px, py);
	// void atribui (Ponto* p, float x, float y) {
	atribui (p, 15, -15);
	acessa(p, &px, &py);
	printf("%f %f\n", px, py);
	Ponto *p2;
	p2 = cria(20,20);	
	printf("%f",distancia(p, p2));
	libera(p);
	libera(p2);*/
	Ponto *p1, *p2;
	p1 = cria(10,10);	
	p2 = cria(20,20);	
	printf("%f",distancia(p1, p2));
	soma(&px,&py,50);
	printf("\n%f %f",px, py);
}
