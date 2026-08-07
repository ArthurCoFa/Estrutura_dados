#include <stdio.h>

int main (){
	
	// Delcaracao de variaveis
	int vetor[10];
	int i, j;
	int temp;
	
	// Entrada de dados
	for (i = 0; i < 10; i++){
		printf("Digite o numero %d: ", i + 1);
		scanf("%d", &vetor[i]);
	}
	
	// Processamento
	for (i = 0; i < 9; i++) { // A variavel i navega do primeiro até o penúltimo
		for (j = i + 1; j < 10; j++) { // A variavel j navega do próximo até o último
			if(vetor[i] > vetor[j]){
				temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
	
	// Saida de dados
	for(i = 0; i < 10; i++){
		printf("%d\n", vetor[i]);
	}
	
	return 0;
}
