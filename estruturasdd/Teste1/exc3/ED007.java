import java.util.Scanner;

public class ED007{

  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);

    int times = stdin.nextInt();
    String space = stdin.nextLine();

    while(times > 0){
      MyStack<Character> par = new LinkedListStack<>();
      String frase = stdin.nextLine();
      int max = frase.length();
      int erro = -1;

      for(int i=0;i<max;i++){
        if(frase.charAt(i)=='(' || frase.charAt(i)=='[')
          par.push(frase.charAt(i));
        if(frase.charAt(i)==')' && !frase.isEmpty()){
          char a = par.pop();
          if(a != '(' && erro!=(-1))
            erro = i;
          }
        if(frase.charAt(i)==']' && !frase.isEmpty()){
          char a = par.pop();
          if(a != '[' && erro!=(-1))
            erro=i;
          }
      }

      if(erro!=-1)
        System.out.println("Erro na posicao "+erro);
      else
        System.out.println("Expressao bem formada");
      times--;
    }
  }
}
