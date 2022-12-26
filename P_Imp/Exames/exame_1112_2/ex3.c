struct fracao ler_analisar(int n, int p, int k){
  struct fracao res;
  int v;

  res.a = 0;
  res.b = 0;

  scanf("%d",&v);
  while(v!=0){
    res.b++;
    if(((v>p+k) || (v<p-k)) && ((v%n!=0) || n==0))
      res.a++;
    scanf("%d",&v);
  }

  int x = mdc(res.a,res.b);

  res.a = res.a / v;
  res.b = res.b / v;
  return res;
}

int mdc(int a,int b){
  int r;
  while(b!=0){
    r = a%b;
    a = b;
    b = r;
  }
  return a;
}
