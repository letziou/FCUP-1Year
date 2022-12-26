import java.util.Scanner;

public class ED243{

  static int Valor(int ningr, int []ingr, int notcases, int []notingr){
    for(int i=0;i<ningr;i++)
      for(int j=0;j<notcases;j++)
        if(ingr[i] == notingr[j])
          return 0;
    return 1;
  }
  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);

    int cont=0;
    int notcases = stdin.nextInt();
    int []notingr = new int[notcases];

    for(int i=0;i<notcases;i++)
      notingr[i] = stdin.nextInt();
    int pizzas = stdin.nextInt();
    while(pizzas>0){
      int ningr = stdin.nextInt();
      int []ingr = new int[ningr];

      for(int i=0;i<ningr;i++)
        ingr[i] = stdin.nextInt();

        cont += Valor(ningr,ingr,notcases,notingr);

      pizzas--;
    }
    System.out.println(cont);
    stdin.close();
  }
}
