#include <iostream>
#include <stdlib.h>
#define MaxSize 100
using namespace std;
/*
*定义树的结构，左儿子的指针和右儿子的指针，树的data域
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
*用于广义表的存储
*/
char withList[100];
int i = 0;
//刚访问过的节点
BTtree pre;
/*
*递归实现二叉树的储存
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
        cout << "输入" << ch << "的左子树" << endl;
        BT -> lchild = preCreateTree();
        cout << "输入" << ch << "的右子树" << endl;
        BT -> rchild = preCreateTree();
    }
    return BT;
}
/*
*前序递归遍历
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
*中序递归遍历
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
*后序递归遍历
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
*前序非递归遍历
*/
void listTreePreNoRe(BTtree * BT)
{
    BTtree *S[MaxSize];
    int top = MaxSize;
    while(BT != NULL || top != MaxSize)
    {
        while(BT !=NULL)
        {
            //一直往做走
            cout << BT -> data << " ";
            S[--top] = BT;
            BT = BT -> lchild;
        }
        if(top != MaxSize)
        {
            //往上反一个
            BT = S[top++];
            BT = BT -> rchild;
        }
    }

}
/*
*中序非递归遍历
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
            //上一层
            BT = S[top++];
            cout << BT -> data << " ";
            BT = BT -> rchild;
        }
    }
}
/*
*后序非递归排序
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
            //一直往左走，保存入栈
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
                //没有左子树，去右子树看看
                S[top].flag = 2;
                tepTree = S[top].tree -> rchild;
            }
        }
    }

}
//遍历操作
void listTree(BTtree * BT)
{
    cout << "=递归实现：=" << endl << endl;
    cout << "先序遍历:" << endl;
    listTreePre(BT);
    cout << endl;
    cout << "中序遍历:" << endl;
    listTreeMid(BT);
    cout << endl;
    cout << "后序遍历:" << endl;
    listTreeBeh(BT);
    cout << endl << "=非递归实现：=" << endl << endl;
    cout << "先序遍历:" << endl;
    listTreePreNoRe(BT);
    cout << endl;
    cout << "中序遍历:" << endl;
    listTreeMidNoRe(BT);
    cout << endl;
    cout << "后序遍历:" << endl;
    listTreeBehNoRe(BT);
}
/*
*广义表的输出
*递归操作，所以对存广义表的数组和控制下标变量是全局变量
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
//按广义表输出，此函数主要用来给广义表的头尾添加括号
void printList(BTtree *BT)
{
    BTtree *tep = BT;
    //初始化i
    i = 0;
    withList[i] = '(';
    i++;
    printWithList(tep);
    withList[i] = ')';
    i++;
    withList[i] = '\0';
}
/*
*按节点数建立相应二叉树
*/
BTtree * levCreateTree()
{
    int m, l;
    char ch;
    BTtree * S[MaxSize];
    BTtree * BT, * tep;
    cout << "输入结点数：";
    cin >> m;
    cout << "输入data域:";
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
        cout << "输入结点数：" << endl;
        cin >> m;
        cout << "输入data域:" << endl;
        cin >> ch;
        cout << "m" << m << "ch:" << ch << endl;
    }
    return BT;
}
/*
*中序二叉树线索化辅助函数
*/
void miding(BTtree p)
{
    if(p != NULL)
    {
        miding(p -> lchild);
        //左子树线索化
        if(p -> lchild == NULL)
        {
            p -> lchild = pre;
            p -> ltag = true;
        }
        //右子树线索化
        if(pre ->rchild == NULL)
        {
            pre -> rchild = pre;
            pre -> rtag = true;
        }
        pre = p;
        midding(p -> rchild);
    }
}
/*
*中序线索化的起始函数
*/
bool toTreeListMid(BTtree  BT, BTtree &HEAD)
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
//中序线索化的输出
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
/*
*前序线索二叉树辅助函数
*/
void preing(BTtree p)
{
    if(p != NULL)
    {
        //前驱线索化
        if(p -> lchild ==NULL)
        {
            p -> lchild = pre;
            p -> ltag = true;
        }
        //后继线索化
        if(pre -> rchild == NULL)
        {
            pre -> rchild = p;
            pre ->rtag = true;
        }
        pre = p;
        //左右子树线索化
        if(p ->ltag == false)
        {
            preing(p -> lchild);
        }
        if(p -> rtag == false)
        {
            preing(p -> rchild);
        }
    }   
}
/*
*前序线索化二叉树的起始函数
*/
bool toTreeListPre(BTtree BT, BTtree &HEAD)
{
    preing(BTtree p);
    HEAD  = new BTtree;
    HEAD -> ltag = false;
    HEAD -> rtag = true;
    HEAD -> rchild = HEAD;
    if(BT == NULL)
    {
        HEAD -> lchild = HEAD;
    }
    else
    {
        HEAD -> lchild  = BT;
        pre  = HEAD;
        preing(BT);
        pre -> rchild  = HEAD;
        pre -> rtag  = true;
        HEAD -> rchild = pre;
    }
    return 1;
}
/*
*前序线索化二叉树的输出函数
*/
void toTreeListPrePrint(BTtree HEAD)
{
    BTtree  p = HEAD -> lchild;
    while(p != HEAD)
    {
        cout << p -> data << "->";
        while(p -> ltag == false)
        {
            p = p -> lchild;
            cout << p -> data << "->";
        }
        while(p -> rtag == true && p -> rtag != HEAD)
        {
            p = p -> rchild;
            cout <<　p -> data << "->";
        }
        if(p -> ltag == false)
        {
            p = p -> lchild;
        }
        else
        {
            p = p -> rchild;
        }
    }
}
/*
*后序线索化辅助函数
*/
void behing(BTtree p)
{
    if(p != NULL)
    {
        behing(p -> lchild);
        behing(p -> rchild);
        //前驱搜索
        if(p -> lchild == NULL)
        {
            pre -> rtag = true;
            pre -> lchild = pre;
        }
        //后驱搜索
        if(pre -> rchild == NULL)
        {
            pre -> rtag = true;
            pre ->  rchild  = p
        }
        pre = p;
    }
}
/*
*后序线索化二叉树的起始函数
*/
BTtree toTreeListBeh(BTtree &BT)
{
    BTtree beh;
    beh = new BTtree;
    beh -> ltag = false;
    beh -> rtag = true;
    beh -> rchild = beh;
    if(BT == NULL)
    {
        beh -> lchild = beh;
    }
    else
    {
        beh -> lchild = BT;
        pre = beh;
        behing(BT);
        beh -> rchild = pre;
    }
    return beh;
}
BTtree Parent(BTtree & HEAD, BTtree & p)
{
    BTtree tep;
    tep = HEAD;
    //tep是头节点
    if(tep -> lchild == p)
    {
        return tep;
    }
    else
    {
        tep = tep -> lchild;
        while(tep -> lchild != p && tep -> rchild != p)
        {
            if(tep -> rtag == false)
            {
                //有右节点，往右走
                tep = tep -> rchild;
            }
            else
            {
                //左儿子，到前驱
                tep = tep -> lchild;
            }
        }
        return tep;
    }
}
/*
*后序线索化二叉树的输出函数
*/
void toTreeListBehPrint(BTtree HEAD)
{
    BTtree p, parent;
    p = HEAD -> lchild;
    while(true)
    {
        while(p -> ltag == 0)
            p = p -> lchild;
        if(p -> rtag == 0)
            p = p -> rchild;
        else
            break;
    }
    while(HEAD != p)
    {
        cout << p -> data << "->";
        parent = Parent(HEAD, P);
        //如果parent是HEAD,则p是根节点,没有后继
        if(HEAD == parent)
            p = HEAD;

        else if(parent -> rchild == p || parent -> rtag == true)
        {
            p = parent;
        }
        //如果p是双亲的右孩子，或者是独生左孩子，，则后继为双亲
        else
        {
            while(parent -> rtag == false)
            {
                //若P是有兄弟的左孩子，则后继为双亲的右子树上后序遍历访问的第一个节点
                parent = parent -> rchild;
                while(parent -> ltag == false)
                {
                    parent = parent -> lchild;
                }
            }
            p = parent;
        }
        cout << p -> data << endl;
    }
}
void resetTreeList(BTtree HEAD, BTtree &BT)
{
    BTtree p, post;
    p = HEAD -> lchild;
    while(p != HEAD)
    {
        while(p -> ltag == false)
            p = p -> lchild;
        p -> ltag  = false;
        p -> lchild  = NULL;
        while(p -> rtag == true && p -> rchild != HEAD)
        {
            p -> rtag  = false;
            post = p -> rchild;
            p -> rchild = NULL;
            p = post;
        }
        p = p -> rchild;;
    }
    p = HEAD -> rchild;
    p -> rtag = false;
    p -> rchild = NULL;
    BT = HEAD -> lchild;
    delete(HEAD);
}
void toTreeList(BTtree * BT)
{
    //头节点
    BTtree * HEAD;
    cout << "==前序==" << endl;
    toTreeListPre(BT, HEAD);
    cout << "遍历前序线索化二叉树：" << endl;
    toTreeListPrePrint(HEAD);
    cout << "==中序==" << endl;
    toTreeListMid(BT, HEAD);
    cout << "遍历中序线索化二叉树：" << endl;
    toTreeListMidPrint(HEAD);
    cout << "==后序==" << endl;
    BTtree beh;
    //会改变BT
    beh = toTreeListBehPrint(BT);
    cout <<　"遍历后序线索化二叉树：" << endl;
    toTreeListBehPrint(beh);
}
//主函数
int main()
{
    BTtree *pre_tree = NULL;
    BTtree *lev_tree = NULL;
    int n;
    //菜单的建立
    cout << "输入数字选择菜单：" << endl << "1.递归建立二叉树" << endl << "2.输入结点的数建立二叉树" << endl << endl;
    cin >> n;
    if(n == 1)
    {
        cout << "说明：#代表空" << endl << "输入根节点" << endl << endl;
        //递归建立二叉树
        pre_tree = preCreateTree();
        cout << "树的储存已经完成！" << endl << endl;
        cout << "===广义表的输出===" << endl;
        printList(pre_tree);
        cout << withList << endl << endl;
        //开始树的遍历
        cout <<"===开始树的遍历操作==="<< endl << endl;
        listTree(pre_tree);
    }
    else if(n == 2)
    {
        lev_tree = levCreateTree();
        cout << "树的储存已经完成！" << endl << endl;
        cout << "===广义表的输出===" << endl;
        printList(lev_tree);
        cout << withList << endl << endl;
        //开始树的遍历
        cout <<"===开始树的遍历操作==="<< endl << endl;
        listTree(lev_tree);
    }
    cout << "===树的线索化===" << endl;
    toTreeList(pre_tree);
}
