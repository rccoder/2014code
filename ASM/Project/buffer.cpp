#include <iostream>
#include <conio.h>
#define MaxSize 16
#define ESC 27
#define print 45
using namespace std;
struct Stack
{
	int top;
	char a[MaxSize];
};
void makeNull(Stack &S)
{
	S.top = -1;
}
void push(Stack &S, char c)
{
		S.top++;
		if (S.top >= 16)
		{
			S.top -= 16;
		}
		S.a[S.top] = c;
}
char pop(Stack &S)
{
		S.top--;
		if (S.top < -1)
		{
			S.top += 16;
		}
		return S.a[S.top+1];
}
int main()
{
	char buffer;
	int i = 0;
	Stack S;
	makeNull(S);
	buffer = _getche();
	while (buffer != ESC)
	{
		if (buffer != print)
		{
			push(S, buffer);
			buffer = _getche();
		}
		while (buffer == print)
		{
			cout << pop(S) << " ";
			i++;
			buffer = _getche();
		}
		
	}
	cout << "Thank you!" << endl;
	return 0;
}