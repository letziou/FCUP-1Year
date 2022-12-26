public void duplicate(){
  Node<T> cur = first;

  while(cur != null){
    Node<T> dup = new Node<>(cur.getValue(), cur.getNext());
    cur.setNext(dup);
    cur = dup;
    cur = cur.getNext();
  }
}
