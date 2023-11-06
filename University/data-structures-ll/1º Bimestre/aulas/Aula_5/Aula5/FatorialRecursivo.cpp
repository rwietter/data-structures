/* programa que le um numero e imprime seu fatorial (vers�o 2) */
#include <stdio.h>
int fat (int n);

int main (void)
{
	int n, r;
	scanf("%d", &n);
	r = fat(n);
	printf("Fatorial = %d\n", r);
	return 0;
}

/* Fun��o recursiva para calculo do fatorial */
int fat (int n)
{
	if (n==0)
		return 1;
	else
		return n*fat(n-1);
}
