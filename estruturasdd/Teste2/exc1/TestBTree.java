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
      int[] b = new int[2];

      t.printPreOrder();
      System.out.println("numberNodes = " + t.numberNodes());
      System.out.println("numberLeafs = " + t.numberLeafs());
      System.out.println("strict = " + t.strict());
      // System.out.println("path(ED) = " + t.path("ED"));
      System.out.println("nodesLevel(2) = " + t.nodesLevel(0));
      System.out.println("internal = " + t.internal());
      System.out.println("count = " + t.count());
      b = t.maxLevel();
      System.out.println(b[0] + " " + b[1]);

   }
}
