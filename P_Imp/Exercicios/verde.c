#include "stdio.h"
int main () {

int verde,azul,amarelo,n,valor;

verde = 0;
azul = 0;
amarelo = 0;

scanf("%d",&n);

while(n != -1){
    valor = n;
    if ( valor >= 0 && valor <= 10){
        azul = azul + 1;

    }else if ( valor >= 11 && valor <= 23){
        verde = verde + 1;

    }else if ( valor >= 24 && valor <= 40){
        amarelo = amarelo + 1;
    }

}

printf("azul: %d\namarelo: %d\nverde: %d\n",azul,amarelo,verde);

return 0;

}
