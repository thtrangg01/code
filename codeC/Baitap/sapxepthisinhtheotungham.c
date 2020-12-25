#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100;

struct sinhvien{
    char hoten[50];
    float toan, ly, hoa, tong;
};
typedef struct sinhvien sv;

void tinh_tong_diem ( sv sv[], int n);
void swap ( sv *a, sv *b);
void sap_xep(sv sv[], int n);
void hien_thi_dl (sv sv[], int n);

void main(){
    sv sv[100];
    int n=1;
    tinh_tong_diem (sv,n);
    sap_xep (sv,n);
    hien_thi_dl (sv,n);

}

void tinh_tong_diem (sv sv[], int n){
    printf("Nhap so sinh vien n= ");
    scanf("%d", &n);
    printf("\n Du lieu sinh vien ");
    fflush(stdin);
    for (int i=0; i<n; i++){

        printf("\n Ho ten thi sinh: ");
        fflush(stdin);
        gets(sv[i].hoten);
        fflush(stdin);

        printf("Diem toan: ");
        scanf("%f", &sv[i].toan);
        printf("Diem ly: ");
        scanf("%f", &sv[i].ly);
        printf("Diem hoa: ");
        scanf("%f", &sv[i].hoa);

        sv[i].tong = sv[i].toan + sv[i].ly +sv[i].hoa;
}

void swap (int  *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
};

void sap_xep(sv sv[], int n){
    for (int i=0; i< n - 1; i++){
        for (int j= i+1; j<n; j++){
            if (sv[i].tong < sv[j].tong){
                swap(&sv[i],&sv[j]);
            }
        }
    }
}

void hien_thi_dl (sv sv[], int n){
    printf("In ra danh sach: ");
    printf(" Ho ten\t Tong diem\t \n");
    for (int i=0; i<n; i++){
            if(sv[i].tong > 1){
            printf("%10s\t %.2f\t \n", sv[i].hoten, sv[i].tong);
        }
    }
}
