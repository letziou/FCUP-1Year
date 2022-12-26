import java.util.Scanner;

public class ED183{

   static void writeArray(int [] v) {
      for (int i=0; i<v.length; i++)
         System.out.println("v[" + i + "] = " + v[i]);
   }

   static int Amplitude(int [] v,int size){
     int max = v[0];
     int min = v[0];

     for(int i=0;i<size;i++){
       if(v[i]>max)
        max = v[i];

      if(v[i]<min)
        min = v[i];
     }
     int amplitude = max-min;
     return amplitude;
   }

   public static void main(String[] args) {

      Scanner stdin = new Scanner(System.in);

      double cont =0;
      int size = stdin.nextInt();   // Ler a quantidade de numeros que se seguem
      int v[] = new int[size];

      for (int i=0; i<size; i++)    // Ler os numeros a partir do stdin
         v[i] = stdin.nextInt();


      int amplitude = Amplitude(v,size);

      for(int j=0;j<size;j++)
        cont += v[j];


      System.out.printf("%.2f\n", cont/size);
      System.out.println(amplitude);
   }
}
