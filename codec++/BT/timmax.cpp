#include <iostream>
using namespace std;
int main()
{
    int a,b,max;
    cout << "Nhap 2 so a,b :" ;
 	cin>>a>>b;
    if (a<b){
        max = b;
    }else {
        max = a;
    }
    cout << "\n Max = " << max;
    return 0;
}

