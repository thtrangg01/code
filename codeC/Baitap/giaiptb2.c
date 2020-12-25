#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,x,x1,x2;
    printf( "Nhap vao 3 so a,b,c:");
    scanf("%d,%d, %d", &a,&b,&c );
    if (a=0){
        if(b=0){
            if(c=0){
                printf ("\n Phuong trinh vo so nghiem");
            } else { printf("\n Phuong trinh vo nghiem");}
        }else {
            x=-c/b;
            printf ("\n Phuong trinh co 1 nghiem: %f", &x);
        }
    }else {
        double delta = b*b - 4*a*c, cdt;
        cdt = sqrt(delta);
        if(delta = 0) {
            x= -b/(2*a);
            printf("\n Phuong trinh co nghiem kep: %f", &x);
        }else if (delta >0) {
            x1= (-b + cdt)/(2*a);
            x2= (-b - cdt)/(2*a);
            printf("Phuong trinh co 2 nghiem phan biet: %f, %f", &x1, &x2);
        }else {
            printf("\nPhuong trinh vo nghiem");
        }
    }
    return 0;
}
