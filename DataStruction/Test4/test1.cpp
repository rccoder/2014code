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
void GraphToList(GRAPH G, LIST *L, int n, int e)
{
	for (int i = 0; i < n; i++)
	{
		L->a[i].vertex = G.vertex[i];
		L->a[i].first = NULL;
	}
	for (int i = 0; i < e; i++)
	{
		for (int j = 0; j < e; j++)
		{
			if (G.edge[i][j] == 1)
			{
				LINK *p = new LINK;
				p->v = i;
				p->next = L->a[j].first;
				L->a[j].first = p;
			}
			/*
			���������ͼ����һ���ѭ�����ɡ�
			*/
		}
	}
}
void ListToGraph(LIST L, GRAPH *G, int, int e)
{
	for (int i = 0; i < n; i++)
	{
		G->vertex[i] = L.a[i].vertex;
	}
	for (int i = 0; i < e; i++)
	{
		for (int j = 0; j < e; j++)
		{
			LINK m = L.a[i].first;
			while(m)
			{
				G.edge[i][j] = 1;
				m = m->next;
			}
		}
	}
}