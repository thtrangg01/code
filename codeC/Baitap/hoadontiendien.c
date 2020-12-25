 /* Bài 2-k55:Cho một tập hoá đơn tiền điện trong một tháng cho N khách hàng. Mỗi hoá đơn bao gồm các thông tin sau: Mã khách hàng, tên khách hàng,
  địa chỉ khách hàng, chỉ số đo đồng hồ tháng trước, chỉ số đo đồng hồ tháng sau, chỉ số tiêu thụ, số tiền.Viết chương trình thực hiện các chức năng sau:
Câu 1: (2 điểm)
Nhập thông tin cho từng khách hàng.
Câu 2: (2 điểm)
Tính chỉ số tiêu thụ điện và số tiền phải trả của từng khách hàng trong tháng.
 Biết rằng: Chỉ số tiêu thụ trong tháng = Chỉ số đo tháng trước – Chỉ số đo tháng sau
Số tiền phải trả trong tháng của từng khách hàng = Chỉ số tiêu thụ *3000
Câu 3: (2 điểm)
Tính tổng số tiền mà nhà sản xuất thu được từ N khách hàng trên.
Câu 4: (2 điểm)
Tìm và in thông tin của những khách hàng có chỉ số tiêu thụ cao nhất.
Câu 5: (2 điểm)
Sắp xếp và in thông tin của từng khách hàng dưới dạng bảng sau theo thứ tự giảm dần của số tiền phải trả.
STT Họ tên khách hàng Chỉ số tiêu thụ Số tiền phải trả */
#include <stdio.h>

struct khachhang{
    char makh[12];
    char tenkh[32];
    char diachi[32];
    int cstt;
    int csts;
};
typedef struct khachhang KH;


void nhapTT(KH kh[], int n){
    printf("Nhap thong tin \n");
    for (int i=1; i <= n; i++){
        printf("Ten khach hang thu %d : ", i );
        fflush(stdin); gets(kh[i].tenkh);
        printf("Ma khach hang thu %d : ", i);
        fflush(stdin); gets(kh[i].makh);
        printf("Dia chi khach hang thu %d : ", i);
        fflush(stdin); gets(kh[i].diachi);
        printf("Chi so tieu thu thang truoc cua khach hang thu %d : ", i);
        scanf("%d",&kh[i].cstt);
        printf("Chi so tieu thu thang nay khach hang thu %d : ", i);
        scanf("%d",&kh[i].csts);
        printf("--------------------------------------------------------------------\n");
    };

};

int chiso(KH kh){
    int cs;
    cs = kh.csts - kh.cstt;
    return cs;
};

int tinhtien(KH kh){
    int tien;
    tien = chiso(kh) * 3000;
    return tien;
};


int tongtien(KH kh, int n){
    int tong;
    for(int i=1; i<=n; i++){
            tong = tong + tinhtien(kh);
    };
    printf("Tong so tien nha san xuat thu duoc tu %d khach hang : %d", &n, &tong);
    return tong;
};


int timmax(KH kh[], int n){
    int max;
    max = chiso(kh[1]);
    for(int i=2; i<= n; i++){
        if(max < chiso(kh[i])){
            max = chiso(kh[i]);
        }
    };
    printf("Khach hang co chi so tieu thu lon nhat:\n");
    for(int i=1; i<=n; i++){
        if(chiso(kh[i]) == max){
            printf("%20s||%10s||%20s||%4d\n", kh[i].tenkh, kh[i].makh, kh[i].diachi, chiso(kh[i]) );
        }
    };
    printf("--------------------------------------------------------------------\n");
};


int SXvainTT(KH kh[], int n){
    for(int i=1; i<= n-1; i++){
        for(int j=i+1; j<= n; j++){
            if(tinhtien(kh[i]) < tinhtien(kh[j])){
                KH temp = kh[i];
                kh[i] = kh[j];
                kh[j] = temp;
            }
        }
    };
    printf("\nIn ra danh sach:\n");
    printf("--------------------------------------------------------------------\n");
    printf("|%3s|%20s|%20s|%20s|\n","STT","  Ho ten  ","Chi so tieu thu", "So tien phai tra");
    for(int i=1; i <= n; i++){
        printf("|%3d|%20s|%20d|%20d|\n",i, kh[i].tenkh, chiso(kh[i]), tinhtien(kh[i]));
    };
    printf("--------------------------------------------------------------------\n");

};

int main(){
    KH kh[100];
    int n;
    printf("So khach hang:");
    scanf("%d", &n);

    nhapTT(kh, n);
    timmax(kh, n);
    SXvainTT(kh, n);

};

