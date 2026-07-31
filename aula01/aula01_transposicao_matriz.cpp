#include <stdio.h>

int main(){
	
	// Declaração de variáveis
	int matrizOriginal[2][3];
	int matrizTransposta[3][2];
	int i, j; // Variavel para geração de matriz
	
	// Entrada de dados
	for (i = 0; i < 2; i++){
		for (j = 0; j < 3; j++){
			printf("matrizOriginal[%d][%d] = ", i, j);
			scanf("%d", &matrizOriginal[i][j]);
		}
	}
	
	// Processamento
	for (i = 0; i < 2; i++){
		for (j = 0; j < 3; j++){
			matrizTransposta[j][i] = matrizOriginal[i][j];
		}
	}
	
	// Saída de dados
	printf("\nMatriz Original\n");
	
	for (i = 0; i < 2; i++){
		for (j = 0; j < 3; j++){
			printf("%d ", matrizOriginal[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz Transposta\n");
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 2; j++){
			printf("%d ", matrizTransposta[i][j]);
		}
		printf("\n");
	}
	
	// Conclusão
	return 0;
}
