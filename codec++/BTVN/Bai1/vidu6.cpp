/* Chương trình tìm max của một dãy số nguyên và max của một dãy số thực.
Trong chương trình có 6 hàm: hai hàm dùng để nhậpdãy số nguyên và dãy số thực có tên chung là nhapds, bốn hàm:
tính max 2 số nguyên, tínhmax 2 số thực, tính max của dãy số nguyên,tính max của dãy số thực đƣợc đặt chung mộttên là max. */

#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
void nhapds(int *x, int n);
void nhapds(double *x, int n);
int max(int x,int y);
double max(double x, double y);
void nhapds(int *x, int n)
{
for(int i=0;i<n;++i)
{
cout<<"Phan tu "<<i+1<<" = "; cin>>x[i];
}
}
void nhapds(double *x, int n)
{
for (int i=0;i<n;i++)
{
cout<<"Phan tu "<<i+1<<" = "; cin>>x[i];
}
}
int max(int x, int y)
{
return x>y?x:y;
}
double max(double x, double y)
{
return x>y?x:y;
}
int max(int *x, int n)
{
int s=x[0];
for(int i=1;i<n;++i) s = max(s,x[i]);
return s;
}
double max(double *x, int n)
{
double s=x[0];
for(int i=1;i<n;++i) s = max(s,x[i]);
return s;
}
main()
{
int a[20], n, ni, nd, maxi;
double x[20], maxd;
cout<<"\n So phan tu nguyen n: "; cin>>ni;
cout<<"\n Nhap day so nguyen: "; nhapds(a,ni);
cout<<"\n So phan tu so thuc: "; cin>>nd;
cout<<"\n Nhap day so thuc: "; nhapds(x,nd);
maxi = max(a,ni);
maxd = max(x,nd);
cout<<"\n Max day so nguyen ="<<maxi;
cout<<"\n Max day so thuc="<<maxd;
getch();
}
