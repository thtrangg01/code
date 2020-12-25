/* Bài 1-k55: Xây dựng cấu trúc gồm các thông tin sau của N cán bộ trong một cơ quan:
 Họ tên, tuổi, giới tính, hệ số lương, thưởng, bảo hiểm.
Viết chương trình thực hiện các chức năng sau:
Câu 1: ( 2 điểm)
Nhập thông tin cho từng cán bộ trong cơ quan.
Câu 2: (2 điểm)
Tính thu nhập của từng cán bộ trong cơ quan và thu nhập trung bình của các cán bộ.
Biết rằng: Thu nhập = hệ số lương *1.150.000 + thưởng – bảo hiểm
Câu 3: (2 điểm)
Đếm xem có bao nhiêu cán bộ là nam giới và tuổi >=60.
Câu 4: (2 điểm)
Tìm và in ra thông tin của cán bộ có thu nhập cao nhất.
Câu 5: (2 điểm)
Sắp xếp và in thông tin dưới dạng bảng sau của các cán bộ theo thứ tự tăng dần của thu nhập.
STT Họ và tên Tuổi Thu nhập */
#include <stdio.h>
#include <conio.h>

struct canbo{
    char hoten[32];
    int tuoi;
    char gt[4];
    float hsl, thuong, bh;
};


typedef struct canbo CB;


void nhapcanbo (CB cb[], int n){
    printf("------Nhap thong tin------\n");
    for (int i=1; i<=n; i++){
        printf("Ho ten can bo thu %d : ", i);
        fflush(stdin); gets(cb[i].hoten);
        printf("Tuoi cua can bo thu %d : ", i);
        scanf("%d", &cb[i].tuoi);
        printf("Gioi tinh : ");
        fflush(stdin); gets(cb[i].gt);
        printf("He so luong cua can bo thu %d : ", i);
        scanf("%s", &cb[i].hsl);
        printf("Thuong cua can bo thu %d : ", i);
        scanf("%s", &cb[i].thuong);
        printf("Bao hiem ma can bo thu %d phai dong : ", i);
        scanf("%s", &cb[i].bh);
        printf("-----------------------------------------------------\n");
    };
};


float thunhap(CB cb){
    float tn;
    tn = cb.hsl * 1150000 + cb.thuong - cb.bh;
    return tn;
};


void dem(CB cb[], int n){
    int demcb = 0;
    for (int i=1; i<=n; i++){
        if (strcmp(cb[i].gt, 'nam') == 0 && cb[i].tuoi >= 60){
            demcb++;
        }
    };
    printf("So can bo nam co tuoi >= 60 la : %d\n", demcb);
    printf("-----------------------------------------------------\n");
};


void timmax(CB cb[], int n){
    int max;
    max = thunhap(cb[1]);
    for(int i=2; i<=n; i++){
        if(max < thunhap(cb[i])){
            max = thunhap(cb[i]);
        }
    };
    printf("Can bo co thu nhap cao nhat: \n");
    for(int i=1; i<=n; i++){
        if(thunhap(cb[i]) == max){
            printf("%20s|%5d|%5s|%10f", cb[i].hoten, cb[i].tuoi, cb[i].gt, thunhap(cb[i]));
        }
    };
    printf("-----------------------------------------------------\n");
};


void incanbo(CB cb[], int n){
    CB temp;
    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            if(thunhap(cb[j]) < thunhap(cb[i])){
                temp = cb[i];
                cb[i]= cb[j];
                cb[j]= temp;
            }
        }
    };
    printf("\n------In ra danh sach------\n");
    printf("-----------------------------------------------------\n");
    printf("%3s|%20s|%5s|%12s\n", "STT", "Ho ten", "Tuoi", "Thu nhap");
    for(int i=1; i<=n; i++){
        printf("%3d|%20s|%5d|%12f\n", i, cb[i].hoten, cb[i].tuoi, thunhap(cb[i]));
    };
    printf("-----------------------------------------------------\n");

};


int main(){
    CB cb[200];
    int n;
    printf("So can bo trong co quan la : ");
    scanf("%d", &n);

    nhapcanbo(cb, n);
    dem(cb,n);
    timmax(cb, n);
    incanbo(cb,n);

};

