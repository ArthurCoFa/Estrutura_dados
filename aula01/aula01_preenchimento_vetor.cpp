#include <stdio.h>

int main(){
	
	// Declaração de variáveis
	int vetor[10];
	int i;
	
	// Entrada de dados
	for (i = 0; i < 10; i++){
		printf("Digite o valor do indice %d: ", i);
		scanf("%d", &vetor[i]);
	}
	
	// Saída de dados
	
	for (i = 0; i < 10; i++){
		printf("vetor[%d] = %d\n", i, vetor[i]);
	}
	
	// Conclusão
	return 0;
}
