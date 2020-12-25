#include <stdio.h>
#include <conio.h>
#include <string.h>

struct canbo{
    char ten[32];
    char gt[4];
    int tuoi;
    char donvi[24];
    float hsl;
    float hscv;
};
typedef struct canbo CB;


void nhapDL(CB cb[], int n){
    for(int i=1; i<=n; i++){
        printf("--nhap dl---\n");
        fflush(stdin);
        printf("ten:");gets(cb[i].ten);
        fflush(stdin);
        printf("gioi tinh:");gets(cb[i].gt);
        fflush(stdin);
        printf("Don vi:");gets(cb[i].donvi);
        printf("hsl:");scanf("%f",&cb[i].hsl);
        printf("hscv:");scanf("%f",&cb[i].hscv);
    }
};


float luong(CB cb){
    float luong;
    luong = (cb.hsl+cb.hscv)*1150000;
    return luong;
}


float tbh(CB cb){
    return 0.05*luong(cb);
}


float tdl(CB cb){
    return luong(cb) - tbh(cb);
}


void inDL(CB cb[], int n){

    printf("-----\n");
    for(int i = 1; i<=n; i++){
        if(cb[i].hscv>2){
            printf("%4s|%2d|%12s|%3.2f\n",cb[i].ten,cb[i].tuoi,cb[i].donvi,cb[i].hscv);
        }
    }
}


void sapxep(CB cb[], int n){
    CB temp;
    for(int i=1;i<=n-1;i++)
    for(int j=i+1;j<=n;j++){
            if(tdl(cb[i]) < tdl(cb[j])){
                temp = cb[i];
                cb[i] = cb[j];
                cb[j] = temp;
            }
        };
    printf("\n-----In ra danh sach-----\n");
    printf("----------------------------------------------------------------------\n");
    printf("%3s|%12s|%4s|%8s\n", "STT", "Ho ten", "Tuoi", "TDL");
    for(int i=1;i<=n;i++){
        printf("%3d|%12s|%4d|%8f\n", i, cb[i].ten, cb[i].tuoi, tdl(cb[i]));
    };
    printf("----------------------------------------------------------------------\n");
}


void main(){
    CB cb[200];
    int n;
    printf("nhap n:");scanf("%d",&n);

    nhapDL(cb,n);

    /*printf("%20s|%15.2f\n","ten","luong");
    for (int i=1; i<=n; i++){
        printf("%20s|%15.2f\n",cb[i].ten,luong(cb[i]));
    }*/

    inDL(cb,n);
    sapxep(cb,n);

}
