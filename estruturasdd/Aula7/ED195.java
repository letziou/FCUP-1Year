public class ED195{
  public static boolean balanced(String s){
    MyStack<Character> p = new LinkedListStack<>();
    int max = s.length();

    for(int i=0; i<max ;i++){
      if(s.charAt(i) == '(' || s.charAt(i) == '['){
        p.push(s.charAt(i));
      }
      if(s.charAt(i) == ')' || s.charAt(i) == ']'){
        if(p.isEmpty()) return false;
        char var = p.pop();
        if(var == '(' && s.charAt(i) == ']' || var == '[' && s.charAt(i) == ')')
          return false;
      }
    }
    return p.isEmpty();
  }

  public static void main(String[] args){
    String s = "([()])";
    String a = "[()()]";
    String b = "]";
    String c = "[()[])";
    String d = "[()[]";
    System.out.println(balanced(s));
    System.out.println(balanced(a));
    System.out.println(balanced(b));
    System.out.println(balanced(c));
    System.out.println(balanced(d));
  }
}
