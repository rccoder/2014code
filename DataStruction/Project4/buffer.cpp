/*
admin:Shangbin Yang
Title:查找结构与排序算法
data:2014-12-04
*/
#include <iostream>
using namespace std;
/*
Define a Tree struction with data, lchild pointer and rchild pointer
*/
struct Tree
{
	int data;
	Tree *lchild, *rchild;
};
typedef Tree *BST;
/*
Insert the R to the Tree by size
*/
void Insert(int R, BST *F)
{
	BST S;
	//The tree is null, Create a new tree, and do some init
	if (*F == NULL)
	{
		S = new Tree;
		S->data = R;
		S->lchild = NULL;
		S->rchild = NULL;
		*F = S;
	}
	//By size, insert the R
	else if (R < (*F)->data)
	{
		Insert(R, &((*F)->lchild));
	}
	else if (R >(*F)->data)
	{
		Insert(R, &((*F)->rchild));
	}
}
//Create the tree, include [void Insert(int R, BST *F)]
void Create(BST *F)
{
	int number, R;
	*F = NULL;
	cout << "Please Input The Number:" << endl;
	cin >> number;
	cout << "Please Input The Data:" << endl;
	//by the void Insert(int R, BST *F)
	for (int i = 0; i < number; i++)
	{
		cin >> R;
		Insert(R, F);
	}
}
/*
Display the Tree, to show the tree any time
*/
void Display(BST F)
{
	if (F != NULL)
	{
		Display(F->lchild);
		cout << F->data << " ";
		Display(F->rchild);
	}
}
/*
Search the k from the Tree
*/
int Search(int k, BST F)
{
	BST p;
	p = F;
	while (p)
	{
		if (p->data == k)
		{
			return p->data;
		}
		if (p->data > k)
		{
			p = p->lchild;
		}
		else
			p = p->rchild;
	}
	return 0;
}
/*
Delete the k from the Tree
Should judge k in the Tree or not
*/
BST  Delete(int k, BST F)
{
	Tree *p, *f, *s, *q;
	p = F;
	f = NULL;
	if (!Search(k, F))
	{
		cout << "The " << k << " was not in the Tree !" << endl;
		return F;
	}
	while (p)
	{
		if (p->data == k)
			f = p;
		if (p->data > k)
			p = p->lchild;
		if (p->data < k)
			p = p->rchild;
	}
	if (p == NULL)
	{
		cout << "Search Failed!" << endl;
		return F;
	}
	//Delete the k
	if (p->lchild == NULL)
	{
		if (f == NULL)
		{
			F = p->rchild;
		}
		else if (f->lchild == p)
		{
			f->lchild = p->lchild;
		}
		else
			f->rchild = p->rchild;
		delete p;
	}
	else
	{
		q = p;
		s = p->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		if (q == p)
		{
			q->lchild = s->lchild;
		}
		else
		{
			q->rchild = s->rchild;
		}
		p->data = s->data;
		delete s;
	}
}
//Choose Menu
void menu()
{
	cout << "1.Create" << endl;
	cout << "2.Search" << endl;
	cout << "3.Insert" << endl;
	cout << "4.Delete" << endl;
	cout << "0.Exit" << endl;
}
int main()
{
	BST F = NULL;
	int n, t;
	int ch;
	cout << "Please Input:" << endl;
	menu();
	cin >> n;
	while (!(n >= 0 && n <= 4))
	{
		cout << "Error! Please Input Again：" << endl;
		menu();
		cin >> n;
	}
	while (n != 0)
	{
		switch (n)
		{
		case 1:
			cout << "Creating…………" << endl;
			Create(&F);
			cout << "Now, The tree is:" << endl;
			Display(F);
			cout << endl;
			cout << endl;
			cout << "Please Input:" << endl;
			menu();
			cin >> n;
			break;
		case 2:
			cout << "Please Input What You Want Search:";
			cin >> ch;
			t = Search(ch, F);
			if (t != 0)
			{
				cout <<"Wow!" << t << " in the tree" << endl;
			}
			else
			{
				cout << "Search Failed!" << endl;
			}
			cout << endl;
			cout << endl;
			cout << "Please Input:" << endl;
			menu();
			cin >> n;
			break;
		case 3:
			cout << "Please Input the number What You want to Insert:" << endl;
			cin >> ch;
			Insert(ch, &F);
			cout << "Now, The tree is:" << endl;
			Display(F);
			cout << endl;
			cout << endl;
			cout << "Please Input:" << endl;
			menu();
			cin >> n;
			break;
		case 4:
			cout << "Please Input the Number What You Want To Delete:" << endl;
			cin >> ch;
			Delete(ch, F);
			cout << "Now, The tree is:" << endl;
			Display(F);
			cout << endl;
			cout << endl;
			cout << "Please Input:" << endl;
			menu();
			cin >> n;
			break;
		}
	}

}