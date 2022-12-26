import java.util.Scanner;

public class ED244{

  static int Criso(int a, int b) {
      int count = 0;
      int v[] = new int[b+1];
        for(int i=2;i<b+1;i++)
            v[i] = 1;

        for(int p = 2; p*p<=b; p++) {
          if(v[p] == 1) {
            for(int i = p*p; i < b+1; i += p)
              v[i] = 0;
            }
          }

          for(int i = a; i < b+1; i++) {
              count += v[i];
          }
        return count;
      }

  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);

    int a = stdin.nextInt();
    int b = stdin.nextInt();
    int contador = Criso(a,b);

    System.out.println(contador);
 }
}
