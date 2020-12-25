#include <stdio.h>

typedef struct{
    char ten[30];
     int tuoi;
     float diem;
} sinhvien;


 int main(){
     FILE *f;
     f = fopen("abc.txt", "r+");  // hàm fopen : mở file,

     sinhvien dsSinhvien[30];

     /* char str[4];
     int i = 1;

     char c = fgetc(f);   //đọc và lấy kí tự
            fgets(str,60,f);



     while ( fgets(str,4,f) != NULL ){    //lấy ra từng kí tự, kí tự cuối cùng cần ktra để kết thúc, trả về từng biến
            printf("%s(%d)", str, i++);
     }; */

     int i = 0;
     while (!feof(f)){
        fscanf(f,"%s %d %f", dsSinhvien[i].ten, &dsSinhvien[i].tuoi, &dsSinhvien[i].diem);
        i++;
     };

     int slsv = i;
     for (int i = 0; i<slsv; i++){
            printf( "%10s %2d %5.1f \n", dsSinhvien[i].ten, dsSinhvien[i].tuoi, dsSinhvien[i].diem);

     };

     //fgetc
     fputc('a', f);
     fputc('\n', f);
     fputs("Duong 21 9.0",f);    // ghi chuỗi vào file

     fprintf(f,"%s %d %f", "Minh", "17", "8.5");

     fclose(f); //đóng file


     //char c1 = fgetc(f); //lấy ra kí tự
     //printf("%c",c1);

     return 0;
 };
