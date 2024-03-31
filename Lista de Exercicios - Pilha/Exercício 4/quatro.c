#include <stdio.h>
#include <stdlib.h>
#include "quatro.h"


/* Considere uma pilha que armazena caracteres. Faça uma função para determinar se
uma string e da forma xy, onde x é uma cadeia formada por caracteres arbitrários
e y é o reverso de x. Por exemplo, se x = ABCD, então y = DCBA e, portanto,
xy = ABCDDCBA. Considere que x e y são duas strings distintas. */

//Criar
Pilha *criar(){

    Pilha *p;

    p = malloc(sizeof(Pilha));

    if (p != NULL)
        p->topo = -1;

    return p;
}

//Destruir
void destruir(Pilha *p){

    if(p!= NULL) free(p);

}

//Vazia
int vazia(Pilha *p){

    if (p->topo == -1)
        return 1; //true
    else{
        return 0; //false
    }

}

//Cheia
int cheia(Pilha *p){

    if (p->topo == MAX-1)
        return 1; //true;
    else
    {
        return 0;
    }
}

//Empilhar
int empilha(Pilha *p, char x){

    if(cheia(p) == 1)
        return 0; //false
    else{
        p->topo = p->topo + 1;
        p->caracteres[p->topo];
        return 1;
    }
}

//Desempilha
int desempilha(Pilha *p, char *x){

    if (vazia(p) == 1)
        return 0;
    else
    {
        *x = p->caracteres[p->topo];
        p->topo = p->topo - 1;
        return 1;
    }
}