// Biết họ tên, số báo danh, điểm toán, lý, hóa của n thí sinh. Viết ct nhập vào họ tên, sbd, điểm toán,lý hóa của n thí sinh này;
// sắp xếp theo thứ tự giảm dần theo tổng điểm. (Ngoại trừ những thí sinh bị điểm liệt (dùng hàm continue để loại));
//Hiển thị ở cuối cùng thí sinh có số báo danh là NEU010;
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

struct sinhvien{
    char hoten[50];
    char SBD[10];
    float toan, ly, hoa;
    float tong;
};
typedef struct sinhvien SV;
int main(){
    SV sv[MAX], temp;
    int n;
    //nhập dữ liệu sinh viên
    printf("Nhap so sinh vien n = ");
    scanf("%d", &n);
    printf("Du lieu sinh vien: \n");
    fflush(stdin); // xóa đi bộ nhớ tạm thời của chương trình để không tồn tại những giá trị rác ....
    for (int i=0; i<n; i++){
        printf("Ho ten: ");
        gets(sv[i].hoten); // hàm gets cho phép dữ liệu nhập vào có khoảng trống
        fflush(stdin);

        printf("SBD: ");
        gets(sv[i].SBD);

        printf("Diem toan: ");
        scanf("%f", &sv[i].toan);

        printf("Diem ly: ");
        scanf("%f", &sv[i].ly);

        printf("Diem hoa: ");
        scanf("%f", &sv[i].hoa);

        sv[i].tong = sv[i].toan + sv[i].ly + sv[i].hoa;

    }
    //sắp xếp
    for (int i=0; i< n - 1; i++){
        for (int j= i+1; j<n; j++){
            if (sv[i].tong < sv[j].tong){
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    //in ra danh sách
    printf("In ra danh sách: \n");
    printf("SBD\t Hoten\t Toan\t Ly\t Hoa\t Tongdiem\t \n");

    for (int i=0; i<n; i++){
        if (strcmp(sv[i].SBD,"NEU010")==0) continue;
        if( sv[i].toan >0 && sv[i].ly  >0 && sv[i].hoa >0 ){
            printf("%s\t %10s\t %.2f\t %.2f\t %.2f\t %.2f\t\n",sv[i].SBD,sv[i].hoten,sv[i].toan,sv[i].ly,sv[i].hoa,sv[i].tong);
        }
    }
    for(int i=0; i<n; i++){
        if( strcmp(sv[i].SBD,"NEU010") == 0 ){
            printf("%s\t %10s\t %.2f\t %.2f\t %.2f\t %.2f\t\n",sv[i].SBD,sv[i].hoten,sv[i].toan,sv[i].ly,sv[i].hoa,sv[i].tong);
        }
    }
    }




