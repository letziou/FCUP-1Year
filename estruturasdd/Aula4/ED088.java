import java.util.Scanner;

class Game {
    final char DEAD  = '.';  // Constante que indica uma celula morta
    final char ALIVE = 'O';  // Constante que indica uma celula viva
    private int rows, cols;  // Numero de linhas e colunas
    private char m[][];      // Matriz para representar o estado do jogo
    private char m2[][];

    Game(int r, int c) {
	    rows = r;
	    cols = c;
	    m = new char[r][c];
      m2 = new char[r][c];
    }

    // Metodo para ler o estado inicial para a matriz m[][]
    public void read(Scanner in) {
	    for (int i=0; i<rows; i++)
	      m[i] = in.next().toCharArray();
    }

    // Metodo para escrever a matriz m[][]
    public void write() {
      for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
           System.out.print(m[i][j]);
        }
        System.out.println();
      }
    }

    // Deve devolver o numero de celulas vivas que sao vizinhas de (y,x)
    private int countAlive(int y, int x) {
	    int count = 0;

      for(int i= y-1; i <= y+1; i++){
        for(int j= x-1; j <= x+1; j++){
          if(i >= 0 && j >= 0 && i < rows & j < cols){
            if(m[i][j]==ALIVE && (i!=y || j!=x))
               count++;
          }
        }
      }

	    return count;
    }

    // Deve fazer uma iteracao: cria nova geracao a partir da actual
    public void iterate() {
      for(int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
          int alive = countAlive(i,j);

          if(alive == 3 || (m[i][j] == ALIVE && alive ==2 ))
            m2[i][j] = ALIVE;

          else
            m2[i][j] = DEAD;
        }
      }

      for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++)
           m[i][j]=m2[i][j];
      }
    }
}

// Classe principal com o main()
public class ED088 {
  public static void main(String[] args) {
	  Scanner in = new Scanner(System.in);

	  // Ler linhas, colunas e numero de iteracoes
	  int rows = in.nextInt();
	  int cols = in.nextInt();
	  int n    = in.nextInt();

	  // Criar objecto para conter o jogo e ler estado inicial
	  Game g = new Game(rows, cols);
	  g.read(in);

    for(int i=0; i<n; i++){
       g.iterate();
    }
    g.write();
  }
}
