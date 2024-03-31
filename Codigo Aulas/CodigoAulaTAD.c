#include<stdlib.h>
#include<stdio.h>

struct vetor {
	int valor[10];
	int tamanho;
};

typedef struct vetor Vetor;

int soma(Vetor vet)
{
	int s;

	s = 0;
	for (int i = 0; i < vet.tamanho; i++) {
		s = s + vet.valor[i];
	}

	return s;
}

// Inserir valor v no vetor vet na posicao pos
void insere(int v, Vetor *vet, int pos)
{
	vet->valor[pos] = v;
	//(*vet).valor[pos] = v;
}

// Atribui tamanho ao vetor
void atr_tamanho(int n, Vetor *vet)
{
	vet->tamanho = n;
}

// Obtem o tamanho do vetor
int peg_tamanho(Vetor vet)
{
	return (vet.tamanho);
}


int main()
{
	Vetor vet;
	int tam, v;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);
	atr_tamanho(tam, &vet);

	for (int i = 0; i < peg_tamanho(vet); i++) {
		printf("Digite o %do. valor: ", i+1);
		scanf("%d", &v);
		//scanf("%d", &vet.valor[i]);
		insere(v, &vet, i);
	}

	printf("O valor da soma eh: %d\n",
			soma(vet));

	return 0;
}
