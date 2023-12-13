/*
Lista encadeada (ligada)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[30];

struct dados {
	string nome;
	string endereco;
	int idade;
	struct dados *prox;
};

typedef struct dados dados;

// Protótipos das funções auxiliares
int menu();
dados* insere_item();
void mostrar_lista(dados* lista);
dados* localiza_por_nome(string nome, dados* lista);
void mostra_dados_pessoa(dados* p);
dados* remover(dados *lista, dados *funcionario);

int main()
{
	dados *lista = NULL, *aux;
	int opcao;
	string nome;
	dados *removido;
	
	do {
		opcao = menu();
		
		switch (opcao) {
			
			case 1: // Verifica se a lista está vazia
							// Inserindo os elementos no início da lista
							if (lista == NULL) {
								aux = insere_item();
								if (aux != NULL)
									lista = aux;
							}
							// Caso não esteja vazia
							else {
								aux = lista;
								lista = insere_item();
								lista->prox = aux;
							}
							break;
			
			case 2: mostrar_lista(lista);
							break;
							
			case 3: getchar();
							printf("Qual o nome da pessoa? \n ");
			        fgets(nome, 30, stdin);
			        aux = localiza_por_nome(nome, lista);
			        if (aux != NULL) {
			        	mostra_dados_pessoa(aux);
							}
							else {
								printf("%s nao encontrado!\n", nome);
							}
							break;
				
			case 4: getchar();
							printf("Qual funcionario deseja deletar? ");
							fgets(nome, 30, stdin);
							aux = localiza_por_nome(nome,lista);
							removido = remover(lista,aux);
							if(removido){
							printf("Funcionario %s removido!\n",removido->nome);
							free (removido);
		}
		break;
							
			case 5: free(lista);
			
		}
		
	} while (opcao != 5);
	
	return 0;
}

// Implementação das rotinas auxiliares
int menu()
{
	int opcao;
	
	printf("1.Inserir dados na lista\n");
	printf("2.Mostrar lista\n");
	printf("3.Localizar pessoa por nome\n");
	printf("4.Remover dados na lista\n");
	printf("5.Sair do programa\n");
	printf("Opcao? \n");
	scanf("%d", &opcao);
	
	return opcao;
}

dados* insere_item()
{
	dados* item;
	
	// Aloca item dinamicamente
	item = (dados*)malloc(sizeof(dados));
	// Captura o enter que sobrou do menu
	getchar();
	printf("Qual o nome da pessoa? \n ");
	fgets(item->nome, 30, stdin);
	printf("Qual o endereco? \n");
	fgets(item->endereco, 30, stdin);
	printf("Qual a idade? \n ");
	scanf("%d", &item->idade);
	item->prox = NULL;
	
	return item;
}

void mostrar_lista(dados* lista)
{
	dados* aux = lista;
	
	while (aux != NULL) {
		mostra_dados_pessoa(aux);
		aux = aux->prox;
	}
}

dados* localiza_por_nome(string nome, dados* lista)
{
	dados* aux = lista;
	
	while (aux != NULL) {
		if (strcmp(nome, aux->nome) == 0) {
			return aux;
		}
		aux = aux->prox;
	}
	
	return NULL;
}

void mostra_dados_pessoa(dados* p)
{
	printf("Nome da pessoa......: %s\n", p->nome);
	printf("Endereco da pessoa..: %s\n", p->endereco);
	printf("Idade da pessoa.....: %d\n", p->idade);
	printf("---------------------\n");	
}

dados* remover(dados *lista, dados *funcionario){
	dados *aux, *remove = NULL;
	if(lista){
		if((lista)== funcionario){
			remove = lista;
			lista = remove->prox;
		}else{
			aux = lista;
			while(aux->prox != funcionario){
				aux = aux->prox;
			}
			if(aux->prox){
				remove = aux->prox;
				aux->prox = remove->prox;
			}
		}
	}
	return remove;
}

