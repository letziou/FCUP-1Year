import java.util.Scanner;

public class ED202{

  static float max;

  static void permutations(float v[]) {
boolean used[] = new boolean[v.length]; // $i$ esta na permutacao?
int perm[] = new int[v.length];         // permutacao actual
goPerm(0, v, used, perm); // chamar funcao recursiva
  }
  // Gera todos os subconjuntos a partir da posicao 'cur'
  static void goPerm(int cur, float v[], boolean used[], int perm[]) {
if (cur == v.length) {  // Caso base: terminamos a permutacao
  int count = 0;
    for (int i=0; i<v.length; i++) // Escrever a permutacao
      count += v[i];
      if(count<max)
        max = count;
    System.out.println();
} else { // Se nao terminamos, continuar a gerar
    for (int i=0; i<v.length; i++) // Tentar todos os elementos
  if (!used[i]) {
      used[i] = true; perm[cur] = i;
      goPerm(cur+1, v, used, perm);
      used[i] = false;
  }
}
  }

  public static void main(String[] args){

    Scanner stdin = new Scanner(System.in);

    int places = stdin.nextInt();

    String n = stdin.nextLine();
    String s = stdin.nextLine();
    System.out.println(s);

    float [][]dist = new float[places][places];

    for(int i=0;i<places;i++)
      for(int j=0;j<places;j++){
        dist[i][j] = stdin.nextFloat();
        max += dist[i][j];
      }

    permutations(dist);

    System.out.println(max);
  }
}
