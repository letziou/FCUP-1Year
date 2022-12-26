#include "stdio.h"
int main () {

int andar,x,y,erro,p,q;

erro = 0;
p = 1;
q = 2;

  scanf("%d %d %d",&andar,&x,&y);

    if( x == 999 && y == 999) {
        printf("%d\n",erro);
    }else if ( x == 999){
      printf("%d\n",q);
    }else if ( y == 999){
      printf("%d\n",p);
    }else if ( x == y){
      printf("%d\n",p);
    }else if ( x < 0 && y < 0){
      x = x*-1;
      y = y*-1;
        if ( x < y){
          if ( x-andar == andar+y){
            printf("%d\n",p);
          }else if (andar-x > andar-y){
            printf("%d\n",p);
          }else printf("%d\n",q);
        }else if ( x > y){
          if ( y-andar == andar+x){
            printf("%d\n",q);
          }else if( andar-x > andar-y){
            printf("%d\n",p);
          }else printf("%d\n",q);
        }
    }else if ( x < 0){
        x = x*-1;

        if ( x == y && andar == 0){
          printf("%d\n",q);
        }else if ( x+andar == andar-y){
          printf("%d\n",q);
        }else if ( andar-x > andar-y){
          printf("%d\n",p);
        }else printf("%d\n",q);
    }else if ( y < 0 ){
      y = y*-1;
        if ( x == y && andar == 0){
          printf("%d",p);
        }else if ( y+andar == andar-x){
          printf("%d\n",p);
    }else if ( andar-x > andar-y){
          printf("%d\n",p);
        }else printf("%d\n",q);

  }else if ( andar-x == y-andar){
    printf("%d\n",q);
  }else if ( andar-y == x-andar){
    printf("%d\n",p);
  }else if (andar-x > andar-y){
      printf("%d\n",p);
    }else printf("%d\n",q);

return 0;

}
