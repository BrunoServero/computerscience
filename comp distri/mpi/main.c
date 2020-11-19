#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM 65536

int searchNum(int num, int *vetor){
  for (int i=0;i < TAM; i++){
    if(vetor[i] == num){
      return i;
    }
  }

}

int main(){

  FILE *fp = fopen("vetor1.csv","r");
  int vetor[TAM];
  int num;
  char line[256];
  
  while (fgets(line, sizeof(line), fp) != NULL) {
      vetor[num] = atoi(line) ;
      num++; 
  }
  fclose(fp);
  //printf("%d",vetor[37099]);

  int posicao = searchNum(165207, vetor);
  printf("posição do elemento no vetor: %d", posicao);
}