#include <stdio.h>
#include <stdlib.h>

/*
1. Escreva um programa que leia um vetor (fornecido pelo usuário) de tamanho 10. O
vetor deve conter apenas números inteiros e não precisa estar ordenado. Em seguida,
implemente as seguintes funções, sem ordenar previamente o vetor.
    (a) Mostrar os valores do vetor;
    (b) Encontrar o maior valor deste vetor;
    (c) Encontrar os dois maiores valores do vetor, percorrendo o vetor apenas uma
    vez;
    (d) Calcular a média dos valores do vetor;
    (e) Verificar se existem dois valores iguais no vetor;
    (f) Mostrar os valores do vetor em ordem inversa;
    (g) Contar o número de elementos ímpares no vetor.
Cada item anterior deve ser implementado em uma função. Na main, você deve
apenas ler os dados do vetor, chamar as funções e imprimir os resultados, quando
possível.
*/

// (a) Mostrar os valores do vetor;
void show(int tamanho, int *array){
    for (int i = 0; i < tamanho; i++)
    {
        printf("P%d: %d.\n", i+1, array[i]);
    }
    
}

// (b) Encontrar o maior valor deste vetor;
int maior(int n, int *array){

    int m = 0; //m para maior

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            m = array[i];
        }
        if (array[i] > m)
        {
            m = array[i];
        }
    }
    
    return m;
}

// (c) Encontrar os dois maiores valores do vetor, percorrendo o vetor apenas uma vez;

// (d) Calcular a média dos valores do vetor;
float media(int n, int *array){

    float m = 0;
    int soma = 0;

    for (int i = 0; i < n; i++)
    {
        soma = soma + array[i];
    }

    m = soma / n;

    return m;

}

// (f) Mostrar os valores do vetor em ordem inversa;
void inverso(int tamanho, int *array){

    int arrayInverso[tamanho];

    int j = tamanho - 1;

    for (int i = 0; i < tamanho; i++)
    {
        arrayInverso[j] = array[i];
        j = j - 1;
    }
    
    for (int i = 0; i < tamanho; i++)
    {
        printf("P%d: %d.\n", i+1, arrayInverso[i]);
    }
    
}

// (g) Contar o número de elementos ímpares no vetor.;
int impar(int tamanho, int *array){

    int ehImpar = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (array[i] % 2 == 0)
        {
            ehImpar++;
        }
        
    }
    
    return ehImpar;
    
}


int main(){

    int count = 10;
    int array[count];

    for (int i = 0; i < count; i++)
    {
        printf("Insira um valor para a posicao %d: ", i+1);
        scanf("%d", &array[i]);
        printf("\n");
    }
    
    //Funções:
    int maiorValor = maior(count, array);
    float mediaArray = media(count, array);
    int quantidadeImpar = impar(count, array);


    printf("\n\n\t*****RESPOSTAS*****\n\n");


    printf("(a) Mostrar os valores do vetor\n");
    printf("     - Return = P's abaixo\n");
    show(count, array);

    printf("\n(b) Encontrar o maior valor deste vetor\n");
    printf("     - Return = %d\n\n", maiorValor);

    printf("\n(d) Calcular a media dos valores do vetor\n");
    printf("     - Return = %.2f\n\n", mediaArray);
    
    printf("\n(f) Mostrar os valores do vetor em ordem inversa\n");
    printf("     - Return = P's abaixo\n");
    inverso(count, array);

    printf("\n(g) Contar o numero de elementos impares no vetor\n");
    printf("     - Return = %d\n\n", quantidadeImpar);
}
