#include<stdlib.h>
#include<stdio.h>

#define  MAX  5 // Tamanho


/*
Considere a implementação de Filas usando vetor circular. Escreva uma função
int FuraFila(Fila* F, char x) que insere um item na primeira posição da Fila.
O detalhe é que seu procedimento deve ser O(1), ou seja, não pode movimentar os
outros itens da Fila. (Nesse caso, estaremos desrespeitando o conceito de FIFO).
*/

// Definir a ED fila
struct fila {
	int primeiro;
	int final;
	int nro_elementos;
	char elementos[MAX];
};

// Definir o tipo de dados Fila
typedef struct fila Fila;

/*
  Entrada: nao existe
  Saida: ponteiro para Fila, ou NULL caso nao seja possivel cria-la
  Pre-condicao: nao existe
  Pos-condicao: nao existe
*/
Fila *criar()
{
	
	Fila *f;

	f = malloc(sizeof(Fila));
	if (f != NULL) {
		f->primeiro = 0;
		f->final = 0;
		f->nro_elementos = 0;
	}

	return f;
}

/* 
 * Entrada: uma fila
 * Saida: nao existe
 * Pre-condicao: nao existe
 * Pos-condicao: memoria da fila liberada
 */
void destruir(Fila *f)
{
	if (f != NULL) free(f);
}

/*
 * Entrada: uma fila
 * Saida: 1 se a fila for vazia, 0 caso contrario
 * Pre-condicao: fila deve ser valida
 * Pos-condicao: nao existe
 */
int vazia(Fila *f)
{
	if (f->nro_elementos == 0) return 1; // true
	else return 0; // false
}

/*
 * Entrada: uma fila
 * Saida: 1 se a fila for cheia, 0 caso contrario
 * Pre-condicao: fila deve ser valida
 * Pos-condicao: nao existe
 */
int cheia(Fila *f)
{
	if (f->nro_elementos == MAX) return 1; // true
	else return 0; // false
}

/*
 * Entrada: uma fila e um caractere
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: fila tem que ser valida e caractere tambem
 * Pos-condicao: conteudo da pilha alterado
 */
int inserir(Fila *f, char x)
{
    //if (cheia(f))
	if (cheia(f) == 1)
		return 0;	// false
	else {
		f->nro_elementos = f->nro_elementos + 1;
		f->elementos[ f->final ] = x;
		
		// avanca o indice Final. Atencao: o vetor eh circular
		if (f->final == (MAX-1))
		    f->final = 0;
		else
		    f->final = f->final + 1;
		
		return 1;	// true
	}
}

/*
 * Entrada: uma fila e um caractere passado por referencia
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: fila tem que ser valida
 * Pos-condicao: conteudo da fila alterado
 */
int retirar(Fila *f, char *x)
{
	if (vazia(f) == 1)
		return 0;	// false
	else {
	    f->nro_elementos = f->nro_elementos - 1;
	    *x = f->elementos[ f->primeiro ];
	    
	    if (f->primeiro == (MAX-1))
	        f->primeiro = 0;
	    else f->primeiro = f->primeiro + 1;
		
		return 1;	// true
	}
}

int FuraFila(Fila *f, char x){

	f->elementos[f->primeiro] = x;
}

int main()
{
	Fila *F;
	char c, x;

	int teste;

	F = criar();
	if (F == NULL) {
		printf("Erro: nao foi possivel criar a pilha\n");
		exit(-1);
	}

	for (int i = 0; i < MAX; i++) {
		printf("Digite um caractere: ");
		scanf(" %c", &c);

		teste = inserir(F, c);
		//printf("Teste = %d\n", teste);
	}

    //while (!cheia(F)) {
	/*while (cheia(F) == 0) {
		printf("Digite um caractere: ");
		scanf(" %c", &c);
		inserir(F, c);
	}*/


	printf("\nInsira o Fura Fila: ");
	scanf(" %c", &x);

	FuraFila(F, x);

	while (retirar(F, &c) == 1)
		printf("%c ", c);

	destruir(F);

	return 0;
}