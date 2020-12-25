#include <stdio.h>

typedef struct{
    char ten[50];
    int diemdanh;     // 10%  Max = 4  => 10    3 => 9   2 => 8   1=> 7  0 => 0;
    float thigiuaky;  // 20%
    float thicuoiky;  // 70%
    float diemtongket; //100%
} sinhvien;

void nhapDsSinhVien(sinhvien dsSinhVien[40],int slsv){
//   for (int i = 0;i < slsv;i++){
//       printf("Sinh vien %i:\n",i+1);
//       printf("Ho va ten Sinh vien:");
//       scanf("%s",dsSinhVien[i].ten);
//       // fflush(stdin);
//       printf("Diem danh/thigiuaky/thicuoiky:");
//       scanf("%d %f %f",&dsSinhVien[i].diemdanh,&dsSinhVien[i].thigiuaky,&dsSinhVien[i].thicuoiky);
//   }

    strcpy(dsSinhVien[0].ten,"Minh");dsSinhVien[0].diemdanh=3;dsSinhVien[0].thigiuaky=7;dsSinhVien[0].thicuoiky=5;
    strcpy(dsSinhVien[1].ten,"Tuan");dsSinhVien[1].diemdanh=4;dsSinhVien[1].thigiuaky=8;dsSinhVien[1].thicuoiky=7.5;
    strcpy(dsSinhVien[2].ten,"Huong");dsSinhVien[2].diemdanh=2;dsSinhVien[2].thigiuaky=2;dsSinhVien[2].thicuoiky=8;


    for (int i = 0;i < slsv;i++){
        int diemchuyencan=0;
        if(dsSinhVien[i].diemdanh>0&&dsSinhVien[i].diemdanh<=4){
            diemchuyencan = dsSinhVien[i].diemdanh+6;
        }
        dsSinhVien[i].diemtongket = 0.1*diemchuyencan+0.2*dsSinhVien[i].thigiuaky+0.7*dsSinhVien[i].thicuoiky;
    }
}

void inDsSinhvien(sinhvien dsSinhVien[40],int slsv){
    for (int i = 0;i < slsv;i++){
        printf("%20s %3d %5.1f %5.1f %5.1f\n",dsSinhVien[i].ten,dsSinhVien[i].diemdanh,dsSinhVien[i].thigiuaky,dsSinhVien[i].thicuoiky,dsSinhVien[i].diemtongket);
    }
}

void sapxepDsSinhvien(sinhvien dsSinhVien[40],int slsv){
    sinhvien svTam;
    for(int i=0;i<slsv-1;i++){
        for(int j=i+1;j<slsv;j++){
            if(dsSinhVien[i].diemtongket<dsSinhVien[j].diemtongket){
                svTam = dsSinhVien[i];
                dsSinhVien[i] = dsSinhVien[j];
                dsSinhVien[j] = svTam;
            }
        }
    }
}
void inTenSinhVienDiemCaoNhat(sinhvien dsSinhVien[40]){
    printf("Sinh vien co diem cao nhat: %s\n",dsSinhVien[0].ten);
}

int main(){
    sinhvien dsSinhVien[40];
    int slsv = 3;
    //printf("So luong sinh vien: ");
    //scanf("%d",&slsv);
    nhapDsSinhVien(dsSinhVien,slsv); //Nhap danh sach sinh vien tu ban phim (Cau A)
    printf("Danh sach sinh vien Sau khi nhap:\n");
    inDsSinhvien(dsSinhVien,slsv);  // In Danh sach sinh vien da nhap (Cau B)
    printf("Danh sach sinh vien Sau khi sap xep:\n");
    sapxepDsSinhvien(dsSinhVien,slsv);
    inDsSinhvien(dsSinhVien,slsv);

    inTenSinhVienDiemCaoNhat(dsSinhVien);
    return 0;
}


