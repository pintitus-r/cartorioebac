#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o responsavel por cadastrar os usuarios
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informa��o do usuar�o
	scanf("%s", cpf); //refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //
	fclose(file); //fecha o arquivo
	
	printf("digite o nome a ser cadastrado: "); //responsavel por copiar os valores das string
	scanf("%s", nome); // refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" siginifica atualizar
	fprintf(file,nome);// salvo o valor da vari�vel
	fclose(file);//fecha o arquivo

	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa atualizar
	fprintf(file, ",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//responsavel por copiar os valores das string
	scanf("%s", sobrenome);// refere-se a string
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome);// salvo o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa atualizar
	fprintf(file, ",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//responsavel por copiar os valores das string
	scanf("%s", cargo);// refere-se a string
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa atualizar
	fprintf(file,cargo);// salvo o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa para fazer a leitura
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); // diz a linguagem
	
	//inicio cria��o de variaveis/string
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//responsavel por copiar os valores das string
	scanf("%s", cpf);// salvo o valor da vari�vel
	
	FILE *file;//cria o arquivo
	file = fopen(cpf, "r");// cria o arquivo e o "r" significa ler
	
	if(file == NULL)//se o arquivo file for nulo, dizer a mensagem a seguir
	{
		printf("N�o foi poss�vel abrir o arquivo n�o localizado");
	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
	
	system("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//deletar
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)//se o arquivo for nulo, dizer essa frase
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}



int main()
{
		int opcao=0; //definindo variavel
		int laco=1;
		
		for(laco=1;laco=1;)
		{
		
			system("cls");
			
		setlocale(LC_ALL, "portuguese"); //definindo linguagem
	
		printf("### Cart�rio da EBAC ### \n\n"); //inicio do menu
		printf("escolha a op��o desejada do menu: \n\n");
		printf("\t1 registrar nome \n");
		printf("\t2 consultar nome \n");
		printf("\t3 deletar nome \n");
		printf("\t4 - sair do sistema\n\n");
		printf("Opc�o "); //fim do menu

		scanf("%d", &opcao); //armazenamento a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela

		switch(opcao) //inicio da sele��o do menu
		{
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
				printf("Obrigado por usar o sistema!\n");
				return 0;
				break;
			default:
			printf("Essa op��o n�o est� dispon�vel \n");
			system("pause");
			break;
		
		} //fim da sele��o do menu
		}
	//fim de sele��o
}

