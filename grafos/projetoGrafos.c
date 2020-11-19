/*
  Teoria dos Grafos - Turma 06N

  Projeto de Programação-Distância entre Vértices e Conexidade

  Integrantes do grupo:
    Bruno Severo Camilo		        TIA: 41781619
    João Pedro Colafati Pedroso	  TIA: 31819656
    Matheus Soares Santos		      TIA: 31895263
    Wanderson Bezerra de Lima 	  TIA: 31895591
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>

#define _BRANCO_ 0
#define _CINZA_ 1
#define _PRETO_ 2

/* Celula de uma lista arestas */
typedef struct a{
	int nome;
	struct a *prox;
} Aresta;

/* Cada vertice tem um ponteiro para uma lista de aresta */
typedef struct vert{
	int nome;
	int dist;
	int cor;
	Aresta *prim;
} Vertice;

/* Criacao de um grafo com ordem predefinida */
void criaGrafo(Vertice **G, int ordem){
	int i;
	/* Alocacao dinamica de um vetor de vertices */
	*G = (Vertice*) malloc(sizeof(Vertice)*ordem);
	
	for(i = 0; i <ordem; i++){
		(*G)[i].nome = i;
		(*G)[i].dist = -1; /* INFINITO */
		(*G)[i].cor = _BRANCO_; /* nao manipulado */
		(*G)[i].prim = NULL; /* vertice sem nenhuma incidente */
	}
}

/* Desaloca a memoria dinamica usada para armazenar o grafo */
void destroiGrafo(Vertice **G, int ordem){
	int i;
	Aresta *a, *n;

	/* Remove lista de adjacencia de cada vertice */	
	for(i = 0; i <ordem; i++){
		a = (*G)[i].prim;
		while (a!= NULL){
			n = a->prox;
			free(a);
			a= n;
		}
	}
	free(*G);
}

/* Acrescenta uma nova aresta em um grafo previamente criado */
int acrescentaAresta(Vertice G[], int ordem, int v1, int v2){
	Aresta *A1, *A2;
	/* Testa se os vertices sao validos */
	if(v1<0 || v1 >= ordem)
		return 0;
	if(v2<0 || v2 >= ordem)
		return 0;
	
	/* Acrescenta aresta na lista do vertice v1 */
	A1= (Aresta*) malloc(sizeof(Aresta));
	A1->nome = v2;
	A1->prox = G[v1].prim;
	G[v1].prim = A1;
	
	/* acrescenta aresta na lista do vertice v2 se v2 != v1 */
	if (v1 == v2)
		return 1;	
		
	A2= (Aresta*) malloc(sizeof(Aresta));
	A2->nome = v1;
	A2->prox = G[v2].prim;
	G[v2].prim = A2;
	
	return 1;
}

/* Funcao que retorna o tamanho de um grafo */
int calculaTamanho(Vertice G[], int ordem){
	int i;
	int totalArestas=0;
	
	for(i = 0; i<ordem; i++){
		int j;
		Aresta *aux=G[i].prim;
		for(j=0; aux != NULL; aux = aux->prox, j++)
			if(aux->nome ==i)
				j++; /* laco "conta em dobro" */
		totalArestas += j;
	}
	return totalArestas/2 + ordem;
}

/* Imprime o grafo com notação similar a uma lista de adjacencia */
void imprimeGrafo(Vertice G[], int ordem){
	int i;
	Aresta *aux;
	char * cores[] = { "BRANCO", "CINZA", "PRETO" };
	
	printf("\nOrdem: %d", ordem);
	printf("\nTamanho: %d", calculaTamanho(G, ordem));
	printf("\nLista de Adjacencia:\n");
	
	for(i = 0; i < ordem; i++){
		printf("\n V%d (Distancia: %2d Cor: %s): ", i, G[i].dist, cores[G[i].cor]);
		aux = G[i].prim;
		for(; aux != NULL; aux = aux-> prox)
			printf("%3d", aux->nome);
	}
	printf("\n\n");
}

/* Função que calcula o grau de um vértice */
int calculaGrauVertice(Vertice G[], int ordem, int v){
	int j;
	if (v < 0 || v>= ordem)
		return (-1);
    
	Aresta *aux = G[v].prim;
	for(j = 0; aux != NULL; aux = aux->prox, j++){
		if(aux->nome == v)
			j++;
	}
	return (j);
}

/* Funcao que retorna o menor grau do grafo */
int grauMinimo(Vertice G[], int ordem){
  int i, temp, m;
  int min = calculaGrauVertice(G, ordem, 0);
  for(i = 1; i<ordem; i++){
    temp = calculaGrauVertice(G, ordem, i);
    if(temp < min){
      min = temp;
      m = i;
    }
  } 
  return m;
}

/* Funcao que retorna o maior grau do grafo */
int grauMaximo(Vertice G[], int ordem){
  int i, temp, m;
  int max = calculaGrauVertice(G, ordem, 0);
  for(i = 1; i<ordem; i++){
    temp = calculaGrauVertice(G, ordem, i);
      if(temp > max){
      max = temp;
      m = i;
    }
  } 
  return m;	
}

/* Funcao que retorna: 1, se o grafo for regular ou 0, caso contrario */
int eRegular(Vertice G[], int ordem){
  int i, temp;
  int grau = calculaGrauVertice(G, ordem, 0);
  for(i = 1; i<ordem; i++){
    temp = calculaGrauVertice(G, ordem, i);
    if(temp != grau)
      return 0;
  } return 1;
}

/* Função que calcula distancia dos vértices em relação a um vértice inicial */
void calculaDistancia(Vertice G[], int ordemG, int vIni) {
  
  /* Variáveis de controle */
  int i = 0, j = 0;

  /* Passo 1: Preenche a distância dos vértices com -1 e vértice inicial recebe distância 0 */
  for(i = 0; i < ordemG; i++){
    G[i].dist = -1;
  }
  G[vIni].dist = 0;

  /* Passo 2: Inicializa d com 0 */
  int d = 0;

  /* Passo 3: */
  for(;j < ordemG; j++){
    i = 0;
    for(;i < ordemG; i++){
      /* 3.a) Se um vértice possuir distância igual a d. Todos os vértices adjacentes a ele recebem d + 1 */
      if(G[i].dist == d){
        Aresta *auxVer = G[i].prim;
        for(; auxVer != NULL; auxVer = auxVer->prox){
          if(G[auxVer->nome].dist == -1) 
            G[auxVer->nome].dist = d + 1;
        }
      }
    }
    
    /* 3.b) Incremente d */
    d++;	
  }
}

/* Função que verifica se o grafo é conexo */
int eConexo(Vertice G[], int ordemG, int vIni){
  calculaDistancia(G, ordemG, vIni);
  int i;
  for(i = 0; i < ordemG; i++){
    /* Se um vértice não possuir distancia em relação a vIni, o grafo não é conexo */
    if(G[i].dist == -1){
      return 0;
    }
  }
  /* O grafo é conexo */
  return 1;
}

int main(){
	Vertice *G;
	int ordemG = 6;
	
	criaGrafo(&G, ordemG);
	
	acrescentaAresta(G, ordemG, 0, 1);
	acrescentaAresta(G, ordemG, 0, 3);
	acrescentaAresta(G, ordemG, 1, 2);
	acrescentaAresta(G, ordemG, 1, 3);
	acrescentaAresta(G, ordemG, 1, 4);
	acrescentaAresta(G, ordemG, 1, 5);
	acrescentaAresta(G, ordemG, 2, 5);
	acrescentaAresta(G, ordemG, 4, 5);
  imprimeGrafo(G, ordemG);
  if(eConexo(G, ordemG, 0))
    printf("O grafo e conexo\n");
  else
    printf("O grafo nao e conexo\n");
  imprimeGrafo(G, ordemG);

	/* system("PAUSE"); */
	return 0;
}
