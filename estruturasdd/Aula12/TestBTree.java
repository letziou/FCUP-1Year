// -----------------------------------------------------------
// Estruturas de Dados 2020/2021 (CC1007) - DCC/FCUP
// http://www.dcc.fc.up.pt/~pribeiro/aulas/edados2021/
// -----------------------------------------------------------
// Exemplo de utilizacao da uma arvore binaria
// Ultima alteracao: 26/04/2018
// -----------------------------------------------------------

import java.util.Scanner;

public class TestBTree {
   public static void main(String[] args) {
      // Ler arvore de inteiros em preorder
      Scanner in = new Scanner(System.in);
      BTree<Integer> t = LibBTree.readIntTree(in);

      System.out.println("numberNodes = " + t.numberNodes());
      System.out.println("numberLeafs = " + t.numberLeafs());
      System.out.println("strict = " + t.strict());
      for(int i=0;i<4;i++)
      System.out.println("nodesLevel"+" "+i+" = "  + t.nodesLevel(i));
      System.out.println("count = "+t.count());
      System.out.println("level(2) = "+t.level(2));

   }
}
