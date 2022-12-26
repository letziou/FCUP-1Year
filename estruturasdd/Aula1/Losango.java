public class Losango {

  static void losango (int n){
    int  asteriscos = 1;
    int  espaços = (n-1)/2;

    while(asteriscos <= n){
      for(int i=1;i<=espaços;i++)
      System.out.print(' ');

      for(int j=1;j<=asteriscos;j++)
      System.out.print('#');

      System.out.println();

      asteriscos += 2;
      espaços--;
        }

    asteriscos -= 4;
    espaços = 1;
    while(asteriscos>=1){
      for(int k=1;k<= espaços;k++)
      System.out.print(' ');

      for(int g=1;g<= asteriscos;g++)
      System.out.print('#');

      System.out.println();

      asteriscos -= 2;
      espaços++;
    }

}


  public static void main(String[] args) {
    losango(53);
  }
}
