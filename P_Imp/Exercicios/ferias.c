#include <stdio.h>

int main () {

  int grupo,tempo,di,df,mi,mf,jeito,a=0;

  int calendario[][32] = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}, {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31} ,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31} ,{1,2,3,4,5,6,7,8,9,10,11}};

for(int junho=0;junho!=30;junho++){
  calendario[junho][0]= 0;
}

for(int julho=0;julho!=31;julho++){
  calendario[julho][0]= 0;
}

for(int agosto=0;agosto!=31;agosto++){
  calendario[agosto][0]= 0;
}

for(int setembro=0;setembro!=11;setembro++){
  calendario[setembro][0]= 0;
}


  scanf("%d",&grupo);

  while(grupo != 0){

  scanf("%d",&tempo);

    while(tempo != 0){
      scanf("%d %d %d %d %d",&di,&mi,&df,&mf,&jeito);
      mi= mi-6;
      mf= mf-6;
      di--;
      df--;

      if(jeito == -1){
      if (mi == mf){
        while( di != df){
          calendario[di][mi] = jeito;
          di++;
        }
      }else if(mi == 0 && mf == 1){
        while(di != 30){
          calendario[di][mi] = jeito ;
          di++;
        }
        while(df !=0){
          calendario[df][mf] = jeito;
          df--;
        }
      }else if(mi == 1 && mf == 2){
        while (di != 31) {
          calendario[di][mi]= jeito;
          di++;
        }
        while(df != 0){
          calendario[df][mf]= jeito;
          df--;
        }
      }else if(mi == 2 && mf == 3){
        while (di != 31) {
          calendario[di][mi]= jeito;
          di++;
        }
        while(df != 0) {
          calendario[df][mf]= jeito;
          df--;
        }
      }else if (mi == 0 && mf == 2){
        while(di != 30){
          calendario[di][mi]= jeito;
          di++;
        }
        di= 1;
        while(di != 31){
          calendario[di][1]= jeito ;
          di++;
        }
        while (df != 0){
          calendario[df][mf]= jeito;
          df--;
        }
      }else if(mi == 1 && mf == 3){
        while (di != 31){
          calendario[di][mi]= jeito;
          di++;
        }
        di = 1;
        while (di != 31){
          calendario[di][2]= jeito;
          di++;
        }
        while (df != 0){
          calendario[df][mf]= jeito;
          df--;
        }
      }else if(mi == 0 && mf == 3){
        while(di != 30){
          calendario[di][mi]= jeito;
          di++;
        }
        di =1;
        while (di != 31){
          calendario[di][1]= jeito;
          di++;
        }
        di =1;
        while (di != 31){
          calendario[di][2]= jeito;
          di++;
        }
        while (df != 0){
          calendario[df][mf]= jeito;
          df--;
        }
      }

      else {
        if (mi == mf){
        while( di != df){
          calendario[di][mi]+= jeito;
          di++;
        }
      }else if(mi == 0 && mf == 1){
        while(di != 30){
          calendario[di][mi]+= jeito ;
          di++;
        }
        while(df !=0){
          calendario[df][mf]+= jeito;
          df--;
        }
      }else if(mi == 1 && mf == 2){
        while (di != 31) {
          calendario[di][mi]+= jeito;
          di++;
        }
        while(df != 0){
          calendario[df][mf]+= jeito;
          df--;
        }
      }else if(mi == 2 && mf == 3){
        while (di != 31) {
          calendario[di][mi]+= jeito;
          di++;
        }
        while(df != 0) {
          calendario[df][mf]+= jeito;
          df--;
        }
      }else if (mi == 0 && mf == 2){
        while(di != 30){
          calendario[di][mi]+= jeito;
          di++;
        }
        di= 1;
        while(di != 31){
          calendario[di][1]+= jeito ;
          di++;
        }
        while (df != 0){
          calendario[df][mf]+= jeito;
          df--;
        }
      }else if(mi == 1 && mf == 3){
        while (di != 31){
          calendario[di][mi]+= jeito;
          di++;
        }
        di = 1;
        while (di != 31){
          calendario[di][2]+= jeito;
          di++;
        }
        while (df != 0){
          calendario[df][mf]+= jeito;
          df--;
        }
      }else if(mi == 0 && mf == 3){
        while(di != 30){
          calendario[di][mi]+= jeito;
          di++;
        }
        di =1;
        while (di != 31){
          calendario[di][1]+= jeito;
          di++;
        }
        di =1;
        while (di != 31){
          calendario[di][2]+= jeito;
          di++;
        }
        while (df != 0){
          calendario[df][mf]+= jeito;
          df--;
        }
      }
    }

    }
    tempo--;
    }
  grupo --;
}

int segunda,sabado,domingo,sexta,cont=0,contmax=0,dimax,mimax;

segunda = 5;
domingo = 11;
while(domingo < 27){

while(domingo != segunda){
  cont += calendario[domingo][0];
  domingo--;
}
if(cont > contmax){
  contmax = cont;
  dimax = segunda;
  mimax = 0;
}
cont = 0;
segunda = segunda + 7;
domingo = domingo + 13;
}

sabado = 3;
sexta = 9;
while(sexta < 25){

while(sexta != sabado){
  cont += calendario[sexta][0];
  sexta--;
}
if(cont > contmax){
  contmax = cont;
  dimax = sabado;
  mimax = 0;
}
cont = 0;
sabado = sabado + 7;
sexta = sexta + 13;
}

segunda = 3;
domingo = 9;
while(domingo < 32){

while(domingo != segunda){
  cont += calendario[domingo][1];
  domingo--;
}
if(cont > contmax){
  contmax = cont;
  dimax = segunda;
  mimax = 1;
}
cont = 0;
segunda = segunda + 7;
domingo = domingo + 13;
}

sabado = 1;
sexta = 7;
while(sexta < 30){

while(sexta != sabado){
  cont += calendario[sexta][1];
  sexta--;
}
if(cont > contmax){
  contmax = cont;
  dimax = sabado;
  mimax = 1;
}
cont = 0;
sabado = sabado + 7;
sexta = sexta + 13;
}

segunda = 0;
domingo = 6;
while(domingo < 30){

while(domingo != segunda){
  cont += calendario[domingo][2];
  domingo--;
}
if(cont > contmax){
  contmax = cont;
  dimax = segunda;
  mimax = 2;
}
cont = 0;
segunda = segunda + 7;
domingo = domingo + 13;
}

sabado = 5;
sexta = 11;
while(sexta < 27){

while ( sexta != sabado){
  cont += calendario[sexta][2];
  sexta--;
}
if(cont > contmax){
  contmax = cont;
  dimax = sabado;
  mimax = 2;
}
cont = 0;
sabado = sabado +7;
sexta = sexta +13;
}

segunda = 4;
domingo = 10;
while(domingo < 12){

while(domingo != segunda){
  cont += calendario[domingo][3];
  domingo--;
}
if (cont > contmax){
  contmax = cont;
  dimax = segunda;
  mimax = 3;
}
cont = 0;
domingo = domingo + 13;
}

sabado = 2;
sexta = 8;
while (sexta < 10){

while ( sexta != sabado){
  cont += calendario[sexta][3];
  sexta--;
}
if (cont > contmax){
  contmax = cont;
  dimax = sabado;
  mimax = 3;
}
cont = 0;
sexta = sexta + 13;
}

if(di==24 && mi==0 && df==0 && mf==1){
sabado = 24;
while(sabado < 30){

  cont += calendario[sabado][0];
  sabado++;
}
cont += calendario[0][1];

if(cont > contmax){
  contmax = cont;
  dimax = 24;
  mimax = 0;
}
cont = 0;
}
if(di==29 && mi==1 && df==4 && mf==2){
sabado = 29;
while(a != 5){
  cont += calendario[a][2];
  a++;
}
cont += calendario[29][1];
cont += calendario[30][1];
if(cont > contmax){
  contmax = cont;
  dimax = 29;
  mimax = 1;
}
cont = 0;
}
if(di==26 && mi==2 && df==1 && mf==3){
sabado = 26;
while(sabado != 31){
  cont += calendario[sabado][2];
  sabado++;
}
cont += calendario[0][3];
cont += calendario[1][3];

if (cont > contmax){
  contmax = cont;
  dimax = 26;
  mimax = 3;
}
cont = 0;
}

if (di==26 && mi==0 && df==2 && mf==1){
segunda = 26;
while(sabado != 30){
  cont += calendario[sabado][0];
  sabado++;
}
cont += calendario[0][1];
cont += calendario[1][1];
cont += calendario[2][1];

if (cont > contmax){
  contmax = cont;
  dimax = 26;
  mimax = 0;
}
cont = 0;
}

if(di==28 && mi==2 && df==3 && mf==3){
segunda = 0;
while(segunda != 3){
  cont += calendario[segunda][3];
  segunda++;
}
cont += calendario[28][2];
cont += calendario[29][2];
cont += calendario[30][2];

if (cont > contmax){
  contmax = cont;
  dimax = 28;
  mimax = 3;
}
cont = 0;
}

dimax++;

if(contmax > 0){
  printf("%d ",dimax);

if(mimax == 0)printf("de Junho\n");
if(mimax == 1)printf("de Julho\n");
if(mimax == 2)printf("de Agosto\n");
if(mimax == 3)printf("de Setembro\n");
}else printf("inconsistente\n");
return 0;
}
