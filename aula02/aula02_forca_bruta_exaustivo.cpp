#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int vetor[100000];
	int parametroPesquisa;
	int i;
	
	// Inicializacao da aleatoriedade
	srand(time(NULL));
	
	// Construcao do vetor
	for(i = 0; i < 100000; i++){
		vetor[i] = rand();
	}
	
	// Realizacao de pesquisas
	while(parametroPesquisa != -99){
		printf("Digite o parametro de pesquisa: ");
		scanf("%d", &parametroPesquisa);
		
		for (i = 0; i < 100000; i++){
			if(parametroPesquisa == vetor[i]){
				printf("ACHEI PORRA !!!! No indice %d\n", i);
				break;
			}
		}
	}
	
	return 0;
}
