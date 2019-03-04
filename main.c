/*
Universidade de Brasília
Disciplina: Algorítmos de Programação de Computadores
Turma: FF
Alunos: 
       Pedro Igor Silva; Matrícula: 17/0062635; 
       Thayná Cortes Pereira; Matrícula: 17/0063577;
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct contato
{
  char nome[100][101], email[100][101], sexo[101], telefone[100][20];
  int idade[100];
  int pessoa;
};
typedef struct contato contato;
int main()
{
  system("clear");
  int opcao, p, p2, igual;
  char enter[1], email[101], yon;
  contato pessoa;
  pessoa.pessoa = 0;
  
  while(1){
    printf("AGENDA DE CONTATOS\n\n");
    printf("\t1. Cadastrar novo contato\n");
    printf("\t2. Atualizar contato existente\n");
    printf("\t3. Pesquisar contato por e-mail\n");
    printf("\t4. Listar todos os contatos\n");
    printf("\t5. Remover contato\n");
    printf("\t6. Sair\n");
    scanf("%d", &opcao);
    getchar();
    system("clear");//para limpar o terminal
    switch(opcao){
      case 1:
        igual = 0;
        for(p = 0; p < 100; p++){
          if(pessoa.email[p][0] == '\0' && igual == 0){
            igual++;
            pessoa.pessoa = p;
          }
        }
        if(igual == 0){ //pessoa.pessoa determina a quantidade de contatos adicionados
          printf("Sua agenda já está cheia\n");
          printf("Digite Enter para voltar ao Menu Principal\n");
          scanf("%[^\n]s", enter);
          getchar();
          system("clear");
          continue;
        }
        printf("Vamos cadastrar um novo contato. Preencha as informações:\n");
        printf("Digite o nome do contato:\n");
        scanf("%[^\n]s", pessoa.nome[pessoa.pessoa]); //armazena o nome
        getchar();
        while(1){
          printf("Digite o email do contato:\n");
          scanf("%s", pessoa.email[pessoa.pessoa]); //armazena o email
          getchar();
          for(p = 0; p < 100; p++){
            pessoa.email[pessoa.pessoa][p] = tolower(pessoa.email[pessoa.pessoa][p]);//transforma todo o email em minúsuculo
            igual = 0;
            if(p == pessoa.pessoa){ //caso o contador p seja igual ao número da pessoa logo abaixo irá acusar como email igual mas é o mesmo email da mesma pessoa.
              p++;
              pessoa.email[pessoa.pessoa][p] = tolower(pessoa.email[pessoa.pessoa][p]);
            }
            if(strcmp(pessoa.email[pessoa.pessoa], pessoa.email[p]) == 0){  //caso o email adicionado seja igual a outro email é solicitado que seja digitado outro.
              igual++;
              printf("Um contato com esse email já foi adicionado. Não é possível adicioná-lo novamente.\n");
              printf("Digite Enter para digitar um email diferente.\n");
              scanf("%[^\n]s", enter);
              getchar();
              break;
            }
        }
          if(igual == 0) //caso o email não coincida com nenhum outro o programa continua
            break;
        }
        printf("Digite o telefone do contato:\n");
        scanf("%[^\n]s",pessoa.telefone[pessoa.pessoa]); //armazena o telefone
        getchar();
        while(1){
          printf("Qual o sexo do contato? Digite 'm' caso masculino e 'f' caso feminino.\n");
          scanf("%c", &pessoa.sexo[pessoa.pessoa]); //armazena o sexo
          getchar();
          pessoa.sexo[pessoa.pessoa] = toupper(pessoa.sexo[pessoa.pessoa]);
            if(pessoa.sexo[pessoa.pessoa] != 'M' && pessoa.sexo[pessoa.pessoa] != 'F'){ //caso o sexo não seja nem 'F' nem 'M'
              printf("Opção de sexo inválida. Pressione Enter para digitá-la novamente.\n");
              scanf("%[^\n]s", enter);
              getchar();
              continue;
          }
            else
              break;
        }
        while(1){
          printf("Qual a idade em anos do contato?\n");
          scanf("%d", &pessoa.idade[pessoa.pessoa]);
          getchar();
          if(pessoa.idade[pessoa.pessoa] <= 0 || pessoa.idade[pessoa.pessoa] > 120){ //Caso a idade seja inválida
            printf("Idade inválida. Pressione Enter para digitá-la novamente.\n");
            scanf("%[^\n]s", enter);
            getchar();
            continue;
           }
          else
            break;
        }
        printf("Cadastro efetuado com sucesso!\n");
        printf("Digite Enter para voltar ao Menu Principal\n");
        scanf("%[^\n]s", enter);
        getchar();
        system("clear");
        pessoa.pessoa++;
        continue;  //Retorna ao menu principal pois o cadastro foi feito com sucesso.
      case 2:
        printf("Vamos atualizar um contato.\n");
        printf("Digite o email do contato o qual deseja atualizar.\n");
        scanf("%s", email);
        getchar();
        for(p = 0; email[p]=='\0'; p++){
          email[p] = tolower(email[p]);
        }
        igual = 0;
        for(p = 0; p < 100; p++){
          if(strcmp(pessoa.email[p], email) == 0){  //Caso realmente seja encontrado o email o qual deseja-se editar
            igual++;
            printf("O contato foi encontrado.\n");
            printf("Preencha as informações:\n");
            printf("Deseja atualizar o nome do contato? Digite 's' caso Sim e 'n' caso Não. Logo após pressione Enter.\n");
            scanf("%c", &yon);
            getchar();
            if(toupper(yon) == 'S'){
              printf("Digite o nome do contato:\n");
              scanf("%[^\n]s",pessoa.nome[p]);
              getchar();
            }
            printf("Deseja atualizar o email do contato? Digite 's' caso Sim e 'n' caso Não. Logo após pressione Enter.\n");
            scanf("%c", &yon);
            getchar();
            if(toupper(yon) == 'S'){
              while(1){
                igual = 1;
                printf("Digite o email do contato:\n");
                scanf("%s", pessoa.email[p]);
                getchar();
                for(p2 = 0; pessoa.email[p][p2]=='\0'; p2++){ //transforma o novo email em minúsuclo
                  pessoa.email[p][p2] = tolower(pessoa.email[p][p2]);
                }
                for(p2 = 0; p2 < 100; p2++){
                  if(p2 == p)
                    p2++;
                  if(strcmp(pessoa.email[p2], pessoa.email[p]) == 0){ //Verifica se há algum email igual ao novo adicionado
                    igual++;
                    printf("Um contato com esse email já foi adicionado. Não é possível adicioná-lo novamente.\n");
                    printf("Digite Enter para adicionar um email diferente.\n"); //Se o email já existir solicita-se que digite outro.
                    scanf("%[^\n]s", enter);
                    getchar();
                    break;
                  }
                }
                if(igual == 1)
                  break;
               }
             }
        printf("Deseja atualizar o telefone do contato? Digite 's' caso Sim e 'n' caso Não. Logo após pressione Enter.\n");
        scanf("%c", &yon);
        getchar();
        if(toupper(yon) == 'S'){
          printf("Digite o telefone do contato:\n"); //Se o usuário desejar atualizar o telefone, solicita-se aqui o novo telefone
          scanf("%[^\n]s", pessoa.telefone[p]);
          getchar();
        }
        printf("Deseja atualizar o sexo do contato? Digite 's' caso Sim e 'n' caso Não. Logo após pressione Enter.\n");
        scanf("%c", &yon);
        getchar();
        if(toupper(yon) == 'S'){
          while(1){
            printf("Qual o sexo do contato? Digite 'm' caso masculino e 'f' caso feminino.\n");
            scanf("%c", &pessoa.sexo[p]); //Se o usuário desejar atualizar o sexo, solicita-se aqui o novo sexo
            getchar();
            pessoa.sexo[p] = toupper(pessoa.sexo[p]);
            if(pessoa.sexo[p] != 'M' && pessoa.sexo[p] != 'F'){
              printf("Opção de sexo inválida. Pressione Enter para digitá-la novamente.\n");
              scanf("%[^\n]s", enter);
              getchar();
              continue;
          }
            else
              break;
          }
        }
        printf("Deseja atualizar a idade do contato? Digite 's' caso Sim e 'n' caso Não. Logo após pressione Enter.\n");
        scanf("%c", &yon);
        getchar();
        if(toupper(yon) == 'S'){
          while(1){
            printf("Qual a idade em anos do contato?\n");
            scanf("%d", &pessoa.idade[pessoa.pessoa]); //Se o usuário desejar atualizar a idade do contato, solicita-se aqui a nova idade
            getchar();
            if(pessoa.idade[pessoa.pessoa] <= 0 || pessoa.idade[pessoa.pessoa] > 120){
              printf("Idade inválida. Pressione Enter para digitá-la novamente.\n");
              scanf("%[^\n]s", enter);
              getchar();
              continue;
            }
            else
              break;
          }
        } 
        printf("Atualização feita com sucesso!\n");
        printf("Digite Enter para voltar ao Menu Principal\n");
        scanf("%[^\n]s", enter);
        getchar();
        system("clear");
        break;
          }
      }
      if(igual == 0){
      printf("O email %s não foi encontrado.\n", email);
      printf("Digite Enter para voltar ao Menu Principal.\n");
      scanf("%[^\n]s", enter);
      getchar();
      system("clear");
      break;  
      }
      continue;
    case 3:
      printf("Vamos consultar as informações de um contato?\n");
      printf("Digite o email do contato o qual deseja verificar as informações.\n");
      scanf("%s", email);
      getchar();
      for(p = 0; p < strlen(email); p++){ //transforma o email em minúsculo
        email[p] = tolower(email[p]);
      }
      igual = 0;
      for(p = 0; p < 100; p++){
        if(strcmp(pessoa.email[p], email) == 0){  //Caso realmente seja encontrado o email o qual deseja-se verificar
          igual++;
          printf("Contato encontrado com sucesso. Informações do Contato:\n");
          printf("Nome: %s\n", pessoa.nome[p]);
          printf("Email: %s\n", pessoa.email[p]);
          if(toupper(pessoa.sexo[p]) == 'M')
            printf("Sexo: Masculino\n");
          else
            printf("Sexo: Feminino\n");
          printf("Telefone: %s\n", pessoa.telefone[p]);
          printf("Idade: %d anos\n", pessoa.idade[p]);
          printf("\nDigite Enter para voltar ao Menu Principal.\n");
          scanf("%[^\n]s", enter);
          getchar();
          system("clear");
          break;
        }
      }
      if(igual == 0){
        printf("O email %s não foi encontrado.\n", email);
        printf("Digite Enter para voltar ao Menu Principal.\n");
        scanf("%[^\n]s", enter);
        getchar();
        system("clear");
        break;
      }
      continue;
    case 4:
      igual = 0;
      for(pessoa.pessoa = 0; pessoa.pessoa < 100; pessoa.pessoa++){
        if(pessoa.email[pessoa.pessoa][0]!= '\0')
          igual++;
      }
      if(igual == 0){
        printf("Sua lista de contatos está vazia! Volte ao Menu Principal e selecione a opção 1 para adicionar um contato.\n");
        printf("Digite Enter para voltar ao Menu Principal.\n");
        scanf("%[^\n]s", enter);
        getchar();
        system("clear");
        break;
      }
      else{
        printf("LISTA DE CONTATOS\n");
        printf("Nome:                    Telefone:                     E-mail:                    \n");      
        for(pessoa.pessoa = 0; pessoa.pessoa < 100; pessoa.pessoa++){
          if(pessoa.email[pessoa.pessoa][0] != '\0'){
            printf("     %20s         %20s       %20s\n", pessoa.nome[pessoa.pessoa], pessoa.telefone[pessoa.pessoa], pessoa.email[pessoa.pessoa]);
          }
        }
        printf("Digite Enter para voltar ao Menu Principal.\n");
        scanf("%[^\n]s", enter);
        getchar();
        system("clear");
        break;
      }
      continue;  
    case 5:
      printf("Vamos remover um contato?\n");
      printf("Digite o email do contato:\n");
      scanf("%s", email);
      getchar();
      igual = 0;
      for(pessoa.pessoa = 0; pessoa.pessoa < 100; pessoa.pessoa++){
        if(strcmp(pessoa.email[pessoa.pessoa], email) == 0){
          igual++;
          printf("Deseja realmente remover o contato ""%s""? Digite 's' caso Sim e 'n' caso Não. Logo após pressione Enter.\n", email);
          scanf("%c", &yon);
          getchar();
          if(toupper(yon) == 'S'){
            pessoa.nome[pessoa.pessoa][0] = '\0'; //LIMPA AS COMPONENTES DA STRUCT
            pessoa.email[pessoa.pessoa][0] = '\0';
            pessoa.sexo[pessoa.pessoa] = '\0';
            pessoa.telefone[pessoa.pessoa][0] = '\0';
            pessoa.idade[pessoa.pessoa] = 0;
            pessoa.pessoa = 0;
            printf("Contato removido com sucesso!\n");
            printf("Digite Enter para voltar ao Menu Principal.\n");
            scanf("%[^\n]s", enter);
            getchar();
            system("clear");
            break;
          }
          else{
            printf("Digite Enter para voltar ao Menu Principal.\n");
            scanf("%[^\n]s", enter);
            getchar();
            system("clear");
            break;
          }
        }
      }
      if(igual == 0){
        printf("O email ""%s"" não foi encontrado!\n", email);
        printf("Digite Enter para voltar ao Menu Principal.\n");
        scanf("%[^\n]s", enter);
        getchar();
        system("clear");
        break;
      }
      continue; 

    case 6:
      printf("Deseja realmente sair? Digite 's' caso Sim e 'n' caso Não. Logo após pressione Enter.\n");
      scanf("%c", &yon);
      getchar();
      if(toupper(yon) == 'S')
        return 0;
      else{
        printf("Digite Enter para voltar ao Menu Principal.\n");
        scanf("%[^\n]s", enter);
        getchar();
        system("clear");
        break;
      }
    }
  }
  return 0;
}