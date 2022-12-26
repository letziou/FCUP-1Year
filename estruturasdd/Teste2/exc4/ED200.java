// -----------------------------------------------------------
// Estruturas de Dados 2020/2021 (CC1007) - DCC/FCUP
// http://www.dcc.fc.up.pt/~pribeiro/aulas/edados2021/
// -----------------------------------------------------------
// Exemplo de flood fill
// Ultima alteracao: 21/04/2018
// -----------------------------------------------------------

import java.util.Scanner;

public class ED200 {
   static int rows;            // Numero de linhas
   static int cols;            // Numero de colunas
   static char m[][];          // Matriz de celulas
   static boolean visited[][]; // Saber se uma dada posicao ja foi visitada

   // Tamanho da mancha que inclui posicao (y,x)
   static int t(int y, int x) {
      if (y<0 || y>=rows || x<0 || x>=cols) return 0; // Caso base: fora dos limites
      if (visited[y][x]) return 0;  // Caso base: celula ja visitada
      if (m[y][x] == '.') return 0; // Caso base: celula vazia
      int count = 1;        // celula nao vazia
      visited[y][x] = true; // marcar como visitada
      count += t(y-1, x);   // Adicionando celulas nao vizinhas
      count += t(y+1, x);
      count += t(y, x+1);
      count += t(y, x-1);
      return count;
   }

   // -----------------------------------------------------------

   public static void main(String[] args) {
      Scanner in = new Scanner(System.in);

      int times = in.nextInt();

      while(times>0){
        rows = in.nextInt();
        cols = in.nextInt();
        m = new char[rows][cols];
        visited = new boolean[rows][cols];
        for (int i=0; i<rows; i++)
          m[i] = in.next().toCharArray();
        int max = 0;
        for(int j=0;j<rows;j++)
          for(int k=0;k<cols;k++){
            int a = t(j,k);
            if(a>max)
              max = a;
          }
        System.out.println(max);
        times--;
      }
   }

}
