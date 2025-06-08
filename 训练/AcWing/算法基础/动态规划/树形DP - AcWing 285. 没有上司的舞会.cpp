#include <bits/stdc++.h>
using namespace std;
const int maxn = 6010;

int n, happy[maxn], f[maxn][2];
int e[maxn], ne[maxn], h[maxn], idx;
bool is_havefa[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
	f[u][1] = happy[u];
	
	for(int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		dfs(j);
		
		f[u][1] += f[j][0];
		f[u][0] += max(f[j][0], f[j][1]);
	}
}

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> happy[i];
	memset(h, -1, sizeof h);
	for(int i = 0 ; i < n-1 ; i++)
	{
		int a, b;
		cin >> a >> b;
		addedge(b, a);
		is_havefa[a] = true;
	}
	
	int root = 1;
	while(is_havefa[root]) root ++;
	
	dfs(root);
	
	cout << max(f[root][1], f[root][0]);
}