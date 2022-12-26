public T remove(int n){
  Node<T> curvalue = first;
  Node<T> curnode = first;

  if(n >= size || n < 0) return null;

  if(n == 0){
    T v = first.getValue();
    this.removeFirst();
    return v;
  }


  for(int i=0; i<n;i++)
    curvalue = curvalue.getNext();
  for(int i=0; i<n-1; i++)
    curnode = curnode.getNext();
  curnode.setNext(curnode.getNext().getNext());
  size--;

  return curvalue.getValue();

}
