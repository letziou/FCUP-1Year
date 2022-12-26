import java.util.Scanner;
import java.util.Arrays;
import java.util.LinkedList;

public class ED234{
  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);

    int flag = stdin.nextInt();

    BSTree<String> t = new BSTree<>();
    BSTMap<String,Integer> one = new BSTMap<>();
    BSTMap<String,Integer> two = new BSTMap<>();

    int movies = stdin.nextInt();
    String buffer = stdin.nextLine();
    while(movies>0){
      String review = stdin.nextLine();
      String []array = review.split(" ");
      t.insert(array[0]);
      Integer j = one.get(array[0]);
      if(j==null) one.put(array[0],1);
      else one.put(array[0],j+1);
      Integer k = two.get(array[0]);
      if(k==null) two.put(array[0],Integer.parseInt(array[1]));
      else two.put(array[0],k+Integer.parseInt(array[1]));
      movies--;
    }
    if(flag==1)
      System.out.println(t.numberNodes());

    if(flag==2){
      int max = 0;
      LinkedList<String> l = one.keys();
      for(String s : l){
        int a = one.get(s);
        if(a > max)
          max = a;
      }
      LinkedList<String> x = one.keys();
        for(String z : x){
        int number = one.get(z);
          if(number == max)
            System.out.println(z+" "+number);
          }
    }

    if(flag==3){
      int count;
      LinkedList<String> b = one.keys();
      for(String a : b){
        if(two.get(a)/one.get(a) >= 5)
          System.out.println(a);
      }
    }


  }
}
