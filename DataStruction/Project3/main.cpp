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
//the point is visited or not
bool visit[N];
void createGraph(GRAPH &G)
{
	int a, b;
	cin >> G.n >> G.e;
	//input the vertex
	for(int i = 0; i < G.n; i++)
	{
		cin >> G.vertex[i];
	}
	//Init the edge
	for(int i = 0; i < G.n; i++)
	{
		for(int j = 0; j < G.n; j++)
		{
			G.edge[i][j] = 0;
		}
	}
	//input the edge
	for(int i = 0; i < G.e; i++)
	{
	    //undirected graph
		cin >> a >> b;
		G.edge[a][b] = 1;
		G.edge[b][a] = 1;
	}
	//print the graph with Matrix
	for(int i = 0; i < G.n; i++)
	{
		for(int j = 0; j < G.n; j++)
		{
			cout << G.edge[i][j] << " ";
		}
		cout << endl;
	}
}
void createGraph2(GRAPH &G)
{
	int a, b;
	cin >> G.n >> G.e;
	//input the vertex
	for(int i = 0; i < G.n; i++)
	{
		cin >> G.vertex[i];
	}
	//Init the edge
	for(int i = 0; i < G.n; i++)
	{
		for(int j = 0; j < G.n; j++)
		{
			G.edge[i][j] = 0;
		}
	}
	//input the edge
	for(int i = 0; i < G.e; i++)
	{
	    //directed graph
		cin >> a >> b;
		G.edge[a][b] = 1;
	}
	//print the graph with Matrix
	for(int i = 0; i < G.n; i++)
	{
		for(int j = 0; j < G.n; j++)
		{
			cout << G.edge[i][j] << " ";
		}
		cout << endl;
	}
}
//init the visiting, with false
void initGraph(GRAPH & G)
{
	for(int i = 0; i < G.n; i++)
	{
		visit[i] = false;
	}
}
void initList(LIST & L)
{
    for(int i = 0; i < L.n; i++)
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
//start DFS in the no visiting
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
//Non-recursive DFS
void DFSGraph2Start(GRAPH *G, int i)
{
    int STACK[N];
    int top = N;
    top --;
    //push stack
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
        for(int i = G->n; i >=0; i--)
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
        //input the point, and the first is null
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
        // undirected graph
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
void createList2(LIST *G)
{
    int j, k;
    cin >> G->n >> G->e;
    for(int i = 0; i < G->n; i++)
    {
        //input the point, and the first is null
        cin >> G->a[i].vertex;
        G->a[i].first = NULL;
    }
    for(int i = 0; i < G->e; i++)
    {
        //directed graph
        cin >> j >> k;
        LINK *p = new LINK;
        p->v = k;
        p->next = G->a[j].first;
        G->a[j].first = p;
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
        }
         p = p->next;
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
    cout << endl;
}

void DFSList2Start(LIST *L, int v)
{
    int STACK[N];
    int top = N;
    LINK *p = NULL;
    top--;
    STACK[top] = v;
    while(top != N)
    {
        int j = STACK[top];
        top++;
        if(!visit[j])
        {
            cout << L->a[j].vertex << " ";
            visit[j] = true;
        }
        for(p = L->a[j].first; p !=NULL; p=p->next)
        {
            if(!visit[p->v])
            {
                top--;
                STACK[top] = p->v;
            }
        }
    }

}
void DFSList2(LIST &L)
{
    for(int i = 0; i < L.n; i++)
    {

        if(!visit[i])
        {
            DFSList2Start(&L, i);
        }
    }
    cout << endl;
}
void BFSListStart(LIST * L, int v)
{
    int Queue[N];
    int front = 0, rear = 0;
    LINK *p = NULL;
    visit[v] = true;
    Queue[rear] = v;
    rear++;
    cout << L->a[v].vertex << " ";
    while(front != rear)
    {
        v = Queue[front];
        front++;
        p = L->a[v].first;
        while(p != NULL && !visit[p->v])
        {
            cout << L->a[p->v].vertex << " ";
            visit[p->v] = true;
            Queue[rear] = p->v;
            rear++;
            p = p->next;
        }
    }
}
void BFSList(LIST &L)
{
    for(int i = 0; i < L.n; i++)
    {
        if(!visit[i])
        {
            BFSListStart(&L, i);
        }
    }
}
int main()
{
	struct GRAPH G;
	struct LIST L;
	int n, o=1;
	cout << "1.Adjacency Matrix(undirected graph) " << "\n" << "2.Adjacency List(undirected graph)"
	<< "\n" << "3.Adjacency Matrix(directed graph) " << "\n" << "4.Adjacency List(directed graph)"<< endl;
	cin >> n;
        if(n == 1)
        {
		freopen("1.txt", "r", stdin);
		createGraph(G);
		cout << "DFS1:";
		initGraph(G);
		DFSGraph1(G);
		cout << endl << "DFS2:";
		initGraph(G);
		DFSGraph2(G);
		cout << endl << "BFS:";
		initGraph(G);
		BFSGraph(G);
		fclose(stdin);
        }
        else if(n ==2)
        {
	    freopen("1.txt", "r", stdin);
	    createList(&L);
	    cout << "DFS1:";
	    initList(L);
	    DFSList1(L);
	    cout << "DFS2:";
	    initList(L);
	    DFSList2(L);
	    cout << "BFS:";
	    initList(L);
	    BFSList(L);
	    fclose(stdin);
        }
        else if(n == 3)
        {
        freopen("1.txt", "r", stdin);
		createGraph2(G);
		cout << "DFS1:";
		initGraph(G);
		DFSGraph1(G);
		cout << endl << "DFS2:";
		initGraph(G);
		DFSGraph2(G);
		cout << endl << "BFS:";
		initGraph(G);
		BFSGraph(G);
		fclose(stdin);
        }
        else if(n == 4)
        {
        freopen("1.txt", "r", stdin);
	    createList2(&L);
	    cout << "DFS1:";
	    initList(L);
	    DFSList1(L);
	    cout << "DFS2:";
	    initList(L);
	    DFSList2(L);
	    cout << "BFS:";
	    initList(L);
	    BFSList(L);
	    fclose(stdin);
        }
        else
        {
            cout << "Thank you!" << endl;
            o = 0;
        }
}
