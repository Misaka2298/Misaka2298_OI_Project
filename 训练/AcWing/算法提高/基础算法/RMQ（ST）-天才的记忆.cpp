// Problem: 天才的记忆
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1275/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10, maxk = 18;
#define endl '\n'

int n, q;
int f[maxn][maxk];
int w[maxn];

void init()
{
	for(int j = 0 ; j <= maxk ; j ++)
		for(int i = 1 ; i+(1<<j)-1 <= n ; i++)
		{
			if(!j)
				f[i][j] = w[i];
			else
				f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
		}
}

int query(int l, int r)
{
	int len = r-l+1;
	int k = log(len) / log(2);
	
	return max(f[l][k], f[r-(1<<k)+1][k]);
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> w[i];
	
	init();
	
	cin >> q;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
}