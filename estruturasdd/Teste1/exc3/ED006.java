import java.util.Scanner;

public class ED006{

  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);

    int cases = stdin.nextInt();

    while(cases>0){
      CircularLinkedList<String> list = new CircularLinkedList<>();
      String spaces = stdin.nextLine();
      String frase = stdin.nextLine();
      int words = frase.split(" ").length;
      int nomes = stdin.nextInt();

      for(int i=0;i<nomes;i++){
        String nome = stdin.next();
        list.addLast(nome);
      }

      while(list.size() != 1){
        for(int i=0;i<words;i++)
          list.rotate();

        list.removeLast();
      }

      if(list.getLast().equals("Carlos"))
        System.out.println("O Carlos nao se livrou");
      else System.out.println("O Carlos livrou-se (coitado do "+list.getLast()+"!)");

      cases--;
    }
  }
}
