#include <stdio.h> // biblioteca de comunicação com usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastra usuários no sistema
{
	  //Inicio da criação de variaveis/strings
	
	  char arquivo[40];
      char cpf[40];
	  char nome[40];
	  char sobrenome[40];
	  char cargo[40];
	  
	  //Final da criação de variaveis
	  
	  printf("Digite o CPF a ser cadastrado: ");//Coletando informações do usuário
	  scanf("%s", cpf);	//%s Refere-se a string e armazena na variavel CPF
	  
      strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
      
      FILE *file; //cria o arquivo
      file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
      fprintf(file,cpf); // Salva o valor da variavel,no arquivo
      fclose(file); //Fecha o arquivo
      
      file = fopen(arquivo, "a");//Abrir o arquivo que esta salvo "a"significa atualizar 
      fprintf(file, ",");//Para salvar dentro de um arquivo existente
      fclose(file); //Fecha o arquivo
      fprintf(file, ",");//Para salvar dentro de um arquivo existente
      fclose(file); //Fecha o arquivo
      
      printf("Digite o nome a ser cadastrado: ");//Coletando informações do usuário
      scanf("%s", nome);//%s Refere-se a string e armazena na variavel Nome
      
      file = fopen(arquivo, "a");//Abrir o arquivo que esta salvo "a"significa atualizar 
      fprintf(file,nome); // Salva o valor da variavel,no arquivo
      fclose(file); //Fecha o arquivo

      file = fopen(arquivo, "a");//Abrir o arquivo que esta salvo "a"significa atualizar 
      fprintf(file, ",");//Para salvar dentro de um arquivo existente
      fclose(file);//Fecha o arquivo
      
      printf("Digite o sobrenome a ser cadastrado: ");//Coletando informações do usuário
      scanf("%s", sobrenome);//%s Refere-se a string e armazena na variavel Sobrenome
      
      file = fopen(arquivo, "a");//Abrir o arquivo que esta salvo "a"significa atualizar 
      fprintf(file,sobrenome); // Salva o valor da variavel,no arquivo
      fclose(file);//Fecha o arquivo
      
      file = fopen(arquivo, "a");//Abrir o arquivo que esta salvo "a"significa atualizar 
      fprintf(file, ",");//Para salvar dentro de um arquivo existente
      fclose(file);//Fecha o arquivo
      
      printf("Digite o cargo a ser cadastrado: ");//Coletando informações do usuário
      scanf("%s", cargo);//%s Refere-se a string e armazena na variavel Cargo
      
      file = fopen(arquivo, "a");//Abrir o arquivo que esta salvo "a"significa atualizar 
      fprintf(file,cargo); // Salva o valor da variavel,no arquivo
      fclose(file);//Fecha o arquivo
      
      system("pause");//Parar
}
int consulta()//Função responsavel por consultar usuários no sistema
{
	  setlocale(LC_ALL, " Portuguese");//Definição de Linguagem
	  
	  //Inicio da criação de variaveis/string
	  
      char cpf[40];
      char conteudo[200];
      
      //Fim da criação de variaveis/string
     
      printf("Digite o CPF a ser consultado: ");//Coletando informação do usuário
      scanf("%s",cpf);//%s Refere-se a string e armazena na variavel CPF
      
      FILE *file;//Consulta o arquivo
      file = fopen(cpf, "r");//Abrir o arquivo "r" significa ler
      
      if(file == NULL)//Validação caso cpf não seja encontrado
      {
      	 printf("Não foi possivel abrir o arquivo ; não localizado!. \n");//Mensagem para o usuário
      	 system("pause");
	  }
      
      while(fgets(conteudo, 200, file) != NULL) //Laçao de repetição de busca dentro do arquivo,parar quando for nulo
      {
      	printf("\nEssas são as informações do usuario: ");//Mensagem para o usuário
      	printf("%s", conteudo);//%s Salva o conteudo que esta dentro da string
      	printf("\n\n");//Pular linhas
	  
	  
	     system("pause");//Parar
	     
	   }
	  
}

int deletar()//Função responsavel por deletar usuários no sistema
{
	 //Inicio da criação de variavel
	
     char cpf[40];
     
     //Fim da criação de variavel 
     
     printf("Digite o CPF do usuário a ser deletado: ");//Coletando informação do usuário
     scanf("%s",cpf);//%s Refere-se a string e armazena na variavel CPF
     
     
     remove(cpf);//Acessa e deleta o arquivo 
     
     FILE *file;//Consulta o arquivo
     file = fopen(cpf, "r");//Abrir o arquivo "r" significa ler
     
     
     if(file == NULL)//Validação se arquivo não existe
     {
     	printf("O usuário não se encontra no sistema!.\n");//Mensagem para o usuário
     	system("pause");//Parar
	 }
     
}



int main()
{
	int opcao=0;//Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
 	
	 system("cls");//Responsavel por limpar a tela
	
     setlocale(LC_ALL, " Portuguese");//Definição de Linguagem
    
	 printf("### Cartório da EBAC ###\n\n");// Inicio do Menu
	 printf("Escolha a opção desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");
	 printf("Opção:");//Fim do Menu
	  
   	 scanf("%d",&opcao);//Armazenamento a escolha do usuário
	 
	 system("cls");
	 
	 switch(opcao)//Inicio da seleção do menu
	 {
	    case 1: 
	    registro();//Chamada de funções
	    break;
	  
	    case 2:	
	    consulta();//Chamada de funções
	    break;
	   
	    case 3:
	    deletar();//Chamada de funções
	    break;	
	  
	    default:
	    printf("Essa opção não esta disponivel!\n");
		system("pause");
		break;
	 
     }
  
   }
	    
}
	
		    
      

	
