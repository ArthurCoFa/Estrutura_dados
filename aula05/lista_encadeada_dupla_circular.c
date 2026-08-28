////////////////////////////////////////////////////////////////
// Programa que implementa uma lista encadeada dupla circular //
////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////
// Modelagem da estrutura //
////////////////////////////

struct no {
    int numero;
    struct no *anterior;
    struct no *proximo;
};

//////////////////////////////////////
// Função que insere um no na lista //
//////////////////////////////////////

struct no *inserir(struct no *cabeca, int numero){
    // Criação do novo no
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = NULL;
    novoNo -> anterior = NULL;

    // Cenário fácil, lista vazia
    if(cabeca == NULL){
        cabeca = novoNo;
        cabeca -> proximo = cabeca;
        cabeca -> anterior = cabeca;
        return cabeca;
    }

    // Cenário difícil, lista não vazia
    struct no *ultimo = cabeca;
    while(ultimo -> proximo != cabeca){
        ultimo = ultimo -> proximo;
    }

    ultimo -> proximo = novoNo;
    novoNo -> proximo = cabeca;
    novoNo -> anterior = ultimo;
    cabeca -> anterior = novoNo;
    return cabeca;
}

//////////////////////////////////////
// Função que exclui um no da lista //
//////////////////////////////////////

struct no *excluir(struct no *cabeca, int numero){
    // Cenário MUITO fácil, lista vazia
    if(cabeca == NULL){
        printf("Lista vazia PORRA voce eh burro?");
        return NULL;
    }

    // Cenário fácil, excluir o único
    if((cabeca -> numero == numero) && (cabeca -> proximo == cabeca)){
        free(cabeca);
        return NULL;
    }
    
    // Cenário médio, excluir o primeiro
    if(cabeca -> numero == numero){
        struct no *limpaBunda = cabeca;
        struct no *ultimo = cabeca;
        while(ultimo -> proximo != cabeca){
            ultimo = ultimo -> proximo;
        }
        cabeca -> proximo -> anterior = ultimo;
        cabeca = cabeca -> proximo;
        ultimo -> proximo = cabeca;
        free(limpaBunda);
        return cabeca;
    }

    // Cenário MUITO difícil, excluir no meio ou no fim
    struct no *varrer = cabeca;
    while ((varrer -> proximo != cabeca) &&
           (varrer -> proximo -> numero != numero)){
        varrer = varrer -> proximo;
    }
    if(varrer -> proximo == cabeca){
        printf("Não achei porra\n");
        return cabeca;
    }
    struct no *limpaBunda = varrer -> proximo;
    varrer -> proximo -> proximo -> anterior = varrer;
    varrer -> proximo = varrer -> proximo -> proximo;
    free(limpaBunda);
    return cabeca;
}

//////////////////////////////////////
// Função que imprime um no na tela //
//////////////////////////////////////

void imprimir(struct no *cabeca){
    if(cabeca == NULL){
        printf("Não tem nada PORRA");
        return;
    }

    struct no *ponteiro = cabeca;
    do{
        printf("%d", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    } while(ponteiro != cabeca);
}

//////////////////////////////////////////////////////////////////////////////////////
// Função que imprime de forma inversa para verificar que está duplamente encadeada //
//////////////////////////////////////////////////////////////////////////////////////

void imprimirReverso(struct no *cabeca) {
    if (cabeca == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    struct no *ponteiro = cabeca -> anterior; // Começa no último no
    
    printf("Reverso: ");
    do {
        printf("%d ", ponteiro -> numero);
        ponteiro = ponteiro -> anterior; // Anda para trás
    } while (ponteiro != cabeca -> anterior);
    printf("\n");
}

//////////////////////////////////////////////
// Função principal de execução do programa //
//////////////////////////////////////////////

int main(){

    struct no *cabeca = NULL;


    cabeca = excluir(cabeca, 0);
    printf("\n");
    imprimir(cabeca);

    printf("\n");

    cabeca = inserir(cabeca, 1);
    cabeca = inserir(cabeca, 2);
    cabeca = inserir(cabeca, 3);
    cabeca = inserir(cabeca, 4);
    cabeca = inserir(cabeca, 5);
    imprimir(cabeca);

    printf("\n");

    imprimirReverso(cabeca);

    printf("\n");

    cabeca = excluir(cabeca, 1);
    cabeca = excluir(cabeca, 3);
    cabeca = excluir(cabeca, 5);
    imprimir(cabeca);

    printf("\n");

    cabeca = excluir(cabeca, 2);
    cabeca = excluir(cabeca, 4);
    imprimir(cabeca);

    return 0;
}