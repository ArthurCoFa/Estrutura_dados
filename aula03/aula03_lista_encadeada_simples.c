// gcc nome_arquivo.c -o nome_arquivo(.exe)
// /.nome_arquivo(.exe)

//////////////////////////////////////////////////////////////
// Programa que implementa uma lista simplesmente encadeada //
//////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////
// Estrutura que modela o no da lista //
////////////////////////////////////////

struct no {
    int numero;
    struct no *proximo;
};

//////////////////////////////////////
// Funcao que insere um no na lista //
//////////////////////////////////////

struct no *inserir(struct no *cabeca, int numero){
    // Criacao do novo No
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = NULL;

    // Cenário facil, lista vazia
    if(cabeca == NULL){
        return novoNo;
    }

    // Cenario dificil, lista nao vazia
    struct no *ultimo = cabeca;
    while(ultimo -> proximo != NULL){
        ultimo = ultimo -> proximo;
    }
    ultimo -> proximo = novoNo;
    return cabeca;
};

//////////////////////////////////////
// Funcao que exclui um no da lista //
//////////////////////////////////////

struct no *excluir(struct no *cabeca, int numero){
    // Cenario muito facil, lista vazia
    if(cabeca == NULL){
        printf("VAI SE FUDER VIADO A LISTA TA VAZIA!!!!!");
        return cabeca;
    } 

    // Cenario facil, excluir o primeiro
    if(cabeca -> numero == numero){
        struct no *limpaBunda = cabeca;
        cabeca = cabeca -> proximo;
        free(limpaBunda);
        return cabeca;
    }

    // Cenario dificil, procurando o no ANTERIOR da lista
    struct no *anterior = cabeca;
    while((anterior -> proximo != NULL) && // Estou no ultimo, varri a lista toda e nao achei
          (anterior -> proximo -> numero != numero)){ // Caso ele ache o numero no proximo ele para
        
        anterior = anterior -> proximo;
    }

    // Cenario dificl, nao foi encontrado
    if(anterior -> proximo == NULL){
        printf("Excluiu um numero que nao existem imbecil");
        return cabeca;
    }

    // Ultimo cenario dificil, excluir o numero no meio ou fim
    struct no *limpaBunda = anterior -> proximo;
    anterior -> proximo = anterior -> proximo -> proximo;
    free(limpaBunda);
    return cabeca;
};

////////////////////////////////
// Funcao que imprime a lista //
////////////////////////////////

void imprimir(struct no *cabeca){
    struct no *ponteiro = cabeca;
    while(ponteiro != NULL) {
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    }
}

//////////////////////////////////////////////
// Funcao principal de execucao do programa //
//////////////////////////////////////////////

int main(){

    struct no *cabeca = NULL;

    // Primeiro teste, imprimir a cabeca, lista vazia

    imprimir(cabeca);
    printf("\n\n\n");
    cabeca = excluir(cabeca, 100);
    printf("\n\n\n");

    cabeca = inserir(cabeca, 1);
    cabeca = inserir(cabeca, 2);
    cabeca = inserir(cabeca, 3);
    cabeca = inserir(cabeca, 4);
    cabeca = inserir(cabeca, 5);
    imprimir(cabeca);
    printf("\n\n\n");
    cabeca = excluir(cabeca, 1);
    cabeca = excluir(cabeca, 3);
    cabeca = excluir(cabeca, 5);
    imprimir(cabeca);

    // Segundo teste
    int i;
    for (i = 0; i < 1000000; i++){
        cabeca = inserir(cabeca, i);
        printf("%d\n", i);
    }

    return 0;
    
}
