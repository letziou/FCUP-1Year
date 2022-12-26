/*

 CC1003 - Programação Imperativa 2020/2021

 Resolução de exercícios da Folha 6 
 (exclui 4c)

 AP Tomás

*/


#include <stdio.h>
#define NMAX 50


// 1 ========================================================
//  1 a)
void imprimeLinha(int mat[][NMAX], int k, int n) {
  int j;
  printf("%d",mat[k][0]);
  for(j=1; j < n; j++)
    printf(" %d",mat[k][j]);
  printf("\n");
}


//  1 b)
int maximo(int mat[][NMAX], int m, int n) {
  int i, j, max;

  max = 0;   // menor do que qualquer positivo
  for(i=0; i<m; i++)
    for (j= 0; j < n; j++)
      if (mat[i][j] > max)
	max = mat[i][j];

  return max;
}


// 2 ========================================================

// 2 a)
void imprimePol(int v[][2],int n) {

  int i,  xmax = -1, ymax = -1, dx, dy, desl; 
  for(i=0; i<n; i++) {
    if (v[i][0] > xmax) 
      xmax = v[i][0];
    if (v[i][1] > ymax) 
      ymax = v[i][1];
  }

  printf("\\documentclass{article}\n");
  printf("\\setlength{\\unitlength}{0,5cm}");

  printf("\\begin{document}\n");
  printf("\\begin{picture}(%d,%d)\n",xmax,ymax);
  
  for(i=0; i < n; i++) {
    dx = v[(i+1)%n][0]-v[i][0];      // (i+1) % n == 0 se i==n-1;  se não é i+1
    dy = v[(i+1)%n][1]-v[i][1];
    if (dx == 0) {
      desl = (dy > 0?  dy : -dy);
      dy = dy / desl;
    }  else  {
      desl = (dx > 0?  dx : -dx);
      dx = dx / desl;
    }
    printf("\\put(%d,%d){\\line(%d,%d){%d}}\n",v[i][0],v[i][1],dx,dy,desl);
  }

  printf("\\end{picture}\n");
  printf("\\end{document}\n");
}


// 2 b

void dilata(int v[][2],int n,int p,int q) {
  int i;
  for(i=0; i < n; i++) {
    if (v[i][0] >= p)
      v[i][0]++;
    if (v[i][1] >= q)
      v[i][1]++;
  }
}


// 3 ========================================================

void repeteLinha(int mat[][NMAX],int m,int n,int i) {
  int linha, j;
  for(linha = m-1; linha >= i; linha--)   // começa por copiar a última linha
    for (j=0; j < n; j++) 
      mat[linha+1][j] = mat[linha][j];
}

void repeteColuna(int mat[][NMAX],int m,int n,int j) {
  int col, i;
  for(col = n-1; col >= j; col--)
    for(i=0; i < m; i++) 
      mat[i][col+1] = mat[i][col];
}



// 4 ========================================================

// 4 a)
void impr(int pol[][NMAX],int m,int n,char c) {
  int i, j;
  for(i=0; i < m; i++) {
    for(j=0; j < n; j++) 
      if (pol[i][j] == 1) 
	putchar(c);
      else 
	putchar(' ');
    putchar('\n');
  }
}

// 4 b)
void dilatar(int pol[][NMAX],int m,int n,int i, int j) {
  repeteLinha(pol,m,n,i);
  repeteColuna(pol,m,n,j);
}

// 4 c)   Exercício mais complexo...
/*

  Problema de ALGA:
    - Para um ponto com coordenadas (X,Y) num referencial ortonornormado
      (como o habitual), quais são as coordenadas da imagem desse ponto
      por uma rotação de 90º (CCW) com centro na origem? E, se for de 180ª? 
      E, 270º?  
    - Se em vez de estar centrada na origem, estivesse num ponto (Cx,Cy),
      como seria?   [Notar que basta transformar coordenadas para
      ter (Cx,Cy) como origem do referencial (X,Y) ---> (X-Cx, Y-Cy)
      A seguir, aplicar rotação, e voltar a alterar a origem somando
      (Cx,Cy)

  Problema de PI:
    - Escrever uma função que, dada uma célula da matriz (Linha,Coluna), 
      indica em que posição ficaria se efetuasse a rotação de rot em CCW
            void rotacaoCelula(int Celula[2],int rot);
             // Celula[0] é Linha e Celula[1] é a Coluna

    - Tentar implementar a rotação da matriz sem usar uma matriz auxiliar
      (fazer "in-place")  Para isso, temos de efetuar transformação circular.
*/





int main(){
  int v[][2] = {1,1, 0, 1, 0, 5, 3, 5, 3, 0, 1, 0};
   
  //  dilata(v,6,1,2);

  imprimePol(v,6);

  return 0;
}
