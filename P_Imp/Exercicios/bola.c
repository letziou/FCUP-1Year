#include <stdio.h>
int main() {

int nos,eles,jornadas,pontos;

scanf("%d %d %d",&nos,&eles,&jornadas);

pontos = jornadas*3;

if( nos >= eles+pontos){
  printf(":-D\n");
}else if(nos+pontos <= eles){
  printf(":-(\n");
}else if( nos < eles && nos+pontos > eles ){
  printf(":-|\n");
}else printf(":-)\n");

return 0;


}
