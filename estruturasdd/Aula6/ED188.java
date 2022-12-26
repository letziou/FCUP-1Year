public T get(int n){
  Node<T> cur = first;

  if(n > (size-1) || n < 0) return null;
  for (int i=0; i < n; i++)
     cur = cur.getNext();

    return cur.getValue();
}
