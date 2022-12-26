public class ED196{
  public static void process(MyQueue<String> q, MyQueue<String> a, MyQueue<String> b){
    int size = q.size();

    for(int i=0; i<size ;i+=2){
      String name = q.dequeue();
      String choice = q.dequeue();
      if(choice.equals("A")){
        a.enqueue(name);
      }
      if(choice.equals("B")){
        b.enqueue(name);
      }
      if(choice.equals("X")){
        if(a.size()<b.size())
          a.enqueue(name);
        if(a.size()>b.size())
          b.enqueue(name);
      }
    }
  }
}
// 
//   public static void main(String[] args){
//     MyQueue<String> q = new LinkedListQueue<String>();
//     MyQueue<String> a = new LinkedListQueue<String>();
//     MyQueue<String> b = new LinkedListQueue<String>();
//
//     q.enqueue("Luis");
//     q.enqueue("B");
//     q.enqueue("Pedro");
//     q.enqueue("A");
//     q.enqueue("Luisa");
//     q.enqueue("A");
//     q.enqueue("Joao");
//     q.enqueue("X");
//     q.enqueue("Jose");
//     q.enqueue("X");
//     q.enqueue("Miguel");
//     q.enqueue("B");
//
//     System.out.println("MyQueue Q : " + q);
//     System.out.println("MyQueue A : " + a);
//     System.out.println("MyQueue B : " + b);
//
//     process(q,a,b);
//     System.out.println("----------------------");
//
//     System.out.println("MyQueue Q : " + q);
//     System.out.println("MyQueue A : " + a);
//     System.out.println("MyQueue B : " + b);
//   }
// }
