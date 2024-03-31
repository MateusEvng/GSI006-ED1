#include <stdio.h>
#include <stdlib.h>
#include "quatro.h"


/* Considere uma pilha que armazena caracteres. Faça uma função para determinar se
uma string e da forma xy, onde x é uma cadeia formada por caracteres arbitrários
e y é o reverso de x. Por exemplo, se x = ABCD, então y = DCBA e, portanto,
xy = ABCDDCBA. Considere que x e y são duas strings distintas. */

int main(){

    Pilha *P;
    char c;

    printf("\t\n****Exercicio 4****\n\n");

    P = criar();
    if(P == NULL)
        printf("\nNao foi possivel criar a Pilha.\n");

    while (cheia(P) == 0)
    {
        printf("Insira um Caractere: ");
        scanf(" %c", &c);

        empilha(P, c);
    }

    printf("\n");

    while (desempilha(P, &c) == 1)
    {
        printf("%c", c);
    }
    
    destruir(P);

    return 0;
}