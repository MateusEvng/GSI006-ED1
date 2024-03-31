#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

int main(){

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

   Ponto *P;
   float coordenadaX, coordenadaY = 0.0;
   char letra;

   //(a) Criar um ponto P com coordenadas x e y;
   for (int i = 0; i < 2; i++)
   {
        P = criar();
        if (P == NULL)
        {
            printf("\n\terror: N foi possivel criar o ponto...\n");
        }
        
   }
   
   for (int i = 0; i < 2; i++)
   {

    printf("Digite uma letra para representar o ponto: ");
    scanf(" %c", &letra);
    printf("\n");

    printf("Insira a coordenada X do Ponto: ");
    scanf("%f", &coordenadaX);
    printf("\n");

    printf("Insira a coordenada Y do Ponto: ");
    scanf("%f", &coordenadaY);
    printf("\n");    

    insere(coordenadaX, coordenadaY, letra, P, i);

   }
   
   for (int i = 0; i < 2; i++)
   {
    retorna(P, i);
   }
   






    return 0;
}