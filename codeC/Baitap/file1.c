#include <stdio.h>


int main(){
    FILE *f;
    f = fopen("abc.txt", "wb+");
    //1354325787
    int x = 10;
    fwrite(&x,4,1,f);
    fclose(f);



    f = fopen("abc.txt", "rb");
    int y;
    fread(&y,4,1,f);
    printf("%d", y);
    fclose(f);
};
