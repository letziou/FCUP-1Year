import java.util.Scanner;

public class ED005{

  static String readString(Scanner stdin){
    String input = stdin.nextLine();
    String numbers = "";
    for(int i=0; i<input.length() ;i++)
      if(input.charAt(i) != ' ')
        numbers += input.charAt(i);
    return numbers;
  }

  static int turntoInt(char s){
    return s-'0';
  }

  static int maths(char s, MyStack<Integer> p){
    switch(s){
      case '*': return p.pop() * p.pop();
      case '/': return p.pop() / p.pop();
      case '-': return p.pop() - p.pop();
      default : return p.pop() + p.pop();
    }
  }

  public static void main(String[] args) {
    Scanner stdin = new Scanner(System.in);

    int cases = stdin.nextInt();

    for(int i=0; i<=cases ;i++){
      String numbers = readString(stdin);
      MyStack<Integer> p = new LinkedListStack<>();

      for(int j=0; j<numbers.length() ;j++){
        if(numbers.charAt(j) >= '0' && numbers.charAt(j) <= '9'){
          p.push(turntoInt(numbers.charAt(j)));

        }
        else {
          if(p.size() >= 2){
            p.push(maths(numbers.charAt(j),p));
          }
          else {
            System.out.println("Expressao incorrecta");
            while(!p.isEmpty())
              System.out.println(p.pop());
          }
        }
      }

      if(p.isEmpty() || p.size() > 1)
        System.out.println("Expressao incorrecta");
      else
        System.out.println(p.top());

        while(!p.isEmpty())
          p.pop();
    }



  }
}
