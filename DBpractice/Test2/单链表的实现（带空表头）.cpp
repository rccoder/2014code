#include <iostream>
#include <stdlib.h>
using namespace std;
struct celltype
{
    char date;
    celltype *next;
};
typedef celltype *LIST;
typedef celltype *position;
position End(LIST L)
{
    position q;
    q = L;
    while(q -> next != NULL)
    {
        q = q -> next;
    }
    return q;
}
void Insert(char x, position p)
{
    position temp;
    temp = p -> next;
    p -> next = new celltype;
    p ->next -> date = x;
    p -> next -> next = temp;

}
void Delete(position p)
{
    position q;
    if(p -> next != NULL)
    {
        q = p -> next;
        p -> next = q -> next;
        delete q;
    }
}
position Locate(char x, LIST L)
{
    position p;
    p = L;
    while(p -> next != NULL)
    {
        if(p -> next -> date == x)
        {
            return p;
        }
        else
        {
            p = p -> next;
        }
    }
    return p;
}
position MakeNull(LIST &L)
{
    position p;
    p -> next = NULL;
    return L;
}
int main()
{
    cout << "单链表" << endl;
    LIST L;
    char ch;
    position p;
    MakeNull(L);
    cout << "请分别输入你在链表中插入的字符和位置" << endl;
    cin >> ch;
    Insert(ch, p);
    return 0;
}
