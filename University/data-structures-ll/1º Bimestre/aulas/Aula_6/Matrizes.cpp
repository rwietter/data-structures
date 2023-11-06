// A linguagem C permite a cria��o de vetores bidimensionais, 
// declarados estaticamente. Por exemplo, para declararmos uma 
// matriz de valores reais com 4 linhas e 3 colunas, fazemos:

float mat[4][3];

// Esta declara��o reserva um espa�o de mem�ria necess�rio para 
// armazenar os 12 elementos da matriz, que s�o armazenados de 
// maneira cont�nua, organizados linha a linha.

float m[4][3] = {{ 5.0,10.0,15.0},
				 {20.0,25.0,30.0},
				 {35.0,40.0,45.0},
				 {50.0,55.0,60.0}};
				 
// As matrizes tamb�m podem ser inicializadas na declara��o:

float mat[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

// Ou podemos inicializar seq�encialmente:

float mat[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};

// O n�mero de elementos por linha pode ser omitido numa 
// inicializa��o, mas o n�mero de colunas deve, obrigatoriamente, 
// ser fornecido:

float mat[][3] = {1,2,3,4,5,6,7,8,9,10,11,12};				 

// Passagem de matrizes para fun��es

void f (..., float (*mat)[3], ...);

//Uma segunda op��o � declarar o par�metro como matriz, podendo 
// omitir o n�mero de linhas2:

void f (..., float mat[][3], ...);

// De qualquer forma, o acesso aos elementos da matriz dentro da 
// fun��o � feito da forma usual, com indexa��o dupla.

// ALTERNATIVA:

// Por exemplo, podemos definir o tipo Matrix4.

typedef float Matrix4[4][4];

// Com esta defini��o podemos declarar vari�veis e par�metros deste 
// tipo:

Matrix4 m; /* declara��o de vari�vel */
...
void f (..., Matrix4 m, ...); /* especifica��o de par�metro */
