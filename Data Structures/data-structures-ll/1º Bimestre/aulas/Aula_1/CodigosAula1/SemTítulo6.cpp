//Um n�mero ser� quadrado perfeito quando respeitar 
//a regra de forma��o: n2= a. Nessa regra, n � 
//qualquer n�mero inteiro positivo e a � o 
//n�mero quadrado perfeito.

#include <stdio.h>
#include <math.h>

int a;
float n;

main() {
	scanf("%d",&a);
	n = sqrt(a);
	// Testando a 1a propriedade
	// Somente o n�mero quadrado perfeito possui raiz 
	// quadrada exata
	printf("%f",n);
	
	int y = n;
	float x = n - y;
	//x = n - x;
	printf("%d xxxxx %f", y, x);
	if (x > 0.0)
		puts("NAO EH UMA RAIZ QUADRADA EXATA");
	else	
		puts("EH UMA RAIZ QUADRADA EXATA");
		
	// Segunda Regra: Quando o n�mero � quadrado perfeito,
	// ele n�o possui como �ltimo algarismo os seguintes 
	// n�meros: 2, 3, 7 e 8.
	
	7658762
	7658763
	7658767
	7658768	
	b = a % 10;
	if ((b == 2) || (b==3) || (b==7) || (b==8))
		puts("NAO ATENDE A 2a PROPRIEDADE");
	else
		puts("ATENDE A 2a PROPRIEDADE");
	
	printf("%d",b);
}
