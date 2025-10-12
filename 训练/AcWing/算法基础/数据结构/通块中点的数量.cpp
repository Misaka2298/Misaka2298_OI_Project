#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m;
int fa[maxn], sz[maxn];

int find(int x)
{
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

signed main()
{
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i++)
	{
		p[i]=i;
		sz[i] = 1;
	}
	
	while(m --)
	{
		char opt;
		cin >> opt;
		int a, b;
		if(opt == 'C')// 合并两个连通块
		{
			cin >> a >> b;
			a = find(a), b = find(b);
			if(a == b) continue;
			else sz[b] += sz[a];
			fa[a] = b;
		}
		else if(opt == '1')// 查询是否在同一个连通块
		{
			cin >> a >> b;
			a = find(a), b = find(b);
			if(a == b) cout << "Yes" <<endl;
			else cout << "No" << endl;
		}
		else// 查询连通块大小
		{
			cin >> a;
			cout << sz[find(a)]<<endl;
		}
	}
	return 0;
}