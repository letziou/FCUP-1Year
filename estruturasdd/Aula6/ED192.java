public int count(T value){
  Node<T> cur = first;
  int count =0;
  while(cur != null){
    if(value.equals(cur.getValue()))
      count++;
    cur = cur.getNext();
  }
  return count;
}
