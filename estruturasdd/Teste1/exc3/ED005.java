import java.util.Scanner;

public class ED005{

  static String readString(Scanner stdin){
    String input = stdin.nextLine();
    input = input.replaceAll("\\s","");
    return input;
  }

  static int turntoInt(char s){
    return s-'0';
  }

  static int signs(char s, MyStack<Integer> p){
    int a = p.pop();
    int b = p.pop();
    switch(s){
      case '*': return b * a;
      case '/': return b / a;
      case '-': return b - a;
      default : return b + a;
    }
  }

  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);
    int times = stdin.nextInt();
    String space = stdin.nextLine();

    while(times > 0){
      MyStack<Integer> pilha = new LinkedListStack<>();

      String all = readString(stdin);

      for(int i=0;i<all.length();i++){
        if(all.charAt(i)<='9' && all.charAt(i)>'0')
          pilha.push(turntoInt(all.charAt(i)));

        else{
          if(pilha.size() >= 2)
            pilha.push(signs(all.charAt(i),pilha));

          else{
            while(!pilha.isEmpty())
              pilha.pop();
          }
        }
      }
      if(pilha.isEmpty() || pilha.size() > 1){
        System.out.println("Expressao incorreta!");
        while(!pilha.isEmpty())
          pilha.pop();
      }
      else System.out.println(pilha.pop());

      times--;
    }
  }
}
