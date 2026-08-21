////////////////////////////////////////////////////////////
// Programa que Implementa uma Lista Duplamente Encadeada //
////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////
// Declaração da Estrutura //
/////////////////////////////

struct no {
    int numero;
    struct no *anterior;
    struct no *proximo;
};

//////////////////////////////////////
// Função que Insere um nó na Lista //
//////////////////////////////////////

// Olhar para o nome da função, antes do nome o que ele entrega e depois do nome o que ela recebe
struct no *inserir(struct no *cabeca, int numero){ 
    // Criação do novo nó
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero; // "numero" esquerda dentro do nó, "numero" da direita argumento
    novoNo -> anterior = NULL;
    novoNo -> proximo = cabeca; 

    // Ajuste do apontamento da cabeca
    cabeca = novoNo;

    // Ajuste do ponteiro do anterior do Segundo
    if(cabeca -> proximo != NULL){ // Se passar não estou sozinho
        cabeca -> proximo -> anterior = cabeca;
        /* cabeca -> proximo = Segundo, 
           proximo -> anterior = anterior do Segundo 
           anterior = cabeca, anterior do Segundo vai ser a cabeca(novoNo) */
    }

    // Retorno da cabeca atualizada
    return cabeca;
}

//////////////////////////////////////
// Função que exclui um no da Lista //
//////////////////////////////////////

struct no *excluir(struct no *cabeca, int numero){

    // Cenário fácil, Lista vazia
    if(cabeca == NULL){
        printf("Esta tentando excluir a lista vazia FDP!\n");
        return cabeca;
    }

    // Cenário fácil, Excluir o único
    if(cabeca -> numero == numero){
        struct no *limpaBunda = cabeca;
        cabeca = cabeca -> proximo;
        free(limpaBunda); // Mesmo fazendo free tem que corrigir os ponteiros

        if(cabeca != NULL){ // Cenario de excluir o não único
            cabeca -> anterior = NULL;
        }
        return cabeca;
    }

    // Procura do no para ser excluído
    struct no *ponteiro = cabeca;
    while((ponteiro != NULL) && (ponteiro -> numero != numero)) {
        ponteiro = ponteiro -> proximo;
    }

    // Cenário difícil, não encontrei o número
    if(ponteiro == NULL){
        printf("Seu numero nao foi encontrado FDP\n");
        return cabeca;
    }

    // Cenario dificil, excluir o último
    ponteiro -> anterior -> proximo = ponteiro -> proximo;
    if(ponteiro -> proximo != NULL){ // Cenário muito difícil: excluir no meio
        ponteiro -> proximo -> anterior = ponteiro -> proximo;
    }
    free(ponteiro);


    // Retorno da cabeca Atualizada
    return cabeca;
}

////////////////////////////////
// Função que imprime a Lista //
////////////////////////////////

void imprimir(struct no *cabeca){
    struct no *ponteiro = cabeca;
    while(ponteiro != NULL){
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    }
}

//////////////////////////////////////////////
// Função principal de execução do programa //
//////////////////////////////////////////////

int main(){

    // Declaração da cabeca da lista
    struct no *cabeca = NULL; 

    // Primeiro teste, imprimir a cabeca
    imprimir(cabeca);
    cabeca = excluir(cabeca, 0);
    printf("\n\n\n");

    cabeca = inserir(cabeca, 1);
    cabeca = inserir(cabeca, 2);
    cabeca = inserir(cabeca, 3);
    cabeca = inserir(cabeca, 4);
    cabeca = inserir(cabeca, 5);
    imprimir(cabeca);
    printf("\n\n\n");

    cabeca = excluir(cabeca, 0);
    cabeca = excluir(cabeca, 1);
    cabeca = excluir(cabeca, 3);
    cabeca = excluir(cabeca, 5);
    imprimir(cabeca);
    printf("\n\n\n");

    return 0;
}