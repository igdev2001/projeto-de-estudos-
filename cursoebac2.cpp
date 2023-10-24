#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_STRING_LENGTH 40

void registro() {
    setlocale(LC_ALL, "Portuguese");
    char cpf[MAX_STRING_LENGTH];
    char nome[MAX_STRING_LENGTH];
    char sobrenome[MAX_STRING_LENGTH];
    char cargo[MAX_STRING_LENGTH];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "w");

    if (file == NULL) {
        perror("Erro ao criar arquivo");
        return;
    }

    fprintf(file, "%s,", cpf);
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(cpf, "a");

    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }

    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(cpf, "a");

    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }

    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(cpf, "a");

    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }

    fprintf(file, "%s,", cargo);
    fclose(file);

    printf("Cadastro realizado com sucesso!\n");
}

void consulta() {
    setlocale(LC_ALL, "Portuguese");
    char cpf[MAX_STRING_LENGTH];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }

    while (fgets(conteudo, 200, file) != NULL) {
        printf("Informações do usuário: %s", conteudo);
    }

    fclose(file);
}

void deletar() {
    char cpf[MAX_STRING_LENGTH];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usuário removido com sucesso!\n");
    } else {
        printf("Usuário não encontrado no sistema!\n");
    }
}

int main() 
{
	
    int opcao = 0;
    int laco = 1;
    char senhadigitada[10]="a";
    
    printf("### Cartorio da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s",senhadigitada);
    
      if (strcmp(senhadigitada, "admin") == 0);
	{
    	
    
       for (laco = 1; laco == 1;) 
	   {
          system("cls");

        setlocale(LC_ALL, "Portuguese");

          printf("### Software listagem de alunos ###\n\n");
          printf("Escolha a opção desejada do menu abaixo:\n\n");
          printf("\t1 - Registrar nomes\n");
          printf("\t2 - Consultar nomes\n");
          printf("\t3 - Deletar nomes\n\n");
          printf("\t4 - sair do sistema\n\n");
          printf("Opção: ");

          scanf("%d", &opcao);

          system("cls");

          switch (opcao) {
              case 1:
                registro();
                break;

              case 2:
                consulta();
                break;

              case 3:
                deletar();
                break;
                
              case 4:
			     printf("obrigado por utilizar o sistema\n");
				 return 0;
				 break;    
                

              default:
                printf("Essa opção não está disponível\n");
                break;
            }

        }
    
   	}
}
