// Passagem de vetores para fun��es

/* Incrementa elementos de um vetor */
#include <stdio.h>
void incr_vetor ( int n, int *v )
{
	int i;
	for (i = 0; i < n; i++)
		v[i]++;
}

void incr_vetor_1 ( int n, int *v )
{
	int i;
	for (i = 0; i < n; i++) {
		*v += 1;
		*v++;
	}
		
}


int main (void)
{
	int a[] = {1, 3, 5};
	incr_vetor(3, a);
	printf("%d %d %d \n", a[0], a[1], a[2]);
	incr_vetor_1(3, a);
	printf("%d %d %d \n", a[0], a[1], a[2]);
	return 0;
}
