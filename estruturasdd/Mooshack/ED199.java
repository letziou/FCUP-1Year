import java.util.Scanner;

public class ED199{

  public static void main(String[] args) {

    Scanner stdin = new Scanner(System.in);

    int narcas = stdin.nextInt();
    int posini = stdin.nextInt();
    int ninstr = stdin.nextInt();
    int posmin = posini;
    int posmax = posini;

    String buf = stdin.nextLine(); // mudar a linha
    String arcas = stdin.next();


    for(int i=0;i<ninstr;i++){
      String c = stdin.next();
      int move = stdin.nextInt();

      if(c.equals("E")){
        posini -= move;
        if(posini<posmin)
          posmin = posini;
      }

      if(c.equals("D")){
        posini += move;
        if(posini>posmax)
          posmax = posini;
      }
    }

    int cont=0;
    for(int j=posmin;j<=posmax;j++){
      if(arcas.charAt(j-1) == 'T')
        cont++;
    }

    System.out.println(cont);
  }
}
