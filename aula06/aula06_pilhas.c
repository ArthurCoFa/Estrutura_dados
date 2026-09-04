//////////////////////////////////////////////////////
// Programa que implementa uma piha (Política FILO) //
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////
// Declaração de estrutura //
/////////////////////////////

struct no {
    int numero;
    struct no *proximo;
};

//////////////////////////////////////
// Função que insere um no na pilha //
//////////////////////////////////////

struct no *push(struct no *cabeca, int numero){
    // Criação de um novo no
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = cabeca;

    return novoNo;
}

//////////////////////////////////////
// Função que remove um no na pilha //
//////////////////////////////////////

struct no *pop(struct no *cabeca){
    // Cenário MUITO fácil, pilha vazia
    if (cabeca == NULL){
        return NULL;
    }

    // Cenário fácil, pilha NÃO vazia
    printf("%d\n", cabeca -> numero);
    struct no *limpaBunda = cabeca;
    cabeca = cabeca -> proximo;
    free(limpaBunda);
    return cabeca;
}

//////////////////////////////////////////////
// Função principal de execução do programa //
//////////////////////////////////////////////

int main(){

    // Declaração de variáveis
    struct no *cabeca = NULL;
    int i = 0;

    cabeca = pop(cabeca);

    for (i = 0; i < 20000000; i++){
        cabeca = push(cabeca, i);
    }
    for (i = 0; i < 20000000; i++){
        cabeca = pop(cabeca);
    }

    return 0;
}