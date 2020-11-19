/*
Entrega de Trabalho - Analisador Léxico

Nós,

Bruno Severo Camilo tia: 41781619
Natália Gama de Mattos tia: 31887201

declaromos que

todas as respostas são fruto de nosso próprio trabalho, não copiamos respostas de colegas externos, não disponibilizaremos nossas respostas para colegas externos e não realizaremos quaisquer outras atividades desonestas para nos beneficiar ou prejudicar outros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Define o tamanho dos vetores Auxiliares */
#define TAMANHO 200

/* Define as constantes inteiras para os atomo */
typedef enum{
  ERRO,
  IDENTIFICADOR,
  NUMERO_INTEIRO,
  REAL,
  ATRIBUICAO,
  WHILE,
  AND,
  OR,
  BEGIN,
  END,
  BOOLEAN,
  CHAR,
  INTEGER,
  DO,
  TRUE,
  FALSE,
  IF,
  ELSE,
  MOD,
  PROGRAM,
  THEN,
  WRITE,
  ABRE_PAR,
  FECHA_PAR,
  PONTO,
  PONTO_VIRGULA,
  SUBTRACAO,
  ADICAO,
  DIVISAO,
  MULTIPLICACAO,
  ME,
  MEI,
  IG,
  DI,
  MA,
  MAI,
  CARACTERE,
  COMENTARIO,
  EOS
} TAtomo;

/* Struct do atomo */
typedef struct{
  TAtomo atomo;
  char *atributo;
  int linha;
} TInfoAtomo;

/* Buffer global que armazenará a string do arquivo */
char *buffer;
/* Variável global que incrementa o buffer */
int i;

/* Contador de linhas do arquivo */
int contadorLinhas = 1;

/* Vetor de Atomos */
char *vetorAtomo[40] = {"ERRO", "IDENTIFICADOR", "NUMERO_INTEIRO", "REAL", "ATRIBUICAO", "WHILE", "AND", "OR", "BEGIN", "END", "BOOLEAN", "CHAR", "INTEGER", "DO", "TRUE", "FALSE", "IF", "ELSE", "MOD", "PROGRAM", "THEN", "WRITE", "ABRE_PAR", "FECHA_PAR", "PONTO","PONTO_VIRGULA", "SUBTRACAO", "ADICAO", "DIVISAO","MULTIPLICACAO", "ME", "MEI", "IG", "DI", "MA", "MAI", "CARACTERE", "COMENTARIO", "EOS"};

/*Função que reconhece a palabra reservada*/
int eReservada(char *palavra){
  TInfoAtomo a;
  int i;
  for(i = 0; i<39; i++){
    if(!strcmp(palavra, vetorAtomo[i])){
      return i;
    }
  }
  return -1;
}

/* Função que identifica NUMERO INTEIRO e NUMERO REAL */
TInfoAtomo eNumero(){
  TInfoAtomo atomo;
  char *num = calloc(TAMANHO, sizeof(char));
  int j = 0;
  atomo.linha = contadorLinhas;

  q0:
    if(isdigit(buffer[i])){ 
      num[j] = buffer[i];
      i++;
      j++;
      goto q1;
    }
  
  q1:
    if(isdigit(buffer[i])){
      num[j] = buffer[i];
      i++;
      j++;
      goto q1;
    }

    else if(isalpha(buffer[i])){
      atomo.atomo = ERRO;
      atomo.atributo = num;
      return atomo;
    }

    else if(buffer[i] == '.'){
      num[j] = buffer[i];
      i++;
      j++;
      goto q2;
    }

    else if(buffer[i] == '\n'){
      atomo.atomo = NUMERO_INTEIRO;
      atomo.atributo = num;
      return atomo;
    }

    else {
      atomo.atomo = NUMERO_INTEIRO;
      atomo.atributo = num;
      return atomo;
    }
    
  q2:
    if(isdigit(buffer[i])){
      num[j] = buffer[i];
      i++;
      j++;
      goto q3;
    }
    else {
      atomo.atomo = ERRO;
      atomo.atributo = num;
      return atomo;
    }

  q3:
    if(isdigit(buffer[i])){
      num[j] = buffer[i];
      i++;
      j++;
      goto q3;
    }
    else if(isalpha(buffer[i])){
      atomo.atomo = ERRO;
      atomo.atributo = num;
      return atomo;
    }
    else if(buffer[i] == '.'){
      atomo.atomo = ERRO;
      atomo.atributo = num;
      return atomo;
    }
    else if(buffer[i] == '\n'){
      atomo.atomo = REAL;
      atomo.atributo = num;
      return atomo;
    }
    else {
      atomo.atomo = REAL;
      atomo.atributo = num;
      return atomo;
    }
}

/*Função que transforma os caracteres em letra maiscula*/
char* upperChar(char* str){
  char* aux = calloc(TAMANHO, sizeof(char));
  int k;

  for (k = 0; str[k]!=0; k++) {
    if(str[k] >= 'a' && str[k] <= 'z') 
      aux[k] = str[k] - 32;
    
    else
      aux[k] = str[k];
  }
  return aux;
}


/*Função que identifica IDENTIFICADOR*/
TInfoAtomo eId(){
  TInfoAtomo atomo;
  char *num = calloc(TAMANHO, sizeof(char));
  int j = 0;
  atomo.linha = contadorLinhas;
  
  q0:
    if(isalpha(buffer[i])) {
      num[j] = buffer[i];
      i++;
      j++;
      goto q1;
    }

  q1:
    if(isdigit(buffer[i])){
      num[j] = buffer[i];
      i++;
      j++;
      goto q1;
    }
    else if(isalpha(buffer[i])){
      num[j] = buffer[i];
      i++;
      j++;
      goto q1;
    }
    else if(buffer[i] == '\n'){
      char *aux = upperChar(num);
      int reser = eReservada(aux);
      if(reser != -1) {
        atomo.atomo = reser;
        atomo.atributo = num;
        return atomo;
      }
      else {
        if(num[1] == 0) 
          atomo.atomo = CARACTERE;
        else
          atomo.atomo = IDENTIFICADOR;

        atomo.atributo = num;
        return atomo;
      }
    }

    else {
      char *aux = upperChar(num);
      int reser = eReservada(aux);
      if(reser != -1) {
        atomo.atomo = reser;
        atomo.atributo = num;
        return atomo;
      }

      else {
         if(num[1] == 0) 
          atomo.atomo = CARACTERE;
        else
          atomo.atomo = IDENTIFICADOR;
        atomo.atributo = num;
        return atomo;
      }
    }
}

/*Função que identifica ATRIBUIÇÃO*/
TInfoAtomo eAtribuicao(){
  TInfoAtomo atomo;
  atomo.linha = contadorLinhas;
  
  if(buffer[i] == ':')
    i++;
    if(buffer[i] == '=') {
      atomo.atomo = ATRIBUICAO;
      atomo.atributo = ":=";
      i++;
      return atomo;
    }
    else {
      atomo.atomo = ERRO;
      return atomo;
    }
}

/*Função identifica COMENTARIO*/
TInfoAtomo eComentario() {
  TInfoAtomo atomo;
  atomo.linha = contadorLinhas;
  char *comentario = calloc(TAMANHO, sizeof(char));
  int j = 0;
  if(buffer[i] == '#'){
    while(buffer[i] != '\n' && buffer[i] != 0){
      comentario[j] = buffer[i];
      i++;
      j++;
    }
  }
  else {
    while(buffer[i] != '}'){
      if(buffer[i] == 0){
        atomo.atomo = ERRO;
        return atomo;
      }
      
      if(buffer[i] == '\n')
        contadorLinhas++;
        
      comentario[j] = buffer[i];
      i++;
      j++;
    }
    comentario[j] = buffer[i];
    i++;
    j++;
  }
  atomo.atomo = COMENTARIO;
  atomo.atributo = comentario;
  return atomo;
}

/*Função que reconhece SIMBOLOS*/
TInfoAtomo eSimbolo(){
  TInfoAtomo atomo;
  atomo.linha = contadorLinhas;

  switch(buffer[i]){
    
    case '(':
      atomo.atributo = "(";
      atomo.atomo = ABRE_PAR;
      break;

    case ')':
      atomo.atributo = ")";
      atomo.atomo = FECHA_PAR;
      break;

    case '.':
      atomo.atributo = ".";
      atomo.atomo = PONTO;
      break;

    case ';':
      atomo.atributo = ")";
      atomo.atomo = PONTO_VIRGULA;
      break;

    case ':':
      return eAtribuicao();
    
    case '-':
      atomo.atributo = "-";
      atomo.atomo = SUBTRACAO;
      break;

    case '+':
      atomo.atributo = "+";
      atomo.atomo = ADICAO;
      break;
    
    case '*':
      atomo.atributo = "*";
      atomo.atomo = MULTIPLICACAO;
      break;
    
    case '/':
      atomo.atributo = "/";
      atomo.atomo = DIVISAO;
      break;
    
    case '=':
      atomo.atributo = "=";
      atomo.atomo = IG;
      break;

    case '<':
      if(buffer[i+1] == '=') {
        atomo.atributo = "<=";
        atomo.atomo = MEI;
      }
      else {
        atomo.atributo = "<";
        atomo.atomo = ME;
      }
      break;

    case '>':
      if(buffer[i+1] == '=') {
        atomo.atributo = ">=";
        atomo.atomo = MAI;
      }
      else {
        atomo.atributo = ">";
        atomo.atomo = MA;
      }
      break;

    case '!':
      if(buffer[i+1] == '=') {
        atomo.atributo = "!=";
        atomo.atomo = DI;
      }
      else {
        atomo.atomo = ERRO;
      }
      break;

    case '#':
      return eComentario();
    
    case '{':
      return eComentario();

    default:
      atomo.atomo = ERRO;
      break;
  }
  i++;
  return atomo;
}

TInfoAtomo obterAtomo(){

  /* Verifica se é um número inteiro */
  if(isdigit(buffer[i])){  
    return eNumero();
  }

  /* Verifica se é identificador */
  else if(isalpha(buffer[i])){
    return eId();
  }

  /* Verifica se pulou a linha */
  else if(buffer[i] == '\n') {
    contadorLinhas++;
    TInfoAtomo atomo;
    return atomo;
  }
  
  /* Verifica se é o final do arquivo */
  else if(buffer[i+1] == 0 || buffer[i] == 0){
    TInfoAtomo atomo;
    atomo.atomo = EOS;
    atomo.linha = contadorLinhas;
    return atomo;
  }

  else if(ispunct(buffer[i])){
    return eSimbolo();
  }
  
  /* Erro em qualquer outro caso */
  else {
    TInfoAtomo atomo;
    atomo.linha = contadorLinhas;
    atomo.atomo = ERRO;
    return atomo;
  }
}

//{Número da Linha do Átomo, Átomo, Atributo}
void construtorSaida(FILE *fp){
  do {
    TInfoAtomo atomo = obterAtomo();
    if(atomo.atomo == ERRO) {
      printf("{Numero da linha: %d | Atomo: %s }\n",atomo.linha, vetorAtomo[atomo.atomo]);
      fprintf(fp, "{Numero da linha: %d | Atomo: %s }\n",atomo.linha, vetorAtomo[atomo.atomo]);
      return;
    } else if(atomo.atomo == EOS) {
      printf("{Numero da linha: %d | Atomo: %s }\n",atomo.linha, vetorAtomo[atomo.atomo]);
      fprintf(fp, "{Numero da linha: %d | Atomo: %s }\n",atomo.linha, vetorAtomo[atomo.atomo]);
      return;
    }
    printf("{Numero da linha: %d | Atomo: %s | Atributo: %s }\n",atomo.linha, vetorAtomo[atomo.atomo],atomo.atributo);
    fprintf(fp, "{Numero da linha: %d | Atomo: %s | Atributo: %s }\n",atomo.linha, vetorAtomo[atomo.atomo],atomo.atributo);
     

    /* Se encontrar espaço, apenas incrementa o caractere */
    if(buffer[i] == ' ')
      i++;
      
    /* Se for quebra de linha, incrementa o contador de linhas e o caractere */
    while(buffer[i] == '\n'){
      contadorLinhas++;
      i++;
    }

  } while(buffer[i-1] != 0);
}

int main(void){

  FILE *fp_input, *fp_output;
  char *iniBuffer;

  fp_input = fopen("input.txt", "r"); //abro o arquivo

  //testa se abriu corretamente
  if(!fp_input){
    printf("erro ao abrir input.\n");
    return 1;
  }

  fseek(fp_input, 0, SEEK_END); // move ponteiro do arquivo para o final
  long tamanho = ftell(fp_input); // conta a quantidade de bytes deslocados na movimentacao

  fseek(fp_input, 0, SEEK_SET); // move novamente para o inicio do arquivo
  buffer = (char*)calloc(tamanho+1,sizeof(char)); // aloca os memoria para guardar o arquivo lido
  fread(buffer, sizeof(char),tamanho,fp_input); // le de uma vez so o arquivo
  printf("%s\n",buffer);

  // abre o arquivo de output
  fp_output = fopen("output.txt", "w+");// w+ abre para escrita e se o arquivo nao existir cria

  //verifica se o arquivo abriu corretamente
  if(!fp_output){
    printf("erro ao abrir output.\n");
    return 1;
  }

  construtorSaida(fp_output);
  iniBuffer = buffer;
  //libero a memoria e fecho ambos os arquivos
  free(iniBuffer);
  fclose(fp_input);
  fclose(fp_output); //fecha o arquivo de output

  return 0;
}