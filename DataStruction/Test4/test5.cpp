int closest[MAXN], lowcost[MAXN], m;//mΪ�ڵ�ĸ���
int G[MAXN][MAXN];//�ڽӾ���
int prim()
{
	for (int i = 0; i<m; i++)
	{
		lowcost[i] = INF;
	}
	for (int i = 0; i<m; i++)
	{
		closest[i] = 0;
	}
	closest[0] = -1;//�����һ���㣬-1��ʾ�õ��ڼ���U�У������ڼ���V��
	int num = 0, ans = 0, e = 0;//eΪ���¼��뼯�ϵĵ�
	while (num<m - 1)//����m-1����
	{
		int micost = INF, miedge = -1;
		for (int i = 0; i<m; i++)
			if (closest[i] != -1)
			{
			int temp = G[e][i];
			if (temp<lowcost[i])
			{
				lowcost[i] = temp;
				closest[i] = e;
			}
			if (lowcost[i]<micost)
				micost = lowcost[miedge = i];
			}
		ans += micost;
		closest[e = miedge] = -1;
		num++;
	}
	returnans;
}