#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário "CPF"
	scanf("%s",cpf); //%s refere-se a string cpf
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string cpf
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa
	fprintf(file,","); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário "Nome"
	scanf("%s",nome); //%s refere-se a string nome
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa
	fprintf(file,nome); //salva o valor da variável nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa
	fprintf(file,","); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário "Sobreome"
	scanf("%s",sobrenome); //%s refere-se a string sobrenome
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa
	fprintf(file,sobrenome); //salva o valor da variável sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa
	fprintf(file,","); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário "Cargo"
	scanf("%s",cargo); //%s refere-se a string cargo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa
	fprintf(file,cargo); //salva o valor da variável cargo
	fclose(file); //fecha o arquivo
	
    system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r");
  	
	if(file == NULL)
{
	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
}
	
	while(fgets(conteudo, 100, file) != NULL)
{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
	system ("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //responsável por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf(">>> Cartório da EBAC <<<\n\n"); //início do menu
		printf("Sejam bem-vindos ao Cartório da EBAC\n\n"); //mensagem inicial do programa
		printf("Por favor, escolha a opção desejada do menu:\n\n"); //mensagem de escolha das opções do menu
		printf("\t1 - Registrar Nomes\n"); //início do cadastro de usuário novo
		printf("\t2 - Consultar Nomes\n"); //consulta de usuário no banco de dados
		printf("\t3 - Deletar Nomes\n\n"); //deletar usuário do banco de dados
		printf("\t4 - Sair do Sistema\n\n"); //sair do sistema
		printf("Opção:"); //escolha das opões do Menu inicial
		//fim do menu
			
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada da função cadastrar usuário
			break;
			
			case 2:
			consulta(); //chamada da função consultar usuário
			break;
			
			case 3:
			deletar(); //chamada da função deletar usuário
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso Sistema!\n"); //chamada da função sair do sistema
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n"); //informação de função não disponível no menu
			system("pause");
			break;	
		} //fim da seleção
		
	}
}
