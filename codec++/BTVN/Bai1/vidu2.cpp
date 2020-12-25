//Tính sau tổng
/* #include <stdio.h>
#include <conio.h>
main()
{
int n;
printf("\n So phan tu cua day n="); scanf("%d",&n);
float s=0.0;
for (int i=1;i<=n;++i)
s+= 1/i;
printf("S=%0.2f",s);
getch();
}
*/

#include <stdio.h>
#include <conio.h>
main()
{
int n;
printf("\n So phan tu cua day n = "); scanf("%d",&n);
float s=0.0;
for (int i=1;i<=n;++i)
s+= float(1)/float(i); //chuyen kieu theo C++
printf("S=%0.2f",s);
getch();
}
