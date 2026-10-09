// Árvore tem no mínimo H (altura de nós)
// E no máximo 2^H - 1 nós (retira a raiz)

// Pré-ordem: Olha raiz, todos da esquerda e todos da direita
// Em-ordem: Todos para esquerda, Raiz, todos a direita.
// Pós-ordem: Todos da esquerda, todos da direita, raiz.

/////////////////////////////////
// Dever de casa gerar Árvores //
/////////////////////////////////

////////////////////////////////////////////////
// Programa que implementa uma Árvore Binária //
////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////////////////////////////////
// Declaração da estrutura do nó //
///////////////////////////////////

struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
};

///////////////////////////////////////
// Função que insere um nó na Árvore //
///////////////////////////////////////

// Recebe a Árvore velha e devolve a Árvore nova
struct no *inserir(struct no *raiz, int numero){
    // Cenário fácil, Árvore vazia
    if (raiz == NULL){
        // Criação do novo Nó
        struct no *novoNo = (struct no *) malloc(sizeof(struct no));
        novoNo -> numero = numero;
        novoNo -> esquerda = NULL;
        novoNo -> direita = NULL;

        // Retorno do novo Nó para a Raiz
        return novoNo;
    }
    
    // Cenário difícil, Árvore NÃO vazia
    int sorteio = (rand() % 2);
    if (sorteio){
        raiz -> esquerda = inserir(raiz -> esquerda, numero);
    } else {
        raiz -> direita = inserir(raiz -> direita, numero);
    }

    return raiz;
}

/////////////////////////////////////////////
// Função que navega a Árvore em Pré-Ordem //
/////////////////////////////////////////////

void navegarPreOrdem(struct no *raiz){
    if (raiz == NULL) return; // Proteção de rabo

    printf("%d", raiz -> numero);
    navegarPreOrdem(raiz -> esquerda);
    navegarPreOrdem(raiz -> direita);
}

////////////////////////////////////////////
// Função que navega a Árvore em Em-Ordem //
////////////////////////////////////////////

void navegarEmOrdem(struct no *raiz){
    if (raiz == NULL) return; // Proteção de rabo

    navegarEmOrdem(raiz -> esquerda);
    printf("%d", raiz -> numero);
    navegarEmOrdem(raiz -> direita);
}

/////////////////////////////////////////////
// Função que navega a Árvore em Pós-Ordem //
/////////////////////////////////////////////

void navegarPosOrdem(struct no *raiz){
    if (raiz == NULL) return; // Proteção de rabo

    navegarPosOrdem(raiz -> esquerda);
    navegarPosOrdem(raiz -> direita);
    printf("%d", raiz -> numero);
}

int main(){

    struct no *raiz = NULL;
    int i = 0;

    time_t t;
    srand(time(&t));

    for (i = 0; i < 10; i++){
        raiz = inserir(raiz, i);
    }

    navegarPreOrdem(raiz);
    printf("\n");
    navegarEmOrdem(raiz);
    printf("\n");
    navegarPosOrdem(raiz);
    printf("\n");
    
    return 0;
}

//////////////////////////////////////////////
/* Raiz o primeiro da pré-ordem e último    //
// Esquerda é o antes da raiz na Em-Ordem   //
// E direita depois do Em-Ordem             */
//////////////////////////////////////////////