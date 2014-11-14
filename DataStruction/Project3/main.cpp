#include <iostream>
#include <stdlib.h>
#include <fstream>
#define N 50
using namespace std;
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
    struct LINK * first;
};
struct LIST
{
    int n, e;
    node a[N];
};
bool visit[N];
void createGraph(GRAPH &G)
{
	int a, b;
	cin >> G.n >> G.e;
	for(int i = 0; i < G.n; i++)
	{
		cin >> G.vertex[i];
	}
	for(int i = 0; i < G.n; i++)
	{
		for(int j = 0; j < G.n; j++)
		{
			G.edge[i][j] = 0;
		}
	}
	for(int i = 0; i < G.e; i++)
	{
		cin >> a >> b;
		G.edge[a][b] = 1;
		G.edge[b][a] = 1;
	}
	for(int i = 0; i < G.n; i++)
	{
		for(int j = 0; j < G.n; j++)
		{
			cout << G.edge[i][j] << " ";
		}
		cout << endl;
	}
}
void init(GRAPH & G)
{
	for(int i = 0; i < G.n; i++)
	{
		visit[i] = false;
	}
}
void DFSGraph1Start(GRAPH * G, int i)
{
	cout << G->vertex[i] << " ";
	visit[i] = true;
	for(int j = 0; j < G->n; j++)
	{
		if(G->edge[i][j] == 1 && !visit[j])
		{
			DFSGraph1Start(G, j);
		}
	}
}
void DFSGraph1(GRAPH &G)
{
	for(int i = 0; i < G.n; i++)
	{
		if(!visit[i])
		{
			DFSGraph1Start(&G, i);
		}
	}
}
void DFSGraph2Start(GRAPH *G, int i)
{
    int STACK[N];
    int top = N;
    top --;
    STACK[top] = i;
    while(top != N)
    {
        int k = STACK[top];
        top ++;
        if(!visit[k])
        {
            cout << G->vertex[k] << " ";
            visit[k] = true;
        }
        for(int i = 0; i < G->n; i++)
        {
            if(!visit[i] && G->edge[k][i])
            {
                top --;
                STACK[top] = i;
            }
        }
    }

}
void DFSGraph2(GRAPH &G)
{
    for(int i = 0; i < G.n; i++)\
    {
        if(!visit[i])
        {
            DFSGraph2Start(&G, i);
        }
    }

}
void BFSGraphStart(GRAPH *G, int i)
{
    int Q[N], f = 0, r = 0;
    visit[i] = true;
    Q[r] = i;
    r++;
    cout << G->vertex[i] << " ";
    while(f!=r)
    {
        i = Q[f];
        f++;
        for(int k = 0; k < G->n; k++)
        {
            if(!visit[k] && G->edge[i][k])
            {
                cout << G->vertex[k] << " ";
                visit[k] = true;
                Q[r] = k;
                r++;
            }
        }
    }
}
void BFSGraph(GRAPH &G)
{
    for(int i = 0; i < G.n; i++)
    {
        if(!visit[i])
        {
            BFSGraphStart(&G, i);
        }
    }
}
void createList(LIST *G)
{
    int j, k;
    cin >> G->n >> G->e;
    for(int i = 0; i < G->n; i++)
    {
        cin >> G->a[i].vertex;
        G->a[i].first = NULL;
    }
    for(int i = 0; i < G->e; i++)
    {
        cin >> j >> k;
        LINK *p = new LINK;
        p->v = k;
        p->next = G->a[j].first;
        G->a[j].first = p;
        p = new LINK;
        p->v = j;
        p->next = G->a[k].first;
        G->a[k].first = p;
    }
    for(int i = 0; i < G->n; i++)
    {
        cout << G->a[i].vertex;
        LINK *m = G->a[i].first;
        while(m != NULL)
        {
            cout << "->" << G->a[m->v].vertex;
            m = m -> next;
        }
        cout << "->NULL" <<endl;
    }
}
void DFSList1Start(LIST *L, int i)
{
    LINK *p;
    cout << L->a[i].vertex << " ";
    visit[i] = true;
    p = L->a[i].first;
    while(p != NULL)
    {
        if(!visit[p->v])
        {
            DFSList1Start(L, p->v);
            p = p->next;
        }
    }
}
void DFSList1(LIST &L)
{
    for(int i = 0; i < L.n; i++)
    {
        if(!visit[i])
        {
            DFSList1Start(&L, i);
        }
    }
}
int main()
{
	struct GRAPH G;
	struct LIST L;
	int n;
	cout << "1.ÁÚ½Ó¾ØÕó" << "\n" << "2.ÁÚ½Ó±í" << endl;
	cin >> n;
	if(n = 1)
	{
		freopen("1.txt", "r", stdin);
		createGraph(G);
		cout << "DFS1:";
		init(G);
		DFSGraph1(G);
		cout << endl << "DFS2:";
		init(G);
		DFSGraph2(G);
		cout << endl << "BFS:";
		init(G);
		BFSGraph(G);
	}
	else if(n ==2)
	{
	    freopen("1.txt", "r", stdin);
	    createList(&L);
	    cout << "DFS1:";
	    init(L);
	    DFSList1(L);
	}
}
