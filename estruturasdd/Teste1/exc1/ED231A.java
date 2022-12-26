import java.util.Scanner;

public class ED231A{

  static void MaxMin(int []cases, int days){
    int min = cases[0], max = 0;

    for(int i=0;i<(days-1);i++){
      if((cases[i+1]-cases[i])>max)
        max = (cases[i+1]-cases[i]);
      if((cases[i+1]-cases[i])<min)
        min = (cases[i+1]-cases[i]);
    }
    System.out.println(min +" "+max);
  }

  static void Propagation(int []cases, int days){
    boolean Prop = false;
    int ncont=0, nmax=0, n=0;
    for(int i=1;i<days;i++){
      float diff = (((float)cases[i] - cases[i-1])/cases[i-1])*100;

      if(diff<=5 && Prop==true){
        n++;
      }

      if(diff <=5 && Prop==false){
        ncont++;
        n++;
        Prop = true;
      }

      if(diff>5){
        if(n>nmax)
          nmax=n;
        Prop = false;
        n = 0;
      }
    }
    if(n>nmax)
      nmax = n;
    System.out.println(ncont+" "+nmax);
  }

  static void Graph(int []cases, int days){
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
    int []cases = new int[days];

    for(int i=0;i<days;i++)
      cases[i] = stdin.nextInt();

    int flag = stdin.nextInt();
    if(flag==1)
      MaxMin(cases,days);
    if(flag==2)
      Propagation(cases,days);
    if(flag==3)
      Graph(cases,days);
    stdin.close();
  }
}
