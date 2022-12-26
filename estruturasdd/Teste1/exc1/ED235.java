import java.util.Scanner;

public class ED235{
  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);
    int cases = stdin.nextInt();

    while(cases>0){
      int stars = stdin.nextInt();
      int spaces = 0;

      while(stars > 0){
        for(int i=0;i<stars;i++)
          System.out.print('#');
        for(int i=0;i<spaces;i++)
          System.out.print('.');
        stars--;
        spaces++;
        System.out.println();
      }
      cases--;
    }
    stdin.close();
  }
}
