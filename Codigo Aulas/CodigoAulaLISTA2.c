#include<stdlib.h>
#include<stdio.h>

// declaracao do no(node) da lista encadeada simples
struct node {
    char info;
    struct node *next;
};

// definicao do tipo Node
typedef struct node Node;

// declaracao da lista em si
struct lista {
    Node *head;
    //struct node *topo;
};

// definicao do tipo Lista
typedef struct lista Lista;

Node *newNode()
{
    Node *n;

    // Se nao puder alocar, retorna NULL
    n = malloc(sizeof(Node));

    return n;
}

void deleteNode(Node *n)
{
    if (n != NULL) free(n);
}

Lista *criar()
{
    Lista *L;

    L = malloc(sizeof(Lista));
    if (L != NULL) L->head = NULL; // lista vazia
    
    return L;
}

// Nessa versao, assume-se que nunca estara cheia
// Poderiamos limitar a quantidade de elementos...
int cheia(Lista *L)
{
    return 0;
}

int vazia(Lista *L)
{
    if (L->head == NULL) return 1;
    else return 0;
}

int inserir(Lista *L, char X)
{
	Node *Paux, *Pant; // Ponteiros auxiliares
	Node *P; // Ponteiro para o novo node
	
	// Se a lista esta cheia, nao pode inserir
	if (cheia(L)) return 0;

	// Cria o novo node e verifica se eh valido
	P = newNode();
	if (P == NULL) return 0;
	P->info = X;

	Paux = L->head;
	Pant = NULL;
	// Busca a possivel posicao de insercao
	while (Paux != NULL && Paux->info < X) {
		Pant = Paux;
		Paux = Paux->next;
	}

	// Elemento ja existente na lista
	if (Paux != NULL && Paux->info == X) return 0;

	if (Paux != L->head) {
		// Caso 1: Node inserido no interior da lista
		// (cauda?)
		Pant->next = P;
		P->next = Paux;
	} else {
		// Caso 2: Node inserido na primeira posicao
		// (cabeca)
		L->head = P;
		P->next = Paux;
	}

	return 1;
}

int remover(Lista *L, char X)
{
	Node *Paux, *Pant;

	Paux = L->head;
	Pant = NULL;

	// Busca o elemento a ser removido
	while (Paux != NULL && Paux->info < X) {
		Pant = Paux;
		Paux = Paux->next;
	}

	if (Paux != NULL && Paux->info == X) {
		// encontrei o elemento e vou retira-lo
		if (Paux != L->head) {
			Pant->next = Paux->next;
		} else {
			//L-head = L->head->next;
			L->head = Paux->next;
		}
		deleteNode(Paux);
		return 1;	// true, deu certo
	} else { // nao encontrei o elemento
		return 0;	// false, nao achou
	}

}

// NAO RESPEITA O TAD
void imprimir(Lista *L)
{
	Node *Paux;
	Paux = L->head;

	while (Paux != NULL) {
		printf("%c ", Paux->info);
		Paux = Paux->next;
	}
	printf("\n");
}

void destruir(Lista *L)
{
	// Avanca o head e deleta o Paux
	Node *Paux;

	while(!vazia(L)) {
		Paux = L->head;
		L->head = Paux->next;
		deleteNode(Paux);
	}

    
	free(L);
}

int main()
{
    Lista *L;

    // Criar a lista
    L = criar();
    if (L == NULL) {
        printf("Erro ao criar a lista\n");
        exit(1);
    }
    
    inserir(L, 'D');
    imprimir(L);
    inserir(L, 'C');
    imprimir(L);
    inserir(L, 'E');
    imprimir(L);
    inserir(L, 'A');
    imprimir(L);
    inserir(L, 'B');
    imprimir(L);

    remover(L, 'D');
    imprimir(L);

    remover(L, 'E');
    imprimir(L);

    printf("%d\n", remover(L, 'A'));
    imprimir(L);

    printf("%d\n", remover(L, 'F'));
    imprimir(L);
    
    destruir(L);
    
    return 0;
}