public class Primes {

  static boolean isPrime(int n){
    for(int j=3;j*j <= n;j++){
      if(n%j==0)
      return false;
    }
      return true;
  }

  public static void main(String[] args){

    int n=1000000;

    for(int i=2; i<=n;i++)
      if(isPrime(i))
      System.out.println(i);
  }
}
