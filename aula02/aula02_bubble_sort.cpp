#include <stdio.h>

int main(){
	// Declaracao de variaveis
	int vetor[10];
	int i;
	int continuar = 1; // Funciona com bool também
	int temp;
	
	// Entrada de dados
	for(i = 0; i < 10; i++){
		printf("Digite o numero %d: ", i + 1);
		scanf("%d", &vetor[i]);
	}
	
	// Processamento
	while (continuar){
		continuar = 0;
		for(i = 0; i < 9; i++){
			if(vetor[i] > vetor[i + 1]){
				temp = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = temp;
				continuar = 1;
			}	
		}
	}
	
	// Saida de dados
	for(i = 0; i < 10; i++){
		printf("%d\n", vetor[i]);
	}
	
	return 0;
}
