// Problem: 小国王
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1066/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-07 18:53:59

#include <bits/stdc++.h>
using namespace std;
const int maxn = 11, maxm = 1 << 11;
typedef long long LL;

int n, K;
vector<int> legal, trans[maxm];
LL f[maxn][maxn*maxn][maxm];

bool check(int x)
{
	return !(x & x>>1);
}

signed main()
{
	cin >> n >> K;
	for(int i = 0 ; i < 1 << n ; i ++)
		if(check(i))
			legal.push_back(i);
	
	for(auto now : legal)
		for(auto to : legal)
			if(!(now&to) && check(now|to))
				trans[now].push_back(to);
		
	f[0][0][0] = 1;		
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j <= K ; j ++)
			for(auto now : legal)
				for(auto pre : trans[now])
					if(j - __builtin_popcount(now) >= 0)
						f[i][j][now] += f[i-1][j-__builtin_popcount(now)][pre];
		
	LL ans = 0;
	for(auto state : legal)
		ans += f[n][K][state];
	cout << ans;
		
		
		
}