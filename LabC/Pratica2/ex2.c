#include <stdio.h>
/*  2.1

a) Não              d) Legal            g) Não

b) Não              e) Não              h) Legal

c) Não              f) Legal            i) Legal
*/

/*  2.2

a) Legal            d) Não              g) Não

b) Não              e) Legal            h) Não

c) Legal            f) Não              i) Legal
*/

 /* int main(){         // 2.3

   int a = 10, *p;
  p = &a;

  printf("tamanho de um int: %d\n",sizeof(a) );
  printf("tamanho do endereço de um int: %d\n",sizeof(&a) );
  printf("tamanho de um apontador para um int: %d\n",sizeof(p) );
  printf("tamanho do conteúdo apontado por um int: %d\n",sizeof(*p) );
  printf("Os valores apontados pelos endereços '%p' e '%p' são '%d' e '%d'\n",&a, p, a, *p);

  char c, *cptr;
  c = 'a';
  cptr = &c;

  printf("tamanho de um char: %lu\n", sizeof(c));
  printf("tamanho do endereço de um char: %lu\n", sizeof(&c));
  printf("tamanho de um apontador para um char: %lu\n", sizeof(cptr));
  printf("tamanho do conteúdo apontado por um apontador para um char: %lu\n", sizeof(*cptr));
  printf("Os valores apontados pelos endereços ’%p’ e ’%p’ são ’%c’ e ’%c’\n", &c, cptr, c, *cptr);

  float f = 10.5 , *baloon;
  baloon = &f;

  printf("tamanho de um float: %f\n",sizeof(f) );
  printf("tamanho do endereço de um float: %d\n",sizeof(&f) );
  printf("tamanho de um apontador para um float: %d\n",sizeof(baloon) );
  printf("tamanho do conteúdo apontado por um float: %d\n",sizeof(*baloon) );
  printf("Os valores apontados pelos endereços '%p' e '%p' são '%d' e '%d'\n",&f, baloon, f, *baloon);
  */

  /*  2.4

  a) 23               e) 23               i) 17

  b) 41               f) Não sei          j) Não sei

  c) 17               g) 41               k) Não sei

  d) Não sei          h)  Não sei         l) Não sei
  */

/* #define SIZE 10  // 2.5 (a)

  void show_vector(char *a, int n);

  int main() {

  char v[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

  show_vector(v, SIZE);

  return 0;

  }

  void show_vector(char *a, int n) {
    int i;
      for (i = 0; i < n; i++) {
          printf("letra --> %c\nendereço do a[%d] == %d\n",a[i],i,&a[i]);
      }
    }
    */

/*  #define SIZE 10    // 2.5 (b)

    void show_vector(char *a, int n);

    int main() {

    char v[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    v[10] = '\0';

    printf("%s\n",v);

    return 0;

    }
    */

    void decompor(int total_seg, int*horas, int*mins, int*segs){  // 2.6

      if(total_seg >= 3600)
        while(total_seg >= 3600){
          *horas += 1;
          total_seg -= 3600;
        }

      if(total_seg >= 60)
        while(total_seg >= 60 ){
          *mins += 1;
          total_seg -= 60;
        }

      if(total_seg > 0)
        *segs = total_seg;

    }

    void max_min(int vec[], int size, int *pmax, int *pmin){

      *pmax = v[0];
      *pmin = v[0];

      for(int i=0;i<size;i++){
        if(vec[i] > *pmax)
          *pmax = v[i]

        if(vec[i] < *pmin)
          *pmin = v[i];
      }

    }
