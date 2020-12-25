/* viết chương trình nhập vào 3 số, kiểm tra xem 3 số có trong khoảng từ pi đến 2pi hay không:
input : 3.4; 5.0; 3.2
output: all of three number is in the range pi - 2pi
input : 1.4; 2.4; 4.5
output: not all of three number is in the range pi - 2pi
#include <stdio.h>
int main(){
    int pi = 3.14;
    float a,b,c;
    printf("Moi ban nhap 3 so a,b,c: ");
    scanf("%f %f %f", &a, &b, &c);
    if ( pi < a && a < 2*pi && pi < b && b < 2*pi && pi < c && c < 2*pi  )
        printf(" all of three number is in the range pi - 2pi ");
    else
        printf(" not all of three number is in the range pi - 2pi ");
    return 0;

} */

// Viết chương trình nhập vào 1 số âm, 1 số dương, ( nếu k phải thì in ra invalid input). Ktra và in ra số nào gần 0 hơn.
/*#include <stdio.h>
int main(){
    int a,b;
    printf("Nhap 2 so a,b: ");
    scanf("%d %d", &a, &b);
    if (a*b > 0)
        printf("Invalid input");
    else
        if ( abs(a) < abs(b))
            printf("%d", a);
        else
            printf("%d", b);
    return 0;

} */

// Viết chương trình dưới dạng hàm để dịch trái 1
#include <stdio.h>
void doicho (int *a, int *b, int *c, int *d){
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = *d;
    *d = temp;
}
int main(){
    int a, b, c, d;
    printf("Input : ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    doicho (&a, &b, &c, &d);
    printf("Output : ");
    printf("%d %d %d %d", a, b, c, d);
    return 0;

}

