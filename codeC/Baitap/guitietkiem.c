/* Bài 2-2017: Cho tập thẻ gửi tiết kiệm năm 2017 mỗi thẻ có các thông tin:
số thẻ, tên người gửi, tháng gửi,
kỳ hạn (3 tháng, 6 tháng, 12 tháng và không kỳ hạn) và số tiền gửi.
Viết chương trình thực hiện các công việc sau :
Câu 1(2đ):
Tổ chức cấu trúc dữ liệu và nhập thông tin cho tập thẻ trên.
Câu 2(2đ):
Tính tổng tiền gửi tiết kiệm của tất cả các thẻ .
Câu 3(2đ):
Tìm và in thẻ tiết kiệm có số tiền gửi cao nhất .
Câu 4(2đ):
Tìm chênh lệch giữa tổng tiền gửi kỳ hạn 12 tháng với tổng tiền gửi kỳ hạn 6 tháng.
Câu 5(2đ):
In ra bảng thống kê các thẻ tiết kiệm kỳ hạn 12tháng
theo trật tự tăng dần của số thẻ gửi theo mẫu:
Số thẻ Tên người gửi Số tiền gửi Tổng Xxxx */
#include <stdio.h>
#include <conio.h>
#include <string.h>


struct tietkiem{
    int sothe;
    char ten[32];
    int thang;
    float kyhan;
    float sotiengui;
};


typedef struct tietkiem TK;


void nhapdulieu (TK tk[], int n){
    printf("------Nhap thong tin------\n");
    for (int i=1; i<=n; i++){
        printf("So the : ");
        scanf("%d", &tk[i].sothe);
        printf("Ten nguoi gui : ");
        fflush(stdin); gets(tk[i].ten);
        printf("Thang gui : ");
        scanf("%d", &tk[i].thang);
        printf("Ky han : ");
        scanf("%f",&tk[i].kyhan);
        printf("So tien gui : ");
        scanf("%f", &tk[i].sotiengui);
        printf("----------------------------------------\n");

    };
}


float tongtien(TK tk[], int n){
    float sum=0;
    for (int i=1; i<=n; i++){
        sum = sum + tk[i].sotiengui;
    };
    printf("Tong tien gui tiet kiem la : %.2f", sum);
    printf("\n----------------------------------------------\n");
}


void timmax(TK tk[], int n){
    int max;
    max = tk[1].sotiengui;
    for (int i=2; i<=n; i++){
        if (max < tk[i].sotiengui){
            max = tk[i].sotiengui;
        }
    };
    printf("The tiet kiem co so tien gui cao nhat la : \n");
    printf("%12s|%24s|%12s\n", "So the", "Ten nguoi gui", "So tien gui");
    for (int i=1; i<=n; i++){
        if (tk[i].sotiengui == max){
            printf("%12d|%24s|%12.2f\n", tk[i].sothe, tk[i].ten, tk[i].sotiengui );
        }
    };
    printf("\n----------------------------------------------\n");
}


void tinhchenhlech(TK tk[], int n){
    float tien12 = 0, tien6 = 0, chenhlech = 0;
    for (int i=1; i<=n; i++){
        if (tk[i].kyhan == 6){
            tien6 += tk[i].sotiengui;
        };
        if (tk[i].kyhan == 12){
            tien12 += tk[i].sotiengui;
        };
    };
    chenhlech = tien12 - tien6;
    printf("Chenh lech giua tong thang 12 voi thang 6 la : %f ", chenhlech);
    printf("\n----------------------------------------------\n");

}


void indulieu(TK tk[], int n){
    TK temp;
    for (int i=1; i<= n-1; i++){
        for (int j=i+1; j<=n; j++){
            if (tk[i].sotiengui < tk[j].sotiengui && tk[i].kyhan == 12){
                temp = tk[i];
                tk[i] = tk[j];
                tk[j] = temp;
            }
        }
    };
    printf("\n--------In ra danh sach thang 12--------\n");
    printf("----------------------------------------------\n");
    printf("%12s|%24s|%12s\n", "So the", "Ten nguoi gui", "So tien gui");
    for (int i=1; i<=n; i++){
        printf("%12d|%24s|%12.2f\n", tk[i].sothe, tk[i].ten, tk[i].sotiengui );

    };
    printf("----------------------------------------------\n");
}


int main(){
    TK tk[200];
    int n;
    printf("Tap the tiet kiem co so the n = ");
    scanf("%d", &n);

    nhapdulieu(tk,n);
    tongtien(tk,n);
    tinhchenhlech(tk,n);
    timmax(tk,n);
    indulieu(tk,n);
}
