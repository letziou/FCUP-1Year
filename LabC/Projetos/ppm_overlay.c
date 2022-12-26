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

int main(int argc, char* argv[]) {

    FILE* firstpic;
    FILE* secondpic;
    FILE* end;

  int lini = atoi(argv[1]);
  int cini = atoi(argv[2]);


  if(argc == 6){
    firstpic = fopen(argv[3],"r");
    secondpic = fopen(argv[4],"r");
    end = fopen(argv[5],"w");
  }

  if(argc == 4){
    firstpic = fopen(argv[3],"r");
    secondpic = stdin;
    end = stdout;
  }

  if(argc == 5){
    firstpic = fopen(argv[3],"r");
    secondpic = fopen(argv[4],"r");
    end = stdout;
  }

    int c;

    DATA first;
    DATA second;

    fscanf(firstpic ,("%s") ,first.type);

    getc(firstpic); //para mudar para a nova linha

    // para remover quaisquer comentarios da primeira figura
    c = getc(firstpic);
    while (c == '#') {
    while (getc(firstpic) != '\n'){};
         c = getc(firstpic);
    }
    ungetc(c, firstpic);

    // para remover quaisquer comentarios da segunda figura
    fscanf(secondpic ,("%s") ,second.type);

    getc(secondpic); //para mudar para a nova linha

    // para remover quaisquer comentarios
    c = getc(secondpic);
    while (c == '#') {
    while (getc(secondpic) != '\n'){};
         c = getc(secondpic);
    }
    ungetc(c, secondpic);

    fscanf(firstpic ,("%d %d %d"),&first.larg,&first.compr,&first.pixelmax);
    fscanf(secondpic ,("%d %d %d"),&second.larg,&second.compr,&second.pixelmax);

    PIXEL p[first.compr][first.larg];
    PIXEL s[second.compr][second.larg];


    for(int i=0; i<first.compr ;i++)
      for(int j=0 ; j<first.larg ;j++)
        fscanf(firstpic ,"%d %d %d" ,&p[i][j].red,&p[i][j].green,&p[i][j].blue);

    for(int i=0; i<second.compr ;i++)
      for(int j=0 ; j<second.larg ;j++)
        fscanf(secondpic ,"%d %d %d" ,&s[i][j].red,&s[i][j].green,&s[i][j].blue);

    fprintf(end ,"%s\n%d %d\n%d\n",second.type,second.larg,second.compr,second.pixelmax);

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

      // copia a segunda imagem para o array
       for(int i=0;i<second.compr;i++)
         for(int j=0;j<second.larg;j++){
           array[i][j].red = s[i][j].red;
           array[i][j].green = s[i][j].green;
           array[i][j].blue = s[i][j].blue;
         }

       for(int i=cini;i<first.compr;i++)
         for(int j=lini;j<first.larg;j++){
           array[i][j].red = p[i][j].red;
           array[i][j].green = p[i][j].green;
           array[i][j].blue = p[i][j].blue;
           printf("adeus\n");
         }

        for(int i=0;i<second.compr;i++)
          for(int j=0;j<second.larg;j++){
            fprintf(end ,"%d %d %d\n",array[i][j].red,array[i][j].green,array[i][j].blue);
          }

    fclose(firstpic);
    fclose(secondpic);
    fclose(end);
    for (int i=0; i<second.compr; i++) {
      free(array[i]);
    }
    free(array);


    return 0;
  }
