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
	float v[10];
	float med, var;
	int i;
	/* leitura dos valores */
	for ( i = 0; i < 10; i++ )
		scanf("%f", &v[i]);
	med = media(10,v);
	var = variancia(10,v,med);
	printf ( "Media = %f Variancia = %f \n", med, var);
	return 0;
}
