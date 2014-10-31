#include <stdio.h>
//程序问题比较多，在学了结构体之后要加以改变，使之趋于完美状态
void Append_record(long ID[], float student_score[], int n);
void Total_Average(float student_score[], int number);
void Sort_with_score(long ID[], float student_score[], int number);
void Sort_with_id(long ID[], float student_score[], int number);
void Search_by_id(long ID[], float student_score[], int number);
void Analysis(float student_score[], int number);

int main()
{
    int number, choose;
    long ID[10];
    int student_score[30];
    printf("Input student number(n<30):");
    scanf("%d", &number); // input the sum of the student
    do
    {
        printf("\nManagement for Student's scores\n"); // print the menu
        printf("1.Append record\n2.Calculate total and average score of course\n3.Sort in descending order by score\n4.Sort in ascending order by score\n5.Search by number\n6.Statistic analysis\n0.Exit\n");
        printf("Please Input your choice:");
        scanf("%d", &choose);
        switch(choose)
        {
        case 1:
            Append_record(ID, student_score, number);
            break;
        case 2:
            Total_Average(student_score, number);
            break;
        case 3:
            Sort_with_score(ID, student_score, number);
            break;
        case 4:
            Sort_with_id(ID, student_score, number);
            break;
        case 5:
            Search_by_id(ID, student_score, number);
            break;
        case 6:
            Analysis(student_score, number);
            break;
        default:
            printf("Input error!\n");
            break;
        }
    }
    while(choose != 0); // if the number of input is "0", the prgraming will exit
    return 0;
}

void Append_record(long ID[], float student_score[], int number)
{
    int i;
    printf("Input student's ID and score:\n");
    for(i = 0; i < number; i++)
    {
        scanf("%ld %f", &ID[i], &student_score[i]);//input the id and score
    }
}

void Total_Average(float student_score[], int number)
{
    int i;
    float sum_score = 0;
    for(i = 0; i < number; i++)
    {
        sum_score += student_score[i];//the sum of the score
    }
    printf("sum=%.0f, aver=%.2f\n", sum_score, sum_score / number);
}

void  Sort_with_score(long ID[], float student_score[], int number)
{
    int i, j, tep_score, tep_id;
    for(i = 1; i < number; i++)
    {
        for(j = 0; j < number-i; j++)
        {
            if(student_score[j] < student_score[j+1])
            {
                tep_score = student_score[j];
                student_score[j] = student_score[j+1]; //give a new order by student score
                student_score[j+1] = tep_score;

                tep_id = ID[j];
                ID[j] = ID[j+1];
                ID[j+1] = tep_id;
            }
        }
    }
    printf("Sort in desceding order by score:\n");
    for(i = 0; i < number; i++)
    {
        printf("%ld\t%.0f\n", ID[i], student_score[i]);
    }
}

void Sort_with_id(long ID[], float student_score[], int number)
{
    int i, j, tep_score, tep_id;
    for(i = 1; i < number; i++)
    {
        for(j = 0; j < number-i; j++)
        {
            if(ID[j] > ID[j+1])
            {
                tep_score = student_score[j];
                student_score[j] = student_score[j+1];
                student_score[j+1] = tep_score;   ////give a new order by student id

                tep_id = ID[j];
                ID[j] = ID[j+1];
                ID[j+1] = tep_id;
            }
        }
    }
    printf("Sort in ascending order by number:\n");
    for(i = 0; i < number; i++)
    {
        printf("%ld\t%.0f\n", ID[i], student_score[i]);
    }
}

void Search_by_id(long ID[], float student_score[], int number)
{
    int i, flag = 0;
    long search_id;
    printf("Please input the number you want to search:");
    scanf("%d", &search_id);
    for(i = 0; i < number; i++)
    {                                           //search by the ID
        if(search_id == ID[i])
        {
            printf("%ld\t%.0f\n", ID[i], student_score[i]);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("Not found!\n");//NO FOUND
}

void Analysis(float student_score[], int number)
{
    int i;
    int count[6] = {0,0,0,0,0,0};
    for(i = 0; i < number; i++)
    {
        if(student_score[i] < 60)
            count[0] ++;
        else if(student_score[i] <= 69)
            count[1] ++;
        else if(student_score[i] <= 79)// judge the degree
            count[2] ++;
        else if(student_score[i] <= 89)
            count[3] ++;
        else if(student_score[i] <= 100)
            count[4] ++;
        if(student_score[i] == 100)
            count[5] ++;
    }
    printf("<60\t%d\t%.2f%%\n", count[0], (float)count[0] * 100 / number);
    printf("%d-%d\t%d\t%.2f%%\n", 60, 69, count[1], (float)count[1] * 100 / number);
    printf("%d-%d\t%d\t%.2f%%\n", 70, 79, count[2], (float)count[2] * 100 / number);
    printf("%d-%d\t%d\t%.2f%%\n", 80, 89, count[3], (float)count[3] * 100 / number);
    printf("%d-%d\t%d\t%.2f%%\n", 90, 99, count[4], (float)count[4] * 100 / number);
    printf("%d\t%d\t%.2f%%\n", 100, count[5], (float)count[5] * 100 / number);
}
