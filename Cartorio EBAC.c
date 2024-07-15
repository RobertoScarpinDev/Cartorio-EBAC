#include <stdio.h> // biblioteca de comunica��o com usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastra usu�rios no sistema
{
	  //Inicio da cria��o de variaveis/strings
	
	  char arquivo[40];
      char cpf[40];
	  char nome[40];
	  char sobrenome[40];
	  char cargo[40];
	  
	  //Final da cria��o de variaveis
	  
	  printf("Digite o CPF a ser cadastrado: ");//Coletando informa��es do usu�rio
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
      
      printf("Digite o nome a ser cadastrado: ");//Coletando informa��es do usu�rio
      scanf("%s", nome);//%s Refere-se a string e armazena na variavel Nome
      
      file = fopen(arquivo, "a");//Abrir o arquivo que esta salvo "a"significa atualizar 
      fprintf(file,nome); // Salva o valor da variavel,no arquivo
      fclose(file); //Fecha o arquivo

      file = fopen(arquivo, "a");//Abrir o arquivo que esta salvo "a"significa atualizar 
      fprintf(file, ",");//Para salvar dentro de um arquivo existente
      fclose(file);//Fecha o arquivo
      
      printf("Digite o sobrenome a ser cadastrado: ");//Coletando informa��es do usu�rio
      scanf("%s", sobrenome);//%s Refere-se a string e armazena na variavel Sobrenome
      
      file = fopen(arquivo, "a");//Abrir o arquivo que esta salvo "a"significa atualizar 
      fprintf(file,sobrenome); // Salva o valor da variavel,no arquivo
      fclose(file);//Fecha o arquivo
      
      file = fopen(arquivo, "a");//Abrir o arquivo que esta salvo "a"significa atualizar 
      fprintf(file, ",");//Para salvar dentro de um arquivo existente
      fclose(file);//Fecha o arquivo
      
      printf("Digite o cargo a ser cadastrado: ");//Coletando informa��es do usu�rio
      scanf("%s", cargo);//%s Refere-se a string e armazena na variavel Cargo
      
      file = fopen(arquivo, "a");//Abrir o arquivo que esta salvo "a"significa atualizar 
      fprintf(file,cargo); // Salva o valor da variavel,no arquivo
      fclose(file);//Fecha o arquivo
      
      system("pause");//Parar
}
int consulta()//Fun��o responsavel por consultar usu�rios no sistema
{
	  setlocale(LC_ALL, " Portuguese");//Defini��o de Linguagem
	  
	  //Inicio da cria��o de variaveis/string
	  
      char cpf[40];
      char conteudo[200];
      
      //Fim da cria��o de variaveis/string
     
      printf("Digite o CPF a ser consultado: ");//Coletando informa��o do usu�rio
      scanf("%s",cpf);//%s Refere-se a string e armazena na variavel CPF
      
      FILE *file;//Consulta o arquivo
      file = fopen(cpf, "r");//Abrir o arquivo "r" significa ler
      
      if(file == NULL)//Valida��o caso cpf n�o seja encontrado
      {
      	 printf("N�o foi possivel abrir o arquivo ; n�o localizado!. \n");//Mensagem para o usu�rio
      	 system("pause");
	  }
      
      while(fgets(conteudo, 200, file) != NULL) //La�ao de repeti��o de busca dentro do arquivo,parar quando for nulo
      {
      	printf("\nEssas s�o as informa��es do usuario: ");//Mensagem para o usu�rio
      	printf("%s", conteudo);//%s Salva o conteudo que esta dentro da string
      	printf("\n\n");//Pular linhas
	  
	  
	     system("pause");//Parar
	     
	   }
	  
}

int deletar()//Fun��o responsavel por deletar usu�rios no sistema
{
	 //Inicio da cria��o de variavel
	
     char cpf[40];
     
     //Fim da cria��o de variavel 
     
     printf("Digite o CPF do usu�rio a ser deletado: ");//Coletando informa��o do usu�rio
     scanf("%s",cpf);//%s Refere-se a string e armazena na variavel CPF
     
     
     remove(cpf);//Acessa e deleta o arquivo 
     
     FILE *file;//Consulta o arquivo
     file = fopen(cpf, "r");//Abrir o arquivo "r" significa ler
     
     
     if(file == NULL)//Valida��o se arquivo n�o existe
     {
     	printf("O usu�rio n�o se encontra no sistema!.\n");//Mensagem para o usu�rio
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
	
     setlocale(LC_ALL, " Portuguese");//Defini��o de Linguagem
    
	 printf("### Cart�rio da EBAC ###\n\n");// Inicio do Menu
	 printf("Escolha a op��o desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");
	 printf("Op��o:");//Fim do Menu
	  
   	 scanf("%d",&opcao);//Armazenamento a escolha do usu�rio
	 
	 system("cls");
	 
	 switch(opcao)//Inicio da sele��o do menu
	 {
	    case 1: 
	    registro();//Chamada de fun��es
	    break;
	  
	    case 2:	
	    consulta();//Chamada de fun��es
	    break;
	   
	    case 3:
	    deletar();//Chamada de fun��es
	    break;	
	  
	    default:
	    printf("Essa op��o n�o esta disponivel!\n");
		system("pause");
		break;
	 
     }
  
   }
	    
}
	
		    
      

	
