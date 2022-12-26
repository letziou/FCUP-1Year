import java.util.Scanner;

public class ED231{

  static void Amplitude(int []casos, int dias){
    int min=(casos[1]-casos[0]),max=0;
    int dif;

    for(int i=0;i<(dias-1);i++){
      dif = casos[i+1]-casos[i];

      if(dif>max)
        max = dif;

      if(dif<min)
        min = dif;
    }
    System.out.println(min +" "+ max);
  }

  static void Propagation(int []casos, int dias){
    int contmax=0,ncont=0,cont=0;
    float dif;


    for(int i=1;i<dias;i++){
      dif = ((((float) casos[i]-casos[i-1])/casos[i-1])*100);


      if(dif<=5){
        //cont++;
        while(dif<=5 && i<(dias-1)){
          cont++;
          i++;
          dif = ((((float) casos[i]-casos[i-1])/casos[i-1])*100);
        }
        ncont++;
        if(contmax < cont)
          contmax = cont;
        cont=0;
      }
    }
    System.out.println(ncont +" "+ contmax);
  }

  static void Graph(int []casos, int dias){
    int heigth = casos[dias-1]/100;

    for(int i=0;i<heigth;i++){
      for(int j=0;j<dias;j++){
        if((casos[j]/100) >= (heigth-i))
          System.out.print("#");
        else System.out.print(".");
      }
      System.out.println();
    }
  }

  public static void main(String[] args){

    Scanner stdin = new Scanner(System.in);

    int dias = stdin.nextInt();

    int casos[] = new int[dias];

    for(int i=0;i<dias;i++)
      casos[i] = stdin.nextInt();

    int flag = stdin.nextInt();

    if(flag == 1)
      Amplitude(casos,dias);

    if(flag == 2)
      Propagation(casos,dias);

    if(flag == 3)
      Graph(casos,dias);
  }
}
