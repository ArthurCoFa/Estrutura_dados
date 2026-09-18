// Matriz esparsa: cache de memória secundária.
// Fazer uma duplamente encadeada

////////////////////////////////////////////////
// Programa que implementa uma matriz esparsa //
////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////
// Declaração de constantes //
//////////////////////////////

#define MODULO 3

//////////////////////////////
// Declaração de estruturas //
//////////////////////////////

struct no { // Estrutura que controla as colunas da tabela
    int numero;
    struct no *proximoNo;
};

struct diretor { // Estrutura que controla as linhas da tabela
    int resto;
    struct no *proximoNo;
    struct diretor *proximoDiretor;
};

/////////////////////////////////////
// Declaração de variáveis globais //
/////////////////////////////////////

struct diretor *cabeca = NULL;

///////////////////////////////////////////
// Função que procura o diretor correto, //
// Se não encontrar cria um diretor      //
///////////////////////////////////////////

struct diretor *procurarDiretor(int numero){
    // Atualizações verticais da cabeça

    // Cálcular o resto
    int resto = (numero % MODULO); 
    
    struct diretor *ponteiro = cabeca;

    while ((ponteiro != NULL) && (ponteiro -> resto != resto)){
        // Enquanto ponteiro for diferente de número, não chegou no final da
        // lista de diretores. Então ou ele é nulo ou ele saiu com o resto achando o numero.
        ponteiro = ponteiro -> proximoDiretor;
    }

    // Cenário que o diretor correto foi encontrado
    if (ponteiro != NULL){
        return ponteiro;
    }

    // Cenário que o diretor correto NÃO foi encontrado
    struct diretor *novoDiretor = (struct diretor *) malloc(sizeof(struct diretor));
    novoDiretor -> resto = resto;
    novoDiretor -> proximoNo = NULL;
    novoDiretor -> proximoDiretor = cabeca;
    cabeca = novoDiretor; 
    return novoDiretor;
}

///////////////////////////////////////////
// Função que insere um número na matriz //
///////////////////////////////////////////

void inserir(int numero){
    // Atualizações horizontais

    // Procurar diretor correto
    struct diretor *ponteiroDiretor = procurarDiretor(numero);

    // Inserir pela cabeça
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximoNo = ponteiroDiretor -> proximoNo;
    ponteiroDiretor -> proximoNo = novoNo;
}

///////////////////////////////////////////
// Função que exclui um número da matriz //
///////////////////////////////////////////

void excluir (int numero) {
    // Procurar o ponteiro diretor
    struct diretor *ponteiroDiretor = procurarDiretor(numero);

    // Cenário muito fácil, lista vazia
    if (ponteiroDiretor -> proximoNo == NULL){
        return;
    }

    // Cenário fácil, excluir o primeiro
    if (ponteiroDiretor -> proximoNo -> numero == numero){
        struct no *limpaBunda = ponteiroDiretor -> proximoNo;
        ponteiroDiretor -> proximoNo = ponteiroDiretor -> proximoNo -> proximoNo;
        free(limpaBunda);
        return;
    }

    // Cenário difícil, procurar o número a ser excluido, parar no anterior
    struct no *anterior = ponteiroDiretor -> proximoNo;
    while ((anterior -> proximoNo != NULL) && // Vai avançar enquanto for diferente de nulo E
           (anterior -> proximoNo -> numero != numero)){ 
            // Vai avançar enquanto não achar o número no próximo

        anterior = anterior -> proximoNo;
    }

    // Cenário que não achou o número e o próximo é nulo
    if (anterior -> proximoNo == NULL){
        return;
    }

    // Cenário onde eu encontrei o número
    struct no *limpaBunda = anterior -> proximoNo;
    anterior -> proximoNo = anterior -> proximoNo -> proximoNo; // Próximo vira o re-próximo
    free(limpaBunda);
}

/////////////////////////////////////////
// Função que imprime a matriz na tela //
/////////////////////////////////////////

void imprimir () {
    struct diretor *ponteiroDiretor = cabeca;
    printf("Resto \t Numeros\n");

    while (ponteiroDiretor != NULL){ // Varredura das linhas
        printf("%d \t ", ponteiroDiretor -> resto);
        struct no *ponteiroNo = ponteiroDiretor -> proximoNo;

        while(ponteiroNo != NULL){ // Varredura das colunas
            printf("%d, ", ponteiroNo -> numero);
            ponteiroNo = ponteiroNo -> proximoNo;
        }
        printf("\n");
        ponteiroDiretor = ponteiroDiretor -> proximoDiretor;
    }
}

//////////////////////////////////////////////
// Função principal de execução de programa //
//////////////////////////////////////////////

int main () {

    imprimir();

    printf("\n");

    inserir(5);
    inserir(293);
    inserir(10);
    inserir(4);
    inserir(144);
    inserir(9);
    inserir(6);

    imprimir();

    printf("\n");

    excluir(5);
    excluir(9);
    excluir(4);

    printf("\n");

    imprimir();

    return 0;
}