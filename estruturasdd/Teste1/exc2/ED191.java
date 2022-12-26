public void duplicate(){
  Node<T> cur = first;

  while(cur != null){
    Node<T> copy = new Node<>(cur.getValue(), cur.getNext());
    cur.setNext(copy);
    cur = cur.getNext().getNext();
  }
}
