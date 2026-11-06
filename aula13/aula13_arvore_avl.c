////////////////////////////////////////////
// Programa que Implementa uma Árvore AVL //
////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////
// Declaração da estrutura do nó //
///////////////////////////////////

struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
    int altura;
};

////////////////////////////////////////
// Função que recupera a altura do nó //
////////////////////////////////////////

int getAlturaDoNo (struct no *raiz) {
    if (raiz == NULL) return 0;
    return raiz -> altura;
}

///////////////////////////////////////////////////
// Função que descobre o maior número entre dois //
///////////////////////////////////////////////////

int getMaximoEntreDoisNumeros (int a, int b) {
    return (a > b) ? a : b;
}

////////////////////////////////////////////
// Função que calculo o balanço da Árvore //
////////////////////////////////////////////

int getBalanco (struct no *raiz) {
    // Função que diz qual é o maior lado, positivo = esquerda, negativo = direita
    if (raiz == NULL) return 0;
    return ((getAlturaDoNo(raiz -> esquerda)) - getAlturaDoNo(raiz -> direita));
}

///////////////////////////////////////////////
// Função que rotaciona a raiz para esquerda //
///////////////////////////////////////////////

struct no *rotacionarEsquerda (struct no *raizVelha) {
    // Correção dos ponteiros
    struct no *raizNova = raizVelha -> direita;
    raizVelha -> direita = raizNova -> esquerda;
    raizNova -> esquerda = raizVelha;

    // Correção das alturas
    raizVelha -> altura = (getMaximoEntreDoisNumeros(
                            getAlturaDoNo(raizVelha -> esquerda), 
                            getAlturaDoNo(raizVelha -> direita)) + 1);

    raizNova -> altura = (getMaximoEntreDoisNumeros(
                            getAlturaDoNo(raizNova -> esquerda), 
                            getAlturaDoNo(raizNova -> direita)) + 1);
    // Retorno da Raiz Nova
    return raizNova;
}

//////////////////////////////////////////////
// Função que rotaciona a raiz para Direita //
//////////////////////////////////////////////

struct no *rotacionarDireita (struct no *raizVelha) {
    // Correção dos ponteiros
    struct no *raizNova = raizVelha -> esquerda;
    raizVelha -> esquerda = raizNova -> direita;
    raizNova -> direita = raizVelha;

    // Correção das alturas
    raizVelha -> altura = (getMaximoEntreDoisNumeros(
                            getAlturaDoNo(raizVelha -> esquerda), 
                            getAlturaDoNo(raizVelha -> direita)) + 1);

    raizNova -> altura = (getMaximoEntreDoisNumeros(
                            getAlturaDoNo(raizNova -> esquerda), 
                            getAlturaDoNo(raizNova -> direita)) + 1);
    // Retorno da Raiz Nova
    return raizNova;
}

///////////////////////////////////////
// Função que insere um nó na Árvore //
///////////////////////////////////////

struct no *inserir (struct no *raiz, int numero) {
    // Cenário fácil, árvore vazia
    if (raiz == NULL) {
        struct no *novoNo = (struct no *) malloc (sizeof(struct no));
        novoNo -> numero = numero;
        novoNo -> esquerda = NULL;
        novoNo -> direita = NULL;
        novoNo -> altura = 1;
        return novoNo;
    }

    // Cenário difícil, Árvore não vazia
    if (numero < raiz -> numero) {
        raiz -> esquerda = inserir(raiz -> esquerda, numero);
    } else {
        raiz -> direita = inserir(raiz -> direita, numero);
    }

    // Correções da balanceamento
    raiz -> altura = (1 + getMaximoEntreDoisNumeros(
                        getAlturaDoNo(raiz -> esquerda), 
                        getAlturaDoNo(raiz -> direita)));

    int balanco = getBalanco(raiz);

    // Inclinando a esquerda, numero menor do que a esquerda
    if ((balanco > 1) && (numero < raiz -> esquerda -> numero)) {
        raiz = rotacionarDireita(raiz);
    }
    // Inclinando a direita, numero maior do que a direita
    if ((balanco < -1) && (numero > raiz -> direita -> numero)) {
        raiz = rotacionarEsquerda(raiz);
    }
    // Inclinação a esquerda, numero maior do que a esquerda
    if ((balanco > 1) && (numero < raiz -> direita -> numero)) {
        raiz -> direita = rotacionarDireita(raiz -> direita);
        raiz = rotacionarEsquerda(raiz);
    }
    // Inclinação a direita, numero menor do que a direita
    if ((balanco < -1) && (numero < raiz -> direita -> numero)) {
        raiz -> direita = rotacionarDireita(raiz -> direita);
        raiz = rotacionarEsquerda(raiz);
    }
    return raiz;
}

/////////////////////////////////
// Função que imprime a Árvore //
/////////////////////////////////

void imprimir(struct no *raiz, char *indentacao) {
    if (raiz == NULL) return;

    printf("%s%d\n", indentacao, raiz -> numero);

    char *temp = (char *) malloc (1024 * sizeof(char));
    strcpy(temp, indentacao);
    strcat(temp, "---");

    imprimir(raiz -> esquerda, temp);
    imprimir(raiz -> direita, temp);
}

//////////////////////////////////////////////
// Função principal de execução do programa //
//////////////////////////////////////////////

int main() {
    // Declaração das variáveis
    struct no *raiz = NULL;
    int i = 0;

    // Construção da Árvore
    for (i = 0; i < 10; i++) {
        raiz = inserir(raiz, i);
    }

    imprimir(raiz, "");

    return 0;
}