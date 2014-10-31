#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct friends_list{
    char name[13];
    char sex[10];
    char tel[13];
};
int Count = 0;
void add_friend(struct friends_list friends[]);
void search_friend(struct friends_list friends[], char *name);
void change_friend(struct friends_list friends[], char *name);
void show_friend(struct friends_list friends[]);
int main(void)
{
    int choice;
    char name[13];
    struct friends_list friends[50];
    printf("                     Friends list\n");
    do{
    printf("Please choice the number:\n");
    printf("1: add   2:search   3:change   4:show friend    5:esc\n");
    scanf("%d", &choice);
    switch(choice){
    case 1: add_friend(friends); break;
    case 2: printf("Please input the name:\n");
            scanf("%s", name);
            search_friend(friends, name); break;
    case 3: printf("Please input the name what you'll change:\n");
            scanf("%s", name);
            change_friend(friends, name); break;
    case 4: show_friend(friends); break;
    case 5: printf("Thank you!"); break;
    }
    }while(choice != 5);
    return 0;
}
void add_friend(struct friends_list friends[])
{
    struct friends_list h;
    if(Count == 50){
        printf("The friends list is full!\n");
    }
    printf("Please input the name:\n");
    scanf("%s", h.name);
    printf("Please input the Sex:\n");
    scanf("%s", h.sex);
    printf("Please input the Tel:\n");
    scanf("%s", h.tel);
    printf("Ok! The friend is saved!\n");
    friends[Count] = h;
    Count ++;
}
void search_friend(struct friends_list friends[], char *name)
{
    int i, flag = 0;
    if(Count == 0){
        printf("The friends list is empty!\n");
    }
    for(i = 0; i < Count; i++){
        if(strcmp(name, friends[i].name) == 0){
            flag = 1;
            break;
        }}
        if(flag == 1){
            printf("Name:%s   Sex:%s    Tel:%s\n", friends[i].name, friends[i].sex, friends[i].tel);
        }
        else printf("The friend what you search is NONE!\n");


}
void change_friend(struct friends_list friends[], char *name)
{
    int i, flag = 0;
    if(Count == 0)
        printf("The friends is empty, So you can't change anyone!\n");
    for(i = 0; i < Count; i++){
        if(strcmp(name, friends[i].name) == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("The original friend is:\nName:%s   Sex:%s    Tel:%s\n", friends[i].name, friends[i].sex, friends[i].tel);
        printf("Please input the information what you'll changed!\n");
        printf("Please input the new name:\n");
        scanf("%s", friends[i].name);
        printf("Please input the new sex:\n");
        scanf("%s", friends[i].sex);
        printf("Please input the new Tel:\n");
        scanf("%s", friends[i].tel);
        printf("Ok! What you input is saved!\n");
    }else printf("The frieng what you want change is NONE!£¬So, you can't change!\n");
}
void show_friend(struct friends_list friends[])
{
    int i;
    if(Count == 0)
        printf("No friend in friend list! You can add friend!\n");
    for(i = 0; i < Count; i++){
        printf("Name:%s   Sex:%s   Tel:%s\n", friends[i].name, friends[i].sex, friends[i].tel);
    }
}
