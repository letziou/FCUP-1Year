import java.util.Scanner;

public class ED198{

  public static void main(String[] args) {

    Scanner stdin = new Scanner(System.in);
    int nnumbers = stdin.nextInt();
    int []numbers = new int[nnumbers];

    for(int i=0;i<nnumbers;i++)
      numbers[i] = stdin.nextInt();

    int sum = numbers[0],summax = sum;

    for(int j=0;j<(nnumbers-1);j++){
      if(sum>0){
        if(sum>summax)
          summax = sum;
        sum += numbers[j+1];
      }
      else if(sum>0 && numbers[j+1]<0){
        if(sum > summax)
          summax = sum;
        sum += numbers[j+1];
      }
      else if(sum<0){
        if(sum > summax)
          summax = sum;
        sum = numbers[j+1];
      }
    }
    if(sum > summax)
      summax = sum;

    System.out.println(summax);
  }
}
