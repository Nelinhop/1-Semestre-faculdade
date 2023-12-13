
#include <stdio.h>
#define LINHA 9
#define COLUNA 9

int i, j;
int vetor[LINHA][COLUNA];


int main()
{ for(i = 0; i< LINHA; i++){
    for(j = 0; j< COLUNA; j++){
        scanf("%d", &vetor[i][j]);}	
	}
	
				
    for (i = 0; i < LINHA; i++) {
		for (j = 0; j < COLUNA; j++) {
			printf("(%d, %d) %d\t", i, j, vetor[i][j]);
		}
		printf("\n");}
		
	for (i = 0; i < LINHA; i++) {
		soma = 0
		for (j = 0; j < COLUNA; j++) {	
		 soma += vetor[i][j];
		}
	}
	
        printf("A soma das linhas pares eh: \n", soma;
 return 0;}

