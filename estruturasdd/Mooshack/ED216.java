import java.util.Scanner;

public class ED216{

  static int countdown(char[][] x, int row, int col, int rows){
    int cont = 0;

    for(int i = 0 ; (row+i) < rows ;i++){
        if(x[row+i][col] == '#'){
          cont++;
        }
        if(x[row+i][col] != '#'){
          return cont;
        }
      }
    return cont;
  }

  static int countright(char[][] x, int row, int col, int cols){
    int cont = 0;

    for(int i = 0 ; (col+i) < cols ;i++){
        if(x[row][col+i] == '#'){
          cont++;
        }
        if(x[row][col+i] != '#'){
          return cont;
        }
      }
    return cont;
  }

public static void main(String[] args){

  Scanner stdin = new Scanner(System.in);

  int rows = stdin.nextInt();
  int cols = stdin.nextInt();
  int contmax = 0;
  int contprox = 0;
  char x[][] = new char[rows][cols];

    for(int i=0;i<rows;i++) // criar tabuleiro;
      x[i]=stdin.next().toCharArray();

    for(int j=0;j<rows;j++){
      for(int k=0;k<cols;k++){
        if(x[j][k] == '#'){
          int a = countdown(x,j,k,rows);
          if(a > contmax){
            contmax = a;
            contprox = 1;
          }
          else if(a == contmax){
            contprox ++;
          }
          int b = countright(x,j,k,cols);
          if(b > contmax){
            contmax = b;
            contprox = 1;
          }
          else if(b == contmax){
            contprox ++;
          }
        }
      }
    }

  System.out.println(contmax + " " + contprox);

  }
}
