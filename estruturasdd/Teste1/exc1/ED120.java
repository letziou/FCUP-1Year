import java.util.Scanner;

public class ED120{

  static void Losango(int size){
    int cardinal = 1;
    int spaces = (size-1)/2;

    while(cardinal <= size){
    for(int i=0;i<spaces;i++)
      System.out.print('.');
    for(int i=0;i<cardinal;i++)
      System.out.print('#');
    for(int i=0;i<spaces;i++)
      System.out.print('.');
    cardinal += 2;
    spaces--;
    System.out.println();
    }
    cardinal -= 4;
    spaces +=2;
    while(cardinal >= 1){
      for(int i=0;i<spaces;i++)
        System.out.print('.');
      for(int i=0;i<cardinal;i++)
        System.out.print('#');
      for(int i=0;i<spaces;i++)
        System.out.print('.');
      System.out.println();
      cardinal -= 2;
      spaces++;
    }
  }

  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);
    int size = stdin.nextInt();
    Losango(size);
    stdin.close();
  }
}
