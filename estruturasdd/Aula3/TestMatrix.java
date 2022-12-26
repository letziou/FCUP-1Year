import java.util.Scanner;

class Matrix {
      int data[][]; // os elementos da matriz em si
      int rows;     // numero de linhas
      int cols;     // numero de colunas


   // construtor padrao de matriz
   Matrix(int r, int c) {
      data = new int[r][c];
      rows = r;
      cols = c;
   }

   // Ler os rows x cols elementos da matriz
   public void read(Scanner in) {
      for (int i=0; i<rows;i++)
         for (int j=0; j<cols;j++)
            data[i][j] = in.nextInt();
   }

   // Representacao em String da matrix
   public String toString() {
      String ans = "";
      for (int i=0; i<rows;i++) {
         for (int j=0; j<cols;j++)
            ans += data[i][j] + " ";
         ans += "\n";
      }
      return ans;
   }
   public static Matrix identity(int n){
     Matrix id = new Matrix(n,n);
     for (int i=0; i<n;i++)
        for (int j=0; j<n;j++){
          if(i==j)id.data[i][j] = 1;
          else id.data[i][j] = 0;
        }
      return id;
   }
   public Matrix sum(Matrix m){
     for (int i=0; i<rows;i++)
        for (int j=0; j<cols;j++)
           m.data[i][j] += data[i][j];
      return m;
   }
   public Matrix transpose(){
     Matrix px = new Matrix(this.cols,this.rows);
       for(int i=0;i<this.cols;i++)
         for(int j=0;j<this.rows;j++)
           px.data[i][j] = data[j][i];
    return px ;
   }
   public Matrix multiply(Matrix m){
     Matrix px = new Matrix(this.rows,m.cols);

      for(int i=0;i<this.rows;i++){
        for(int j=0;j<m.cols;j++){
          for(int k=0;k<m.rows;k++){
            px.data[i][j] += this.data[i][k] * m.data[k][j];
          }
        }
      }
      return px;
   }
   public Matrix clone(){
     Matrix n = new Matrix(this.rows,this.cols);

      for(int i=0;i<this.rows;i++)
        for(int j=0;j<this.cols;j++)
          n.data[i][j] = this.data[i][j];

     return n;
   }

   public boolean magic(){
     int test = 0;

      for(int i=0;i<this.rows;i++)
        test += this.data[i][0];

      for(int i=0;i<this.rows;i++){
        int aux = 0;
        for(int j=0;j<this.cols;j++)
          aux += this.data[i][j];

        if(aux!=test) return false;
      }

      for(int i=0;i<this.cols;i++){
        int aux = 0;
        for(int j=0;j<this.rows;j++)
          aux += this.data[j][i];

        if(aux!=test) return false;
      }

      int a = 0;
      for(int i=0;i<this.rows;i++)
        a += this.data[i][i];

      if(a!=test) return false;

      int b = 0;
      for(int i=0;i<this.rows;i++)
        b += this.data[this.rows-1-i][this.rows-1-i];

      if(b!=test) return false;

      return true;
   }
}
class TestMatrix {
   public static void main(String[] args) {
      Scanner stdin = new Scanner(System.in);

      Matrix m1 = Matrix.identity(5);
      System.out.println(m1);

      Matrix m2 = new Matrix(stdin.nextInt(), stdin.nextInt());
      m2.read(stdin);
      System.out.println(m2);
      System.out.println(m2.magic());
   }
}
