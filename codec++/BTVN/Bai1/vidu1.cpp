//Ví dụ: Nhập một dãy số thực rồi sắp xếp theo thứ tự tăng dần.
#include <stdio.h>
#include <conio.h>
//#include <alloc.h>
#include <cstdlib>
int main()
{
    int n;
    printf("\n So phan tu cua day n = "); scanf("%d",&n);
    float *x=(float*)malloc((n+1)*sizeof(float));
    for (int i=0;i<n;i++)
        {
            printf("\n X[%d]=",i); scanf("%f",x+i);   //&x[i]
        }
    float tg;
    for(int i=0;i<n-1;++i)
    for (int j=i+1;j<n;++j)
    if (x[i]>x[j])    //(*(x+i)>*(x+j))
        {
            tg = x[i];
            x[i] = x[j];
            x[j] = tg;
        }
    printf("\n Day sau khi sap xep\n");
    for (int i=0;i<n;++i)
        printf("%0.2f ",x[i]);   //*(x+i)
        free(x);
        getch();
}
