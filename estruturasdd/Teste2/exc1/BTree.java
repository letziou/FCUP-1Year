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
     if(n==null) return 0;
     if(n.getLeft()==null && n.getRight()==null) return 1;
     return numberLeafs(n.getRight()) + numberLeafs(n.getLeft());
   }

   public boolean strict(){
     return strict(root);
   }

   private boolean strict(BTNode<T> n){                      // ED205
    if(n==null) return true;
    if(n.getRight()==null && n.getLeft()!= null || n.getRight()!=null && n.getLeft()== null) return false;
    return strict(n.getLeft()) && strict(n.getRight());
  }

  public T path(String s){                                   // ED206
    if(s.equals("R")) return root.getValue();
    return path(root,s);
  }

  private T path(BTNode<T> n, String s){
    for(int i=0;i<s.length();i++)
      if(s.charAt(i)=='E')
        n = n.getLeft();
      else n = n.getRight();

    return n.getValue();
  }

  public int nodesLevel(int k){                              // ED207
    return nodesLevel(root,k,0);
  }

  private int nodesLevel(BTNode<T> n, int k, int level){
    if(n==null) return 0;
    if(level == k) return 1 + nodesLevel(n.getLeft(),k,level+1) + nodesLevel(n.getRight(),k,level+1);
    return nodesLevel(n.getLeft(),k,level+1) + nodesLevel(n.getRight(),k,level+1);
  }

  public int internal(){                                     // ED233(a)
    return internal(root);
  }

  private int internal(BTNode<T> n){
    if(n==null) return 0;
    if(n.getLeft()==null && n.getRight()==null) return 0 + internal(n.getLeft()) + internal(n.getRight());
    return 1 + internal(n.getLeft()) + internal(n.getRight());
  }

  public void cut(int d){                                    //ED233(b)
    cut(root, d, 0);
  }

  private void cut(BTNode<T> n, int d, int level){
    if((d-1)==level){
      n.setLeft(null);
      n.setRight(null);
    }
    else if(level<d-1){
      cut(n.getLeft(), d, level+1);
      cut(n.getRight(), d, level+1);
    }
  }

  public int[] maxLevel(){
    return maxLevel(root);
  }

  private int[] maxLevel(BTNode<T> n){
    int[] b = new int[2];
    int a = levelmax(), m = 0, count = 1;

    for(int i=0;i<(a-1);i++){
      if(nodesLevel(i) > m){
        m = nodesLevel(i);
        count = 1;
      }
      else if(nodesLevel(i)==m) count++;
    }

    b[0] = a;
    b[1] = count;

    return b;
  }

  public int count(){                                        // ED239(a)
    return count(root);
  }

  private int count(BTNode<T> n){
    if(n==null) return 0;
    if(n.getRight()==null && n.getLeft()!= null || n.getRight()!=null && n.getLeft()== null) return 1 + count(n.getLeft()) + count(n.getRight());
    return count(n.getLeft()) + count(n.getRight());
  }


  public int level(T v){                                     // ED239(b)
    int tpm = level(root,v,0);
    if(tpm == Integer.MAX_VALUE) return -1;
    return tpm;
  }

  private int level(BTNode<T> n, T v, int space){
    if(n==null) return Integer.MAX_VALUE;
    if(n.getValue().equals(v)) return space;
    return Math.min(level(n.getLeft(),v,space+1),level(n.getRight(),v,space+1));
  }

  public int levelmax(){                                     // ED233 ajuda
    int tpm = levelmax(root,0);
    return tpm;
  }

  private int levelmax(BTNode<T> n, int space){
    if(n==null) return space;
    return Math.max(levelmax(n.getLeft(),space+1),levelmax(n.getRight(),space+1));
  }

  // public int countEven(){       tecnicamente certo        // ED211
  //   return countEven(root);
  // }
  //
  // private int countEven(BTNode<T> n){
  //   if(n==null) return 0;
  //   if(n.getValue()%2 == 0) return 1 + countEven(n.getLeft()) + countEven(n.getRight());
  //   return countEven(n.getLeft()) + countEven(n.getRight());
  // }

}
