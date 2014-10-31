#include <iostream>
#include<string.h>
#include <stdlib.h>
#include<math.h>
using namespace std;
#define Maxsize 100000
typedef float ElemType;
/*
*����ջ��ջ�Ĳ���
*ջ��Stack
*��ʼ����makenull
*��ջ��push
*��ջ������ջ����pop
*����ջ����peek
*/
struct Stack
{
    ElemType s[Maxsize];
    int top;
};
void makenull(Stack& S)//���ջ������
{
    S.top=-1;
}
void push(Stack &S,ElemType item)//������ѹ��ջ
{
    if(S.top==Maxsize-1)
        cout<<"��ջ����!"<<endl;
    else
    {
        S.s[++S.top]=item;
    }
}
ElemType pop(Stack& S)//��ȡջ��Ԫ�أ���ɾ��ջ��Ԫ��
{
    if(S.top==-1)
        exit(1);
    else
    {
        return S.s[S.top--];
    }
}
ElemType peek(Stack& S)//��ȡջ��Ԫ��
{
    if(S.top==-1)
    {
        cout<<"��ջΪ��!"<<endl;
    }
    return S.s[S.top];
}
/*
*��������ȼ����ж�
* +-    return 1
*  x/%    return 2
*  ^     return 3
*   ( #    return 0
*  �ȼ�Խ�ߣ����ȼ�Խ��
*/
int judge(char op)//����������ȼ��Ƚ�
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
*��׺ת��׺�ĺ��ĺ�����ʵ������׺���׺��ת��
*
*Stack r ������������
*������middle��������
*last�����������Ϊ���Ŷ�������֮����ֵ���ʱ�����
*/
void change(char* middle,char* last)
{
    Stack r;
    makenull(r);
    //����һ����־'#'������ջ�ף���Ϊһ����־
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
            cout << "ջ����" << peek(r) << endl;
            i++;
            ch=middle[i];
        }
        else if(ch==')')
        {
            //���֣���������ƥ���(
            while(peek(r)!='(')
            {
                //pop����ɾ��ջ�����ҷ���ջ��Ԫ��
                last[j]=pop(r);
                j++;
                cout << "ջ����" << peek(r) << endl;
            }
            //ɾ��(
            pop(r);
            cout << "ջ����" << peek(r) << endl;
            i++;
            ch=middle[i];
        }
        //ch��������������
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='^')
        {
            char w=peek(r);
            //������ıȽ�
            while(judge(w)>=judge(ch))
            {
                last[j]=w;
                j++;
                pop(r);
                cout << "ջ����" << peek(r) << endl;
                w=peek(r);
            }
            push(r,ch);
            cout << "ջ����" << peek(r) << endl;
            i++;
            ch=middle[i];
        }
        //�ų���С��
        else if((ch<'0'||ch>'9')&&ch!='.')
        {
            cout<<"�������"<<endl;
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
    cout << "ջ����" << peek(r) << endl;
    while(ch!='#')
    {
        if(ch=='(')
        {
            cout<<"���ʽ����!"<<endl;
            exit(1);
        }
        else
        {
            last[j]=ch;
            j++;
            ch=pop(r);
            cout << "ջ����" << peek(r) << endl;
        }
    }
    last[j]='\0';
    j++;
}
/*
*�Ժ�׺���ʽ������ֵ����
*���Σ�str������׺���ʽ
*/
double start(char *str)//���ú�׺���ʽ��ֵ
{
    Stack s;
    //��ʼ���ÿ�ջ
    makenull(s);
    double x,y;
    double a,b;
    cout << "��׺���ʽ��ֵ��ʱ��ջ��Ԫ�ر仯"  << endl;
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
            cout << "ջ����" << peek(s) << endl;
            a=pop(s);
            cout << "ջ����" << peek(s) << endl;
            b=pop(s);
            x=a+b;
            i++;
            break;
        case '-':
            cout << "ջ����" << peek(s) << endl;
            a=pop(s);
            cout << "ջ����" << peek(s) << endl;
            b=pop(s);
            x=b-a;
            i++;
            break;
        case '*':
            cout << "ջ����" << peek(s) << endl;
            a=pop(s);
            cout << "ջ����" << peek(s) << endl;
            b=pop(s);
            x=b*a;
            i++;
            break;
        case '/':
            cout << "ջ����" << peek(s) << endl;
            a=pop(s);
            cout << "ջ����" << peek(s) << endl;
            b=pop(s);
            if(a!=0.0)
            {
                x=b/a;
            }
            else
            {
                cout<<"��������Ϊ0��"<<endl;
                exit(1);
            }
            i++;
            break;
        case '%':
            cout << "ջ����" << peek(s) << endl;
            a=pop(s);
            cout << "ջ����" << peek(s) << endl;
            b=pop(s);
            x=(double)((int)b%(int)a);
            i++;
            break;
        case '^':
            cout << "ջ����" << peek(s) << endl;
            a=pop(s);
            cout << "ջ����" << peek(s) << endl;
            b=pop(s);
            x=pow(b,a);
            i++;
            break;
        default:
            //����С��
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
                    y=y+(str[i]-'0')/j;//y������ֵ��С������
                    i++;
                    j*=10;
                }
                x+=y;
            }
        }
        //ѹջ
        push(s,x);
    }
    if(s.top==-1)
    {
        cout<<"��ջΪ��!"<<endl;
        exit(1);
    }
    else
    {
        x=pop(s);
        cout << "���ʽ������Ϊ��" << x << endl;
        cout<<endl;

    }
    return 0;
}
int  main()
{
    Stack s;
    //��ʼ��ջ
    makenull(s);
    char a[100];
    cout << "Please Input(Start and Ended by '#'" << endl;
    cin >> a;
    char b[100];
    change(a,b);
    cout<<"��׺���ʽΪ��"<<endl;
    cout<<b<<endl;
    cout<<endl;
    start(b);
    cout << "The end!" << endl;
    return 0;
}
