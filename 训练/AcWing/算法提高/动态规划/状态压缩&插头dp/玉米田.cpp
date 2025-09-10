// Problem: 玉米田
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/329/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
const int maxn = 13, maxm = 1 << maxn, mod = 1e8;
typedef long long LL;

int n, m;
int g[maxn];
vector<int> legal, trans[maxm];
LL f[maxn][maxm];

bool check(int x)
{
	return !(x & x << 1);
}

signed main()
{
	cin >> n >> m;
	int k;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j < m ; j ++)
			cin >> k, g[i] |= !k << j;
			
	
	for(int i = 0 ; i < 1 << m ; i ++)
		if(check(i))
			legal.push_back(i);
	
	for(auto now : legal)
		for(auto to : legal)
			if(!(now & to))
				trans[now].push_back(to);
		
	f[0][0] = 1;
	for(int i = 1 ; i <= n+1 ; i ++)
		for(auto now : legal)
			if(!(now & g[i]))
				for(auto pre : trans[now])
					f[i][now] = (f[i][now] + f[i-1][pre]) % mod;
	
	cout << f[n+1][0];
}
