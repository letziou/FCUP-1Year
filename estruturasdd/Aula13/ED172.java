import java.util.Scanner;
import java.util.LinkedList;
import java.util.Arrays;

public class ED172{
  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);
    BSTMap<String, Integer> t = new BSTMap<>();

    while(stdin.hasNextLine()){
        String sentence = stdin.nextLine();
        String []words = sentence.split(" ");
        for(int i=0;i<words.length;i++){
          Integer j = t.get(words[i]);
          if(j == null) t.put(words[i],1);
          else t.put(words[i],j+1);
      }
    }
    LinkedList<String> text = t.keys();
    for(String s : text)
      System.out.println(s+": "+t.get(s));
  }
}
