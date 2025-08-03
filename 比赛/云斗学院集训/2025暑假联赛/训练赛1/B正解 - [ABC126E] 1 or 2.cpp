// T2
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

int n, m;
int fa[maxn];

int find(int x)
{
	if(fa[x] != x) return fa[x] = find(fa[x]);
	return fa[x];
}

signed main()
{
	cin >> n >> m;
	int cnt = n;
	for(int i = 1 ; i <= n ; i ++)
		fa[i] = i;
	for(int i = 0 ; i < m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a = find(a); b = find(b);
		if(a != b)
		{
			fa[a] = b;
			cnt --;
		}
	}
	cout << cnt;
}