/* Viết chƣơng trình minh hoạ cách dùng new để cấp phát bộ nhớ chứa n thí sinh.
Mỗi thí sinh là một cấu trúc gồm các trƣờng ht(họ tên), sobd(số báo danh), và td(tổng điểm).
Chƣơng trình sẽ nhập n, cấp phát bộ nhớ chứa n thí sinh, kiểm tra lỗi cấp phát bộnhớ,
nhập n thí sinh, sắp xếp thí sinh theo thứ tự giảm dần của tổng điểm,
in danh sách thí sinh sau khi sắp xếp, giải phóng bộ nhớ đã cấp phát. */


#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>

struct TS   {
    char ht[20];
    long sobd;
    float td;
};

using namespace std;


main()
{
    TS *ts;
    int n;
    cout<<"\n So thi sinh n = "; cin>>n;
    ts = new TS[n+1];
    if (ts == NULL)
    {
        cout << "\n Loi cap phat vung nho";
        getch();
        exit(0);
    }
    for (int i=0;i<n;++i)
    {
        cout << "\n Thi sinh thu "<<i+1;
        cout<< "\n Ho ten : ";
        cin.ignore(1);
        cin.get (ts[i].ht,20); //cin(ts[i].ht);
        cout << " So bao danh : ";
        cin>> ts[i].sobd;
        cout<< " Tong diem : ";
        cin>>ts[i].td;
    }
    for (int i=0;i<n-1;++i)
    for (int j=i+1;j<n;++j)
    if (ts[i].td<ts[j].td)
    {
        TS tg=ts[i];
        ts[i]=ts[j];
        ts[j]=tg;
    }
    for (int i=0;i<n;++i)
    cout << "\n Danh sach thi sinh : " <<
    setw(20)<<ts[i].ht<<setw(6)<<ts[i].td;
    delete ts;
    getch();
}



