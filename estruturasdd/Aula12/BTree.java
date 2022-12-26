// -----------------------------------------------------------
// Estruturas de Dados 2020/2021 (CC1007) - DCC/FCUP
// http://www.dcc.fc.up.pt/~pribeiro/aulas/edados2021/
// -----------------------------------------------------------
// Arvore binaria "normal"
// Ultima alteracao: 26/04/2018
// -----------------------------------------------------------

public class BTree<T> {
   private BTNode<T> root; // raiz da arvore

   // Construtor
   BTree() {
      root = null;
   }

   // Getter e Setter para a raiz
   public BTNode<T> getRoot() {return root;}
   public void setRoot(BTNode<T> r) {root = r;}

   // Verificar se arvore esta vazia
   public boolean isEmpty() {
      return root == null;
   }

   // --------------------------------------------------------

   // Numero de nos da arvore
   public int numberNodes() {
      return numberNodes(root);
   }

   private int numberNodes(BTNode<T> n) {
      if (n == null) return 0;
      return 1 + numberNodes(n.getLeft()) + numberNodes(n.getRight());
   }

   // --------------------------------------------------------

   // Altura da arvore
   public int depth() {
      return depth(root);
   }

   private int depth(BTNode<T> n) {
      if (n == null) return -1;
      return 1 + Math.max(depth(n.getLeft()), depth(n.getRight()));
   }

   // --------------------------------------------------------

   // O elemento value esta contido na arvore?
   public boolean contains(T value) {
      return contains(root, value);
   }

   private boolean contains(BTNode<T> n, T value) {
      if (n==null) return false;
      if (n.getValue().equals(value)) return true;
      return contains(n.getLeft(), value) || contains(n.getRight(), value);
   }

   // --------------------------------------------------------

   // Imprimir arvore em PreOrder
   public void printPreOrder() {
      System.out.print("PreOrder:");
      printPreOrder(root);
      System.out.println();
   }

   private void printPreOrder(BTNode<T> n) {
      if (n==null) return;
      System.out.print(" " + n.getValue() );
      printPreOrder(n.getLeft());
      printPreOrder(n.getRight());
   }

   // --------------------------------------------------------

   // Imprimir arvore em InOrder
   public void printInOrder() {
      System.out.print("InOrder:");
      printInOrder(root);
      System.out.println();
   }

   private void printInOrder(BTNode<T> n) {
      if (n==null) return;
      printInOrder(n.getLeft());
      System.out.print(" " + n.getValue());
      printInOrder(n.getRight());
   }

   // --------------------------------------------------------

   // Imprimir arvore em PostOrder
   public void printPostOrder() {
      System.out.print("PostOrder:");
      printPostOrder(root);
      System.out.println();
   }

   private void printPostOrder(BTNode<T> n) {
      if (n==null) return;
      printPostOrder(n.getLeft());
      printPostOrder(n.getRight());
      System.out.print(" " + n.getValue());
   }

   // --------------------------------------------------------

   // Imprimir arvore numa visita em largura (usando TAD Fila)
   public void printBFS() {
      System.out.print("BFS:");

      MyQueue<BTNode<T>> q = new LinkedListQueue<BTNode<T>>();
      q.enqueue(root);
      while (!q.isEmpty()) {
         BTNode<T> cur = q.dequeue();
         if (cur != null) {
            System.out.print(" " + cur.getValue());
            q.enqueue(cur.getLeft());
            q.enqueue(cur.getRight());
         }
      }
      System.out.println();
   }

   // --------------------------------------------------------

   // Imprimir arvore numa visita em profundidade (usando TAD Pilha)
   public void printDFS() {
      System.out.print("DFS:");

      MyStack<BTNode<T>> q = new LinkedListStack<BTNode<T>>();
      q.push(root);
      while (!q.isEmpty()) {
         BTNode<T> cur = q.pop();
         if (cur != null) {
            System.out.print(" " + cur.getValue());
            q.push(cur.getLeft());
            q.push(cur.getRight());
         }
      }
      System.out.println();
   }

   // --------------------------------------------------------

   public int numberLeafs(){                                 // ED204
     return numberLeafs(root);
   }

   private int numberLeafs(BTNode<T> n){
     if(n == null) return 0;
     if(n.getLeft() == null && n.getRight() == null) return 1;
     return numberLeafs(n.getLeft()) + numberLeafs(n.getRight());
   }

   public boolean strict(){                                  // ED205
     return strict(root);
   }

   private boolean strict(BTNode <T> n){
     if(n == null) return true;
     if(n.getLeft() == null && n.getRight() != null || n.getLeft() != null && n.getRight() == null) return false;
     return strict(n.getLeft()) && strict(n.getRight());
   }


   public T path(String s){                                  // ED206
     return path(s, root);
   }

   private T path(String s, BTNode<T> n){
     if(s.charAt(0)=='R') return n.getValue();
     int size = s.length();

     for(int i=0;i<size;i++){
       if(s.charAt(i)=='E') n = n.getLeft();
       if(s.charAt(i)=='D') n = n.getRight();
     }
     return n.getValue();
   }

   public int nodesLevel(int k){                             // ED207
     return nodesLevel(root,k);
   }

   private int nodesLevel(BTNode<T> n, int k){
     if( n == null) return 0;
     if( k == 0 ) return 1;
     return nodesLevel(n.getLeft(),k-1) + nodesLevel(n.getRight(),k-1);
   }

   public int count(){                                       // ED239(a)
     return count(root);
   }

   private int count(BTNode<T> n){
     if(n==null) return 0;
     if(n.getLeft()==null && n.getRight()!= null || n.getLeft()!=null && n.getRight()== null) return 1 + count(n.getLeft()) + count(n.getRight());
     return count(n.getLeft()) + count(n.getRight());
   }

   public int level(T v){
     int tmp = level(root,v,0);
     if(tmp == Integer.MAX_VALUE) return -1;
     return tmp;
   }

   private int level(BTNode<T> n, T v, int place){
     if(n==null)return Integer.MAX_VALUE;
     if(n.getValue().equals(v)) return place;
     return Math.min(level(n.getLeft(),v,place+1),level(n.getRight(),v,place+1));
   }
}
