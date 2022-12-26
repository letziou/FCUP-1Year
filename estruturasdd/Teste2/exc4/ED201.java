import java.util.Scanner;

public class ED201 {

  static int max;

   // Escrever todos os subconjuntos do array v[]
   static void sets(int v[],int time) {
      // array de booleanos para representar o conjunto
      boolean used[] = new boolean[v.length];
      goSets(0, v, used, time); // chamar funcao recursiva
   }

   // Gera todos os subconjuntos a partir da posicao 'cur'
   static void goSets(int cur, int v[], boolean used[], int time) {
      if (cur == v.length) {  // Caso base: terminamos o conjunto
        int count = 0;
        for(int i=0;i<v.length;i++)
          if(used[i]) count += v[i];
        if(count>max && count<=time)
        max = count;
      } else {                  // Se nao terminamos, continuar a gerar
         used[cur] = true;      // Subconjuntos que incluem o elemento actual
         goSets(cur+1, v, used, time);// Chamada recursiva
         used[cur] = false;     // Subconjuntos que nao incluem o el. actual
         goSets(cur+1, v, used, time);// Chamada recursiva
      }
   }

   // -----------------------------------------------------------

   public static void main(String[] args) {
      max = 0;
      Scanner stdin = new Scanner(System.in);
      int time = stdin.nextInt();
      int songs = stdin.nextInt();
      int []playlist = new int[songs];

      for(int i=0;i<songs;i++)
        playlist[i] = stdin.nextInt();

      sets(playlist, time);
      System.out.println(max);
   }
}
