
int DFS(int i, int k)
{
	int top = -1;
	visited[i] = 1;
	top++;
	stack[top] = i;
	j = 0;
	while (top != -1 || j == 0)
	{
		i = stack[top];
		p = a[i].first;
		while (p && j == 0)
		{
			t = p->next;
			if (t == k)
				j = 1;
			else if (visited[t] == 0)
			{
				visited[t] == 1;
				top++;
				stack[top] = t;
			}
			else
				p = p->next;
		}
		if (!p)
			top--;
	}
	return j;
}


int BFS(int i, int k)
{
	front = -1;
	rear = -1;
	visited[i] = 1;
	queue[++rear] = i;
	j = 0;
	while (front != rear || j == 0)
	{
		i = queue[++front];
		p = a[i].first;
		while (p && j == 0)
		{
			t = p->a;
			if (t == k)
				j = 1;
			else if (visited[t] == 0)
			{
				visited[t] = 1;
				queue[++rear] = t;
			}
			else
				p = p->next;
		}
		return j;
	}
}