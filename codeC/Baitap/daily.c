/*
Bài 6-2015: Một công ty A có N đại lý. Cho biết tên các đại lý, địa chỉ các đại lý, daonh thu năm của từng đại lý. Viết chương trình:
Câu 1(2đ):
Nhập thông tin co từng đại lý của công ty A,
Câu 2(2đ):
Tính tổng số tiền mà công ty A thu được từ doanh thu của N đại lý trên trong năm 2015.
Câu 3(2đ):
Tình doanh thu trung bình năm 2015 của N đại lý trên.
Câu 4(2đ):
Tìm và in thông tin của đại lý có doanh thu cao nhất.
Câu 5(2đ):
Sắp xếp và in thông tin dưới dạng bảng của từng đại lý theo thứ tự giảm dần doanh thu năm 2015:.
STT Tên đại lý Địa chỉ đại lý Doanh thu năm 2015
….. */

#include <stdio.h>
#include <conio.h>
#include <string.h>


struct daily{
    char ten[12];
    char diachi[20];
    float doanhthu;
};
typedef struct daily DL;


//Nhập thông tin cho từng đại lý của công ti A
void nhapDL(DL dl[], int n){
    printf("\n--------Nhap du lieu--------\n");
    for(int i=1; i<=n; i++){
        printf("Ten dai li : ");
        fflush(stdin);gets(dl[i].ten);
        printf("Dia chi dai li : ");
        fflush(stdin);gets(dl[i].diachi);
        printf("Doanh thu cua dia li : ");
        scanf("%f",&dl[i].doanhthu);
        printf("------------------------------------------------------\n");
    };
}


//tinh tong so tien ma cong ti A thu duoc  tu doanh thu cua n dai li tren trong nam
float tongtien(DL dl[], int n){
    float S = 0;
    for(int i=1; i<=n; i++){
        S += dl[i].doanhthu;
    };
    float TB = S/n;
    return TB;
}


//tim va in ra thong tin cua dai li co doanh thu cao nhat
void timmax(DL dl[], int n){
    float max = dl[1].doanhthu;
    for(int i=2; i<=n; i++){
        if (max < dl[i].doanhthu){
            max = dl[i].doanhthu;
        }
    };
    printf("-----Dai ly co doanh thu cao nhat-----\n");
    printf("%12s|%12s|%12s\n", "Ten", "Dia chi", "Doanh thu");
    for(int i=1;i<=n;i++){
        if(dl[i].doanhthu == max){
            printf("%12s|%12s|%12.2f\n", dl[i].ten, dl[i].diachi, dl[i].doanhthu);
            //break;
        }
    };
    printf("------------------------------------------------------\n");

}


//Sắp xếp và in thông tin dưới dạng bảng của từng đại lý theo thứ tự giảm dần doanh thu năm 2015:.
void sapxep(DL dl[], int n){
    DL temp;
    for(int i=1;i<=n-1; i++){
        for(int j=i-1;j<=n;j++){
            if(dl[i].doanhthu < dl[j].doanhthu){
                temp = dl[i];
                dl[i]= dl[j];
                dl[j] = temp;
            }
        }
    };
    printf("-----In ra danh sach-----\n");
    printf("%3s|%12s|%12s|%12s\n","STT","Ten","Dia chi","Doanh thu");
    for (int i=1;i<=n;i++){
        printf("%3d|%12s|%12s|%12.2f\n",i, dl[i].ten, dl[i].diachi, dl[i].doanhthu);
    };
    printf("--------------------------------------------------------\n");
}


int main(){
    DL dl[300];
    int n;
    printf("So dai ly o cong ty A : ");
    scanf("%d", &n);

    nhapDL(dl,n);
    timmax(dl,n);
    sapxep(dl,n);
}
