#include <stdio.h>

int main(){
	
	// Declaração de variáveis
	int vetorOriginal[5];
	int vetorInvertido[5];
	int i;
	
	// Entrada de dados
	for (i = 0; i < 5; i++){
		printf("Digite o valor do indice %d: ", i);
		scanf("%d", &vetorOriginal[i]);
	}
	
	// Processamento
	for (i = 0; i < 5; i++){
		vetorInvertido[5 - 1 - i] = vetorOriginal[i]; // 5 pelo tamanho do vetor, - 1 para contagem usada, [tamanho - 1 - i]
	}
	
	// Saída de dados
	for (i = 0; i < 5; i++){
		printf("vetorInvertido[%d] = %d\n", i, vetorInvertido[i]);
	}
	
	// Conclusão
	return 0;
}
