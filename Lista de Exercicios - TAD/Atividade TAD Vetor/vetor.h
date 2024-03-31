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

struct vetor {
  float dados[10];
  int tamanho;
};

typedef struct vetor Vetor;

Vetor *criar(int tam);
void destruir(Vetor *vet);
int inserir(float valor, Vetor *vet, int pos);
int acessar(Vetor *vet, int pos, float *valor);
int tamanho(Vetor *vet);
//(a) somar o elementos de um vetor; 
float somaVetor(Vetor *vet);
//(b) calcular a média aritmética dos valores de um vetor; 
float mediaVetor(Vetor *vet);
//(c) encontrar o maior elemento de um vetor (lembrando que o vetor não está, necessariamente, ordenado).
float maiorElemento(Vetor *vet);
/*Exercício 2. Escreva, no TAD, uma função para remover um elemento de vetor, dado o vetor e a posição do
elemento*/
void removeElemento(Vetor *vet, int posicao);