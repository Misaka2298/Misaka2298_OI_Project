// D
// expect pts = 100
// expect diff = orange

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

int n, k;
bool g[3][maxn], st[3][maxn];
int dh[] = {0, 1, -1, 0};//k

void dfs(int side, int height, int water)
{
	if(height > n)
	{
		cout << "YES";
		exit(0);
	}
	
	for(int i = 1 ; i <= 3 ; i ++)// up, down, jump
	{
		int nh = height + dh[i];
		int ns = side;
		if(i == 3)
		{
			if(side == 1)
				ns = 2;
			else
				ns = 1;
		}
		if(st[ns][nh] || nh <= water || !g[ns][nh])
			continue;
		//cout << ns << ' ' << nh << endl;
		st[ns][nh] = 1;
		dfs(ns, nh, water+1);
		st[ns][nh] = 0;
	}
}

signed main()
{
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	cin >> n >> k;
	dh[3] = k;
	char chr;
	for(int i = 1 ; i <= 2 ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			cin >> chr, g[i][j] = (chr == '-');
			
	for(int i = 1 ; i <= 2 ; i ++)
		for(int j = n+1 ; j <= n+k+1 ; j ++)
			g[i][j] = 1;
	
	dfs(1, 1, 0);
	cout << "NO";
}