/* Xây dựng cấu trúc đẻ quản lí thông tin cho N quyển sách. Mỗi quyển sách bao gồm các thông tin sau: Tên sách; tên tác giả,
nhà xuất bản; giá tiền. Viết chương trình thực hiện các chức năng sau:
1. Nhập thông tin cho từng quyển sách.
2. Tính tổng giá tiền của N quyển sách trên.
3. Đếm xem có bao nhiêu cuốn sách xuất bản sau năm 2010.
4. Tìm và in ra thông tin những quyển sách có giá tiền cao nhất.
5. Sắp xếp tên các cuốn sách theo thứ tự điền và in dưới dạng bảng sau của các quyển sách theo thứ tự vừa sắp xếp.*/
#include <stdio.h>
#include <conio.h>
#include <string.h>


struct quyensach{
    char tensach[32];
    char tacgia[32];
    char nxb[32];
    float gia;
};


typedef struct quyensach QS;


void nhapDL(QS qs[], int n){
    printf("-----Nhap thong tin cho sach-----\n");
    for (int i=1; i<=n; i++){
        printf("Ten cuon sach thu %d", &i);
        fflush(stdin); gets(qs[i].tensach);
        printf("Ten tac gia : ");
        fflush(stdin); gets(qs[i].tacgia);
        printf("Nha xuat ban : ");
        fflush(stdin); gets(qs[i].nxb);
        printf("Gia cuon sach : ");
        scanf("%f", &qs[i].gia);
    };
    printf("-------------------------------------------\n");
}



