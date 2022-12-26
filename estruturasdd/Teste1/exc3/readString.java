import java.util.Scanner;

public class readString{

  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);
    int times = stdin.nextInt();
    String space = stdin.nextLine();

    while(times>0){
      String sup = stdin.nextLine();
      sup = sup.replaceAll("\\s","");
      System.out.println(sup +" "+times);
      times--;
    }
  }
}
