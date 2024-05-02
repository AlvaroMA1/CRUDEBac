#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação do espaço em memória
#include <locale.h>	// biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável pelo gerenciamento das strings

int cadastrar()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF do usuário a ser cadastrado:");
	scanf("%s", &cpf);
	
	strcpy(arquivo, cpf); //comando responsável por copiar o valor das strings apontadas, no caso, o valor atribuído a arquivo será equiparado a CPF, para criar, após, uma arquivo de nome CPF
	
	FILE* file; //abra um arquivo
	file = fopen(arquivo, "w"); //neste comando o arquivo será criado na pasta (nosso banco de dados) file será igualado ao valor da variável arquivo, no caso cpf, e "w", significa um novo arquivo, WRITE
	fprintf(file, "CPF:");
	fprintf(file, cpf); // salva o valor da variavel CPF no nome do arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" serve para atualizar um arquivo existente e não criar novo
	fprintf(file, ", NOME:"); // comando para inlcuir no arquivo VÍRGULA entre os valores armazenados
	fclose(file);
	
	printf("Digite o nome do usuário a ser cadastrado:");
	scanf("%s", &nome);
	
	file = fopen(arquivo, "a"); //"a" para atualizar o arquivo criado correpsondente ao CPF
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" serve para atualizar um arquivo existente e não criar novo
	fprintf(file, ", SOBRENOME:"); // comando para inlcuir no arquivo VÍRGULA entre os valores armazenados
	fclose(file);
	
	printf("Digite o sobrenome do usuário a ser cadastrado:");
	scanf("%s", &sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" serve para atualizar um arquivo existente e não criar novo
	fprintf(file, ", CARGO:"); // comando para inlcuir no arquivo VÍRGULA entre os valores armazenados
	fclose(file);
	
	printf("Digite o cargo do usuário a ser cadastrado:");
	scanf("%s", &cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consultar()
{
	char cpf[40];
	char conteudo[200];

	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF do usuário que deseja consultar:\n");
	scanf("%s", &cpf);
		
	FILE* file;
	file = fopen(cpf, "r"); //"r" do inglês, READ, ordena a abertura do arquivo para leitura.
	
	if(file == NULL)
	{
		printf("O CPF do usuário a ser consultado não consta na base de dados!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // fgets comando para colocar no programa o que consta no arquivo, no caso, até 200 valores dentro da file de nome CPF. != "diferente de NULL, ou seja, enquanto houverem valores
	{
		printf("Essas são as informações do usuário salvas na base de dados!:\n");
		printf("%s", &conteudo);
		printf("\n\n");
	}
	system("pause");
}

int excluir()
{
	char cpf[40];

	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Qual o CPF do usuário que deseja excluir da base de dados:\n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		remove(cpf);
		printf("\nO usuário foi excluído com sucesso!\n");
		system("pause");
	}


	
}


int main()
{
	int opcao=0;
	int x=1;
	
	for(x=1;x=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
	
		printf("### Cártorio da EBAC ### \n \n");
		printf("Escolha um dos itens abaixo para a ação que deseja executar: \n \n");
		printf("\t1 - Registrar usuários \n \n");
		printf("\t2 - Consultar usuários \n \n");
		printf("\t3 - Excluir usuários \n \n");
		printf("Opção selecionada:\t");
	
	
		scanf("%d", &opcao);
	
		system("cls"); //comando que indica ao SO para "limpar a tela", no caso, após o comando scanf
	
		switch(opcao)
		{	
	
			case 1:
			cadastrar();
			break;		
		
			case 2:
			consultar();
			break;
		
			case 3:
			excluir();
			break;
		
			default:
			printf("A opção desejada não está disponível. Escolha um número entre 1 e 3.\n");	
			system("pause");
			break;
		}
	}
}
