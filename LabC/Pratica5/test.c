#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE* start;
    FILE* end;
    int count = 0;

    start = fopen(argv[1],"r");
    end = fopen(argv[2],"w");

    
    
    fclose(start);
    fclose(end);
    return 0;
}