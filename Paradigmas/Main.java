public class Main {
  public static void main(String[] args) {
    Ponto p1 = new Ponto(2, -3);
    Ponto p2 = new Ponto(1, 4);
    Ponto p3 = new Ponto(4, 5);
    ListaPonto lp = new ListaPonto(4);
    //inserindo final
    System.out.println(lp.adicionaFinal(p1)+" "+lp.getValido());
    System.out.println(lp.adicionaFinal(p2)+" "+lp.getValido());
    lp.adicionaColecao(p3, 0);
    System.out.println(lp.adicionaFinal(p1)+" "+lp.getValido());
    System.out.println(lp.adicionaFinal(p3)+" "+lp.getValido());
    //Verificar cheio
    System.out.println(lp.isFull());
    lp.adicionaColecao(p2, -1);
    lp.adicionaColecao(p3, 4);
    /*lp.imprimeLista();
    System.out.println(lp.ocorrencia(p2));
    System.out.println(lp.ocorrencia(p3));*/
  }
}