public class SinglyLinkedList<T> {
  private Node<T> first;    // Primeiro no da lista
  private int size;         // Tamanho da lista

  // Construtor (cria lista vazia)
  SinglyLinkedList() {
    first = null;
    size = 0;
  }

   // Retorna o tamanho da lista
  public int size() {
    return size;
   }

   // Devolve true se a lista estiver vazia ou falso caso contrario
  public boolean isEmpty() {
    return (size == 0);
   }

   // Adiciona v ao inicio da lista
  public void addFirst(T v) {
    Node<T> newNode = new Node<T>(v, first);
    first = newNode;
    size++;
   }

   // Adiciona v ao final da lista
 public void addLast(T v) {
    Node<T> newNode = new Node<T>(v, null);
    if (isEmpty()) {
       first = newNode;
    } else {
       Node<T> cur = first;
       while (cur.getNext() != null)
          cur = cur.getNext();
       cur.setNext(newNode);
    }
    size++;
     }

   // Retorna o primeiro valor da lista (ou null se a lista for vazia)
  public T getFirst() {
    if (isEmpty()) return null;
    return first.getValue();
  }

   // Retorna o ultimo valor da lista (ou null se a lista for vazia)
  public T getLast() {
    if (isEmpty()) return null;
    Node<T> cur = first;
    while (cur.getNext() != null)
       cur = cur.getNext();
    return cur.getValue();
 }

   // Remove o primeiro elemento da lista (se for vazia nao faz nada)
  public void removeFirst() {
    if (isEmpty()) return;
    first = first.getNext();
    size--;
 }

   // Remove o ultimo elemento da lista (se for vazia nao faz nada)
  public void removeLast() {
    if (isEmpty()) return;
    if (size == 1) {
       first = null;
    } else {
       // Ciclo com for e uso de de size para mostrar alternativa ao while
       Node<T> cur = first;
       for (int i=0; i<size-2; i++)
          cur = cur.getNext();
       cur.setNext(cur.getNext().getNext());
    }
    size--;
 }

   // Converte a lista para uma String
  public String toString() {
    String str = "{";
    Node<T> cur = first;
    while (cur != null) {
       str += cur.getValue();
       cur = cur.getNext();
       if (cur != null) str += ",";
    }
    str += "}";
    return str;
  }

  public T get(int pos){                                     // ED188
    if(pos<0 || pos>size) return null;
    Node<T> cur = first;
    for(int i=0;i<pos;i++)
      cur = cur.getNext();
    return cur.getValue();
  }

  public T remove(int pos){                                  // ED189
    if(pos<0 || pos>size) return null;
    Node<T> cur = first;
    for(int i=0;i<pos-1;i++)
      cur = cur.getNext();
    T a = cur.getNext().getValue();
    cur.setNext(cur.getNext().getNext());

    return a;
  }

  public SinglyLinkedList<T> copy(){                         // ED190
    SinglyLinkedList<T> a = new SinglyLinkedList<>();
    Node<T> cur = first;
    for(int i=0;i<size;i++){
      a.addLast(cur.getValue());
      cur = cur.getNext();
    }
    return a;
  }

  public void duplicate(){                                   // ED191
    Node<T> cur = first;
    for(int i=0;i<size;i++){
      Node<T> dub = new Node<>(cur.getValue(),cur.getNext());
      cur.setNext(dub);
      cur = cur.getNext().getNext();
    }
  }

  public int count(T value){                                 // ED192
    Node<T> cur = first;
    int count = 0;
    for(int i=0;i<size;i++){
      if(cur.getValue().equals(value)) count++;
      cur = cur.getNext();
    }
    return count;
  }

  public void removeAll(T value){                            // ED193
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

  public SinglyLinkedList<T> reverse(){                      // ED232a
    SinglyLinkedList<T> a = new SinglyLinkedList<>();
    Node<T> cur = first;
    while(cur != null){
      a.addFirst(cur.getValue());
      cur = cur.getNext();
    }
    return a;
  }
}
