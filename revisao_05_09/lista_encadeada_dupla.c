// Revisão de lista encadeada dupla

#include <stdio.h> // Biblioteca para interações no terminal
#include <stdlib.h> // Biblioteca com operações de alocação dinâmica de memória

/////////////////////////////
// Declaração da estrutura //
/////////////////////////////

struct no {
    /* 
    Struct: Serve para criar um novo tipo de dado personalizado,
    definindo o molde da estrutura. Onde "no" é o nome dela, poderia
    ser qualquer nome, tipo struct bunda.  
    */
    int numero;
    struct no *proximo;
    struct no *anterior;
    /* Criação de um ponteiro para referencias de endereços de memória anteriores
    a ele, adicionando mais 8 bytes para o total da estrutura. */
    /*
    A estrutura ocupa 20 bytes, porém devido a arquitetura faz com que a 
    estrutura seja divisível por 8, adicionando 4 bytes para chegar em 24 bytes. 
    */
};

//////////////////////////////////////
// Função que insere um nó na lista //
//////////////////////////////////////

struct no *inserir(struct no *cabeca, int numero){
    // Criação de um novo nó
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = cabeca;
    // Necessário para o "cabeca = novoNo" funcionar
    novoNo -> anterior = NULL;
    // Novo nó é nulo, pois será adicionado no início da estrutura

    cabeca = novoNo;
    // Sempre vai passar, pois ele está sendo adicionado no início
    // A cabeça antiga vai virar o próximo na cabeça nova

    if(cabeca -> proximo != NULL){
        // Se passar significa que ele não está sozinho
        cabeca -> proximo -> anterior = cabeca;
        // Aponta o anterior da cabeça antiga para a cabeça nova,
        // Concluindo a parte dupla
    }

    // Retorno da cabeça nova
    return cabeca;
}

//////////////////////////////////////
// Função que exclui um nó da lista //
//////////////////////////////////////

struct no *excluir(struct no *cabeca, int numero){
    // Cenário fácil com a lista vazia
    if(cabeca == NULL){
        printf("A lista esta vazia animal.");
        return cabeca;
    }

    // Cenário de retirar o primeiro
    if(cabeca -> numero == numero){
        // Entrou no if significa que número que quero retirar é o primeiro
        struct no *limpaBunda = cabeca;
        // Criação do ponteiro para limpar a bunda da memória
        cabeca = cabeca -> proximo;
        // Apontando a cabeça para o próximo da lista
        if(cabeca != NULL){
            // Verifica se a nova cabeça não é nula, para adicionar o anterior
            cabeca -> anterior = NULL;
        }   
        free(limpaBunda);
        // Limpa bunda da memória
        return cabeca;
        // Retorna a cabeça nova sem o número desejado
    }

    struct no *busca = cabeca;
    while((busca != NULL) && (busca -> numero != numero)){
        // Enquanto o ponteiro de busca não for nulo E
        // Não for o número que estou procurando
        // Ele vai avançar na lista
        busca = busca -> proximo;
    }
    // Se não encontrou
    if(busca == NULL){
        printf("Escolheu numero que nao existe imbecil.");
        return cabeca;
    }
    // Achamos o número então:
    busca -> anterior -> proximo = busca -> proximo;
    // Ajeita o ponteiro do anterior para o depois do número a ser excluido
    // Ex.: Queremos excluir o B. A -> B -> C. Apontamos o A para o C
    // A -> C.
    if(busca -> proximo != NULL){
        // Se o próximo do que queremos excluir é diferente de nulo
        busca -> proximo -> anterior = busca -> anterior;
        // Ajeitamos o ponteiro para o anterior do que queremos excluir
        // Ex.: A <- B <- C. A <- C
    }
    free(busca); // Super importante limpar a bunda da memória
    return cabeca;
    // Por fim retornar a cabeça nova.
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

int main(){

    struct no *cabeca = NULL;
    // Criando a cabeça da lista para os testes.

    // Primeiro teste, imprimir a cabeca, lista vazia
    imprimir(cabeca);
    printf("\n-- Fim primeiro teste --\n");

    // Segundo teste apagar um nó que não existe, pois está vazia
    cabeca = excluir(cabeca, 0);

    printf("\n-- Fim do segundo teste --\n");

    // Terceiro teste inserindo 5 número na lista
    cabeca = inserir(cabeca, 1);
    cabeca = inserir(cabeca, 2);
    cabeca = inserir(cabeca, 3);
    cabeca = inserir(cabeca, 4);
    cabeca = inserir(cabeca, 5);
    imprimir(cabeca);

    printf("\n-- Fim do terceiro teste --\n");

    // Quarto teste, excluindo no início, meio e fim da lista.
    cabeca = excluir(cabeca, 1);
    cabeca = excluir(cabeca, 3);
    cabeca = excluir(cabeca, 5);
    imprimir(cabeca);

    printf("\n-- Fim do quarto teste --\n");

    return 0;
}