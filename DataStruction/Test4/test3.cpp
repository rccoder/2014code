/*
G����ԭ�е��ڽӾ���
L�������ı���ڽӱ�
n, e���� �ߺ͵�ĸ���
-----
ʡ�Գ�ʼ������
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
int Graphzero(GRAPH G, int n)
{
	int count = 0, flag = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (G.edge[i][j] != 0)
			{
				flag = 1;
				break;
			}
			if (!flag)
				count++;
		}
	}
	return count;
}
int Listzero(LIST L, int n)
{
	node *p;
	for (int i = 0; i < n; i++)
	{
		int outdg = 0;
		p = L.a[i].first;
		while (p != NULL)
		{
			outdg++;
			p = p->next;
		}
		if (outdg == 0)
		{
			int count++;
		}
	}
	return count;
}