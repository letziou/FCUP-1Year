public T get(int pos){                                       // ED188
  Node<T> cur = first;

  if(pos<0 || pos>size) return null;

  while(pos>0){
    cur = cur.getNext();
    pos--;
  }
  return cur.getValue();
}

public T remove(int pos){                                    // ED189
  Node<T> cur = first;

  if(pos<0 || pos>size) return null;

  while(pos>1){
    cur = cur.getNext();
    pos--;
  }

  T valor = cur.getNext().getValue();
  cur.setNext(cur.getNext().getNext());
  return valor;
}

public SinglyLinkedList<T> copy(){                           // ED190
  SinglyLinkedList<T> copy = new SinglyLinkedList<>();
  Node <T> cur = first;

  while(cur != null){
    copy.addLast(cur.getValue());
    cur = cur.getNext();
  }
  return copy;
}

public void duplicate(){                                     // ED191
  Node<T> cur = first;

  while(cur != null){
    Node<T> duplo = new Node<>(cur.getValue(), cur.getNext());
    cur.setNext(duplo);
    cur = cur.getNext().getNext();
  }
}


public int count(T value){                                   // ED192
  Node<T> cur = first;
  int count = 0;

  while(cur != null){
    if(cur.getValue().equals(value))
      count++;
    cur = cur.getNext();
  }
  return count;
}


public void removeAll(T value){                              // ED193
  while(!isEmpty() && first.getValue().equals(value)) removeFirst();
  Node<T> cur = first;

  while(cur != null && cur.getNext() != null){
    if(value.equals(cur.getNext().getValue())){
      cur.setNext(cur.getNext().getNext());
      size--;
    }
    else cur = cur.getNext();
  }
}


public SinglyLinkedList<T> reverse(){                        // ED232a
  Node<T> cur = first;
  SinglyLinkedList<T> back = new SinglyLinkedList<>();

  while(cur != null){
    back.addFirst(cur.getValue());
    cur = cur.getNext();
  }
  return back;
}


public int[] ocurrences(T elem){                             // ED232b
  int count = 0;
  int j = 0, i = 0;
  Node<T> cur = first;

  while(cur != null){
    if(elem.equals(cur.getValue()))
      count++;
    cur = cur.getNext();
  }
  if(count==0) return null;

  int []pos = new int[count];
  cur = first;

  while(cur != null){
    if(elem.equals(cur.getValue())){
      pos[i] = j;
      i++;
    }
    j++;
    cur = cur.getNext();
  }
  return pos;
}


public void remove(SinglyLinkedList<T> Remove){              // ED232c
  Node<T> cur = Remove.first;

  while(cur != null){
    this.removeAll(cur.getValue());
    cur = cur.getNext();
  }
}


public SinglyLinkedList<T> cut(int a, int b){                // ED236a
  Node<T> cur = first;
  int count = 0;
  SinglyLinkedList<T> chop = new SinglyLinkedList<>();

  while(cur != null){
    if(count>=a && count<=b)
      chop.addLast(cur.getValue());
    cur = cur.getNext();
    count++;
  }
  return chop;
}


public void shift(int k){                                    // ED236b
  SinglyLinkedList<T> copy = new SinglyLinkedList<>();
  SinglyLinkedList<T> aux = new SinglyLinkedList<>();
  int i;
  Node<T> cur = this.first;
  copy = cut((this.size-k),this.size);
  Node<T> cur2 = copy.first;

  for(i=0;i<(this.size-k)-1;i++)
    cur = cur.getNext();

  cur.setNext(null);

  while(cur2 != null){
    aux.addFirst(cur2.getValue());
    cur2 = cur2.getNext();
  }

  Node<T> cur3 = aux.first;

  while(cur3 != null){
    this.addFirst(cur3.getValue());
    cur3 = cur3.getNext();
  }
}
