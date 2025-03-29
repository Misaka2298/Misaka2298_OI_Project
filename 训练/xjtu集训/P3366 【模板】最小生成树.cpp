#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

int n, m, fa[maxn];

struct Edge{
	int a, b, w;
}edge[maxn];

bool cmp(Edge A, Edge B)
{
	return A.w < B.w;
}

int find(int x)
{
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		fa[i] = i;
	
	int a, b, c;
	for(int i = 0 ; i <= m ; i++)
	{
		cin >> a >> b >> c;
		edge[i] = {a, b, c};
	}
	
	sort(edge, edge+m, cmp);
	
	int res = 0, cnt = 0;
	for(int i = 0 ; i < m ; i++)
	{
		int a = edge[i].a, b = edge[i].b, c = edge[i].w;
		a = find(a), b = find(b);
		if(a != b)
		{
			fa[a] = b;
			cnt++;
			res += c;
		}
	}
	if(cnt < n-1) cout << "orz";
	else cout << res;
}