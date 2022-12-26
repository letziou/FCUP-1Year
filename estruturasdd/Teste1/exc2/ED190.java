public SinglyLinkedList<T> copy(){
  SinglyLinkedList<T> sup = new SinglyLinkedList<T>();
  Node<T> cur = first;

  for(int i=0;i<this.size;i++){
    sup.addLast(cur.getValue());
    cur = cur.getNext();
  }
  return sup;
}
