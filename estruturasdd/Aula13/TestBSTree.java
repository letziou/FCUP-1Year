// -----------------------------------------------------------
// Estruturas de Dados 2020/2021 (CC1007) - DCC/FCUP
// http://www.dcc.fc.up.pt/~pribeiro/aulas/edados2021/
// -----------------------------------------------------------
// Exemplo de utilizacao da uma arvore binaria de pesquisa
// Ultima alteracao: 02/05/2018
// -----------------------------------------------------------

class TestBSTree {
   public static void main(String[] args) {

      // Criacao da Arvore
      BSTree<Integer> t = new BSTree<>();

      // Inserindo 11 elementos na arvore binaria de pesquisa
      Integer[] data = {6,3,10,1,4,2,8,7,42,23,54};
      for (int i=0; i<data.length; i++) t.insert(data[i]);

      // Escrever resultado de chamada a alguns metodos
      System.out.println("numberNodes = " + t.numberNodes());
      System.out.println("depth = " + t.depth());
      System.out.println("minValue = " + t.minValue());
      System.out.println("maxValue = " + t.maxValue());
      System.out.println("countBetween(5,44) = " + t.countBetween(5,44));
      System.out.println("countBetween(7,10) = " + t.countBetween(7,10));
      System.out.println("countBetween(0,99) = " + t.countBetween(0,99));
      System.out.println("countBetween(60,80) = " + t.countBetween(60,80));
   }
}
