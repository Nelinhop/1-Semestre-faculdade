#include <stdio.h>
#define TAMANHO 100


int i, numeros, vquant, quantidade[TAMANHO],opcao, posmaior, posmenor, maior1, menor1;
char letra, produtos[TAMANHO], pesquisa;
float preco[TAMANHO], valor, maior, menor, precototal;
int main ()
{
  printf ("Insira a quantidade de produtos a serem inseridas: \n");
  scanf ("%i", &numeros);
  for (i = 0; i < numeros && i < 100; i++)
    {
      printf ("Insira a letra identificadora numero %d: \n", i + 1);
      scanf ("%c", &letra);
      letra = getchar ();
      printf ("Agora insira a quantidade do produto N%d: \n ", i + 1);
      scanf ("%i", &vquant);
      printf ("Digite o preco do produto N%d: \n", i + 1);
      scanf ("%f", &valor);
      produtos[i] = letra;
      quantidade[i] = vquant;
      preco[i] = valor;
    }
  for (i = 0; i < numeros; i++)
    {
      printf("Produto N%i: letra de identificacao %c \n",
	 i + 1, produtos[i]);
	 printf("Quantidade no estoque de: %i \n", quantidade[i]); 
	 printf("Valor unitario do produto: %f \n", preco[i]);
	 printf("\n");
    }
    
   do{
    printf("Escolha uma acao: \nVer produto mais caro (1) \n\nVer produto mais barato (2) \n\nVer maior numero em estoque (3) \n\nVer menor numero em estoque(4) \n\nProcurar um produto por identicicacao(5)\n\nVer o preco total do estoque(6)\n\nSair(7) ");
    scanf("%d", &opcao);
	printf("\n");
	
	switch(opcao){
		case 1: maior    = 0;
    			posmaior = 0;
    for (i = 0; i < numeros && i < 100; i++) {
        if (preco[i] > maior) {
            maior = preco[i];
            posmaior = i;}
			 }printf(" O produto mais caro eh o produto N%d a um preco de %f \n", posmaior+1, maior);
			 break;
			 
			 
		case 2: menor    = preco[0];
    			posmenor = 0;
    for (i = 0; i < numeros && i < 100; i++) {
        if (preco[i] < menor) {
            menor = preco[i];
            posmenor = i;}
			 }printf(" O produto mais barato eh o produto N%d a um preco de %f \n", posmenor+1, menor);
			 break;
			 
	
        case 3: maior    = 0;
    			posmaior = 0;
    for (i = 0; i < numeros && i < 100; i++) {
        if (quantidade[i] > maior1){
            maior1   = quantidade[i];
            posmaior = i;}
			 }printf(" O produto com maior quantidade eh o N%d a um total de: %d unidades \n", posmaior+1, maior1);
			 break;
			 
			 
        	case 4: menor1   = quantidade[0];
    			    posmenor = 0;
    for (i = 0; i < numeros && i < 100; i++) {
        if (quantidade[i] < menor1){
            menor1= quantidade[i];
            posmenor = i;}
			 }printf("  O produto com menor quantidade eh o N%d a um total de %d: unidades \n", posmenor+1, menor1);
			 break;
			 
			 
        	case 5: printf("Insira a letra do produto que queira pesquisar: \n");
        			scanf("%c", &pesquisa);
        			pesquisa = getchar();
        			for(i = 0; i < numeros && i < 100; i++){
        				if(produtos[i] == pesquisa){
        					 printf("Produto N%i: letra de identificacao %c \n",
	 							i + 1, produtos[i]);
	 						printf("Quantidade no estoque de: %i \n", quantidade[i]); 
							 printf("Valor unitario do produto: %f \n", preco[i]);
							 printf("\n");
						}
					}
			break;


			case 6: precototal = 0;
				for(i = 0; i < numeros && i < 100; i++){
				precototal = (precototal + (quantidade[i] * preco[i]));
			} printf(" O preco total do estoque da empresa eh de: %f \n", precototal);
			break;
			case 7: printf("Tchau :^)");
			}
			}while (opcao != 7);
			
  return 0;}
