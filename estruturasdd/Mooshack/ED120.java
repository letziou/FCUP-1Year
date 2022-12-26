import java.util.Scanner;

public class ED120 {
  public static void main(String[] args){

    Scanner stdin = new Scanner(System.in);

    int n= stdin.nextInt();
    int espaços = (n-1)/2;
    int espaçosmax = n;
    int asteriscos = 1;

    while(asteriscos <= n){        //parte de cima até ao centro
      for(int i=1;i<=espaços;i++)
      System.out.print('.');

      for(int j=1;j<=asteriscos;j++)
      System.out.print('#');

      for(int l=(n+1)/2;l<espaçosmax;l++)
      System.out.print('.');

      System.out.println();

      asteriscos += 2;
      espaços--;
      espaçosmax--;
    }
    espaços = 1;
    asteriscos -= 4;
    espaçosmax = (n+1)/2;
    while(asteriscos >= 1){
      for(int k=1;k<=espaços;k++)
      System.out.print('.');

      for(int g=1;g<=asteriscos;g++)
      System.out.print('#');

      for(int m=(n+1)/2;m<=espaçosmax;m++)
      System.out.print('.');

      System.out.println();

      asteriscos -=2;
      espaços++;
      espaçosmax++;
    }
  }

}
