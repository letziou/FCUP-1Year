public class TestED248 {
    public static void main(String[] args) {
	int n = 1000000;
  IntSet s1 = new BooleanArrayIntSet(n);
  IntSet s2 = new BooleanArrayIntSet(n);
  IntSet s3 ;
  IntSet s4 ;
  IntSet s5 ;
  IntSet s6 = new BooleanArrayIntSet(n);;
  IntSet s7 = new BooleanArrayIntSet(n);;
  IntSet s8 ; // Criar array de booleanos para numeros no intervalo [1,n]
	boolean tmp;

  

  System.out.println(s3 = s1.intersection(s2));
  System.out.println(s3.size());
  System.out.println("_________");
  System.out.println(s1.add(900));
  System.out.println(s1.add(800));
  System.out.println(s1.add(700));
  System.out.println(s1.add(600));
  System.out.println(s1.add(500));
  System.out.println(s1.add(400));
  System.out.println("_________");
  System.out.println(s2.add(100));
  System.out.println(s2.add(400));
  System.out.println(s2.add(900));
  System.out.println(s2.add(700));
  System.out.println(s2.add(6500));
  System.out.println("_________");
  System.out.println(s3 = s1.intersection(s2));
  System.out.println(s3.size());
  System.out.println("_________");
  System.out.println(s3.contains(700));
  System.out.println(s3.contains(400));
  System.out.println(s3.contains(900));
  System.out.println(s3.contains(800));
  System.out.println(s3.contains(100));
  System.out.println("_________");
  System.out.println(s4 = s3.intersection(s1));
  System.out.println(s4.size());
  System.out.println("_________");
  System.out.println(s5 = s4.intersection(s3));
  System.out.println(s5.size());
  System.out.println("_________");
  System.out.println(s6.add(1));
  System.out.println(s6.add(2));
  System.out.println(s6.add(3));
  System.out.println("_________");
  System.out.println(s7.add(4));
  System.out.println(s7.add(5));
  System.out.println(s7.add(6));
  System.out.println("_________");
  System.out.println(s8 = s6.intersection(s7));
  System.out.println(s8.size());
  System.out.println("_________");
  System.out.println(s8.contains(1));
  System.out.println(s8.contains(2));
  System.out.println(s8.contains(3));
  System.out.println(s8.contains(4));
  System.out.println(s8.contains(5));
  System.out.println(s8.contains(6)); 








    }
}
