import java.util.Scanner;

public class ED121{

  static boolean Palindromo(String s){
    String s2 = s.replaceAll("\\W","");
    String s3 = s2.toLowerCase();
    int size = s3.length();
    boolean answer = true;

    for(int i=0;i< size/2;i++){
      if( s3.charAt(i) != s3.charAt(size-i-1))
      answer = false;
    }
    return answer;
  }


  public static void main(String[] args){

    Scanner stdin = new Scanner(System.in);

    int n = stdin.nextInt();

    int j = 0;


    System.out.println(n);
    stdin.nextLine();

    while(j<n){
      String s = stdin.nextLine();

      if(Palindromo(s)){
        System.out.println("sim");
      }
      else System.out.println("nao");

      j++;
    }
  }
}
