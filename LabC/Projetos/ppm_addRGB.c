#include <stdio.h>
#include <stdlib.h>

struct Pixel{
  int red;
  int green;
  int blue;
};

typedef struct Pixel PIXEL;

struct Data{
  char type[2];
  int compr, larg;
  int pixelmax;
};

typedef struct Data DATA;

void addR(PIXEL **array, int rows, int cols, int add, int pixelmax);
void addG(PIXEL **array, int rows, int cols, int add, int pixelmax);
void addB(PIXEL **array, int rows, int cols, int add, int pixelmax);


int main(int argc, char* argv[]) {

  FILE* buf;
  FILE* end;

  // retira da consola os valores pata adicionar a cada pixel
  int addred = atoi(argv[1]);
  int addgreen = atoi(argv[2]);
  int addblue = atoi(argv[3]);


  if(argc == 6){
    buf = fopen(argv[4],"r");
    end = fopen(argv[5],"w");
  }

  if(argc == 4){
    buf = stdin;
    end = stdout;
  }

  if(argc == 5){
    buf = fopen(argv[4],"r");
    end = stdout;
  }
  int c;

  DATA m;

  fscanf(buf ,("%s") ,m.type);

  getc(buf); //para mudar para a nova linha

  // para remover quaisquer comentarios
  c = getc(buf);
  while (c == '#') {
  while (getc(buf) != '\n'){};
       c = getc(buf);
  }
  ungetc(c, buf);


  fscanf(buf ,("%d %d %d"),&m.larg,&m.compr,&m.pixelmax);


  PIXEL p[m.compr][m.larg];


  for(int i=0; i<m.compr ;i++)
    for(int j=0 ; j<m.larg ;j++)
      fscanf(buf ,"%d %d %d" ,&p[i][j].red,&p[i][j].green,&p[i][j].blue);


  fprintf(end ,"%s\n%d %d\n%d\n",m.type,m.larg,m.compr,m.pixelmax);

  PIXEL **array;
  array = malloc(m.compr * sizeof(struct Pixel*));
    if(array == NULL){
      printf("Out of memory!\n");
    return 0;
    }
    for(int i=0;i<m.compr;i++){
      array[i] = malloc(m.larg * sizeof(struct Pixel));
      if(array[i] == NULL){
        printf("Out of memory!\n");
        return 0;
      }
    }
      // copia todos os elementos que estão em cada pixel para um array de arrays
      for(int i=0;i<m.compr;i++){
        for(int j=0;j<m.larg;j++){
          array[i][j].red = p[i][j].red;
          array[i][j].green = p[i][j].green;
          array[i][j].blue = p[i][j].blue;
        }
      }

        addR(array,m.compr,m.larg,addred,m.pixelmax);
        addG(array,m.compr,m.larg,addgreen,m.pixelmax);
        addB(array,m.compr,m.larg,addblue,m.pixelmax);

      for(int i=0;i<m.compr;i++)
        for(int j=0;j<m.larg;j++){
          fprintf(end ,"%d %d %d\n",array[i][j].red,array[i][j].green,array[i][j].blue);
        }


  fclose(buf);
  fclose(end);
  for (int i=0; i<m.compr; i++) {
    free(array[i]);
  }
  free(array);


  return 0;
}

void addR(PIXEL **array, int rows, int cols, int add, int pixelmax){
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if(array[i][j].red+add > pixelmax){
        array[i][j].red = pixelmax;
      }
      else if(array[i][j].red+add < 0){
        array[i][j].red = 0;
      }
      else array[i][j].red += add;
    }
  }
}
void addG(PIXEL **array, int rows, int cols, int add, int pixelmax){
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if(array[i][j].green+add > pixelmax){
        array[i][j].green = pixelmax;
      }
      else if(array[i][j].green+add < 0){
        array[i][j].green = 0;
      }
      else array[i][j].green += add;
    }
  }
}
void addB(PIXEL **array, int rows, int cols, int add, int pixelmax){
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if(array[i][j].blue+add > pixelmax){
        array[i][j].blue = pixelmax;
      }
      else if(array[i][j].blue+add < 0){
        array[i][j].blue = 0;
      }
      else array[i][j].blue += add;
    }
  }
}
