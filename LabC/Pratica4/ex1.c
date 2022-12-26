 #include <stdio.h>
 #include <string.h>

 int main(int argc, char* argv[]){          // argc é o número da string e argv é o conteudo da string

   for(int i=1;i<argc;i++){
    int a = strlen(argv[i]);
    printf("%s -> %d\n",argv[i],a);
  }

  return 0;
}
