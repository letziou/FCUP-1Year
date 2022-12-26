#include <stdio.h>
#include <stdlib.h>
#define MAX_N 3

typedef struct {
  int r,g,b;
} COLOR;

typedef struct {
  COLOR **mat;
  char mnumb[MAX_N];
  int linhas, cols, nmax;
} METADADOS;

void imprimir_imagem(FILE *fx, COLOR **mat, int l, int c, char *mnumb, int nmax);
void ler_imagem(FILE *fx, COLOR **mat, int l, int c);
FILE *abrir_ficheiro(char *filename, char *modo);
void copiarimagem(COLOR** mat, COLOR** nova, int l, int c);
void criarcontornos(COLOR** mat, COLOR **copia, int l, int c, int max);

int main(int argc, char* argv[]){
  METADADOS imagem, imagemnova;
  FILE *input = stdin, *output = stdout;

  if(argc >= 2) input = abrir_ficheiro(argv[1],"r");
  if(argc >= 3) output = abrir_ficheiro(argv[2],"w");

  fscanf(input,"%s\n %d %d %d",imagem.mnumb,&imagem.cols,&imagem.linhas,&imagem.nmax);

  imagem.mat = malloc(sizeof(COLOR **) * imagem.linhas);
  for(int i = 0; i < imagem.linhas; i++)
    imagem.mat[i] = malloc(sizeof(COLOR) * imagem.cols);

  ler_imagem(input,imagem.mat,imagem.linhas,imagem.cols);

  imagemnova.mat = malloc(sizeof(COLOR **) * imagem.linhas);
  for(int i = 0; i < imagem.linhas; i++)
    imagemnova.mat[i] = malloc(sizeof(COLOR) * imagem.cols);

  copiarimagem(imagem.mat,imagemnova.mat,imagem.linhas,imagem.cols);
  criarcontornos(imagem.mat,imagemnova.mat,imagem.linhas,imagem.cols,imagem.nmax);
  imprimir_imagem(output,imagem.mat,imagem.linhas,imagem.cols,imagem.mnumb,imagem.nmax);

  for(int i = 0; i < imagem.linhas; i++) free(imagem.mat[i]);
  free(imagem.mat);

  fclose(input);
  fclose(output);

  return 0;
}

FILE *abrir_ficheiro(char *filename, char *modo){
  FILE *fx = fopen(filename, modo);
  if(fx == NULL){
    printf("Erro a abrir o ficheiro %s\n",filename);
    exit(1);
  }
  return fx;
}

void ler_imagem(FILE *fx, COLOR **mat, int l, int c){
  for(int i = 0; i < l; i++)
    for(int j = 0; j < c; j++)
      fscanf(fx,"%d %d %d",&mat[i][j].r,&mat[i][j].g,&mat[i][j].b);
}

void imprimir_imagem(FILE *fx, COLOR **mat, int l, int c, char *mnumb, int nmax){
  fprintf(fx,"%s\n%d %d\n%d\n",mnumb,c,l,nmax);

  for(int i = 0; i < l; i++)
    for(int j = 0; j < c; j++)
      fprintf(fx,"%d %d %d\n",mat[i][j].r,mat[i][j].g,mat[i][j].b);
}

void copiarimagem(COLOR** mat, COLOR** nova, int l, int c){
  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){
      nova[i][j].r = mat[i][j].r;
      nova[i][j].g = mat[i][j].g;
      nova[i][j].b = mat[i][j].b;
    }
  }
}

void criarcontornos(COLOR** mat, COLOR** copia, int l, int c, int max){
  int px[] = {-1,-1,-1,0,0,0,1,1,1};
  int py[] = {-1,0,1,-1,0,1,-1,0,1};
  int soma;

  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){
      soma = 0;
      if(i == 0 || j == 0 || i == l-1 || j == c-1){
        copia[i][j].r = 0;
        copia[i][j].g = 0;
        copia[i][j].b = 0;
      } else {
        for(int k = 0; k < 9; k++){
          int xx = i + px[k];
          int yy = j + py[k];
          if(i == xx && j == yy) continue;
          soma += mat[xx][yy].r;
        }
        int t = (8*mat[i][j].r) - soma;
        if(t > max) t = max;
        else if(t < 0) t = 0;
        copia[i][j].r = t;
        copia[i][j].g = t;
        copia[i][j].b = t;
      }
    }
  }
  copiarimagem(copia,mat,l,c);
}
