#include <stdio.h>
int main()
{
    int nam;
    printf ("Moi ban nhap vao nam sinh: ");
    scanf ("%d", &nam);

    int can(string b){
    string b = nam%10;
    switch (b) {
        case 0: b= "Canh"; break;
        case 1: b= "Tan"; break;
        case 2: b= "Nham"; break;
        case 3: b= "Quy"; break;
        case 4: b= "Giap"; break;
        case 5: b= "At"; break;
        case 6: b= "Binh"; break;
        case 7: b= "Dinh"; break;
        case 8: b= "Mau"; break;
        case 9: b= "Ky"; break;
    }
    return b;
    }
    int chi(string a){
    string a = nam%100;
    switch (a%12) {
        case 0: a= "Ti"; break;
        case 1: a= "Suu"; break;
        case 2: a= "Dan"; break;
        case 3: a= "Mao"; break;
        case 4: a= "Thin"; break;
        case 5: a= "Ty"; break;
        case 6: a= "Ngo"; break;
        case 7: a= "Mui"; break;
        case 8: a= "Than"; break;
        case 9: a= "Dau"; break;
        case 10: a= "Tuat"; break;
        case 11: a= "Hoi"; break;
    }
    return a;
    }
    printf ("\n %d la nam %f %f ", nam, b, a);
    return 0;





}
