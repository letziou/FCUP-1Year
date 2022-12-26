import java.util.Scanner;

public class ED164{

  public static void main(String[] args) {
    Scanner stdin = new Scanner(System.in);
    BSTree<String> t = new BSTree<>();

    int names = stdin.nextInt();
    String buffer = stdin.nextLine();

    while(stdin.hasNextLine()){
      String name = stdin.nextLine();
      t.insert(name);
    }

    System.out.println(t.numberNodes());
  }
}
