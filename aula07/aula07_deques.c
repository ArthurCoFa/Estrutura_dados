///////////////////////////////////////////////////////////
// Programa que implementa um deque (Double Ended Queue) //
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////
// Definição das variáveis globais //
/////////////////////////////////////

int contador = 1;

////////////////////////////
// Modelagem da Estrutura //
////////////////////////////

struct no {
    int numero;
    struct no *proximo;
};

struct deque {
    struct no *filaNormal;
    struct no *filaPreferencial;
};

////////////////////////////////////////////////
// Função que insere um nó na fila específica //
////////////////////////////////////////////////

struct no *inserir(struct no *fila, int numero){
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = fila;
    return novoNo;
}

////////////////////////////////////////////////////
// Função que remove um nó de uma fila específica //
////////////////////////////////////////////////////

struct no *remover(struct no *fila){
    // 3 cenários
    // Cenário muito fácil, fila vazia
    if (fila == NULL){
        printf("A fila esta vazia porra, vai tomar cafe\n");
        return NULL;
    }
    // Cenário fácil, só tem 1 na fila
    if (fila -> proximo == NULL){
        printf("%d\n", fila -> numero);
        free(fila);
        return NULL;
    }
    // Cenário difícil, mais de um nó na fila
    struct no *penultimo = fila;
    while (penultimo -> proximo -> proximo != NULL){
        penultimo = penultimo -> proximo;
    }
    printf("%d\n", penultimo -> proximo -> numero);
    free(penultimo -> proximo);
    penultimo -> proximo = NULL;
    return fila;
}

//////////////////////////////////////
// Função que realiza o atendimento //
//////////////////////////////////////

void atender(struct deque *cabeca){
    // Cenário MUITO fácil, ambas filas vazias
    if ((cabeca -> filaNormal == NULL) && (cabeca -> filaPreferencial == NULL)){
        contador = 1;
        return;
    }
    // Cenário fácil, só tem normal
    if(cabeca -> filaPreferencial == NULL){
        cabeca -> filaNormal = remover(cabeca -> filaNormal);
        contador = 1;
        return;
    } 
    // Cenário fácil, só tem preferêncial
    if (cabeca -> filaNormal == NULL){
        cabeca -> filaPreferencial = remover(cabeca -> filaPreferencial);
        contador = 1;
        return;
    }

    // Cenário difícl, ambas filas NÃO estão vazias
    if ((contador % 4) == 0){
        cabeca -> filaNormal = remover(cabeca -> filaNormal);
    } else {
        cabeca -> filaPreferencial = remover(cabeca -> filaPreferencial);
    }
    contador++;
}

//////////////////////////////////////////////
// Função principal de execução do programa //
//////////////////////////////////////////////

int main(){

    struct deque *cabeca = (struct deque *) malloc(sizeof(struct deque));
    cabeca -> filaNormal = NULL;
    cabeca -> filaPreferencial = NULL;

    atender(cabeca);

    printf("\nTeste parte 1\n");

    int i = 0;
    for (i = 0; i < 10; i++){
        cabeca -> filaNormal = inserir(cabeca -> filaNormal, i);
    }

    for (i = 0; i < 10; i++){
        atender(cabeca);
    }

    printf("\nTeste preferencial\n");

    for (i = 1000; i < 1020; i++){
        cabeca -> filaPreferencial= inserir(cabeca -> filaPreferencial, i);
    }
    for (i = 0; i < 10; i++){
        atender(cabeca);
    }

    printf("\nTeste parte 2\n");

    for (i = 0; i < 10; i++){
        cabeca -> filaNormal = inserir(cabeca -> filaNormal, i);
    }

    for (i = 0; i < 20; i++){
        atender(cabeca);
    }

    return 0;
}