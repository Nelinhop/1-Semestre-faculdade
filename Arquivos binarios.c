#include <stdio.h>
#include <stdlib.h>

#define SALVAR_AO_SAIR				1
#define IMPORTAR_AO_INICIAR		1

struct dados {
	int numero;
	float valor;
	struct dados *prox;
};

typedef struct dados dados_t;

int menu();
dados_t *cria_novo_item();
void insere_novo_item_lista(dados_t **lista, dados_t *novo);
void mostra_itens_lista(dados_t *lista);
void salva_lista_arquivo_binario(dados_t *lista);
void importa_dados_arquivo_binario(dados_t **lista);
dados_t* retorna_ultimo_elemento_lista(dados_t *lista);

int main()
{
	dados_t *lista = NULL;
	int opcao;
	
	#if IMPORTAR_AO_INICIAR
	importa_dados_arquivo_binario(&lista);
	#endif
	
	do {
		opcao = menu();
		
		switch(opcao) {
			
			case 1: insere_novo_item_lista(&lista, cria_novo_item());
							break;
			
			case 2: mostra_itens_lista(lista);
							break;
			
			case 3: salva_lista_arquivo_binario(lista);
							break;
			
			case 4: importa_dados_arquivo_binario(&lista);
							break;
			
			case 5: 
							#if SALVAR_AO_SAIR
								salva_lista_arquivo_binario(lista);
							#endif							
			
		}
		
	} while (opcao != 5);
	
	return 0;
}

int menu()
{
	int opcao;
	
	printf("1.Inserir itens na lista\n");
	printf("2.Mostar itens da lista\n");
	printf("3.Salvar dados da lista em arquivo binario\n");
	printf("4.Importar dados de um arquivo binario\n");
	printf("5.Sair do programa\n");
	printf(":: ");
	scanf("%d", &opcao);
	
	return opcao;	
}

dados_t *cria_novo_item()
{
	dados_t *novo;
	
	novo = (dados_t*)malloc(sizeof(dados_t));
	
	printf("Informe um numero: ");
	scanf("%d", &novo->numero);
	printf("Informe um valor: ");
	scanf("%f", &novo->valor);
	novo->prox = NULL;
	
	return novo;
}

void insere_novo_item_lista(dados_t **lista, dados_t *novo)
{
	// Verifica se lista está vazia
	if (*lista == NULL) {
		*lista = novo;
	}
	else {
		// Inserir elemento pelo fim da lista
		dados_t *ultimo = retorna_ultimo_elemento_lista(*lista);
		ultimo->prox = novo;		
	}
}

void mostra_itens_lista(dados_t *lista)
{
	dados_t *aux = lista;
	
	while (aux != NULL) {
		printf("Numero...........: %d\n", aux->numero);
		printf("Valor............: %.2f\n\n", aux->valor);
		aux = aux->prox;
	}
}

void salva_lista_arquivo_binario(dados_t *lista)
{
	FILE *fp;
	dados_t *aux = lista;
	
	fp = fopen("dados.bin", "wb+");
	
	if (fp == NULL) {
		printf("Erro ao tentar abrir arquivo <dados.bin>");
		exit(0);
	}
	
	while (aux != NULL) {
		fwrite(&aux->numero, sizeof(int), 1, fp);
		fwrite(&aux->valor, sizeof(float), 1, fp);
		aux = aux->prox;
	}
	
	fclose(fp);
}

void importa_dados_arquivo_binario(dados_t **lista)
{
	FILE *fp;
	dados_t *aux;
	int numero;
	float valor;
	
	fp = fopen("dados.bin", "rb");
	
	if (fp == NULL) {
		printf("Erro ao tentar abrir arquivo <dados.bin>");
		exit(0);
	}

  while (!feof(fp)) {
  	fread(&numero, sizeof(int), 1, fp);
  	fread(&valor, sizeof(float), 1, fp);
  	if (!feof(fp)) {
	  	aux = (dados_t*)malloc(sizeof(dados_t));
	  	aux->numero = numero;
	  	aux->valor = valor;
	  	aux->prox = NULL;
	  	insere_novo_item_lista(lista, aux);
	  }
	}
	
	fclose(fp);
}

dados_t* retorna_ultimo_elemento_lista(dados_t *lista)
{
	dados_t *aux = lista;
	
	while (aux->prox != NULL) {
		aux = aux->prox;
	}
	
	return aux;
}
