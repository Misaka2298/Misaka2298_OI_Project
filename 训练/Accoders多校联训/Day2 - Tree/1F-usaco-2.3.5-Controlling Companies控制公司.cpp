// Tree1-F
// Problem: P1475 [USACO2.3] 控制公司 Controlling Companies
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1475
// Memory Limit: 125 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
#define endl '\n'

int n, pers[maxn][maxn], sumpers[maxn], comp;
bool st[maxn], ctrl[maxn];

void search(int u)
{
	if(st[u])
		return;
	st[u] = true;
	
	for(int i = 1 ; i <= comp ; i ++)
	{
		sumpers[i] += pers[u][i];
		if(sumpers[i] >= 50)
		{
			ctrl[i] = true;
			search(i);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pers[a][b] = c;
		comp = max(a, max(b, comp));
	}
	
	for(int i = 1 ; i <= comp ; i ++)
	{
		memset(st, false, sizeof st);
		memset(ctrl, false, sizeof ctrl);
		memset(sumpers, 0, sizeof sumpers);
		
		search(i);
		
		for(int j = 1 ; j <= comp ; j ++)
			if(i != j && ctrl[j])
				cout << i << ' ' << j << endl;
	}
}