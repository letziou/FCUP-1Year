public class Strings2{    // Not really made

  static void change(int n){

    String d = "A";
    String s = "A";
    String c = "AB";
    String o = "B";

    for(int i=1;i<n;i++){
      if(d.charAt(i) == 'A'){

         d = d + c;
      }
      if(d.charAt(i) == 'B'){

         d = d + s;
      }

      System.out.println();
    }

  }

  public static void main(String[] args){
    change(3);
  }
}
