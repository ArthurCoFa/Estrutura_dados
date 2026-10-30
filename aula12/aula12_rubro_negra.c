////////////////////////////////////////////////////
// Programa que implementa uma árvore rubro-negra //
////////////////////////////////////////////////////

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
    int vermelho;
};

///////////////////////////////////////////////
// Função que executa uma rotação a esquerda //
///////////////////////////////////////////////

struct no *rotacionarEsquerda(struct no *raizVelha) {
    // Correção dos ponteiros
    struct no *raizNova = raizVelha -> direita;
    raizVelha -> direita = raizNova -> esquerda;
    raizNova -> esquerda = raizVelha;
    // Correção das cores
    raizNova -> vermelho = raizVelha -> vermelho;
    raizVelha -> vermelho = 1;
    // Retorno raizNova
    return raizNova;
}

//////////////////////////////////////////////
// Função que executa uma rotação a direita //
//////////////////////////////////////////////

struct no *rotacionarDireita(struct no *raizVelha) {
    // Correção dos ponteiros
    struct no *raizNova = raizVelha -> esquerda;
    raizVelha -> esquerda = raizNova -> direita;
    raizNova -> direita = raizVelha;
    // Correção das cores
    raizNova -> vermelho = raizVelha -> vermelho;
    raizVelha -> vermelho = 1;
    // Retorno raizNova
    return raizNova;
}

///////////////////////////////////////////
// Função que executa subida do vermelho //
///////////////////////////////////////////

void subirVermelho(struct no *raiz) {
    raiz -> vermelho = 1;
    raiz -> esquerda -> vermelho = 0;
    raiz -> direita -> vermelho = 0;
}

///////////////////////////////////
// Função que avalia a cor do nó //
///////////////////////////////////

int isVermelho(struct no *raiz) {
    if(raiz == NULL) return 0;
    return raiz -> vermelho;
}

///////////////////////////////////////
// Função que insere um nó na Árvore //
///////////////////////////////////////

struct no *inserir(struct no *raiz, int numero) {
    // Cenário facil, árvore vazia
    if (raiz == NULL) {
        struct no *novoNo = (struct no *) malloc(sizeof(struct no));
        novoNo -> numero = numero;
        novoNo -> esquerda = NULL;
        novoNo -> direita = NULL;
        novoNo -> vermelho = 1;
        return novoNo;
    }
    // Cenário difícil, árvore não vazia
    if (numero < raiz -> numero) {
        raiz -> esquerda = inserir(raiz -> esquerda, numero);
    } else {
        raiz -> direita = inserir(raiz -> direita, numero);
    }

    // Correções de balanceamento
    if ((!isVermelho(raiz -> esquerda)) && (isVermelho(raiz -> direita))){
        raiz = rotacionarEsquerda(raiz);
    } 
    if ((isVermelho(raiz -> esquerda)) && (isVermelho(raiz -> esquerda -> esquerda))){
        raiz = rotacionarDireita(raiz);
    }
    if ((isVermelho(raiz -> esquerda)) && (isVermelho(raiz -> direita))){
        subirVermelho(raiz);
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

int main(){

    // Declaração de variáveis
    struct no *raiz = NULL; 
    int i = 0;

    // Construção da Árvore
    for (i = 0; i < 10; i++) {
        raiz = inserir(raiz, i);
    }

    raiz -> vermelho = 0;

    imprimir(raiz, "");
    
    return 0;
}