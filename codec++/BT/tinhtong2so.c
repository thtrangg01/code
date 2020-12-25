#include <stdio.h>
#include <conio.h>
void main(void)
{
    int a,b;
    printf("Moi ban nhap so a:");
    scanf("%d", &a);
    printf("\n Moi ban nhap so b:");
    scanf("%d", &b);
    printf("\n Tong cua 2 so %d va %d la: %d ", a,b,a+b);
    printf("\n Hieu cua 2 so %d va %d la: %d ", a,b,a-b);
    printf("\n Tich cua 2 so %d va %d la: %d" , a,b,a*b);
    float t;
    t = a/b;
    printf("\n Thuong cua 2 so %d va %d la: %f", a,b,t);
    // printf("\n Thuong cua 2 so %d va %d la: %d" , a,b,(float) a/b);

    getch();

}
