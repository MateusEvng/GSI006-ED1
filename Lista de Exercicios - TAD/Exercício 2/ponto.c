#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Desenvolva um TAD Ponto que represente um ponto em R2 com as seguintes operações:

    (a) Criar um ponto P com coordenadas x e y;
    (b) Acessar as coordenadas de um ponto;
    (c) Calcular a distância entre dois pontos.

Note que as coordenadas x e y são valores reais. Para revisar conceitos sobre pontos
e distâncias, acesse este link. Faça, inicialmente, uma especificação textual do TAD e
de suas operações. Em seguida, crie um programa em C que implemente esse TAD e
faça diversos testes (não se esqueça de implementar a função main, ou seja, o usuário
do TAD).
*/

//(a) Criar um ponto P com coordenadas x e y;
Ponto *criar(){

    Ponto *p;
    p = malloc(2*sizeof(Ponto));

    return p;
}

//destroi P
Ponto destruir(Ponto *p){
    if(p != NULL) free(p);
}

//Insere as coordenadas X e Y;
void insere(float x, float y, char a, Ponto *p, int count){

    p[count].x = x;
    p[count].y = y;
    p[count].letraPonto = a;

}

//(b) Acessar as coordenadas de um ponto;
void retorna(Ponto *p, int count){

    printf("\nCoordenada X do Ponto %c: %.2f.\n", p[count].x, p[count].letraPonto);
    printf("Coordenada X do Ponto %c: %.2f.\n\n", p[count].y, p[count].letraPonto);

}

//(c) Calcular a distância entre dois pontos.
