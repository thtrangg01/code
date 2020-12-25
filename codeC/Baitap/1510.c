/* #include <stdio.h>
#include <string.h>
int main()
{
    char s[10];
    strcpy(s,"Xin chao");
    //printf("%c", *(s+1));
    printf("%u\n", s);
    printf("%u\n", &s[0]);
    printf("%u\n", &s[1]);
    printf("%u\n", &s[2]);
    return 0;
} */



// Sắp xếp chuỗi theo thứ tự abc (5 phần tử)
#include<stdio.h>
#include<string.h>

int main() {
   char s[5][20];
   char t[20];
   int i, j;

   printf("\nNhap 5 chuoi bat ky: \n");
   for (i = 0; i < 5; i++) {
      scanf("%s", s[i]);
   }
   // sap xep chuoi
   for (i = 1; i < 5; i++) {
      for (j = 1; j < 5; j++) {
         if (strcmp(s[j - 1], s[j]) > 0) {
            strcpy(t, s[j - 1]);
            strcpy(s[j - 1], s[j]);
            strcpy(s[j], t);
         }
      }
   }

   printf("\nSap xep thu tu cua cac chuoi:");
   for (i = 0; i < 5; i++) {
      printf("\n%s", s[i]);
   }
   return(0);
}


