import java.util.Scanner;

public class ED254{

  static void Figure(int size){
    int start = 0;
    int middle = (size-1)/2;
    int end = size-1;

    for(int i=0;i<size;i++){
      for(int j=0;j<size;j++){
        if(j==start || j==end)
          System.out.print('#');
        else System.out.print('.');
      }
      if(start != middle) start++;
      if(end != middle) end--;
      System.out.println();
    }
  }

  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);
    int times = stdin.nextInt();

    for(int i=0;i<times;i++){
      int size = stdin.nextInt();
      Figure(size);
    }
  }
}
