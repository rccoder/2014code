#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    int ID;
    char name[13];
    int score;
};
int main()
{
   struct student students[10];
   int i, sum = 0, j, temps, tempi;
   char str = 'a';
   for(i = 0; i < 10; i++){
    printf("Please input the %d student's information(ID, NAME, SCORE):\n", i+1);
    scanf("%d%s%d", &students[i].ID, students[i].name, &students[i].score);
    sum += students[i].score;
   }
   for(i = 0; i < 9; i++){
    for(j = 0; j < 9-i; j++){
        if(students[j].score > students[j+1].score){
            temps = students[j].score;
            students[j].score = students[j+1].score;
            students[j+1].score = temps;
            tempi = students[j].ID;
            students[j].ID = students[j+1].ID;
            students[j+1].ID = tempi;
            strcpy(str, students[j].name);
            strcpy(students[j].name, students[j+1].name);
            strcpy(students[j+1].name, str);
        }
    }
   }
   printf("The average is:%.2f\n", sum / 10.0);
   printf("The order about score is:\n");
   for(i = 0; i < 10; i++){
    printf("ID:%d     Name:%s     Score:%d\n", students[i].ID, students[i].name, students[i].score);
   }
    return 0;
}
