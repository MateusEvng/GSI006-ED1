#include <stdio.h>
#include <stdlib.h>


/* Considere uma pilha que armazena caracteres. Faça uma função para determinar se
uma string e da forma xy, onde x é uma cadeia formada por caracteres arbitrários
e y é o reverso de x. Por exemplo, se x = ABCD, então y = DCBA e, portanto,
xy = ABCDDCBA. Considere que x e y são duas strings distintas. */

#define MAX 8

struct pilha
{
    int topo;
    char caracteres[MAX];
};

typedef struct pilha Pilha;

//Criar
Pilha *criar();

//Destruir
void destruir(Pilha *p);

//Vazia
int vazia(Pilha *p);

//Cheia
int cheia(Pilha *p);

//Empilhar
int empilha(Pilha *p, char x);

//Desempilha
int desempilha(Pilha *p, char *x);
