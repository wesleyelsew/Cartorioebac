#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bibliteca de alo��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa *escrever*
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //envia o resultado para o arquivo  
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",nome); //refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome); //envia o resultado para o arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //envia o resultado para o arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",sobrenome); //refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,sobrenome); //envia o resultado para o arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquio
	fprintf(file, ","); //envia o resultado para o arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //colentando informa��es do usu�rio
	scanf("%s",cargo); //refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,cargo); //envia resultado para o arquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" = read, ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es o usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //pausa na tela
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause"); //pausa na tela
	}	
}


int main()
{
    int opcao=0; //Definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
    {

		system("cls"); //Limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Limpar a tela
		
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break; //encerra o loop
			
			case 2:
			consulta(); //chamada de fun��es
			break; //encerra o loop
			
			case 3:
			deletar(); //chamada de fun��es
			break; //encerra o loop
			
			default:
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause"); //pausar na tela
			break; //encerra o loop
				
		} //fim da sele��o do menu
	
	}		
}
