import java.util.Scanner;

public class Test{

  static void MaxMin(int days, int []cases){
    int min = cases[1] - cases[0];
    int max = min, var = 0;

    for(int i=1;i<days-1;i++){
      var = cases[i+1] - cases[i];
      if(var < min) min = var;
      if(var > max) max = var;
    }
    System.out.println(min + " " + max);
  }

  static void Propagation(int days, int []cases){
    boolean Prop = false;
    int nmax = 0, ncount = 0, n = 0;

    for(int i=1;i<days;i++){
      float var = (((float)cases[i] - cases[i-1])/ cases[i-1])*100;

      if(var<= 5 && Prop==true) n++;
      if(var<=5 && Prop==false){
        ncount++;
        n++;
        Prop = true;
      }

      if(var > 5){
        if(n > nmax) nmax = n;
      Prop = false;
      n = 0;
      }
    }
    if(n > nmax) nmax = n;
    System.out.println(ncount + " " + nmax);
  }

  static void Graph(int days, int []cases){
    int max = 0;

    for(int i=0;i<days;i++)
      if(cases[i] > max) max = cases[i];
    max /= 100;
    while(max > 0){
      for(int i=0;i<days;i++){
        if(cases[i]/100 >= max)
          System.out.print('#');
        else System.out.print('.');
      }
      System.out.println();
      max--;
    }
  }

  public static void main(String[] args){
    Scanner stdin = new Scanner(System.in);

    int days = stdin.nextInt();
    int cases[] = new int[days];
    for(int i=0;i<days;i++){
      cases[i] = stdin.nextInt();
    }
    int flag = stdin.nextInt();
    if(flag==1) MaxMin(days,cases);
    else if(flag==2) Propagation(days,cases);
    else Graph(days,cases);
    stdin.close();
  }
}
