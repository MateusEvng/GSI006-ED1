#include "vetor.h"
#include <stdlib.h> // para funcao exit()
#include <stdio.h> 


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

int main()
{
  Vetor *V;
  int tam, p; // p para posição
  float valor;


  printf("Forneca o tamanho do vetor: ");
  scanf("%d", &tam);
  
  V = criar(tam);
  if (V == NULL) {
    printf("Erro: nao foi possivel criar o vetor\n");
    exit(1);
  }

  for (int i = 0; i < tamanho(V); i++) {
    printf("Digite o %do. valor: ", i+1);
    scanf("%f", &valor);
    inserir(valor, V, i);
  }

  /*for (int i = 0; i < tamanho(V); i++) {
    acessar(V, i, &valor);
    printf("%f ", valor);
  }*/

  float soma = somaVetor(V);

  float media = mediaVetor(V);

  float maior = maiorElemento(V);

  printf("\n(a) somar o elementos de um vetor; R: Soma eh: %.2f.\n", soma);
  printf("\n(b) calcular a media aritmetica dos valores de um vetor; R: Media eh: %.2f.\n", media);
  printf("\n(c) encontrar o maior elemento de um vetor; R: %.2f eh o maior.\n", maior);

  printf("\nInsira a posicao que deseja remover:");
  scanf("%d", &p);

  //teste para confirmar entrada da posição p
  while (p < 0 || p > tam)
  {
    printf("Insira um valor correto.\n");
    printf("\nInsira a posicao que deseja remover: ");
    scanf("%d", &p);
  }

  /*Exercício 2. Escreva, no TAD, uma função para remover um elemento de vetor, dado o vetor e a posição do
  elemento*/
  removeElemento(V, p);

  destruir(V);
  return 0;
}

