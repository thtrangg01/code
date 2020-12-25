#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float a,b,c,x,x1,x2;
    cout << "Nhap vao 3 so a,b,c:";
    cin >> a,b,c;
    if (a=0){
        if(b=0){
            if(c=0){
                cout << "\n Phuong trinh vo so nghiem";
            } else { cout <<"\n Phuong trinh vo nghiem";}
        }else {
            x=-c/b;
            cout << "\n Phuong trinh co 1 nghiem:" << x;
        }
    }else {
        double delta = b*b - 4*a*c, cdt;
        cdt = sqrt(delta);
        if(delta = 0) {
            x= -b/(2*a);
            cout << "\n Phuong trinh co nghiem kep:" << x;
        }else if (delta >0) {
            x1= (-b + cdt)/(2*a);
            x2= (-b - cdt)/(2*a);
            cout << "\n Phuong trinh co 2 nghiem phan biet:" << x1, x2;
        }else {
            cout << "\n Phuong trinh vo nghiem";
        }
    }
    return 0;
}
