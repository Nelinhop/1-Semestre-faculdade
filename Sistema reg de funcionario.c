#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct Funcionario{ // estrutura com as informações do funcionario 
	char nome[50];
	char cidade[50];
	int  data[3];
	float salario;
	struct Funcionario *prox;
};

typedef struct Funcionario dados_t;
typedef char string[50];

//opcoes do programa
int menu();
dados_t *insere_item();
void excluir_item(dados_t *item_a_ser_excluido, dados_t **lista);
dados_t *altera_item();
void mostra_itens_lista(dados_t *lista);
void mostra_dados_pessoa(dados_t* p);
dados_t *localiza_por_nome(string nome, dados_t *lista);
void localiza_por_salario(int salario, dados_t *lista);
void comparar_salario(int salario, dados_t *lista);
void funccidade(dados_t* lista);
void insere_novo_item_lista(dados_t **lista, dados_t *novo);
dados_t *retorna_ultimo_elemento_lista(dados_t *lista);

//manipulacao de arquivo
void exporta_lista_arquivo_binario(dados_t *lista);
void importa_dados_arquivo_binario(dados_t **lista);

void importa_dados_texto(dados_t **lista);
void exporta_dados_arquivo_texto(dados_t *lista);

int main(){
	int opcao;
	dados_t *lista = NULL, *aux, *removido, *aux2;
	char nome[50]; 
	float salario;
	
	do{ // Menu do sistema
		
		system("cls");
		opcao = menu();
		
		switch(opcao){
			case 1: //cadastro de funcionario
				system("cls");
				if (lista == NULL) {
					aux = insere_item();
					if (aux != NULL)
					lista = aux;
							}
					// Caso não esteja vazia
				else {
					aux = lista;
					lista = insere_item();
					lista->prox = aux;	}
				break;
				
			case 2: // atualização de cadastro
				system("cls");
				getchar();
				printf("Qual o nome da pessoa que deseja atualizar? \n ");
			    fgets(nome, 50, stdin);	
			    aux = localiza_por_nome(nome, lista);
			        if (aux != NULL) {
			        	excluir_item(aux, &lista);
			        		aux = lista;
							lista = altera_item();
							lista->prox = aux;
							}
							else {
								printf("%s nao encontrado!\n", nome);
							}	
				break;
				
				
			case 3: // apagar um funcionario
			system("cls");
				getchar();
					printf("Qual o nome da pessoa a ser excluida? \n ");
			        fgets(nome, 50, stdin);
			        aux = localiza_por_nome(nome, lista);
			        if (aux != NULL) {
			        	system("cls");
			        	mostra_dados_pessoa(aux);
			        	system("pause");
			        	excluir_item(aux, &lista);
							}
							else {
								printf("%s nao encontrado!\n", nome);
							}
				break;					
				
			case 4: // mostrar todos os funcionarios ja registrados
				system("cls");
				mostra_itens_lista(lista);
				system("pause");
				break;
				
			case 5: //consultar por nome
				system("cls");
				getchar();
					printf("Qual o nome da pessoa procurada? \n ");
			        fgets(nome, 50, stdin);
			        aux = localiza_por_nome(nome, lista);
			        if (aux != NULL) {
			        	system("cls");
			        	mostra_dados_pessoa(aux);
			        	system("pause");
							}
							else {
								printf("%s nao encontrado!\n", nome);
							}
				break;
				
			case 6: //salario maior ao informado
					system("cls");
					printf("Insira o salarario o salario a ser comparado: \n");
					scanf("%f", &salario);
					localiza_por_salario(salario, lista);
					system("pause");
				break;
				
			case 7: // relatorio por salarios minimos
					system("cls");
					printf("Insira o salarario minimo atual: \n");
					scanf("%f", &salario);
					comparar_salario(salario, lista);
					system("pause");
					
				break;
	
			case 8: // numero de funcionarios por cidade
				system("cls");
				funccidade(lista);
				system("pause");
				break;
				
				
			case 9:	// cria arquivo bin
			    exporta_lista_arquivo_binario(lista);
				break;
				
				
			case 10: // le arquivo bin
				importa_dados_arquivo_binario(&lista);
				break;
				
		 	case 11: // cria arquivo txt
		 		exporta_dados_arquivo_texto(lista);
		 		break;
		 		
		 	case 12: // le arquivo txt
		 		importa_dados_texto(&lista);
			 	break;
				 	
				 	
			case 13: // sair
				system("cls");
				printf("Ate mais...");
				break;
				
			default: // opção invalida
				system("cls");
				printf("....Opcao Invalida....\n");
				system("pause");
		}
	}while(opcao!=13);
	return 0;
	}	

int menu(){
	int opcao;
	printf("1.Cadastro de funcionario.\n");
 	printf("2.Atualizacao de dados de funcionario.\n");
 	printf("3.Deletar registro de funcionario.\n");
 	printf("4.Relatorio de funcionarios.\n");
	printf("5.Consultar por nome de funcionario.\n");
	printf("6.Relatorio de funcionarios com salario maior ao informado.\n");
	printf("7.Relatorio de funcionarios por salario minimo.\n");
	printf("8.Relatorio de numero de funcionarios por cidade.\n");
	printf("-----------------------------------------------------\n");
	printf("9.Exportar arquivo binario.\n");
 	printf("10.Importar arquivo binario.\n");
 	printf("11.Exportar arquivo texto.\n");
	printf("12.Importar arquivo texto.\n");
	printf("------------------------------------------------------\n");
 	printf("13.Sair...\n");
 	
 	scanf("%d", &opcao);
 	return opcao;
}
dados_t *insere_item(){
	dados_t *item;
	
	item = (dados_t*)malloc(sizeof(dados_t));
	
	// captura o enter do menu
	getchar();
	printf("Qual o nome da pessoa? \n ");
	fgets(item->nome, 30, stdin);
	printf("Qual a cidade? \n");
	fgets(item->cidade, 30, stdin);
	printf("Qual a data de nascimento?(Insira na ordem: DIA/MES/ANO)\n");
	printf("Dia:");
	scanf("%d", &item->data[0]);
	printf("Mes:");
	scanf("%d", &item->data[1]);
	printf("Ano:");
	scanf("%d", &item->data[2]);
	printf("Qual o salario? \n ");
	scanf("%f", &item->salario);
	item->prox = NULL;
	
	return item;
}
void excluir_item(dados_t *item_a_ser_excluido, dados_t **lista){
	dados_t *aux = *lista;	
	
	// verifica se o item é o primeiro da lista
	if (item_a_ser_excluido == *lista) {
		*lista = item_a_ser_excluido->prox;
	}
	else {
		// verifica se o item esta no meio ou final da lista
		while (aux->prox != NULL)	{
			if (aux->prox == item_a_ser_excluido) {
				aux->prox = item_a_ser_excluido->prox;
				break;
			}
		}
	}
	free(item_a_ser_excluido);
}
dados_t *altera_item(){
	dados_t *item;
	
	// cria novo item
	item = (dados_t*)malloc(sizeof(dados_t));

	printf("Insira o novo nome: \n ");
	fgets(item->nome, 30, stdin);
	printf("Insira a nova cidade: \n");
	fgets(item->cidade, 30, stdin);
	printf("Insira a nova data de nascimento?(Insira na ordem: DIA/MES/ANO)\n");
	printf("Dia:");
	scanf("%d", &item->data[0]);
	printf("Mes:");
	scanf("%d", &item->data[1]);
	printf("Ano:");
	scanf("%d", &item->data[2]);
	printf("Insira o novo salario: \n ");
	scanf("%f", &item->salario);
	item->prox = NULL;
	
	return item;
}
void mostra_itens_lista(dados_t *lista){
	dados_t *aux = lista;
	
	while (aux != NULL) {
		printf("Nome...........: %s\n", aux->nome);
		printf("Cidade...........: %s\n", aux->cidade);
		printf("Data de nascimento: %d / %d / %d \n",aux->data[0],aux->data[1] ,aux->data[2] );
		printf("Salario............: %.2f\n\n", aux->salario);
		printf("----------------------------------------------------------------------\n");
		aux = aux->prox;
	}
}
void mostra_dados_pessoa(dados_t* pessoa){
	printf("Nome da pessoa....: %s\n", pessoa->nome);
	printf("Cidade da pessoa..: %s\n", pessoa->cidade);
	printf("Data de nascimento: %d / %d / %d \n",pessoa->data[0],pessoa->data[1] ,pessoa->data[2] );
	printf("Salario da pessoa.: %f\n", pessoa->salario);
	printf("---------------------------------------------------------\n");	
}
dados_t* localiza_por_nome(string nome, dados_t* lista){
	dados_t* aux = lista;
	
	while (aux != NULL) {
		if (strcmp(nome, aux->nome) == 0) {
			return aux;
		}
		aux = aux->prox;
	}
	
	return NULL;
}
void localiza_por_salario(int salario, dados_t *lista){
		dados_t* aux = lista;
	
	//percorre todos os itens para achar os que se encaixam 
	while (aux != NULL) {
		if (aux->salario >= salario) {
			mostra_dados_pessoa(aux);
			aux = aux->prox;
		}
		else if(aux->salario < salario){
		aux = aux->prox;
	}	
}
}
void comparar_salario(int salario, dados_t *lista){
	
		int opcao;
	//menu	
	do{
		printf("1. Um salario minimo ou menos\n");
		printf("2. Mais de um salario minimo a 3 salario minimos\n");
		printf("3. Acima de 3 salarios minimos\n");
		printf("4. Sair do menu\n");
		scanf("%d", &opcao);
		
		dados_t* aux = lista;
		
		switch(opcao){
			case 1:
				while (aux != NULL) {
				if (aux->salario <= salario) {
				mostra_dados_pessoa(aux);
				aux = aux->prox;
				}
				else{
				aux = aux->prox;}	
				}break;
				
			case 2: 	
				while (aux != NULL) {
				if (aux->salario > salario && aux->salario <= salario * 3) {
				mostra_dados_pessoa(aux);
				aux = aux->prox;
				}			
				else	{
				aux = aux->prox;}	
				}break;	
				
			case 3:	
				while (aux != NULL) {
				if (aux->salario > salario * 3) {
				mostra_dados_pessoa(aux);
				aux = aux->prox;
				}
				else{
				aux = aux->prox;
				}					
				}break;
		}
	}
	while(opcao != 4);
	}
void funccidade(dados_t* lista){
		
		dados_t* aux = lista;
		int igual;
	do{	
		while (aux != NULL) {
			//se a cidade for igual aumenta em 1 a variavel que dira quantos funcionarios tem na cidade 
		if (strcmp(lista->cidade,aux->cidade)==0) {
			aux = aux->prox;
			igual++;}
			else{
				// passa para o proximo item
			aux = aux->prox;
		}
	}
		printf("Cidade: %s  | Quantidade %d \n", lista->cidade, igual);
		lista = lista->prox;
}while(lista != NULL);
}	
void insere_novo_item_lista(dados_t **lista, dados_t *novo){
	// insere na lista
	if (*lista == NULL) {
		*lista = novo;
	}
	// insere no fim da lista 
	else {
		dados_t *ultimo = retorna_ultimo_elemento_lista(*lista);
		ultimo->prox = novo;		
	}
}
dados_t* retorna_ultimo_elemento_lista(dados_t *lista){
	dados_t *aux = lista;
	
	while (aux->prox != NULL) {
		aux = aux->prox;
	}
	
	return aux;
}





void exporta_lista_arquivo_binario(dados_t *lista){
	FILE *fp;
	dados_t *aux = lista;
	
	// abre o arquivo para escrever e se n exisitir cria
	fp = fopen("dados", "wb+");
	
	if (fp == NULL) {
		printf("Erro ao tentar abrir arquivo <dados.bin>");
		exit(0);
	}
	// escrevendo os dados no arquivo
	while (aux != NULL) {
		fwrite(&aux->nome, sizeof(char), 50, fp);
		fwrite(&aux->cidade, sizeof(char), 50, fp);
		fwrite(&aux->data, sizeof(int), 3, fp);
		fwrite(&aux->salario, sizeof(float), 1, fp);
		aux = aux->prox;
	}
	
	fclose(fp);
}
void importa_dados_arquivo_binario(dados_t **lista){
	FILE *fp;
	dados_t *aux;
	string nome, cidade;
	float salario;
	int data[3];
	
	fp = fopen("dados", "rb");
	
	if (fp == NULL) {
		printf("Erro ao tentar abrir arquivo <dados.bin>");
		exit(0);
	}
//lendo o arquivo
  while (!feof(fp)) {
	fread(&nome, sizeof(char), 50, fp);
  	fread(&cidade, sizeof(char), 50, fp);
  	fread(&data, sizeof(int), 3, fp);
  	fread(&salario, sizeof(float), 1, fp);
  	//atribuindo os dados
  	if (!feof(fp)) {
	  	aux = (dados_t*)malloc(sizeof(dados_t));
	  	strcpy(aux->nome,nome);
	  	strcpy(aux->cidade,cidade);
	  	aux->data[0] = data[0];
	  	aux->data[1] = data[1];
	  	aux->data[2] = data[2];
	  	aux->salario = salario;
	  	aux->prox = NULL;
	  	insere_novo_item_lista(lista, aux);
	  }
	}
	
	fclose(fp);
}



void exporta_dados_arquivo_texto(dados_t *lista){
	FILE* fp;
	int i;
	dados_t *aux = lista;
	
	// abre o arquivo para escrever e se n exisitir cria
	fp = fopen("arq-texto", "w+");
	
	//escreve os dados no arquivo
	while(aux != NULL) {
		fprintf(fp, "%s\n", aux->nome);
		fprintf(fp, "%s\n", aux->cidade);
		fprintf(fp, "%d\n", aux->data[0]);
		fprintf(fp, "%d\n", aux->data[1]);
		fprintf(fp, "%d\n", aux->data[2]);
		fprintf(fp, "%f\n", aux->salario);
		aux = aux->prox;
	}
	
	fclose(fp);
}
void importa_dados_texto(dados_t **lista){

	FILE* fp;
	string nome,cidade;
	float salario;
	dados_t *aux;
	int data[3];
	
	//abre o arquivo para ler
	fp = fopen("arq-texto", "rt");
	
	//le todos os dados ate o fim do arquivo e no fim insere na lista 
while (!feof(fp)) {
		fscanf(fp, "%s", nome);
		fscanf(fp, "%s", cidade);
		fscanf(fp, "%d", &data[0]);
		fscanf(fp, "%d", &data[1]);
		fscanf(fp, "%d", &data[2]);
		fscanf(fp, "%f", &salario);
	  	if (!feof(fp)) {
	  	aux = (dados_t*)malloc(sizeof(dados_t));
	  	strcpy(aux->nome,nome);
	  	strcpy(aux->cidade,cidade);
	  	aux->data[0] = data[0];
	  	aux->data[1] = data[1];
	  	aux->data[2] = data[2];
	  	aux->salario = salario;
	  	aux->prox = NULL;
	  	// insere no fim da lista sem precisar passar pela rotina de insere_item
	  	insere_novo_item_lista(lista, aux);
	  }
	}
	fclose(fp);
}






	
