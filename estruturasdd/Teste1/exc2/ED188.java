public T get(int pos){
  Node<T> cur = first;

  if(pos > (size-1) || pos < 0) return null;

  for(int i=0;i<pos;i++)
    cur = cur.getNext();

  return cur.getValue();
}
