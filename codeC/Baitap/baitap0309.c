c// Viết chương trình nhập vào một số nguyên 3 chữ số, in ra cách đọc bằng chữ của số nguyên này.
#include <stdio.h>
#include <string.h>

#define MAX_str 100

void bai_1(){
    int n;
    printf("nhap vao so 100->999:\n");
    scanf("%d",&n);
    if(n>=100 && n<=999){
        switch(n/100){
            case 1: printf("mot tram ");break;
            case 2: printf("hai tram ");break;
            case 3: printf("ba tram ");break;
            case 4: printf("bon tram ");break;
            case 5: printf("nam tram ");break;
            case 6: printf("sau tram ");break;
            case 7: printf("bay tram ");break;
            case 8: printf("tam tram ");break;
            case 9: printf("chin tram ");break;
        }
         switch((n%100)/10){
            case 0:
                if(n%10 != 0)
                    printf("le ");
                break;
            case 1: printf("muoi ");break;
            case 2: printf("hai muoi ");break;
            case 3: printf("ba muoi ");break;
            case 4: printf("bon muoi ");break;
            case 5: printf("nam muoi ");break;
            case 6: printf("sau muoi ");break;
            case 7: printf("bay muoi ");break;
            case 8: printf("tam muoi ");break;
            case 9: printf("chin muoi ");break;
        }
        switch(n%10){
            case 0: break;
            case 1: printf("mot");break;
            case 2: printf("hai");break;
            case 3: printf("ba");break;
            case 4: printf("bon");break;
            case 5: printf("nam");break;
            case 6: printf("sau");break;
            case 7: printf("bay");break;
            case 8: printf("tam");break;
            case 9: printf("chin");break;
        }
    }else bai_1();
}

