/* Bài 3-k55: Cho một tập phiếu lương. Mỗi phiếu có ghi các thông tin sau:
Họ và tên, giới tính, lương, phụ cấp, các khoản trừ của mỗi nhân viên trong một đơn vị.
Viết chương trình thực hiện các chức năng sau:
Câu 1: (2 điểm)
Nhập thông tin cho từng nhân viên trong đơn vị.
Câu 2: (2 điểm)
Tính tiền được lĩnh của mỗi nhân viên biết rằng:
Tiền được lĩnh = lương + phụ cấp –các khoản trừ
Câu 3: (2 điểm) Tính tỷ lệ phần trăm các nhân viên nữ và có lương > 10 triệu trong đơn vị
Câu 4: (2 điểm)
Tìm và in ra thông tin của những nhân viên có tiền được lĩnh thấp nhất trong đơn vị
Câu 5: (2 điểm)
Sắp xếp và in thông tin của các nhân viên dưới dạng bảng sau theo thứ tự tăng dần của tiền được lĩnh
STT Họ và tên Tiền được lĩnh  */

#include <stdio.h>
#include <conio.h>
#include <string.h>


struct nhanvien{
    char hoten[32];
    char gt[4];
    float luong, phucap, khoantru;
};


typedef struct nhanvien NV;

void nhapthongtin(NV nv[], int n){
    for(int i=1; i<=n; i++){
        printf("Ho ten cua nhan vien thu %d : ", i);
        fflush(stdin); gets(nv[i].hoten);
        printf("Gioi tinh : ");
        fflush(stdin); gets(nv[i].gt);
        printf("Luong cua nhan vien thu %d : ",i);
        scanf("%f", &nv[i].luong);
        printf("Phu cap cua nhan vien thu %d : ", i);
        scanf("%f", &nv[i].phucap);
        printf("Khoan tru cua nhan vien thu &d : ", i);
        scanf("%f", &nv[i].khoantru);
        printf("-------------------------------------------\n");
    };
};


float tinhtien(NV nv){
    float tien;
    tien = nv.luong + nv.phucap - nv.khoantru;
    return tien;
};



void tile(NV nv[], int n){
    float dem = 0;
    for (int i=1; i<=n; i++){
        if (strcmp(nv[i].gt, "nu") == 0 && nv[i].luong > 10){
            dem++;
        }
    };
    printf("Ti le nhan vien nu co luong > 10tr la : %f", dem / n);
};


void timmin(NV nv[], int n){
    float min;
    min = tinhtien(nv[1]);
    for(int i=1; i<=n; i++){
        if(min > tinhtien(nv[i])){
            min = tinhtien(nv[i]);
        };
    };
    printf("Thong tin cua nhan vien co tien duoc linh thap nhap trong don vi la : \n");
    for (int i=1; i<=n; i++){
        if(tinhtien(nv[i]) == min ){
            printf("%12s|%12s \n ", "Ten", "Tien duoc linh (trieu) ");
            printf("%12s|%12f\n", nv[i].hoten, tinhtien(nv[i]));
        }
    };
    printf("-------------------------------------------\n");
};


void inthongtin(NV nv[], int n){
    NV temp;
    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            if(tinhtien(nv[j]) < tinhtien(nv[i])){
                temp = nv[i];
                nv[i] = nv[j];
                nv[j] = temp;
            }
        }
    };
    printf("\n------ In ra danh sách ------\n");
    printf("-------------------------------------------\n");
    printf("%3s|%24s|%12s", "STT", "Ho ten", "Tien duoc linh (trieu) ");
    for(int i=1; i<=n; i++){
        printf("%3d|%24s|%12f", i, nv[i].hoten, tinhtien(nv[i]));
    };
    printf("-------------------------------------------\n");
};


int main(){
    NV nv[200];
    int n;
    printf("So nhan vien trong don vi la : ");
    scanf("%d", &n);

    nhapthongtin(nv, n);
    tile(nv, n);
    timmin(nv, n);
    inthongtin(nv, n);
};
