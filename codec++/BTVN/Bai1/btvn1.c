/* Viết chƣơng trình thực hiện các yêu cầu sau đây:
 Nhập dữ liệu cho các sinh viên (dùng mảng động), các thông tin của sinh viên bao gồm:
mã sinh viên, họ tên, lớp, điểm trung bình.
 Chương trình có sử dụng toán tử new và delete.
 In ra danh sách sinh viên có sắp xếp vị thứ theo điểm trung bình.
 In ra những sinh viên có điểm trung bình cao nhất. */


#include <iostream.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct SV {
    int MSV;
    char Hoten[32];
    char Lop[12];
    double DTB;
} ;

int main() {
    int n;
    cout << "So sinh vien n = " ; cin >> n;
    SV *sv = new SV[n];
    cout << "\n====> Nhap du lieu <====\n";
    for (int i = 0; i < n; ++i) {
        cout << "\n-> Thi sinh thu "<< i+1 <<" <-";
        cout << "\nHo ten : "; cin.ignore(1);
        cin.get(sv[i].Hoten,32);
        cout << "\nMa sinh vien : ";
        cin >> sv[i].MSV;
        cout <<"\nLop : "; cin.ignore(1);
        cin.get(sv[i].Lop,12);
        cout >> "\nDiem trung binh : ";
        cin >> sv[i].DTB;
    }
    //in ra bảng điểm giảm dần
    for (int i = 0; i < n-1; ++i)
    for(int j = 0; j < n; ++j){
        if(sv[i].DTB < sv[j].DTB){
            SV tg = sv[i];
            sv[i] = sv[j];
            sv[j] = tg;
        }
    }
    cout << "\n====> Danh sach thi sinh <====\n";
    for (int i = 0; i < n; ++i){
        cout <<"\n"<<setw(24)<<sv[i].Hoten<<setw(8)<<sv[i].MSV<<setw(12)<<sv[i].Lop<<setw(4)<<sv[i].DTB <<endl;
    }
    //in ra sv có điểm trung bình cao nhất
    cout << "\n---> Thi sinh co diem trung binh cao nhat <---\n"
    <<"     STT     MSV           HoTen     Lop     DTB" <<endl;
    for(int i = n-1; i >= 0; i--){
        if(sv[i].DTB == sv[n-1].DTB){
            cout <<setw(8)<< i << setw(8) << sv[i].MSV << setw(16) << sv[i].Hoten << setw(8) << sv[i].Lop << setw(8) << sv[i].DTB << endl;
        }
        else break;
    }
    delete sv;
    getch();

}
