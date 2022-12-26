#include <stdio.h>

int main () {
#define CHAR 15

char x[CHAR],s[CHAR];
int i,cont=0,sub=0,l=0;

for(i=0;(x[i]= getchar()) != '\n';i++);
for(i=0;(s[i]= getchar()) != '\n';i++);

while(l != i){
if(x[l]==s[l]){
  cont = cont;
  sub = sub;
}else if((x[l]=='R' && s[l]== 'T')||(x[l]=='T'&&s[l]=='P')||(x[l]=='P'&&s[l]=='R'))
cont ++;

else sub++;
l++;
}

printf("%d\n%d\n",cont,sub);
return 0;
}
