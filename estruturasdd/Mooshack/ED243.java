import java.util.Scanner;

public class ED243{

  static int Ingredientes(int n, int [] x, int m, int [] vec){

    for(int l=0;l<n;l++){
      for(int k=0;k<m;k++){
      if(vec[l] == x[k])
        return 0;
    }
  }
  return 1;
}

  public static void main(String[] args){

    Scanner stdin = new Scanner(System.in);

    int mauingr = stdin.nextInt();
    int x[] = new int[mauingr];
    int j = 0;
    int count = 0;

    for(int i=0;i<mauingr;i++)
      x[i] = stdin.nextInt();


    int pizzas = stdin.nextInt();


    while(j != pizzas){
      int ingr = stdin.nextInt();

      int vec[] = new int[ingr];
        for(int k=0;k<ingr;k++)
          vec[k] = stdin.nextInt();

      count += Ingredientes(ingr,x,mauingr,vec);
      j++;
    }

    System.out.println(count);
  }
}
