#include <iostream>
#include <stdlib.h>
#include <stack>
#define N 100
#define MaxSize 1000
using namespace std;
/*
*define a structure about tree
*/
struct node
{
    node * lchild;
    char data;
    node * rchild;
};
typedef node *BTREE;
/*
*define a stack
*/
typedef node * ElemType;
struct Stack
{
    ElemType s[MaxSize];
    int top;
};

void MakeNull(Stack &S)
{
    S.top = -1;
}
void push(Stack &S, ElemType item)
{
    if(S.top == MaxSize-1)
    {
        cout << "��ջ������" << endl;
    }
    else
    {
        S.s[++S.top] = item;
    }
}
ElemType pop(Stack &S)
{
    if(S.top == -1)
    {
        cout << "��ջ" << endl;
    }
    else
    {
        return S.s[S.top --];
    }
}
ElemType peek(Stack &S)
{
    if(S.top == -1)
    {
        cout << "��ջ" << endl;
    }
    else
    {
        return S.s[S.top];
    }
}
void ToTree(char ch[], BTREE &BT)
{
    Stack S;
    MakeNull(S);
    int i = 0;
    struct node *p = BT;//pָBT
    struct node *q = NULL;
    while(ch[i] != '\0')
    {
        if(ch[i] != '(' && ch[i] != ')' && ch[i] != ',')
        {
            //֮ǰָ����Ѿ�ָ��λ��
            p -> data = ch[i];
            cout << 1 << endl;
        }
        else if(ch[i] == '(')
        {
            push(S, p);
            if(ch[i+1] != ',')//�����Ҷ��ӵ������c(, d)��Ԥ����
            {
                p ->lchild = new node;
                p = p -> lchild;
                p -> lchild = NULL;
                p -> rchild = NULL;
            }
        }
        //ֻ���Ҷ��ӵ����
        else if(ch[i] == ',')
        {
            p = peek(S);
            p -> rchild = new node;
            p = p -> rchild;
            p -> lchild = NULL;
            p -> rchild = NULL;
        }
        else if(ch[i] == ')')
        {
            q = peek(S);
            q -> lchild -> lchild = NULL;
            q -> lchild -> rchild = NULL;
            pop(S);
            //���ñ�־
        }
        i++;
    }
}
void ToList(BTREE p)
{
    if(p != NULL)
    {
        cout << p -> data;
        cout << 1 << endl;
        if(p -> lchild != NULL || p -> rchild !=NULL)
        {
            cout << '(';
            ToList(p -> lchild);
            if(p -> rchild != NULL)
            {
                cout << ",";
            }
            ToList(p -> rchild);
            cout << ")";
        }
    }
}
void EmptyBT(BTREE &BT)
{
    BT = new node;
    BT -> lchild = NULL;
    BT -> rchild = NULL;
}
BTREE CreateBT(char ch, BTREE ltree, BTREE rtree)
{
    BTREE root;
    root = new node;
    root -> data = ch;
    root -> lchild = ltree;
    root -> rchild = rtree;
    return root;
}
int main()
{
    char ch[N];
    BTREE BT;
    cout << "�����������:" << endl;
    cin.getline(ch, N);
    ToTree(ch, BT);
    cout << "������Ķ�����Ϊ��" << endl;
    ToList(BT);
    return 0;
}
