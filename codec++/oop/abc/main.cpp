#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


class Person{
public: // được truy cập trực tiếp, sử dụng tùy ý
    int a;

protected:  //bảo vệ so với bên ngoài, các con kế thừa đều có quyền truy cập trực tiếp
    int b;

private: // không được truy cập trực tiếp, kể cả con
    int c;

};
/* quy ước đặt tên class : viết hoa chữ cái đầu class LopHoc {};*/

