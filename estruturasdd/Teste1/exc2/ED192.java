public int count(T value){
  int count = 0;
  Node<T> cur = first;
  while(cur != null){
    if(cur.getValue().equals(value))
      count++;
  }
  return count;
}
