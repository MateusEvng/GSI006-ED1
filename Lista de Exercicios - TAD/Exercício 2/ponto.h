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


typedef struct ponto
{
    char letraPonto;
    float x;
    float y;

} Ponto;

//(a) Criar um ponto P com coordenadas x e y;
Ponto *criar();

//destroi P
Ponto destruir(Ponto *p);

//Insere as coordenadas X e Y;
void insere(float x, float y, char a, Ponto *p, int count);

//(b) Acessar as coordenadas de um ponto;
void retorna(Ponto *p, int count);

//(c) Calcular a distância entre dois pontos.

