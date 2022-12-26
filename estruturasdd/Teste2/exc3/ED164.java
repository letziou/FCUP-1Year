import java.util.Scanner;

public class ED164{
  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);
    BSTree<String> t = new BSTree<>();

    int names = stdin.nextInt();

    while(names>0){
      String name = stdin.next();
      t.insert(name);
      names--;
    }
    System.out.println(t.numberNodes());
  }
}
