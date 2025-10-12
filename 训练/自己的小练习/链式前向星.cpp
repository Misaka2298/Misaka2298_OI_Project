int e[maxm], ne[maxm], w[maxm], h[maxn], idx;

void addedge(int a, int b, int c)// 加边
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

memset(h, -1, sizeof h);// 初始化

for(int i = h[u] ; i != -1 ; i = ne[i])
{
	int j = e[i];
}