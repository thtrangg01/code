/* Xây dựng cấu trúc cho M sinh viên dự thi vào DHKTQD. Mỗi sinh viên có các thông tin sau:
Họ tên, quê quán, năm sinh, điểm toán, điểm lý, điểm hóa.
Viết chương trình :
Câu 1: Nhập thông tin cho từng thí sinh
Câu 2: Tính điểm trung bình ba môn của từng sv
Câu 3: Đếm xem có bn sinh viên có điểm trung bình từ 8.0 trở lên và không có môn nào dưới 5.
Câu 4: Tính tỉ lệ những sinh viên đạt điểm 10 môn toán
Câu 5: Sắp xểp theo thứ tự tăng dân và in ra dưới dạng bảng
STT | Họ Tên | Quê quán | Điểm trung bình */
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

struct sinhvien{
    char hoten[32];
    char quequan[24];
    int namsinh;
    float toan, ly, hoa;
};

typedef struct sinhvien SV;


void NhapDL(SV sv[], int n){
    printf("---------Nhap Du Lieu---------\n");
    for (int i=0; i<n; i++){
        printf("Ho ten cua sinh vien thu %d:", i+1);
        fflush(stdin); gets(sv[i].hoten);
        printf("Que quan cua sinh vien thu %d:", i+1);
        fflush(stdin); gets(sv[i].quequan);
        printf("Nam sinh cua sinh vien thu %d:", i+1);
        scanf("%d", &sv[i].namsinh);
        printf("Diem toan cua sinh vien thu %d:", i+1);
        scanf("%f", &sv[i].toan);
        printf("Diem ly cua sinh vien thu %d:", i+1);
        scanf("%f", &sv[i].ly);
        printf("Diem hoa cua sinh vien thu %d:", i+1);
        scanf("%f", &sv[i].hoa);
        printf("--------------------------------------------------\n");
    };
    printf("----------------------------------------------------------------\n");
    printf("\n");

}


float TB(SV sv){
    float TB = (sv.toan + sv.ly + sv.hoa) / 3 ;
    return TB;
}


int dem(SV sv[], int n){
    int dem =0;
    for(int i=0; i<n; i++){
        if( TB(sv[i]) > 8.0 && sv[i].toan >=5 && sv[i].ly >=5 && sv[i].hoa >= 5){
            dem++;
        }
    };
    printf("So sinh vien co diem TB > 8.0 va khong co mon nao duoi 5 : %d", dem);
    printf("\n----------------------------------------------------------------\n");
    printf("\n");
}


float tile(SV sv[], int n){
    int count;
    for(int i=0; i<n; i++){
        if( sv[i].toan == 10){
            count++;
        };
    };
    float tile = count / n;
    return tile;
}


void sapxep(SV sv[], int n){
    SV temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(TB(sv[j]) < TB(sv[i])){
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    };
    printf("---------In ra danh sach---------\n");
    printf("%3s|%24s|%24s|%5s\n", "STT", "Ho ten", "Que quan", "DTB");
    for(int i=0; i<n; i++){
        printf("%3d|%24s|%24s|%5.2f\n", i+1, sv[i].hoten, sv[i].quequan, TB(sv[i]));
    };
}


void main(){
    SV sv[1000];
    int n;
    printf("So sinh vien thi vao DHKTQD : ");
    scanf("%d", &n);

    NhapDL(sv, n);
    dem(sv,n);
    sapxep(sv,n);
}
