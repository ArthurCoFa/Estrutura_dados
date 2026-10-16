/////////////////////////////////////////////////
// Programa que implementa uma Árvore de busca //
/////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////////////////////////////////////
// Declaração da estrutura da Árvore //
///////////////////////////////////////

struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
};

///////////////////////////////////////
// Função que insere um nó na Árvore //
///////////////////////////////////////

struct no *inserir(struct no *raiz, int numero) {

    // Cenário fácil, raiz vazia
    if (raiz == NULL) {
        struct no *novoNo = (struct no *)malloc(sizeof(struct no));
        novoNo -> numero = numero;
        novoNo -> esquerda = NULL;
        novoNo -> direita = NULL;
        return novoNo;
    }
    // Cenário difícil, Árvore não vazia
    if (numero < raiz -> numero) {
        raiz -> esquerda = inserir(raiz -> esquerda, numero);
    } else {
        raiz -> direita = inserir(raiz -> direita, numero);
    }
    return raiz;
}

////////////////////////////////////////////
// Função que procura um número na Árvore //
////////////////////////////////////////////

int contador = 0;

void procurar(struct no *raiz, int numero) {
    // Cenário MUITO Fácil, Árvore vazia
    if (raiz == NULL){
        printf("Não achei filho da puta\n");
        contador = 0;
        return;
    }
    // Cenário fácil, dei a sorte de estar procurando o número da raiz
    if (numero == raiz -> numero) {
        printf("Paravens achou em %d tentativas\n", contador);
        contador = 0;
        return;
    }
    // Caso difícil, o número não está na raiz
    contador++;
    if (numero < raiz -> numero) {
        procurar(raiz -> esquerda, numero);
    } else {
        procurar(raiz -> direita, numero);
    }
} 

////////////////////////////////
// Função que navega EM-ORDEM //
////////////////////////////////

void navegarEmOrdem(struct no *raiz) {
    if (raiz == NULL) return;

    navegarEmOrdem(raiz -> esquerda);
    printf("%d, ", raiz -> numero);
    navegarEmOrdem(raiz -> direita);
}

//////////////////////////////////////////////
// Função principal de execução do programa //
//////////////////////////////////////////////

int main() {

    // Declaração de variáveis
    struct no *raiz = NULL;
    int i = 0;
    int numero = 0;

    // Inicialização da aleatoriedade
    time_t t;
    srand(time(&t));

    // Construção da Árvore
    int quantidade = 999;
    for (i = 0; i < quantidade; i++){
        raiz = inserir(raiz, ((quantidade * rand()) % (quantidade - 1)));
    }

    // Realização de buscas
    do {
        printf("Digite um numero: ");
        scanf("%d", &numero);
        procurar(raiz, numero);
    } while (numero != -99);

    // Impressão ordenada
    navegarEmOrdem(raiz);

    return 0;
}
