/* C�lculo da media e da vari�ncia de 10 reais (segunda vers�o) */
#include <stdio.h>
/* Fun��o para c�lculo da m�dia */
float media (int n, float* v)
{
	int i;
	float s = 0.0;
	for (i = 0; i < n; i++)
		s += v[i];
	return s/n;
}
/* Fun��o para c�lculo da vari�ncia */
float variancia (int n, float* v, float m)
{
	int i;
	float s = 0.0;
	for (i = 0; i < n; i++)
		s += (v[i] - m) * (v[i] - m);
	return s/n;
}
int main ( void )
{
	float v[5];
	float* pv;
	int i;
	
	pv = v;
	
	/* leitura dos valores */
	for ( i = 0; i < 10; i++ ) {
		scanf("%f", &pv[i]);
	}
	
	for ( i = 0; i < 10; i++ ) {
		printf("%f", *pv++);
	}	

	return 0;
}







