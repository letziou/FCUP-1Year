import java.util.Scanner;
import java.util.LinkedList;
import java.util.Arrays;

public class ED241{
  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);

    int flag = stdin.nextInt();
    int sub = stdin.nextInt();
    String buffer = stdin.nextLine();
    BSTree<String> one = new BSTree<>();
    BSTMap<String,Integer> two =  new BSTMap<>();
    BSTMap<String,Integer> three = new BSTMap<>();


    while(sub>0){
      String sentence = stdin.nextLine();
      String a[] = sentence.split(" ");
      one.insert(a[0]);
      Integer tmj = two.get(a[1]);
      if(tmj==null) two.put(a[1],1);
      else two.put(a[1],tmj+1);
      if(a[2].equals("Accepted")){
        Integer tmg = three.get(a[1]);
        if(tmg==null) three.put(a[1],1);
        else three.put(a[1],tmg+1);
      }
      sub--;
    }

    if(flag==1)
      System.out.println(one.numberNodes());

    if(flag==2){
      int max=0;
      LinkedList<String> t = two.keys();
      for(String s : t){
        int aux = two.get(s);
        if(aux > max)
          max = aux;
      }
      LinkedList<String> y = two.keys();
      for(String s : y){
          int aux = two.get(s);
          if(aux==max)
            System.out.println(s+" "+max);
      }
    }

    if(flag==3){
      LinkedList<String> t = three.keys();
      for(String s : t)
      if(three.get(s)/two.get(s) > 0)
        System.out.println(s);
    }

  }
}
