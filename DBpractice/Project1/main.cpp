#include <iostream>
#include<string.h>
#include <stdlib.h>
#include<math.h>
using namespace std;
#define Maxsize 100000
typedef float ElemType;
/*
*定义栈与栈的操作
*栈：Stack
*初始化：makenull
*入栈：push
*出栈并返回栈顶：pop
*返回栈顶：peek
*/
struct Stack
{
    ElemType s[Maxsize];
    int top;
};
void makenull(Stack& S)//清空栈中数据
{
    S.top=-1;
}
void push(Stack &S,ElemType item)//将数据压入栈
{
    if(S.top==Maxsize-1)
        cout<<"该栈已满!"<<endl;
    else
    {
        S.s[++S.top]=item;
    }
}
ElemType pop(Stack& S)//读取栈顶元素，并删除栈顶元素
{
    if(S.top==-1)
        exit(1);
    else
    {
        return S.s[S.top--];
    }
}
ElemType peek(Stack& S)//读取栈顶元素
{
    if(S.top==-1)
    {
        cout<<"该栈为空!"<<endl;
    }
    return S.s[S.top];
}
/*
*运算符优先级的判断
* +-    return 1
*  x/%    return 2
*  ^     return 3
*   ( #    return 0
*  等级越高，优先级越高
*/
int judge(char op)//运算符的优先级比较
{
    switch(op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    case '(':
    case '#':
    default:
        return 0;
    }
}
/*
*中缀转后缀的核心函数，实现了中缀向后缀的转化
*
*Stack r 用来存放运算符
*数存在middle的数组中
*last数组里面存因为括号而在括号之间出现的临时运算符
*/
void change(char* middle,char* last)
{
    Stack r;
    makenull(r);
    //将第一个标志'#'储存在栈底，作为一个标志
    push(r,middle[0]);
    int i=1,j=0;
    char ch=middle[i];
    while(ch!='#')
    {
        if(ch==' ')
        {
            i++;
            ch=middle[i];
        }
        else if(ch=='(')
        {
            push(r,ch);
            cout << "栈顶：" << peek(r) << endl;
            i++;
            ch=middle[i];
        }
        else if(ch==')')
        {
            //发现），找与他匹配的(
            while(peek(r)!='(')
            {
                //pop函数删除栈顶并且返回栈顶元素
                last[j]=pop(r);
                j++;
                cout << "栈顶：" << peek(r) << endl;
            }
            //删除(
            pop(r);
            cout << "栈顶：" << peek(r) << endl;
            i++;
            ch=middle[i];
        }
        //ch是运算符的情况下
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='^')
        {
            char w=peek(r);
            //运算符的比较
            while(judge(w)>=judge(ch))
            {
                last[j]=w;
                j++;
                pop(r);
                cout << "栈顶：" << peek(r) << endl;
                w=peek(r);
            }
            push(r,ch);
            cout << "栈顶：" << peek(r) << endl;
            i++;
            ch=middle[i];
        }
        //排除是小数
        else if((ch<'0'||ch>'9')&&ch!='.')
        {
            cout<<"输入错误"<<endl;
            exit(1);
        }
        else
            while((ch>='0'&&ch<='9')||ch=='.')
            {
                last[j]=ch;
                j++;
                i++;
                ch=middle[i];
            }
        last[j]=' ';
        j++;
    }
    ch=pop(r);
    cout << "栈顶：" << peek(r) << endl;
    while(ch!='#')
    {
        if(ch=='(')
        {
            cout<<"表达式错误!"<<endl;
            exit(1);
        }
        else
        {
            last[j]=ch;
            j++;
            ch=pop(r);
            cout << "栈顶：" << peek(r) << endl;
        }
    }
    last[j]='\0';
    j++;
}
/*
*对后缀表达式进行求值计算
*传参：str，即后缀表达式
*/
double start(char *str)//利用后缀表达式求值
{
    Stack s;
    //初始化置空栈
    makenull(s);
    double x,y;
    double a,b;
    cout << "后缀表达式求值的时候栈顶元素变化"  << endl;
    int i=0;
    while(str[i])
    {
        if(str[i]==' ')
        {
            i++;
            continue;
        }
        switch(str[i])
        {
        case '+':
            cout << "栈顶：" << peek(s) << endl;
            a=pop(s);
            cout << "栈顶：" << peek(s) << endl;
            b=pop(s);
            x=a+b;
            i++;
            break;
        case '-':
            cout << "栈顶：" << peek(s) << endl;
            a=pop(s);
            cout << "栈顶：" << peek(s) << endl;
            b=pop(s);
            x=b-a;
            i++;
            break;
        case '*':
            cout << "栈顶：" << peek(s) << endl;
            a=pop(s);
            cout << "栈顶：" << peek(s) << endl;
            b=pop(s);
            x=b*a;
            i++;
            break;
        case '/':
            cout << "栈顶：" << peek(s) << endl;
            a=pop(s);
            cout << "栈顶：" << peek(s) << endl;
            b=pop(s);
            if(a!=0.0)
            {
                x=b/a;
            }
            else
            {
                cout<<"除数不能为0！"<<endl;
                exit(1);
            }
            i++;
            break;
        case '%':
            cout << "栈顶：" << peek(s) << endl;
            a=pop(s);
            cout << "栈顶：" << peek(s) << endl;
            b=pop(s);
            x=(double)((int)b%(int)a);
            i++;
            break;
        case '^':
            cout << "栈顶：" << peek(s) << endl;
            a=pop(s);
            cout << "栈顶：" << peek(s) << endl;
            b=pop(s);
            x=pow(b,a);
            i++;
            break;
        default:
            //处理小数
            x=0;
            while(str[i]>='0'&&str[i]<='9')
            {
                x=x*10+str[i]-'0';
                i++;
            }
            if(str[i]=='.')
            {
                i++;
                y=0;
                double j=10.0;
                while(str[i]>='0'&&str[i]<='9')
                {
                    y=y+(str[i]-'0')/j;//y保存数值的小数部分
                    i++;
                    j*=10;
                }
                x+=y;
            }
        }
        //压栈
        push(s,x);
    }
    if(s.top==-1)
    {
        cout<<"该栈为空!"<<endl;
        exit(1);
    }
    else
    {
        x=pop(s);
        cout << "表达式计算结果为：" << x << endl;
        cout<<endl;

    }
    return 0;
}
int  main()
{
    Stack s;
    //初始化栈
    makenull(s);
    char a[100];
    cout << "Please Input(Start and Ended by '#'" << endl;
    cin >> a;
    char b[100];
    change(a,b);
    cout<<"后缀表达式为："<<endl;
    cout<<b<<endl;
    cout<<endl;
    start(b);
    cout << "The end!" << endl;
    return 0;
}
