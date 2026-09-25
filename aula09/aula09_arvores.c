/*
 Árvore possui uma raiz,
 Nó intermediario no meio,
 Folhas em baixo.
 Uma árvore é um conjunto de subárvores.
 Ordem: Quantidade de filhos. Qual a maior quantidade de filhos que o nó pode ter?
 Nível: Distância do filho para raiz.
*/

////////////////////////////////////////
// Programa que implementa uma Árvore //
////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

///////////////////////////////
// Declaracação da estrutura //
///////////////////////////////

struct no {
  int numero;
  struct no *filho1;
  struct no *filho2;
  struct no *filho3;
  struct no *filho4;
  struct no *filho5;
};

///////////////////////////////////////
// Função que insere um nó na Árvore //
///////////////////////////////////////

struct no *inserir(struct no *raiz, int numero){
    // Cenário fácil, Árvore vazia, folha, raiz ou nó vazio
    if(raiz == NULL){
        struct no *folha = (struct no *) malloc(sizeof(struct no));
        folha -> numero = numero;
        folha -> filho1 = NULL;
        folha -> filho2 = NULL;
        folha -> filho3 = NULL;
        folha -> filho4 = NULL;
        folha -> filho5 = NULL;
        return folha;
    }
    
    // Cenário difícil, Árvore não vazia
    int sorteio = (1 + (rand() % 5));
    if (sorteio == 1){
        // Invocação recursiva, chamei minha própria função, pois filho 1 está vazio.
        raiz -> filho1 = inserir(raiz -> filho1, numero);
    } else if (sorteio == 2){
        raiz -> filho2 = inserir(raiz -> filho2, numero);
    } else if (sorteio == 3){
        raiz -> filho3 = inserir(raiz -> filho3, numero);
    } else if (sorteio == 4){
        raiz -> filho4 = inserir(raiz -> filho4, numero);
    } else {
        raiz -> filho5 = inserir(raiz -> filho5, numero);
    }
    return raiz;
}

///////////////////////////////////////////
// Função que imprime uma Árvore na tela //
///////////////////////////////////////////

void imprimir(struct no *raiz, char *indentacao){
    if (raiz == NULL){
        return;
    }
    printf("%s%d\n", indentacao, raiz -> numero);

    char *temp = (char *) malloc(1024 * sizeof(char));
    strcpy(temp, indentacao);
    strcat(temp, "---");
    
    imprimir(raiz -> filho1, temp);
    imprimir(raiz -> filho2, temp);
    imprimir(raiz -> filho3, temp);
    imprimir(raiz -> filho4, temp);
    imprimir(raiz -> filho5, temp);
}

//////////////////////////////////////////////
// Função principal de execução do programa //
//////////////////////////////////////////////

int main(){
    // Declaração de variáveis
    struct no *raiz = NULL; 
    int i = 0;
    char *indentacao = (char *) malloc(1024 * sizeof(char));
    strcpy(indentacao, "");

    // Inicialização da aleatoriedade
    time_t t;
    srand(time(&t));

    // Inserção de nós na Árvore
    for (i = 0; i < 20; i++){
        raiz = inserir(raiz, i);
    }

    imprimir(raiz, indentacao);
    
    return 0;
}

/*
0
---2
------8
---1
------5
---7
------9
---3
------4
------6
*/