// Revisão de listas encadeadas simples

/* Estrutura linear onde os elementos ficam armazenados de forma
independente na memória e se conecta por meio de referências. */

#include <stdio.h> // Biblioteca para interações no terminal
#include <stdlib.h> // Biblioteca com operações de alocação dinâmica de memória

////////////////////////////////////////
// Estrutura que modela o nó da lista //
////////////////////////////////////////

struct no {
    /* 
    Struct: Serve para criar um novo tipo de dado personalizado,
    definindo o molde da estrutura. Onde "no" é o nome dela, poderia
    ser qualquer nome, tipo struct bunda.  
    */

    int numero; // Declarando que na estrutura existe uma váriavel que representa
                // um número inteiro. Poderia ser qualquer outro tipo, ex.: float,
                // char e entre outros. Além disso, ele ocupa 4 bytes.

    struct no *proximo; // Aqui está criando somente um ponteiro(*) para estrutura
                        // esse ponteiro usa 8 bytes, num sistema 64 bits,
                        // esse ponteiro está apontando para um endereço de memória
                        // onde está um struct no. Sem isso, o compilador não saberia
                        // o que está no endereço de memória apontado.
    // Por fim, essa estrutura ocupa 12 bytes de memória.
};

//////////////////////////////////////////////////
// Funcao que insere um nó na lista pelo início //
//////////////////////////////////////////////////

struct no *inserir(struct no *cabeca, int numero){
    /*
    Essa função recebe um ponteiro para a cabeça da estrutura(struct no *cabeca),
    e um número(int numero). 
    E devolve um ponteiro novo que adiciona um nó na lista.
    */
    // Criação de um novo nó
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    /*
    Criação de um ponteiro da estrutura struct no de nome "novoNo", que é um 
    Endereço de memória do tamanho da estrutura(struct no) criada, no caso
    12 bytes(int + * = 4 + 8), que é do tipo ponteiro de struct no (struct no *).
    Sistema operacional que gerencia o bloco de memória do Malloc(Memory Allocation).
    */
    novoNo -> numero = numero;
    // Adiciona ao novo nó o número que vai ser inserido na lista.
    novoNo -> proximo = cabeca;
    // Faz com que o próximo do novo nó seja cabeca. Pois vamos inserir no inicio da lista.
    // Se fosse inserir no final da lista seria novoNo -> proximo = NULL.

    cabeca = novoNo;
    // Só precisamos de cabeça = novo nó, pois não importa se a lista está vazia,
    // sempre vamos colocar na cabeça
    return cabeca;
    // Retornando a cabeça nova
}

//////////////////////////////////////
// Funcao que exclui um nó da lista //
//////////////////////////////////////

struct no *excluir(struct no *cabeca, int numero){
    // Cenário fácil onde a lista está vazia e não tem nada para excluir
    if (cabeca == NULL){
        printf("A lista não tem elementos burro.");
        return cabeca;
    }

    // Eliminando o primeiro elemento da lista
    if(cabeca -> numero == numero){
        struct no *limpaBunda = cabeca;
        // Criação do ponteiro que aponta para o endereço de memória da cabeça
        cabeca = cabeca -> proximo;
        // Movendo a cabeça para o próximo elemento da lista
        free(limpaBunda); // Livrando o espaço de memória, deixando ele livre,
                          // Sem estar alocado.
        return cabeca; // Retornando a cabeca nova.
    }

    // Tirando no meio ou fim da lista
    struct no *anterior = cabeca;
    // Criação do ponteiro que representa o anterior do qual queremos tirar
    while((anterior -> proximo != NULL) && 
          (anterior -> proximo -> numero != numero)){
        /*
        Enquanto o próximo elemento for diferente de nulo E 
        o número do próximo for diferente do que eu quero
        o ponteiro vai avançar na lista.
        */
        anterior = anterior -> proximo;        
    }

    if(anterior -> proximo == NULL){
        // Percorreu a lista, mas não achou o número, então devolve a mesma lista.
        printf("O numero desejado nao existe FDP.\n");
        return cabeca;
    }

    // Achou o número e agora vamos excluir
    struct no *limpaBunda = anterior -> proximo;
    // Pega o endereço de memória do qual temos que apagar
    anterior -> proximo = anterior -> proximo -> proximo;
    // Muda o ponteiro do anterior que queremos remover para o próximo do qual 
    // queremos remover, ex.: A -> B -> C, vamos remover o B, então A -> C.
    free(limpaBunda);
    // Removemos o endereço alocado da memória com o free.
    return cabeca; // Retornamos a cabeça nova sem o número que escolhemos.
}

////////////////////////////////////////
// Funcao que imprime a lista na tela //
////////////////////////////////////////

void imprimir(struct no *cabeca){
    // Função para imprimir a lista na tela
    struct no *varredor = cabeca;
    // Criação do ponteiro que vai varrer a lista
    while (varredor != NULL){
        // Enquanto o próximo não for nulo ele vai imprimir o valor e
        // passar para o próximo nó.
        printf("%d ", varredor -> numero);
        varredor = varredor -> proximo;
    }
}

//////////////////////////////////////////////
// Funcao principal de execucao do programa //
//////////////////////////////////////////////

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