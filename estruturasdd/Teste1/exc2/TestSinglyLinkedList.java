import java.util.Arrays;

public class TestSinglyLinkedList {
   public static void main(String[] args) {

      // Criacao de lista de inteiros
      SinglyLinkedList<Integer> list = new SinglyLinkedList<>();
      SinglyLinkedList<Integer> a = new SinglyLinkedList<>();

      for(int i=1;i<11;i++)
        list.addLast(i);

      System.out.println(list);
      a = list.reverse();
      System.out.println(a);
   }
}
