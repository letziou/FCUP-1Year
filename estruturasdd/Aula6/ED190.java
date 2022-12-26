public SinglyLinkedList<T> copy(){
  SinglyLinkedList<T> copia = new SinglyLinkedList<>();
  Node<T> cur = this.first;

  while(cur != null){
    copia.addLast(cur.getValue());
    cur = cur.getNext();
  }
  return copia;
}
