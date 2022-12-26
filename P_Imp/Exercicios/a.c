#include <stdio.h>
int main() {
int novo, ultimo;
scanf("%d",&ultimo); // o primeiro
scanf("%d",&novo); // o segundo
while (novo != -1) {
ultimo = novo; // substituir
scanf("%d",&novo); // ler o seguinte
}
printf("%d\n",ultimo); // resposta
return 0;
}
