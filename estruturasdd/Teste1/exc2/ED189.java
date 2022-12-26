public T Remove(int pos){
  Node<T> value = first;
  Node<T> cur = first;

  if(pos >= size || pos < 0) return null;

  for(int j=0;j<pos;j++)
    value = value.getNext();

  for(int j=1;j<pos;j++)
    cur = cur.getNext();
  cur.setNext(cur.getNext().getNext());

  return value.getValue();
}
