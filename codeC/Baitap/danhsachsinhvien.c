#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct Sinhvien{
    char ten[32];
    int diemdanh; //10% Max=4 => 10; 3 => 9; 2=>8; 1=> 7; 0=> 0;
    float thigiuaki; //20%
    float thicuoiki; //70%
    float diemtongket; //100%
} Sinhvien ;

void nhapDsSinhVien(Sinhvien dsSinhVien[40], int slsv){
    //Viết câu lệnh để nhập danh sách sinh viên từ bàn phím
    for (int i=0; i < slsv; i++){
        printf("Sinh vien %d :\n", i+1);
        printf("Ho va ten Sinh vien: ");
        scanf("%s", dsSinhVien[i].ten);
        printf("Diem danh: ");
        scanf("%d", &dsSinhVien[i].diemdanh);
        printf("Diem thi giua ki: ");
        scanf("%f", &dsSinhVien[i].thigiuaki);
        printf("Diem thi cuoi ki: ");
        scanf("%f", &dsSinhVien[i].thicuoiki);
    }

};

void inDsSinhVien(Sinhvien dsSinhVien[40],int slsv){
    for (int i = 0; i < slsv; i++){
            printf("%20s %3d %5.2f %5.2f \n", dsSinhVien[i].ten,
                   dsSinhVien[i].diemdanh,
                   dsSinhVien[i].thigiuaki,
                   dsSinhVien[i].thicuoiki);
    }

}

int main(){
    Sinhvien dsSinhVien[40];
    int slsv;
    printf(" So luong sinh vien: ");
    scanf("%d", &slsv);
    nhapDsSinhVien(dsSinhVien,slsv);
    inDsSinhVien(dsSinhVien,slsv);

    return 0;
}


