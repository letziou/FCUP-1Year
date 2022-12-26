import java.util.Arrays;

public class TestSinglyLinkedList {
   public static void main(String[] args) {

      // Criacao de lista de inteiros
      SinglyLinkedList<Character> list = new SinglyLinkedList<>();

      list.addLast('a');
      list.addLast('b');
      list.addLast('c');
      list.addLast('d');
      list.addLast('e');

      System.out.println(list);
      list.duplicate();
      System.out.println(list);

   }
}
