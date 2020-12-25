#include <stdio.h>

#define Number 5

typedef struct{
    char id[12];
    char name[24];
    float att, mid1, mid2, finalex;
} sinhvien;


void InputData(sinhvien sv[]){
    for (int i=0; i < Number; i++){
        printf("Students no.%d", i++);
        printf("ID     : "); scanf("%s", sv[i].id);
        printf("Name   : "); scanf("%s", sv[i].name);
        printf("Scores : "); scanf("%f %f %f %f", &sv[i].att, &sv[i].mid1, &sv[i].mid2, &sv[i].finalex);
        printf("-------------------------------------\n");

    };

    printf("-------------------------------------\n");

};


void saveData(){
    FILE *f;
    f = fopen("students.dat", "a");
    for(int i=0; i<Number; i++){
        fprintf(f,"%s %s %.2f %.2f %.2f %.2f", sv[i].id, sv[i].name, sv[i].att, sv[i].)
    }
};

