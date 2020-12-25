/* cho mô tả đối tượng gồm 2 số nguyên a và b. Hãy xây dựng một chương trình theo nững yêu cầu sau:
1. định nghĩa lớp đối tượng trên với hàm tạo, hủy, nhập, in đối tượng 2 số nguyên đó dưới dạng cặp (a,b)
2. định nghĩa hàm đổi số a theo cơ số b
3. định nghĩa toán tử cộng 2 đối tượng trên theo nguyên tắc : thành phần thứ nhất cộng thành phần thứ nhất
thành phần thứ 2 cộng thành phần thứ 2
4. định nghĩa thành phần cho biết tổng số các đối tượng
5.tạo ra một danh sách gồm n đối tượng trên, sắp xếp danh sách theo thứ tự giảm dần của (a + b) */

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;


class MyClass{
public:
    int a,b;
    static int numObj ; // câu 4

public:
    // câu 1
    MyClass(){
        numObj++;
    }; //tạo
    MyClass( int input_a, int input_b){
        this->a = input_a;
        this->b = input_b;
    };

    ~MyClass(){
        numObj--;
    }; //hủy

    void set0bj(){
        cout << "Enter a = ";
        cin >> a;
        cout << "Enter b = ";
        cin >> b;
    }; //nhập

    void showObj(){
        cout << "(" << this->a << "," << this->b <<")" << endl;
    }; // in


    //câu 2
    void trans(){
        int temp = this->a;
        this->a = this-> b;
        this->b = temp;
    };


    //câu 3
    void sum(MyClass object){
        int x = this->a + object.a;
        int y = this->b + object.b;
        cout << "(" << x << "," << y <<")" << endl;
    };


    //câu 4
    static void showNumObj(){
        cout << numObj << endl ; // hiển thị số lượng obj
    }

    //câu 5




};


int MyClass::numObj = 0; // câu 4

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;

    MyClass listObj[n]; // tạo danh sách gồm n phần tử

    for (int i=0; i<n;i++){
        listObj[i].set0bj();
    }

    MyClass::showNumObj();
    MyClass::showObj();

    return 0;
}
