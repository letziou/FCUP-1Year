public class ED194{
public static void reverse(MyStack<Integer> s, int n){
  int array[] = new int [n];
  for(int i=0; i<n ;i++){
    array[i] = s.pop();
  }

  for(int j=0; j<n ;j++){
    s.push(array[j]);
    }
  }
}
