public class Numbers {
    public static void main(String[] args) {
      int n =500;
      int cont =0;
      System.out.print("Numeros de 1 a " + n +": ");
      for (int i=1;i<=n-1;i++){
        System.out.print(i+",");
          cont += i;
        }
        System.out.println(n);
        cont += n;

        System.out.println("Soma = " + cont);
    }
}
