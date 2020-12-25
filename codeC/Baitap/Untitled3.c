#include<stdio.h>
#include<conio.h>
int main()
{
double MTS,T,L,H,KV;
char k;
printf("Nhap vao ma thi sinh: ");
scanf("%d", &MTS);
char HT[100];
printf("Nhap ho ten: ");
scanf("%s", HT);
printf("Nhap diem toan: ");
scanf("%d", &T);
printf("Nhap diem ly: ");
scanf("%d", &L);
printf("Nhap diem hoa: ");
scanf("%d", &H);
double TONG = T + L + H;
printf("Nhap khu vuc: ");
scanf("%s", k);
do
{
if(k = '3')
   {TONG = TONG + 2;}
if(k = '2')
   {TONG = TONG + 1.5;}
if(k = '1')
   {TONG = TONG + 1;}
printf("Tong la: %f\n", TONG);
}
while(k == '1' || k == '2' || k == '3');
{if(TONG >= 22.5)
   {printf("Trung tuyen");}
else
   {printf("Truot");}
}
return 0;
}
