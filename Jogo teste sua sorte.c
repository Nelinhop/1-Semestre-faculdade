#include <stdio.h>

int rodadas, limite, i, valor, jogador, computador, x; 
jogador = 0;
computador = 0;


int main(){
	printf("Bem vindo ao jogo ''Teste sua sorte'' \n");	

	printf("Informe o numero de rodadas que gostaria de participar \n");
		scanf("%d", &rodadas);	

	printf("Agora informe o limite maximo para o gerador de numeros\n");
		scanf("%d", &limite);
	
	for(i = 1; i <= rodadas; i++){
	printf("Insira um valor para a rodada %d: \n", i);
	scanf("%d", &valor);
	x = 1 + rand() % limite;
	if (x == valor){
	
		printf("Voce ganhou a rodada\n");
		jogador++;
		}
	else {
		printf("O computador ganhou a rodada\n");
		computador++; 
		}
}
	if (jogador > computador){
		printf("Voce venceu o jogo a um total de %d VS %d", jogador, computador);
	} else if(computador > jogador) {
		printf("Voce perdeu o jogo a um total de %d VS %d", computador, jogador);}
	  else {
	  	printf("A partida resultou em empate a um total de %d VS %d", jogador, computador);
	  }
	
	return 0;}
