import java.util.Scanner;

public class ED006{

  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);
    CircularLinkedList<String> list = new CircularLinkedList<>();

    int cases = stdin.nextInt();
    while(cases > 0){
    String buffer = stdin.next();
    String frase = stdin.nextLine();
    int size = frase.split(" ").length;

    int kids = stdin.nextInt();

    for(int i=0; i<kids ;i++){
      String nome = stdin.next();
      list.addLast(nome);
    }

    while(list.size() != 1){
      for(int j=0; j<size-1 ;j++){
        list.rotate();
      }
      list.removeFirst();
    }
    if(list.getFirst().equals("Carlos"))
      System.out.println("O Carlos nao se livrou");

    else System.out.println("O Carlos livrou-se (coitado do " + list.getFirst() + "!)");

    list.removeFirst();
    cases--;
   }
  }
}
