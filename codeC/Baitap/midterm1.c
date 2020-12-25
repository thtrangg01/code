#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    int attendance;
    int midterm1;
    int midterm2;
    int final;
} student;
int main () {
   student students[5],x;
   FILE *fp = fopen("students.dat", "w+");
    for(int i=0;i<=4;i++){
        printf("Enter student%d's id:",i+1);
        scanf("%d",&students[i].id);
        printf("Enter student%d's name:",i+1);
        scanf("%s",students[i].name);
        printf("Enter student%d's score (attendance, midterm1, midterm2, final):",i+1);
        scanf("%d%d%d%d", &students[i].attendance, &students[i].midterm1,&students[i].midterm2,&students[i].final);
        fwrite(&students[i], sizeof (student), 1, fp);
    }
   fclose(fp);
   fp = fopen("students.dat", "r");
   char highestStudentName[50];
   int highestStudentScore=0;
   for(int i=0;i<=4;i++){
       fread(&x, sizeof (student), 1, fp);
       float avgScore= x.attendance*0.1 + x.midterm1*0.2+x.midterm2*0.2+x.final*0.5;
      printf("%s %f\n",x.name,avgScore);
       if(avgScore>highestStudentScore){
           strcpy(highestStudentName,x.name);
           highestStudentScore = avgScore;
       }
   }
   fclose(fp);
   printf("Student with the highest average score:");
   printf("%s",highestStudentName);
   return(0);
}
