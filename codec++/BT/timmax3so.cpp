#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
int main (int argc, char*argv[])
{
    int a,b,c,max;
    cout << "Nhap 3 so a,b,c:" ;
    cin >>a>>b>>c;
    max=a;
    if (max<b) max=b;
    if (max<c) max=c;
    cout << "\n Gia tri lon nhat cua 3 so la: " << max;
    return 0;
}
