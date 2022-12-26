public class Strings1{

  static int count(String s, char x){
    int max = s.length();
    int cont = 0;

    for(int i=0;i<max;i++){
      if(s.charAt(i) == x) cont++;
    }
    return cont;
  }

  public static void main(String[] args){
    int cont = count("algoritmo",'o');

    System.out.println(cont);
  }
}
