import java.util.Scanner;

public class ED183{

  static void Average(int cases, int []numbers){
    int cont=0;
    for(int i=0;i<cases;i++)
      cont += numbers[i];
    float drop = ((float)cont / cases);
    System.out.printf("%.2f\n",drop);
  }

  static void Spread(int cases, int []numbers){
    int max = numbers[0];
    int min = max;

    for(int i=0;i<cases;i++){
      if(numbers[i]>max)
        max = numbers[i];
      if(numbers[i]<min)
        min = numbers[i];
    }
    int spread = max-min;
    System.out.println(spread);
  }

  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);

     int cases = stdin.nextInt();
     int []numbers = new int[cases];

     for(int i=0;i<cases;i++)
      numbers[i] = stdin.nextInt();

      Average(cases,numbers);
      Spread(cases,numbers);
      stdin.close();
  }
}
