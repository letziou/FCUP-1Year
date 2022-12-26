public void removeAll(T value){
  while(!isEmpty() && first.getValue().equals(value)) removeFirst();

  Node<T> cur = first;

  while(cur != null && cur.getNext() != null){
    if(value.equals(cur.getNext().getValue())){
      cur.setNext(cur.getNext().getNext());
      size--;
    }
    else {
      cur = cur.getNext();
    }
  }
}
