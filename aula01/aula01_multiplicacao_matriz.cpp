#include <stdio.h>

#define LINHA 2
#define COLUNA 2
#define SOMATORIO 3

int main(){
	
	// Declaração de variáveis
	int operando1[LINHA][SOMATORIO];
	int operando2[SOMATORIO][COLUNA];
	int resultado[LINHA][COLUNA];
	int i, j, k;
	
	// Entrada de dados
	for (i = 0; i < LINHA; i++){
		for (j = 0; j < SOMATORIO; j++){
			printf("operando1[%d][%d] = ", i, j);
			scanf("%d", &operando1[i][j]);
		}
	}
	
	for (i = 0; i < SOMATORIO; i++){
		for (j = 0; j < COLUNA; j++){
			printf("operando2[%d][%d] = ", i, j);
			scanf("%d", &operando2[i][j]);
		}
	}
	
	// Processamento
	for (i = 0; i < LINHA; i++){
		for (j = 0; j < COLUNA; j++){
			resultado[i][j] = 0;
			for (k = 0; k < SOMATORIO; k++) {
				resultado[i][j] += (operando1[i][k] * operando2[k][j]);
			}
		}		
	}
	
	// Saída de dados
	for (i = 0; i < LINHA; i++){
		for (j = 0; j < COLUNA; j++){
			printf("%d ", resultado[i][j]);
		}
		printf("\n");
	}
	
	
	// Conclusão
	return 0;
}
