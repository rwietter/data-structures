//
// Solucao para o problema "Quermesse" da OBI2000
//
// (jan)
//

#include <stdio.h>

int main(int, char*[])
{
  int teste = 1;
  while (true)
    {
      // l� n�mero de convidados
      int convidados;
      scanf("%d", &convidados);
      
      if (!convidados) break;

      // header
      printf("Teste %d\n", teste);

      // l� entrada e encontra solu��o
      int solucao = -1;
      int posicao = 1;
      while (posicao <= convidados)
        {
          int ingresso;
          scanf("%d", &ingresso);
          
          if (posicao == ingresso) 
            {
              if (solucao != -1)
              	printf("*** + de uma solu��o \n");
              else
                solucao = posicao;
            }
          posicao++;
        }

      // imprime solu�ao
      printf("solucao %d\n", solucao);

      // vai para pr�ximo teste
      teste ++;
    }
}

