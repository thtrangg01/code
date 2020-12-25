#include <stdio.h>
int main(){
    printf("Nhap n va m:");
    int n,m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    printf("Mang:");
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int count = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
                if(a[i][j] %2 ==0 && a[i][j] <20){
                    count ++;
                }
        }
    }
    printf("\ndap an: %d", count);
}
