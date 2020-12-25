/* viết ct c để cài đặt một hệ thống quản lí kho. hãy lưu trữ mã số, tên hàng, giá cả và số lượng đáng có của mỗi
món hàng trong một cấu trúc. Nhập chi tiết của 5 món hàng vào một mảng các cấu trúc và hiển thị tên từng món hàng và
tổng giá trị của nó. ở cuối ct, hãy hiển thị tổng giá trị của kho hàng. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

struct khohang{
    char maso[10];
    char tenhang[30];
    float gia;
    int soluong;
    float tong;
    float tonggt;
};
typedef struct khohang KH;

void nhapkhohang (KH kh[], int n);
void tinhtienhang (KH kh[], int n);
void xuatkhohang (KH kh[], int n);

int main(){
    int n;
    printf("\n Co bao nhieu mon hang: ");
    scanf("%d", &n);
    KH kh[30];
    nhapkhohang(kh,n);
    xuatkhohang(kh,n);
    tinhtienhang(kh,n);
    return 0;
}

void nhapkhohang(KH kh[], int n){
    for(int i=0; i<n; i++){
        printf("\n --- Nhap mon hang thu %d --- \n", i+1);
        printf("\n Nhap ma so mon hang: "); fflush(stdin); gets(kh[i].maso);
        printf("\n Nhap ten mon hang: "); fflush(stdin); gets(kh[i].tenhang);
        printf("\n Nhap gia mon hang: "); scanf("%f", &kh[i].gia);
        printf("\n Nhap so luong dang co cua mon hang: "); scanf("%d", &kh[i].soluong);
        kh[i].tong = kh[i].gia * kh[i].soluong;
    }
}


void xuatkhohang(KH kh[], int n){
    printf("\n ---- Thong tin kho hang ---- \n");
    printf("%5s %-25s%-10s%7s\n","STT","Ten mon hang","Ma so","Thanh tien");
    for(int i=0; i<n; i++){
         printf("%5d %-25s%-10s%5.2f\n",i+1,kh[i].tenhang,kh[i].maso,kh[i].tong);
    };
}

void tinhtienhang(KH kh[], int n){
    int tonggt = 0;
    for (int i=0; i<n; i++){
        tonggt += kh[i].tong;
    }
    printf("\n =>> Tong gia tri don hang: %d ", tonggt);
}
