public class BooleanArrayIntSet implements IntSet {
  private boolean elem[];
  private int size, maxSize;

  BooleanArrayIntSet(int maxSize){
    this.maxSize = maxSize+1;
    elem = new boolean[this.maxSize];
    size = 0;
  }

  public boolean contains(int x){
    if(elem[x])
      return true;
    return false;
  }

  public boolean add(int x){
    if(!contains(x)){
      elem[x] = true;
      return true;
    }
    return false;
  }

  public boolean remove(int x){
    if(contains(x)){
      elem[x] = false;
      return true;
    }
    return false;
  }

  public int size(){
    int count = 0;
    for(int i = 0; i < this.maxSize; i++)
      if(elem[i]) count++;
    return count;
  }

  public void clear(){
    for(int i = 0; i < maxSize; i++)
      if(elem[i])
        elem[i] = false;
  }

  public boolean equals(IntSet s){
    if(this.size() != s.size())
    return false;
    for(int i = 0; i < maxSize; i++)
      if(this.contains(i) != s.contains(i))
      return false;
    return true;
  }

  public IntSet intersection(IntSet s){
    IntSet intsect = new BooleanArrayIntSet(maxSize-1);

    for(int i = 0; i < maxSize; i++)
     if(s.contains(i) && contains(i))
      intsect.add(i);

    return intsect;
  }

 @Override
  public String toString() {
     String res = "{";
     for (int i = 0, s = 0; i < maxSize; i++, s++) {
        if(elem[i]) {
          res += i;
          if(i>1) res += ",";
        }
     }
     res += "}";
     return res;
  }
}
