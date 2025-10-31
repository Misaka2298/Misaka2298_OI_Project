// Problem: T685372 乃隆饱饱大作战
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T685372
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Time: 2025-10-26 14:04:17

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m;
int fa[maxn];
int cnt;

int find(int x)
{
	if(x != fa[x])
		return find(fa[x]);
	return fa[x];
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	cnt = n;
	
	for(int i = 1 ; i <= n ; i ++)
		fa[i] = i;
		
	while(m --)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x = find(x), y = find(y);
		if(x != y)
		{
			fa[x] = y;
			cnt --;
		}
	}
	cout << cnt << endl << "乔子健真帅";
	
}