#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
  int ano;
  int mes;
  int dia;
}DATA;

int compara(DATA d1,DATA d2);
DATA adicionaDias(DATA d,int nd);
int bissexto(int ano);
int maxAniversarios(DATA datas[],int n,int ano);

int main(int argc,char* argv[]) {
  DATA d = {2021,10,28};
  DATA j = adicionaDias(d,4);
  printf("ano :%d\nmes :%d\ndia :%d\n",j.ano,j.mes,j.dia);
  return 0;
}

int compara(DATA d1,DATA d2){
  if(d1.ano<d2.ano) return -1;
  if(d1.ano>d2.ano) return 1;

  if(d1.mes<d2.mes) return -1;
  if(d1.mes>d2.mes) return 1;

  if(d1.dia<d2.dia) return -1;
  if(d1.dia>d2.dia) return 1;

  return 0;
}

int bissexto(int ano){
  if(ano%4!=0) return 1;
  if(ano%10==0) return 1;
  if(ano%400==0) return 0;
  return 1;
}

DATA adicionaDias(DATA d,int nd){
  if((bissexto(d.ano)==0) && (d.mes==2)){
    if((d.dia+nd)>29){
      d.mes++;
      nd -= (29-d.dia);
      d.dia = nd;
      return d;
    }
    else{
      d.dia += nd;
      return d;
    }
  }
  else if((bissexto(d.ano)==0) && (d.mes!=2)){
    if((d.dia+nd)>28){
      d.mes++;
      nd = nd -(28-d.dia);
      d.dia = nd;
      return d;
    }
    else{
      d.dia += nd;
      return d;
    }
  }
  if((d.mes<8) && (d.ano%3==0)){
    if((d.dia+nd)>31){
      d.mes++;
      nd -= (31-d.dia);
      d.dia = nd;
      return d;
    }
    else{
      d.dia += nd;
      return d;
    }
  }
  else if((d.mes<8) && (d.ano%3!=0)){
    if((d.dia+nd)>30){
      d.mes++;
      nd -= (30-d.dia);
      d.dia = nd;
      return d;
    }
    else{
      d.dia += nd;
      return d;
    }
  }
  if((d.mes>7 && d.mes<12) && (d.ano%2==0)){
    if((d.dia+nd)>31){
      d.mes++;
      nd -= (31-d.dia);
      d.dia = nd;
      return d;
    }
    else{
      d.dia += nd;
      return d;
    }
  }
  else if((d.mes>7 && d.mes<12) && (d.ano%2!=0)){
    if((d.dia+nd)>30){
      d.mes++;
      nd -= (30-d.dia);
      d.dia = nd;
      return d;
    }
    else{
      d.dia += nd;
      return d;
    }
  }
  if(d.mes==12){
    if((d.dia+nd)>31){
      d.ano++;
      d.mes = 1;
      nd -= (31-d.dia);
      d.dia = nd;
      return d;
    }
  }
  else{
    d.dia += nd;
    return d;
  }
  d.dia = -1;
  return d;
}

int maxAniversarios(DATA datas[],int n,int ano){
  int contmax=0;
  int cont[]={0,0,0,0,0,0,0,0,0,0,0,0};
  for(int j=0;j<12;j++){
    for(int i=0;i<n;i++){
      if(bissexto(ano) != 0 && (datas[i].dia == 29) && (datas[i].mes == 2)){
        datas[i].dia = 1;
        datas[i].mes = 3;
      }
      if(datas[i].mes == j)
      cont[j]++;
    }
    for(int k=0;k<12;k++){
      if(cont[k]>contmax)
        contmax = cont[k];
    }
  }
  return contmax;
}
