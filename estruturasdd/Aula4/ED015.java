import java.util.Scanner;

class Sopa{

  int rows;
  int cols;
  char sopa[][];
  char troca[][];


  Sopa(int l,int c){
    rows = l;
    cols = c;
    sopa = new char [rows][cols];
    troca = new char [rows][cols];
  }

  void read(Scanner stdin){
    for(int i=0;i<rows;i++)
      sopa[i] = stdin.next().toCharArray();
  }

  void search(String a){

      String l = a;
      int k = l.length();

      for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
          if(sopa[i][j] == l.charAt(0) && searchud(i,j,l,k)){
            evaluate(l,'+',i,j,k);
            }
          if(sopa[i][j] == l.charAt(0) && searchdu(i,j,l,k)){
            evaluate(l,'-',i,j,k);
          }
          if(sopa[i][j] == l.charAt(0) && searchrl(i,j,l,k)){
            evaluate(l,'*',i,j,k);
          }
          if(sopa[i][j] == l.charAt(0) && searchlr(i,j,l,k)){
            evaluate(l,'/',i,j,k);
          }
        }
      }
    }

  void evaluate(String l,char q,int i,int j,int k){
    if(q == '+'){
      for (int m = i; m < k; m++){
        troca[m][j] = l.charAt((m-i));
      }
    }
    if(q == '-'){
      for(int a = 0; a < k; a++){
        troca[i-a][j] = l.charAt(a);
      }
    }
    if(q == '*'){
      for(int o = j; o < k; o++){
        troca[i][o] = l.charAt((o-j));
      }
    }
    if(q == '/'){
      for(int x = 0; x < k; x++){
        troca[i][j-x] = l.charAt(x);
      }
    }
    return ;
  }

  boolean searchud(int i, int j, String l, int k){
    int count=0;
      for (int m = i; m < k; m++) {
        if(m >= 0 && m < rows ){
          if(sopa[m][j] != l.charAt(m)) break;
          else count++;
        }
      }

      if(count == k) return true;
      else return false;
    }

    boolean searchrl(int i, int j, String l, int k){
      int count=0;
      for(int o = j; o < k; o++){
        if(o >= 0 && o < cols ){
          if(sopa[i][o] != l.charAt(o)) break;
          else count++;
        }
      }

      if(count == k) return true;
      return false;
    }

    boolean searchdu(int i, int j, String l, int k){
      int count = 0;
      for(int a = 0; a < k; a++){
        if((i-a) >= 0 && (i-a) < rows){
          if(sopa[i-a][j] != l.charAt(a)) break;
          else count++;
        }
      }

      if(count == k) return true;
      return false;
    }

    boolean searchlr(int i, int j, String l, int k){
      int count =0;

      for(int x = 0; x < k; x++){
        if((i-x) >= 0 && (i-x) < cols){
          if(sopa[i][j-x] != l.charAt(x)) break;
          else count++;
        }
      }

      if(count == k) return true;
      else return false;
    }

    void sopafinal(){
      for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
          if(troca[i][j]>='A' && troca[i][j]<='Z'){
            sopa[i][j] = troca[i][j];
          }
          else{
            sopa[i][j] = '.';
          }
        }
      }
    void write(){
      for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
          System.out.print(sopa[i][j]);
        }
      System.out.println();
    }
  }

    public class ED015{
      public static void main(String[] args) {

        Scanner stdin = new Scanner(System.in);

        int j = 1;
        int l = stdin.nextInt();
        int c = stdin.nextInt();
        while(l!=0 && c!=0){
          int n = 0;
        int i = stdin.nextInt();

        Game g = new Game(l,c);
        g.read(stdin);

        while(n<i){
        String k = stdin.next();
        g.search(k);
        n++;
        }
        g.sopafinal();
        System.out.println("Input #" + j);
        g.write();

        int a = stdin.nextInt();
        l = a;
        int b = stdin.nextInt();
        c = b;
        j++;
    }
  }
}
