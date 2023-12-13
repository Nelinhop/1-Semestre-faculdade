/*
Lista encadeada
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIM 			8
#define TRUE			1
#define FALSE 			0

typedef char string[50];
typedef unsigned char boolean;

// Dados de um produto para venda
typedef struct dados_no {
	string nome;
	int idade;
	float media;
	struct dados_no *prox;
} dados_no_t;

int menu();
dados_no_t *cadastrar_aluno();
void mostra_todos_os_alunos(dados_no_t *lista);
void apaga_todos_os_alunos(dados_no_t **lista);
boolean lista_esta_vazia(dados_no_t *lista);
void insere_aluno_pelo_fim(dados_no_t **lista, dados_no_t *item);
void remove_enter(string s);
dados_no_t *localiza_por_nome(string nome, dados_no_t *lista);
void mostra_dados_aluno(dados_no_t *item);
dados_no_t *alterar_dados_aluno();
dados_no_t *remover(dados_no_t *lista, dados_no_t *funcionario);


int main()
{    

	FILE *f;
			
    int opcao, i;
  // Lista inicia vazia
	dados_no_t *lista = NULL, *novo, *aux, *removido;
	string aluno;

	f = fopen("binario", "a+b");
	
	do {	
		
		opcao = menu();

		switch (opcao) {

			case 1:         novo = cadastrar_aluno();
							insere_aluno_pelo_fim(&lista, novo);
							break;

			case 2: mostra_todos_os_alunos(lista);
	   						break;

	 		case 3: apaga_todos_os_alunos(&lista);
	 						break;

	 		case 4: getchar();
							printf("Qual o nome do aluno?");
			      		  	fgets(aluno, 50, stdin);
			      		  	remove_enter(aluno);
			        		aux = localiza_por_nome(aluno, lista);
			      			  if (aux != NULL) {
			        		mostra_dados_aluno(aux);
								}
							else {
								printf("%s nao encontrado!\n", aluno);
							}
							break;
			case 5: getchar();

                            printf("Qual aluno deseja alterar?");
                            fgets(aluno, 50, stdin);
                            remove_enter(aluno);
                            aux = localiza_por_nome(aluno, lista);
                                if(aux != NULL){
                                removido = remover(lista,aux);
                                free(removido);

                                 novo = alterar_dados_aluno();
                                 insere_aluno_pelo_fim(&lista, novo);
                                }
                            else {
								printf("%s nao encontrado!\n", aluno);
							}

                            break;
        
        	
        	case 6: 		fread(&lista,sizeof(dados_no_t),i,f);
							break;
						
						
	
					
			case 7:			fclose(f);
							f = fopen("binario", "wb");
							fwrite(&lista,sizeof(dados_no_t),5,f);
							fclose(f);
							return 0;
							break;
				}
			
			} while (opcao != FIM);
	
	fclose(f);
	return 0;
}

int menu()
{
  int opcao;

	printf("1.Inserir novo aluno\n");
	printf("2.Mostrar todos os alunos e sua medias\n");
	printf("3.Apagar todos os alunos\n");
	printf("4.Localizar aluno por nome\n");
	printf("5.Alterar os dados de um aluno\n");
	printf("6.Ler arquivo \n");
	printf("7.Escrever arquivo e fechar programa\n");
	printf("8.Sair do programa\n");
	printf("?: ");
	scanf("%d", &opcao);

	return opcao;
}

dados_no_t *cadastrar_aluno()
{
  dados_no_t *no = (dados_no_t*)malloc(sizeof(dados_no_t));

  getchar();
  printf("Nome do aluno.....: ");
  fgets(no->nome, 50, stdin);
  remove_enter(no->nome);
  printf("Idade do Aluno....: ");
  scanf("%d", &no->idade);
  printf("Media do aluno........: ");
  scanf("%f", &no->media);

  no->prox = NULL;

  return no;
}

void mostra_todos_os_alunos(dados_no_t *lista)
{
	dados_no_t *aux = lista;

	while (aux != NULL) {
	  printf("Nome do aluno.....: %s\n", aux->nome);
	  printf("Idade do aluno....: %d\n", aux->idade);
	  printf("Media do aluno........: %.2f\n", aux->media);
	  printf("*****************\n\n");

		aux = aux->prox;
	}

}

void apaga_todos_os_alunos(dados_no_t **lista)
{
	dados_no_t *aux;

	while (*lista != NULL) {
		aux = *lista;
		*lista = (*lista)->prox;
		printf("Apagando o aluno %s\n", aux->nome);
		free(aux);
	}
}

boolean lista_esta_vazia(dados_no_t *lista)
{
	if (lista == NULL) return TRUE;
	return FALSE;
}

void insere_aluno_pelo_fim(dados_no_t **lista, dados_no_t *item)
{
	dados_no_t *aux;
	if (lista_esta_vazia(*lista) == TRUE) {
		*lista = item;
	}
	else {
		aux = *lista;
		while (aux->prox != NULL) aux = aux->prox;
		aux->prox = item;
	}
}

void remove_enter(string s)
{
	int tamanho = strlen(s);
	s[tamanho-1] = '\0';
}
dados_no_t *localiza_por_nome(string item, dados_no_t *lista)
{
	dados_no_t *aux = lista;

	while (aux != NULL) {
		if (strcmp(item, aux->nome) == 0) {
			return aux;
		}
		aux = aux->prox;
	}

	return NULL;
}

void mostra_dados_aluno(dados_no_t *item)
{
	printf("Nome do aluno......: %s\n", item->nome);
	printf("Idade do aluno: %d\n", item->idade);
	printf("Media do aluno........: %f\n", item->media);
	printf("---------------------\n");
}

dados_no_t* remover(dados_no_t *lista, dados_no_t *funcionario){
	dados_no_t *aux, *remove = NULL;
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

dados_no_t *alterar_dados_aluno(){
{
  dados_no_t *no = (dados_no_t*)malloc(sizeof(dados_no_t));


  printf("Alterar nome do aluno para?:\n ");
  fgets(no->nome, 50, stdin);
  remove_enter(no->nome);
  printf("Alterar idade do aluno para?:\n ");
  scanf("%d", &no->idade);
  printf("Alterar media do aluno para?:\n ");
  scanf("%f", &no->media);

  no->prox = NULL;

  return no;
}
}
