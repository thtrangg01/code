 /*Ví dụ: Nhập một danh sách n thí sinh (n<=100).
Dữ liệu mỗi thí sinh gồm họ tên, các điểm thi môn
1, môn 2, môn 3. Sau đó in danh sách thí sinh theo
thứ tự giảm dần của tổng điểm. */

#include <iostream> // thu vien cout, cin
#include <conio.h> // thu vien getch()
#include <iomanip> // thu vien setw
#include <string.h> // thu vien ham chuoi ky tu

using namespace std;

main()
{
    struct {
        char ht[25];
        float d1, d2, d3, td;
        }
    ts[100], tg;
    int n, i, j;
    cout << "So thi sinh: "; cin>>n; cin.ignore(1);
    for (i=0;i<n;++i){
        cout << "\n Thi sinh thu "<< i+1;
        cout << "\n Ho ten : ";
        cin.get(ts[i].ht,25); cin.ignore(1);
        cout << " Diem cac mon thi : ";
        cin>>ts[i].d1>>ts[i].d2>>ts[i].d3;
        cin.ignore(1);
        ts[i].td=ts[i].d1+ts[i].d2+ts[i].d3;
}
    for (i=0;i<n-1;++i)
    for(j=i+1;j<n;++j)
    if(ts[i].td<ts[j].td) {
        tg=ts[i];
        ts[i]=ts[j];
        ts[j]=tg;
        }
    cout<< "\ Danh sach thi sinh sau khi sap xep :";
    for (i=0;i<n;++i){
        cout<<"\n"<< setw(25)<<ts[i].ht<<setw(5)<< ts[i].td ;
        }
    getch();
}



