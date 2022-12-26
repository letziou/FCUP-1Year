public class ED197{
  public static MyQueue<Integer> merge(MyQueue<Integer> a, MyQueue<Integer> b){
    MyQueue<Integer> q = new LinkedListQueue<>();
    while(a.size() != 0 && b.size() != 0){
      int a1 = a.first();
      int b1 = b.first();

      if(a1 > b1){
        q.enqueue(b.dequeue());
      }
      else {
        q.enqueue(a.dequeue());
      }
    }
    if(!a.isEmpty()){
      while(!a.isEmpty())
      q.enqueue(a.dequeue());
    }

    if(!b.isEmpty()){
      while(!b.isEmpty())
      q.enqueue(b.dequeue());
    }

    return q;
  }
}

//   public static void main(String[] args){
//     MyQueue<Integer> a = new LinkedListQueue<>();
//     MyQueue<Integer> b = new LinkedListQueue<>();
//
//     a.enqueue(1);
//     a.enqueue(2);
//     a.enqueue(4);
//     a.enqueue(8);
//     a.enqueue(10);
//     b.enqueue(9);
//
//     MyQueue<Integer> q = merge(a,b);
//     System.out.println(q);
//   }
// }
