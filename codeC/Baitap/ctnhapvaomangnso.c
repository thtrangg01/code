#include<stdio.h>
int main(){
    int n;
    printf("Nhap n:");
    scanf("%d", &n);
    char a[1000];
    // số lớn nhất
    printf("\nMang %d so la:",n);
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int max = a[0];
    for (int i=0; i<n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    printf("\nGia tri lon nhat: %d ", max);
    //số nhỏ nhất
    int min = a[1];
    for (int i=0; i<n; i++){
        if (a[i] < min){
            min = a[i];
        }
    }
    printf("\nGia tri nho nhat: %d ", min);
    // tổng
    int tong = 0;
    for (int i=0; i <n; i++){
        if ( a[i] % 2 !=0){
            tong += a[i];
        }
    }
    printf("\n Tong cac so le: %d ", tong);
    // sắp xếp
    for (int i=0; i<n; i++){
        for (int j= i+1; j<n; j++){
            if (a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j]=temp;
            }
        }
    }
    printf ("\n Thu tu tang dan la: ");
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    //Đếm số âm, số dương, sắp xếp:
    int count = 0;
    printf("\n So cac so am la: ");
    for (int i=0; i<n; i++){
        if (a[i]<0){
            count++;
        }
        printf("%d ", count);
        return 0;
    }
    printf("\n So cac so duong la: ");
    for (int i=0; i<n; i++){
        if (a[i]>0){
            count++;
        }
        printf("%d ", count);
        return 0;
    }
    printf("\n So cac so 0 la: ");
    for (int i=0; i<n; i++){
        if (a[i]==0){
            count++;
        }
        printf("%d ", count);
        return 0;
    }




}
