// Dever de casa da semana - Lista encadaeada dupla circular

////////////////////////////////////////////////////////////////////////
// Programa que implementa uma lista circular de encadeamento simples // 
////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////
// Modelagem da estrutura //
////////////////////////////

struct no {
    int numero;
    struct no *proximo;
};

//////////////////////////////////////
// Função que insere um no na lista //
//////////////////////////////////////

// Função devolve um ponteiro(*) struct no
struct no *inserir(struct no *cabeca, int numero){ 
    // Criação do novo no
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
                        // tipo do ponteiro
    novoNo -> numero = numero;
    novoNo -> proximo = NULL;

    // Cenário fácil, lista vazia
    if(cabeca == NULL){
        cabeca = novoNo;
        cabeca -> proximo = cabeca;
        return cabeca;
    }

    // Cenário difícil, lista não vazia
    struct no *ultimo = cabeca;
    while(ultimo -> proximo != cabeca){
        ultimo = ultimo -> proximo;
    }
    
    ultimo -> proximo = novoNo;
    novoNo -> proximo = cabeca; // Importante para lista circular
    return cabeca;
}

//////////////////////////////////////
// Função que exclui um no da lista //
//////////////////////////////////////

struct no *excluir(struct no *cabeca, int numero){
    // Cenário MUITO fácil, lista vazia
    if(cabeca == NULL){
        printf("A lista esta vazia PORRA!\n");
        return NULL;
    }

    // Cenário fácil, excluir o único

    // Se o número for o que eu quero excluir 
    // E
    // o proximo da cabeca for a cabeca
    if((cabeca -> numero == numero) && (cabeca -> proximo == cabeca)){
        free(cabeca);
        return NULL;
    }

    // Cenário médio, excluir o primeiro
    if(cabeca -> numero == numero){
        struct no *ultimo = cabeca;
        while(ultimo -> proximo != cabeca){
            ultimo = ultimo -> proximo;
        }
        cabeca = cabeca -> proximo;
        free(ultimo -> proximo); // Limpei a memória da cabeca velha
        ultimo -> proximo = cabeca;
        return cabeca;
    }

    // Cenário MUITO difícil, excluir no meio ou no fim
    struct no *anterior = cabeca;
    // Verifica se o proximo é diferente da cabeca 
    // E
    // se o numero do proximo é diferente do número que eu quero
    while((anterior -> proximo != cabeca) &&
          (anterior -> proximo -> numero != numero)){
        anterior = anterior -> proximo;
    }
    if(anterior -> proximo == cabeca){
        printf("Não achei o número. Vai se FODER\n");
        return cabeca;
    }
    struct no *limpaBunda = anterior -> proximo;
    anterior -> proximo = anterior -> proximo -> proximo;
    free(limpaBunda);
    return cabeca;
}

////////////////////////////////////////
// Função que imprime a lista na tela //
////////////////////////////////////////

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

//////////////////////////////////////////////
// Função principal de execução do programa //
//////////////////////////////////////////////

int main(){

    struct no *cabeca = NULL;

    imprimir(cabeca);
    cabeca = excluir(cabeca, 0);

    printf("\n");

    cabeca = inserir(cabeca, 1);
    cabeca = inserir(cabeca, 2);
    cabeca = inserir(cabeca, 3);
    cabeca = inserir(cabeca, 4);
    cabeca = inserir(cabeca, 5);
    imprimir(cabeca);

    printf("\n");

    cabeca = excluir(cabeca, 1);
    cabeca = excluir(cabeca, 3);
    cabeca = excluir(cabeca, 5);
    imprimir(cabeca);

    printf("\n");

    cabeca = excluir(cabeca, 0);
    cabeca = excluir(cabeca, 2);
    cabeca = excluir(cabeca, 4);
    imprimir(cabeca);

    return 0;
}