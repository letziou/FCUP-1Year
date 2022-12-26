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

int main(int argc, char *argv[]) {

  FILE* firstpic;
  FILE* secondpic;
  FILE* end;

  if(argc == 4){
    firstpic = fopen(argv[1],"r");
    secondpic = fopen(argv[2],"r");
    end = fopen(argv[3],"w");
  }

  if(argc == 3){
    firstpic = fopen(argv[1],"r");
    secondpic = stdin;
    end = stdout;
  }

  int c;

  DATA first;
  DATA second;

// remover quaisquer comentarios da 1 imagem
  fscanf(firstpic, ("%s"),first.type);

  getc(firstpic);

  c = getc(firstpic);
  while( c == '#'){
    while( getc(firstpic) != '\n'){};
     c = getc(firstpic);
  }
  ungetc(c,firstpic);


// remover quaisquer comentarios da 2 imagem
  fscanf(secondpic, ("%s"),second.type);
  getc(secondpic);

  c = getc(secondpic);
  while( c == '#'){
    while( getc(firstpic) != '\n'){};
    c = getc(secondpic);
  }
  ungetc(c,secondpic);

  fscanf(firstpic, ("%d %d %d"),&first.larg,&first.compr,&first.pixelmax);
  fscanf(secondpic, ("%d %d %d"),&second.larg,&second.compr,&second.pixelmax);

  int maxlarg = first.larg + second.larg;

  PIXEL p[first.compr][first.larg];
  PIXEL s[second.compr][second.larg];

  for(int i=0;i<first.compr;i++)
    for(int j=0;j<first.larg;j++)
      fscanf(firstpic, ("%d %d %d"),&p[i][j].red,&p[i][j].green,&p[i][j].blue);

  for(int i=0;i<second.compr;i++)
    for(int j=0;j<second.larg;j++)
      fscanf(secondpic, ("%d %d %d"),&s[i][j].red,&s[i][j].green,&s[i][j].blue);

  if(first.compr < second.compr){
printf("1\n");
    fprintf(end, "%s\n%d %d\n%d\n",second.type,second.larg,second.compr,second.pixelmax);

  PIXEL **array;
  array = malloc( second.compr * sizeof(struct Pixel*) );
    if(array == NULL){
      printf("Out of memory!\n");
    return 0;
    }
    for(int i=0;i<second.compr ;i++){
      array[i] = malloc( second.larg * sizeof(struct Pixel) );
      if(array[i] == NULL){
        printf("Out of memory!\n");
        return 0;
      }
    }

    for(int i=0;i<second.compr;i++)
      for(int j=0;j<second.larg;j++){
        array[i][j].red = s[i][j].red;
        array[i][j].green = s[i][j].green;
        array[i][j].blue = s[i][j].blue;
      }

    for(int i=0;i<second.compr;i++)
      for(int j=0;j<second.larg;j++){
        fprintf(end ,"%d %d %d\n",array[i][j].red,array[i][j].green,array[i][j].blue);
      }

    for (int i=0; i<second.compr; i++) {
      free(array[i]);
    }
    free(array);
  }

  else{
    printf("2\n");
    fprintf(end, "%s\n%d %d\n%d\n",second.type,maxlarg,second.compr,second.pixelmax);

  PIXEL **array;
  array = malloc( second.compr * sizeof(struct Pixel*) );
    if(array == NULL){
      printf("Out of memory!\n");
    return 0;
    }
    for(int i=0;i<second.compr ;i++){
      array[i] = malloc( maxlarg * sizeof(struct Pixel) );
      if(array[i] == NULL){
        printf("Out of memory!\n");
        return 0;
      }
    }

    for(int i=0;i<second.compr;i++){
      int j;
      for(j=0;j<first.larg;j++){
        array[i][j].red = p[i][j].red;
        array[i][j].green = p[i][j].green;
        array[i][j].blue = p[i][j].blue;
      }
      for(int k=0,j;j<maxlarg;j++,k++){
        array[i][j].red = s[i][k].red;
        array[i][j].green = s[i][k].green;
        array[i][j].blue = s[i][k].blue;
      }
    }

    for(int i=0;i<second.compr;i++)
      for(int j=0;j<second.larg;j++){
        fprintf(end ,"%d %d %d\n",array[i][j].red,array[i][j].green,array[i][j].blue);
      }

    for (int i=0; i<second.compr; i++) {
      free(array[i]);
    }
    free(array);
  }

  fclose(firstpic);
  fclose(secondpic);
  fclose(end);


  return 0;
}
