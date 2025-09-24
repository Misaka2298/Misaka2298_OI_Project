#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, m;
int e[maxn], ne[maxn], h[maxn], idx;
int stk[maxn], times, low[maxn], id[maxn], dfn[maxn];
int top;
bool st[maxn];
int scc_cnt, dout[maxn], sz[maxn];

void tarjan(int u)
{
	dfn[u] = low[u] = ++times;
	stk[++top] = u, st[u] = 1;
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if(st[j])
			low[u] = min(low[u], dfn[j]);
	}
	
	if(dfn[u] == low[u])
	{
		++scc_cnt;
		int y;
		do
		{
			y = stk[top--];
			st[y] = 0;
			id[y] = scc_cnt;
			sz[scc_cnt] ++;
		}while(y != u);
	}
}

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

signed main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b);
	}
	
	for(int i = 1 ; i <= n ; i ++)
		if(!dfn[i])
			tarjan(i);
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = h[i] ; j != -1 ; j = ne[j])
		{
			int k = e[j];
			int a = id[i], b = id[k];
			if(a != b)
				dout[a] ++;
		}
	
	int zeros = 0, sum = 0;
	for(int i = 1 ; i <= scc_cnt ; i ++)
		if(!dout[i])
		{
			zeros ++;
			sum += sz[i];
			if(zeros > 1)
			{
				sum = 0;
				break;
			}
		}
	
	cout << sum;
}