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

  public void remove(int pos){                                    // ED189
    Node<T> cur = first;

    if(pos<0 || pos>size) return;

    while(pos>1){
      cur = cur.getNext();
      pos--;
    }

    cur.setNext(cur.getNext().getNext());
  }

  public void duplicate(){
    Node<T> cur = first;

    while(cur != null){
      Node<T> a = new Node<T>(cur.getValue(),cur.getNext());
      cur.setNext(a);
      cur = cur.getNext().getNext();
    }
  }
}
