/* Xây dựng cấu trúc gồm các thông tin sau của nhân viên trong một công ty:
Họ tên, đơn vị, hệ số lương, phụ cấp, số ngày nghỉ trong tháng, thu nhập.
Câu 1: Nhập thông tin N nhân viên trong công ti
Câu 2: Tính thu nhập trong tháng của từng nhân viên trong công ty biết rằng:
Thu nhập = hệ số lương * 2.000.000 + phụ cấp - số ngày nghỉ trong tháng * 300.000
Câu 3: Tính thu nhập trung bình của các nhân viên trong công ty
Câu 4: Tìm và in ra thông tin của nhân viên có thu nhập > 10.000.000 và số ngày nghỉ trong tháng < 3.
Câu 5: Sắp xếp hệ số lương của các nhân viên theo thứ tự tăng dần và in thông tin dưới dạng bảng sau
STT| Họ và tên| Hệ số lương|Thu nhập */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>


struct nhanvien{
    char hoten[32];
    char donvi[24];
    float hesoluong;
    float phucap;
    int songaynghi;
    //float thunhap;
};

typedef struct nhanvien NV;


void Nhapthongtin(NV nv[], int n){
    printf("---------Nhap thong tin---------\n");
    for(int i=0; i<n; i++){
        printf("-> Nhan vien thu %d <-\n", i+1);
        printf("Ho va ten : ");
        fflush(stdin); gets(nv[i].hoten);
        printf("Don vi : ");
        fflush(stdin); gets(nv[i].donvi);
        printf("He so luong : ");
        scanf("%f", &nv[i].hesoluong);
        printf("Phu cap : ");
        scanf("%f", &nv[i].phucap);
        printf("So ngay nghi trong thang : ");
        scanf("%d", &nv[i].songaynghi);
        printf("----------------------------------------------------------\n");

    }
}


float thunhap(NV nv){
    float thunhap;
    thunhap = nv.hesoluong * 2000000 + nv.phucap - nv.songaynghi * 300000;
    return thunhap;
}


float TB(NV nv[], int n){
    float sum = 0;
    for(int i=0; i<n; i++){
        sum += thunhap(nv[i]);
    };
    float TB;
    TB = sum / n;
    return TB;
}


void Timthongtin(NV nv[], int n){
    printf("Danh sach nhan vien co thu nhap > 10000000 va so ngay nghi trong thang < 3 : \n");
    printf("%3s|%32s|%24s\n", "STT", "Ho ten", "Don vi");
    for(int i=0; i<n; i++){
        if(thunhap(nv[i]) > 10000000 && nv[i].songaynghi < 3){
            printf("%3d|%32s|%24s\n", i+1, nv[i].hoten, nv[i].donvi);
        }
    };
    printf("----------------------------------------------------------\n");
}


void Inthongtin(NV nv[], int n){
    NV temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(nv[j].hesoluong < nv[i].hesoluong){
                temp = nv[i];
                nv[i] = nv[j];
                nv[j] = temp;
            };
        };
    };
    printf("---------In thong tin---------\n ");
    printf("%3s|%32s|%24s|%12s\n", "STT", "Ho ten", "Thu nhap", "Hso luong");
    for(int i=0; i<n; i++){
        printf("%3d|%32s|%24.2f|%12f\n", i+1, nv[i].hoten, thunhap(nv[i]), nv[i].hesoluong);
    };
}


int main(){
    NV nv[1000];
    int n;
    printf("Moi ban nhap so nhan vien trong cong ty : ");
    scanf("%d", &n);

    Nhapthongtin(nv,n);
    Timthongtin(nv,n);
    Inthongtin(nv,n);

}

