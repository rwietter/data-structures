// Matriz representada por um vetor simples

// Conceitualmente, podemos representar uma matriz num vetor simples. Reservamos as
// primeiras posi��es do vetor para armazenar os elementos da primeira linha, seguidos dos
// elementos da segunda linha, e assim por diante. Como, de fato, trabalharemos com um
// vetor unidimensional, temos que criar uma disciplina para acessar os elementos da matriz,
// representada conceitualmente. A estrat�gia de endere�amento para acessar os elementos � a
// seguinte: se quisermos acessar o que seria o elemento mat[i][j] de uma matriz, devemos
// acessar o elemento v[i*n+j], onde n representa o n�mero de colunas da matriz.

#define M 3
#define N 4

int mat[M][N];
int v[M*N];

// como achar v[]?

v[i*n+j]; // onde n representa o n�mero de colunas da matriz.

// Com esta estrat�gia, a aloca��o da �matriz� recai numa aloca��o de vetor que tem m*n
// elementos, onde m e n representam as dimens�es da matriz.

float *mat; /* matriz representada por um vetor */
...
mat = (float*) malloc(m*n*sizeof(float));
...

// No entanto, somos obrigados a usar uma nota��o desconfort�vel, v[i*n+j], para acessar
// os elementos, o que pode deixar o c�digo pouco leg�vel.

------------------------------

// Matriz representada por um vetor de ponteiros

// Nesta segunda estrat�gia, cada linha da matriz � representada por um vetor
// independente. A matriz � ent�o representada por um vetor de vetores, ou vetor de ponteiros,
// no qual cada elemento armazena o endere�o do primeiro elemento de cada linha. 

// A aloca��o da matriz agora � mais elaborada. Primeiro, temos que alocar o vetor de
// ponteiros. Em seguida, alocamos cada uma das linhas da matriz, atribuindo seus endere�os
// aos elementos do vetor de ponteiros criado. O fragmento de c�digo abaixo ilustra esta
// codifica��o:

int i;

float **mat; /* matriz representada por um vetor de ponteiros */
...

mat = (float**) malloc(m*sizeof(float*));
for (i=0; i<m; i++)
	m[i] = (float*) malloc(n*sizeof(float));

// A grande vantagem desta estrat�gia � que o acesso aos elementos � feito da mesma forma
// que quando temos uma matriz criada estaticamente, pois, se mat representa uma matriz
// alocada segundo esta estrat�gia, mat[i] representa o ponteiro para o primeiro elemento da
// linha i, e, conseq�entemente, mat[i][j] acessa o elemento da coluna j da linha i.
// A libera��o do espa�o de mem�ria ocupado pela matriz tamb�m exige a constru��o de um
// la�o, pois temos que liberar cada linha antes de liberar o vetor de ponteiros:

...
for (i=0; i<m; i++)
free(mat[i]);
free(mat);

mat[i][j]; // BOA NOTICIA!!!!
