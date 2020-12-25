 // Chương trình sau sử dụng hàm inline để tính chu vi và diện tích hình chữ nhật.
#include <iostream>
#include <conio.h>
inline void dtcvhcn(int a,int b,int &dt,int &cv)
{
dt=a*b;
cv=2*(a+b);
}

using namespace std;

main()
{
int a[20], b[20], cv[20], dt[20], n;
cout<<"\n So hinh chu nhat : "; cin>>n;
for(int i=0;i<n;++i)
{
cout<<"\n Nhap 2 canh cua hinh chu nhat "<< i + 1<<":";
cin>>a[i]>>b[i];
dtcvhcn(a[i],b[i],dt[i],cv[i]);
}
for(int i=0;i<n;++i)
{
cout<<"\n\n Hinh chu nhat thu "<<i+1<<":";
cout<<"\n Do dai hai canh "<<a[i]<<" va "<<b[i];
cout<<"\n Dien tich S = "<<dt[i];
cout<<"\n Chu vi P = "<<cv[i];
}
getch();
}
