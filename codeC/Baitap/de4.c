#include <stdio.h>
#include <conio.h>

struct mathang{
    char mahang[12];
    char tenhang[32];
    int soluong;
    int thangnhap;
    float gianhap;
};

typedef struct mathang MH;


void Nhapthongtin(MH mh[], int n){
    printf("Nhap thong tin : \n");
    for(int i=0; i<n; i++){
        printf("Nhap ma hang : ");
        fflush(stdin); gets(mh[i].mahang);
        printf("Nhap ten hang : ");
        fflush(stdin); gets(mh[i].tenhang);
        printf("So luong :");
        scanf("%d", &mh[i].soluong);
        printf("Thang nhap : ");
        scanf("%d", &mh[i].thangnhap);
        printf("Gia nhap : ");
        scanf("%f", &mh[i].gianhap);
    };
}


float Tinhtien(MH mh[], int n){
    float Tinhtien = mh.soluong *
}


int main(){
    MH mh[1000];
    int n;
    printf("Mat hang trong cong ty : ");
    scanf("%d", &n);



}
