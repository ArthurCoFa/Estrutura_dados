// Dever de casa, fila pela saída ao ínves de pela entrada

//////////////////////////////////////////////////////
// Programa que Implementa uma fila (Política FIFO) //
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////
// Declaração da estrutura do no //
///////////////////////////////////

struct no {
    int numero;
    struct no *proximo;
};

/////////////////////////////////////
// Função que insere um no na fila //
/////////////////////////////////////

struct no *entrar(struct no *cabeca, int numero){
    // Criação de um novo no
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = cabeca;

    return novoNo;
}

/////////////////////////////////////
// Função que remove um no da fila //
/////////////////////////////////////

struct no *sair(struct no *cabeca){
    // Cenário fácil, fila vazia
    if (cabeca == NULL){
        printf("Não tem nada porra");
        return cabeca;
    }

    // Cenário médio, somente 1 no na fila
    if (cabeca -> proximo == NULL){
        printf("%d\n", cabeca -> numero);
        // Imprimindo o único antes de matar ele
        free(cabeca);
        return NULL;
    }

    // Cenário difícil, fila NÃO vazia e NÃO único
    
    // Ponteiro para no penúltimo
    struct no *penultimo = cabeca;
    while(penultimo -> proximo -> proximo != NULL){
        // Enquanto o próximo do próximo for diferente de Nulo,
        // Ele vai avançar na fila
        penultimo = penultimo -> proximo;
    }
    printf("%d\n", penultimo -> proximo -> numero);
    // Imprimindo o último antes de matar ele
    free(penultimo -> proximo);
    penultimo -> proximo = NULL;
    return cabeca;
}

//////////////////////////////////////////////
// Função principal de execução do programa //
//////////////////////////////////////////////

int main(){
    
    // Declaração de variáveis
    struct no *cabeca = NULL;
    int i = 0;

    cabeca = sair(cabeca);

    for (i = 0; i < 200000; i++){
        cabeca = entrar(cabeca, i);
    }
    for (i = 0; i < 200000; i++){
        cabeca = sair(cabeca);
    }

    return 0;
}