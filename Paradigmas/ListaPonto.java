/*
Entrega da prova 1 - Paradigmas de Linguagens de Programação – 05N

Nós,

Bruno Severo Camilo - 41781619
Nome completo e TIA (2º integrante)

declaramos que

todas as respostas são fruto de nosso próprio trabalho, não copiamos respostas de colegas externos à equipe, não disponibilizamos nossas respostas para colegas externos ao grupo e não realizamos quaisquer outras atividades desonestas para nos beneficiar ou prejudicar outros.
*/

/* Classe ListaPonto */
public class ListaPonto{
  private Ponto pontos[]; 
  private int validos; 
  
  /* Construtor */
  public ListaPonto(int n){ 
    this.pontos = new Ponto[n];
    this.validos = 0;
  }

  public boolean isFull(){
    return (this.pontos.length == this.validos);
  }

  public boolean isNull(int ind){
    return (this.pontos[ind] == null);
  }

  public int getValido(){
    return this.validos;
  }

  public int getPosicaoPossivel(){
    for(int i = pontos.lenght-1; i >= 0; i--){
      if(isNull(i))
        return i; 
    }
    return -1;
  }

  public void empurraDireita(){
    
  }


// 0 1 2 3 4 5 6 7 8 9 10
// 1 1 1 4             

  public void imprimeLista(){
    System.out.print("[ ");
    for(int i = 0; i < this.validos; i++){
      if(this.pontos[i] == null)
        System.out.print("0 ");
      else
        System.out.print(this.pontos[i]+" ");
    }
    System.out.println("]");
  }

  public boolean adicionaFinal(Ponto p){
    if(isFull())
      return false;
    this.pontos[this.validos] = p;
    this.validos += 1;
    return true;
  }
  
  public void adicionaColecao(Ponto p, int ind){
    if(ind < 0 || ind >= pontos.length)
      System.out.println("Indice Inválido!");
    else if(isFull()){
      System.out.println("A lista de pontos está cheia");
      return;
    }
    else{
      if(isNull(ind)){
        if(ind != this.validos) {
          this.pontos[validos] = p;
        } else {
          
        } 
        validos += 1;
      } else if() {

      }
    }
  }
  
/*
  public int ocorrencia(Ponto p){
    for(int i = 0; i < this.validos; i++){
      if(this.pontos[i] == p)
        return i;
    }
    return -1;
  }

  public void removePonto(int ind){
    if(ind == (validos-1))
      this.pontos[this.validos] = null;
    int prox = ind+1;
    if((this.pontos[prox] != null) && (prox < this.validos)){
      for(int i = ind ; i < this.validos; i++){
        this.pontos[i] = this.pontos[i+1];
      }
      this.pontos[validos] = null;
    }
  }

  public double distanciaPonto(){
    
    return 1.1;
  }*/
}