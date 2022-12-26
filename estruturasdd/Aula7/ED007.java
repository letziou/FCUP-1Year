import java.util.Scanner;

public class ED007{
  public static void main(String[] args){
    MyStack<Character> p = new LinkedListStack<>();
    Scanner stdin = new Scanner(System.in);
    int times = stdin.nextInt();

    while(times > 0){
      String s = stdin.next();
      int max = s.length();
      char var;
      int pos;

      for(int i=0; i<max ;i++){
        if(s.charAt(i) != ')' || s.charAt(i) != ']')
          p.push(s.charAt(i));

        if(s.charAt(i) == ')' || s.charAt(i) == ']'){
          if(p.isEmpty()){
            System.out.println("Erro na posicao " + p.size());
            continue;
          }

          pos = p.size();
          var = p.pop();
          while(var != '(' || var != '[' || p.isEmpty())
            var = p.pop();

          if(p.isEmpty() && var != '(' && var != '['){
            System.out.println("Erro na posicao " + p.size());
            continue;
          }
        }
      }

      if(p.isEmpty())
        System.out.println("Ficam parenteses por fechar");
      else System.out.println("Expressao bem formada");
      times--;
    }
  }
}
