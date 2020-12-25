/* mỗi phiếu lương có ghi các thông tin sau: họ và tên, đơn vị, tuổi, lương, phụ cấp đứng lớp, bảo hiểm, thu nhập.
viết chương trình thực hiện các chức năng sau:
khai báo cấu trúc dữ liệu và nhập thông tin về họ tên, tuổi, đơn vị, lương, bảo hiểm cho n cán bộ giáo viên.
tính thu nhập của mỗi nhân viên, biết rằng: phụ cấp đứng lớp = 25% lương,
thu nhập = lương + phụ cấp đứng lớp - bảo hiểm;
tìm và in ra thông tin của các cbgv có thu nhập lớn hơn 10 triệu và có tuổi < 55
tính và in ra thu nhập trung bình của các cán bộ giáo viên;
sắp xếp và in thông tin của các cán bộ gv dưới dạng bản sau theo thứ tự giảm dần của thu nhập. */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

struct nhanvien{
    char hoten[50];
    char donvi[50];
    int tuoi;
    float luong, phucap, baohiem;
    float thu nhap;
};

typedef struct nhanvien NV;
void nhapnhanvien(NV nv[], int n);
void thongtinthunhap (NV nv[], int n);
void sapxepnhanvien (NV nv[], int n);
void xuatnhanvien (NV nv[], int n);

int main(){
    int n;
    printf("\n Co bao nhieu cbgv: ");
    scanf("%d", &n);
    NV nv[50];
    nhapnhanvien(nv,n);
    thongtinthunhap(nv,n);
    sapxepnhanvien(nv,n);
    xuatnhanvien(nv,n);
    return 0;
}

void nhapnhanvien (NV nv[], int n){
    for(int i=0; i<n; i++){
        printf("\n Nhap nhan vien thu %d", i+1);
        printf("\n Nhap ho ten can bo: "); fflush(stdin); gets(nv[i].hoten);
        printf("\n Nhap don vi can bo: "); fflush(stdin); gets(nv[i].donvi);
        printf("\n Nhap tuoi can bo: "); fflush(stdin); gets(nv[i].tuoi);
        printf("\n Nhap luong can bo: "); fflush(stdin); gets(nv[i].baohiem);
        sv[i].phucap = sv[i].luong * 0.25 ;
        sv[i].thunhap = sv[i].luong + sv[i].phucap - sv[i].baohiem ;
    }
}

void thongtinthunhap (NV nv[], int n){
    for(int i=0; i<n; i++){
        if(nv[i].thunhap > 10000000 && nv[i].tuoi < 55){

        }
    }
}
