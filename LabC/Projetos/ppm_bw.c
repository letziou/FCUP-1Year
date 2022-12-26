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

void turnBW(PIXEL **array, int rows, int cols, int hole, int pixelmax);

int main(int argc, char* argv[]) {

  FILE* buf;
  FILE* end;

  int threshold = atoi(argv[1]);


  if(argc == 4){
    buf = fopen(argv[2],"r");
    end = fopen(argv[3],"w");
  }

  if(argc == 2){
    buf = stdin;
    end = stdout;
  }

  if(argc == 3){
    buf = fopen(argv[2],"r");
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

  //obter os valores de cada pixel
  for(int i=0; i<m.compr ;i++)
    for(int j=0 ; j<m.larg ;j++)
      fscanf(buf ,"%d %d %d" ,&p[i][j].red,&p[i][j].green,&p[i][j].blue);


  fprintf(end ,"%s\n%d %d\n%d\n",m.type,m.larg,m.compr,m.pixelmax);

  PIXEL **array;
  array = malloc(m.compr * sizeof(struct Pixel*));
    if(array == NULL){                                                          //para o caso do array não conseguir alocar memoria suficiente
      printf("Out of memory!\n");
    return 0;
    }
    for(int i=0;i<m.compr;i++){
      array[i] = malloc(m.larg * sizeof(struct Pixel));
      if(array[i] == NULL){                                                     //para o caso do array dos arrays não conseguir alocar memoria suficiente
        printf("Out of memory!\n");
        return 0;
      }
    }
      // copia todos os elementos que estão em cada pixel para um array de arrays
      for(int i=0;i<m.compr;i++)
        for(int j=0;j<m.larg;j++){
          array[i][j].red = p[i][j].red;
          array[i][j].green = p[i][j].green;
          array[i][j].blue = p[i][j].blue;
        }
      // chamada da função que vai transformar os pixeis todos
      turnBW(array,m.compr,m.larg,threshold,m.pixelmax);

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

void turnBW(PIXEL **array, int rows, int cols, int hole, int pixelmax){
  float g;
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      g = array[i][j].red * 0.2126 + array[i][j].green * 0.7152 + array[i][j].blue * 0.0722;   // calcular o valor do G em cada ponto
      g = (int)g;
      if(g > hole){                                                                                // se G maior que threshold transforma os 3 parametros em pixelmax
        array[i][j].red = pixelmax;
        array[i][j].green = pixelmax;
        array[i][j].blue = pixelmax;
      }
      else{                                                                                        // se G não for maior transformaos 3 parametros em 0
        array[i][j].red = 0;
        array[i][j].green = 0;
        array[i][j].blue = 0;
      }
    }
  }
}
