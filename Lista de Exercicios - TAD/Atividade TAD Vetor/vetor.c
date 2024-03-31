#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

/*
---------------------------------------------------------------------------------------------------------
Exercício 1. Complete o arquivo cliente.c, criando funções para: 
(a) somar o elementos de um vetor; 
(b) calcular a média aritmética dos valores de um vetor; 
(c) encontrar o maior elemento de um vetor (lembrando que o vetor não está, necessariamente, ordenado). 
Complete a função main() para que ela mostre os resultados dessas funções.

Neste exercício, você tem que utilizar as funções do TAD vetor. Lembre-se de que você não deve acessar, 
diretamente, os campos do registro; você pode, apenas, utilizar as funções do TAD que provêem essas 
funcionalidades.

Exercício 2. Escreva, no TAD, uma função para remover um elemento de vetor, dado o vetor e a posição do
elemento (por exemplo, para remover um valor na posição 3).

Você deve editar o TAD, ou seja, criar a função, documento-la e inserir seu cabeçalho no arquivo vetor.h.
Não se esqueça de testar essa função no arquivo cliente.c.
---------------------------------------------------------------------------------------------------------
*/

/*
  Entrada: valor inteiro que representa o tamanho do vetor
  Saida: ponteiro para o vetor, ou NULL caso nao seja possivel cria-lo
  Pre-condicao: o tamanho deve ser menor ou igual ao tamanho maximo do vetor (ou seja, 10)
  Pos-condicao: nao existe
*/
Vetor *criar(int tam)
{
  Vetor *vet;

  vet = malloc(sizeof(Vetor));
  vet->tamanho = tam;

  return vet;
}

/*
  Entrada: ponteiro para um vetor
  Saida: nao existe
  Pre-condicao: nao existe
  Pos-condicao: memoria do vetor eh desalocada
*/
void destruir(Vetor *vet)
{
  if (vet != NULL) free(vet);
}

/*
  Entrada: um valor em ponto flutuante, um ponteiro para vetor e a posicao onde o valor sera inserido
  Saida: 1, se a posicao for valida, 0 caso contrario
  Pre-condicao: o ponteiro tem que ser valido
  Pos-condicao: o valor na posicao eh modificado
*/
int inserir(float valor, Vetor *vet, int pos)
{
  if (pos < 0 || pos >= vet->tamanho)
    return 0;
  
  vet->dados[pos] = valor;
  return 1;
}

/*
  Entrada: um ponteiro para vetor, uma posicao e um valor em ponto flutuante passado por referencia
  Saida: 1, se a posicao for valida, 0 caso contrario
  Pre-condicao: o ponteiro tem que ser valido
  Pos-condicao: a variavel valor eh modificada
*/
int acessar(Vetor *vet, int pos, float *valor)
{
  if (pos < 0 || pos >= vet->tamanho)
    return 0;

  *valor = vet->dados[pos];
  return 1;
}

/*
  Entrada: um ponteiro para vetor
  Saida: tamanho do vetor
  Pre-condicao: ponteiro tem que ser valido
  Pos-condicao: nao existe
*/
int tamanho(Vetor *vet) {
  return vet->tamanho;
}

//(a) somar o elementos de um vetor; 
float somaVetor(Vetor *vet){

  float s = 0.0;

  for(int i = 0; i < vet->tamanho; i++){
    s = s + vet->dados[i];
  }

  return(s);

}
//(b) calcular a média aritmética dos valores de um vetor; 
float mediaVetor(Vetor *vet){

  float s = 0.0;

  for(int i = 0; i < vet->tamanho; i++){
    s = s + vet->dados[i];
  }

  float m = (s / vet->tamanho);

  return(m);
}
//(c) encontrar o maior elemento de um vetor (lembrando que o vetor não está, necessariamente, ordenado).
float maiorElemento(Vetor *vet){

  int maior = 0.0;

  for (int i = 0; i < vet ->tamanho; i++)
  {
    if (i == 0)
    {
      maior = vet->dados[i];
    }
    if (vet->dados[i] > maior)
    {
      maior = vet->dados[i];
    }
     
  }
  
  return(maior);

}
/*Exercício 2. Escreva, no TAD, uma função para remover um elemento de vetor, dado o vetor e a posição do
elemento*/
void removeElemento(Vetor *vet, int posicao){
  
  for (int i = posicao-1; i < vet->tamanho-1; i++)
  {
    vet->dados[i] = vet->dados[i+1];
  }

  vet->tamanho = vet->tamanho - 1;

  printf("\nVetor foi atualizado: ");
  for (int i = 0; i < vet->tamanho; i++)
  {
    printf("%.2f      ", vet->dados[i]);
  }
  
  

}
