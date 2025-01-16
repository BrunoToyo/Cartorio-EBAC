#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de epa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca para cuidar das string 

int registro() //Fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}	

	system("pause");
	
	
}

int deletar() 
{
    char cpf[40];
    FILE *file;
    
    printf("Digite o CPF que deseja deletar: "); // Solicita o CPF do usu�rio
    scanf("%s", cpf);
    
    
    file = fopen(cpf, "r");// Verifica se o arquivo com o CPF existe
    if (file == NULL) 
	{
        printf("O usu�rio com CPF %s n�o se encontra no sistema!\n", cpf); // Arquivo n�o encontrado, usu�rio n�o existe no sistema
        system("pause");
        return 0;  // Retorna 0 para indicar que n�o foi poss�vel deletar
    }
    
    fclose(file); // Fecha o arquivo antes de deletar
    
   
    if (remove(cpf) == 0)  // Tenta remover o arquivo
	{
        printf("Usu�rio com CPF %s foi deletado com sucesso!\n", cpf);
    } 
    
	else 
	{   
        printf("Erro ao deletar o arquivo com CPF %s.\n", cpf); // Caso o arquivo n�o possa ser deletado
    }
    
    system("pause");
    return 1;  // Retorna 1 para indicar que a opera��o foi realizada
}
	

int main()
{
	int opcao=0; //Definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consulta nomes \n");
		printf("\t3 - Deletar nomes \n\n"); 
		printf("Qual op��o voc� deseja:"); // Fim do menu

		scanf("%d", &opcao); //armazendo a escolha do usuario
	
		system("cls");
		
		
		switch(opcao)
		{
			case 1:
			registro(); //chamda de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;		
		} //fim da sele��o
	
	
	}
}
