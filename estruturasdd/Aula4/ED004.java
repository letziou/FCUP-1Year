import java.util.Scanner;

class Galo {

  char tabuleiro[][];
  int n;

   Galo(int size){
     n = size;
     tabuleiro = new char[n][n];

   }

  void read(Scanner stdin){
    for(int i=0;i<n;i++){
    String buf = stdin.next();
      for(int j=0;j<n;j++)
        tabuleiro[i][j] = buf.charAt(j);
      }
    }

  void verify(int y,int x,int incry,int incrx){
    if(tabuleiro[y][x] == '.') return;
    for(int i=0, yy=y, xx=x;i<n;i++, yy+=incry, xx+=incrx)
      if(tabuleiro[y][x] != tabuleiro[yy][xx]) return;
    win(tabuleiro[y][x]);
  }

  void win(char player){
    System.out.println("Ganhou o " + player);
    System.exit(0);
  }

  void check(){
    for(int i=0;i<n;i++) verify (i,0,0,1);
    for(int j=0;j<n;j++) verify (0,j,1,0);
    verify (0,0,1,1);
    verify (0,n-1,1,-1);

    if(finished()) System.out.println("Jogo incompleto");
    else System.out.println("Empate");

  }

  boolean finished(){
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      if(tabuleiro[i][j] == '.') return true;
      return false;
  }
}

class ED004{
  public static void main(String[] args){

    Scanner stdin = new Scanner(System.in);

    int n = stdin.nextInt();

    Galo g = new Galo(n);
    g.read(stdin);
    g.check();

  }
}
