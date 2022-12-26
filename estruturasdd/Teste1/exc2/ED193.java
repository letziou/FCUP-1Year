public void removeAll(T value){
  while(!isEmpty() && first.getValue().equals(value)) removeFirst();
  Node<T> cur = first;

  while(cur != null && cur.getNext() != null){
    if(cur.getNext().getValue().equals(value)){
      cur.setNext(cur.getNext().getNext());
      size--;
    }
    else cur = cur.getNext();
  }
}
