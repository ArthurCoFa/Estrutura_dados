#include <stdio.h>

int main(){
	
	// Declaracao variaveis
	int vetor[100000];
	int inicio;
	int meio;
	int fim;
	int parametroPesquisa;
	int contador;
	int i;
	
	// Construcao do vetor
	for(i = 0; i < 100000; i++){
		vetor[i] = i;
	}
	
	while (parametroPesquisa != -99){
		printf("Digite o parametro de pesquisa: ");
		scanf("%d", &parametroPesquisa);
		
		inicio = 0;
		fim = 99999;
		contador = 0;
		
		while (inicio <= fim){
			meio = (inicio + fim) / 2;
			contador++;
			
			if(parametroPesquisa == vetor[meio]){
				printf("ACHEI PORRA na tentativa %d\n", contador);
				break;
			} else if(parametroPesquisa < vetor[meio]){
				fim = (meio - 1);
			} else {
				inicio = (meio + 1);
			}
		}
		
	}
	
	return 0;
}
