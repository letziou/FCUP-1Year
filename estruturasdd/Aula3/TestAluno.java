class Aluno {
  public static int contador = 0;
   // Atributos da classe (variáveis para conter informação)
   String nome;
   int numero;

   // Construtor "padrão"
   Aluno() {
      nome   = "indefinido";
      numero = -1;
      contador++;
   }
   Aluno(String n, int mec) {
   nome = n;
   numero = mec;
   contador++;
}
int ano() {
   return numero / 100000;
}
   public String toString() {
   return "(" + nome + "," + numero + ")";
}
}

// Classe principal contendo o main para testar a classe Aluno
public class TestAluno {
   public static void main(String[] args) {
     System.out.println("contador = " + Aluno.contador);
     int n = 3;
Aluno[] v = new Aluno[n];
for (int i=0; i<n; i++) v[i] = new Aluno();
v[0].nome = "Pedro";
for (int i=0; i<n; i++){
  System.out.println("v[" + i + "] = " + v[i]);
   }
   System.out.println("contador = " + Aluno.contador);
}
}
