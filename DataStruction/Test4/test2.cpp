/*
G——原有的邻接矩阵
L——将改变的邻接表
n, e—— 边和点的个数
-----
省略初始化过程
-----
*/
struct GRAPH
{
	int n, e;
	int edge[N][N];
	char vertex[N];
};
struct LINK
{
	int v;
	LINK *next;
};
struct node
{
	char vertex;
	struct LINK *first;
};
struct LIST
{
	int n, e;
	node a[N];
};
void change(LIST L, LIST & R)
{
	R.n = L.n;
	R.e = L.e;
	for (int i = 0; i < L.n; i++)
	{
		R.a[i].first = NULL;
	}
	for (int i = 0; i < L.n; i++)
	{
		p = L.a[i].first;
		while (p)
		{
			j = p->vertex;
			p2 = new LIST;
			p2->vertext = i;
			p2->next = R.a[i].first;
			R.a[i].first = p2;
			p = p->next;
		}
	}
}