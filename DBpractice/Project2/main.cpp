#include <iostream>
#include <stdlib.h>
#define MaxSize 100
using namespace std;
/*
*�������Ľṹ������ӵ�ָ����Ҷ��ӵ�ָ�룬����data��
*/
struct BTtree
{
    BTtree *lchild;
    char data;
    BTtree *rchild;
    bool ltag;
    bool rtag;
};
/*
*���ڹ����Ĵ洢
*/
char withList[100];
int i = 0;
//�շ��ʹ��Ľڵ�
BTtree pre;
/*
*�ݹ�ʵ�ֶ������Ĵ���
*/
BTtree * preCreateTree()
{
    char ch;
    BTtree *BT;
    cin >> ch;
    if(ch == '#')
    {
        BT = NULL;
    }
    else
    {
        BT = new BTtree;
        BT -> data = ch;
        BT -> ltag = false;
        BT -> rtag = false;
        cout << "����" << ch << "��������" << endl;
        BT -> lchild = preCreateTree();
        cout << "����" << ch << "��������" << endl;
        BT -> rchild = preCreateTree();
    }
    return BT;
}
/*
*ǰ��ݹ����
*/
void listTreePre(BTtree * BT)
{
    if(BT != NULL)
    {
        cout << BT ->data << " ";
        listTreePre(BT -> lchild);
        listTreePre(BT -> rchild);
    }
}
/*
*����ݹ����
*/
void listTreeMid(BTtree * BT)
{
    if(BT != NULL)
    {
        listTreeMid(BT -> lchild);
        cout << BT -> data << " ";
        listTreeMid(BT -> rchild);
    }
}
/*
*����ݹ����
*/
void listTreeBeh(BTtree * BT)
{
    if(BT != NULL)
    {
        listTreeBeh(BT -> lchild);
        listTreeBeh(BT -> rchild);
        cout << BT -> data << " ";
    }
}
/*
*ǰ��ǵݹ����
*/
void listTreePreNoRe(BTtree * BT)
{
    BTtree *S[MaxSize];
    int top = MaxSize;
    while(BT != NULL || top != MaxSize)
    {
        while(BT !=NULL)
        {
            //һֱ������
            cout << BT -> data << " ";
            S[--top] = BT;
            BT = BT -> lchild;
        }
        if(top != MaxSize)
        {
            //���Ϸ�һ��
            BT = S[top++];
            BT = BT -> rchild;
        }
    }

}
/*
*����ǵݹ����
*/
void listTreeMidNoRe(BTtree * BT)
{
    BTtree *S[MaxSize];
    int top = MaxSize;
    while(BT != NULL || top != MaxSize)
    {
        while(BT !=NULL)
        {
            S[--top] = BT;
            BT = BT -> lchild;
        }
        if(top != MaxSize)
        {
            //��һ��
            BT = S[top++];
            cout << BT -> data << " ";
            BT = BT -> rchild;
        }
    }
}
/*
*����ǵݹ�����
*/
void listTreeBehNoRe(BTtree * BT)
{
    struct tep
    {
        BTtree *tree;
        int flag;
    } S[MaxSize];
    int top = MaxSize;

    BTtree * tepTree = BT;
    while(tepTree !=NULL || top != MaxSize)
    {
        if(tepTree != NULL)
        {
            //һֱ�����ߣ�������ջ
            S[--top].tree = tepTree;
            S[top].flag = 1;
            tepTree = tepTree -> lchild;
        }
        else
        {
            if(S[top].flag == 2)
            {
                BT = S[top++].tree;
                cout << BT -> data << " ";
            }
            else
            {
                //û����������ȥ����������
                S[top].flag = 2;
                tepTree = S[top].tree -> rchild;
            }
        }
    }

}
void listTree(BTtree * BT)
{
    cout << "=�ݹ�ʵ�֣�=" << endl << endl;
    cout << "�������:" << endl;
    listTreePre(BT);
    cout << endl;
    cout << "�������:" << endl;
    listTreeMid(BT);
    cout << endl;
    cout << "�������:" << endl;
    listTreeBeh(BT);
    cout << endl << "=�ǵݹ�ʵ�֣�=" << endl << endl;
    cout << "�������:" << endl;
    listTreePreNoRe(BT);
    cout << endl;
    cout << "�������:" << endl;
    listTreeMidNoRe(BT);
    cout << endl;
    cout << "�������:" << endl;
    listTreeBehNoRe(BT);
}
/*
*���������
*�ݹ���������ԶԴ����������Ϳ����±������ȫ�ֱ���
*/
void printWithList(BTtree * BT)
{
    if(BT != NULL)
    {
        if(BT -> lchild == NULL && BT -> rchild == NULL)
        {
            withList[i++] = BT -> data;
        }
        else
        {
            withList[i++] = BT -> data;
            withList[i++] = '(';
            printWithList(BT -> lchild);
            withList[i++] = ',';
            printWithList(BT -> rchild);
            withList[i++] = ')';
        }
    }
}
void printList(BTtree *BT)
{
    BTtree *tep = BT;
    i = 0;
    withList[i] = '(';
    i++;
    printWithList(tep);
    withList[i] = ')';
    i++;
    withList[i] = '\0';
}
/*
*
*/
BTtree * levCreateTree()
{
    int m, l;
    char ch;
    BTtree * S[MaxSize];
    BTtree * BT, * tep;
    cout << "����������";
    cin >> m;
    cout << "����data��:";
    cin >> ch;
    while(m != 0 || ch != '#')
    {
        tep = new BTtree;
        tep -> data = ch;
        tep -> lchild = NULL;
        tep -> rchild = NULL;
        S[m] = tep;
        if(m == 1)
            BT = tep;
        else
        {
            l = m/2;
            if(m % 2 == 0)
            {
                S[l] -> lchild = tep;
            }
            else
            {
                S[l] -> rchild = tep;
            }
        }
        cout << "����������" << endl;
        cin >> m;
        cout << "����data��:" << endl;
        cin >> ch;
        cout << "m" << m << "ch:" << ch << endl;
    }
    return BT;
}
/*
*���������������
*/
void miding(BTtree p)
{
    if(p != NULL)
    {
        miding(p -> lchild);
        if(!p -> lchild)
        {
            p -> lchild = pre;
            p -> ltag = true;
        }
        if(!pre ->rchild)
        {
            p -> rchild = pre;
            pre -> rtag = true;
        }
        pre = p;
        midding(p -> rchild);
    }
}
bool toTreeListMid(BTtree * BT, BTtree &HEAD)
{
    miding(BTtree p);
    HEAD = new BTtree;
    HEAD -> ltag = false;
    HEAD -> rtag = true;
    HEAD -> rchild = HEAD;
    if(BT == NULL)
    {
        HEAD -> lchild = HEAD;
    }
    else
    {
        HEAD -> lchild = BT;
        pre = HEAD;
        miding(BT);
        pre -> rchild = HEAD;
        pre -> rtag = true;
        HEAD -> rchild = pre;
    }
    return 1;
}
void toTreeListMidPrint(BTtree HEAD)
{
    BTtree p = HEAD -> lchild;
    while(p != HEAD)
    {
        while(HEAD -> ltag == false)
        {
            p = p -> lchild;
        }
        cout << p -> data << "->";
        while(p -> rtag == true && p -> rchild != HEAD)
        {
            p = p -> rchild;
            cout << p -> data << endl << p -> data << "->";
        }
        p = p -> rchild;
    }
}
void toTreeList(BTtree * BT)
{
    //ͷ�ڵ�
    BTtree * HEAD;
    cout << "==����==" << endl;
    toTreeListMid(BT, HEAD);
    cout << "��������������������" << endl;
    toTreeListMidPrint(HEAD);

}
int main()
{
    BTtree *pre_tree = NULL;
    BTtree *lev_tree = NULL;
    int n;
    //�˵��Ľ���
    cout << "��������ѡ��˵���" << endl << "1.�ݹ齨��������" << endl << "2.�������������������" << endl << endl;
    cin >> n;
    if(n == 1)
    {
        cout << "˵����#�����" << endl << "������ڵ�" << endl << endl;
        //�ݹ齨��������
        pre_tree = preCreateTree();
        cout << "���Ĵ����Ѿ���ɣ�" << endl << endl;
        cout << "===���������===" << endl;
        printList(pre_tree);
        cout << withList << endl << endl;
        //��ʼ���ı���
        cout <<"===��ʼ���ı�������==="<< endl << endl;
        listTree(pre_tree);
    }
    else if(n == 2)
    {
        lev_tree = levCreateTree();
        cout << "���Ĵ����Ѿ���ɣ�" << endl << endl;
        cout << "===���������===" << endl;
        printList(lev_tree);
        cout << withList << endl << endl;
        //��ʼ���ı���
        cout <<"===��ʼ���ı�������==="<< endl << endl;
        listTree(lev_tree);
    }
    cout << "===����������===" << endl;
    toTreeList(pre_tree);
}
