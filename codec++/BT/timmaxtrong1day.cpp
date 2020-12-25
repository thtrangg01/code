/*#include <iostream>
using namespace std;
long long n, a[1000001], ans= -1e9;
int main() {
    cout << "Nhap n :";
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin>> a[i];
        ans= max(ans,a[i]);
    }
    cout << ans << endl;
    return 0;

} */
#include <iostream>
using namespace std ;
int main()
{
    int n;
    cout << "So luong phan tu trong day:" << endl;
    cin >> n;
    int a[n];
    int max = INT_MIN;
    for (int i=0; i<n; i++) {
        cout << "\n Phan tu thu:" << i+1 << endl;
        cin >> a[i];
        if(max<a[i]) {max = a[i];
        }
    }
    cout << "\n Gia tri lon nhat: " << max <<endl;
    return 0;
}
