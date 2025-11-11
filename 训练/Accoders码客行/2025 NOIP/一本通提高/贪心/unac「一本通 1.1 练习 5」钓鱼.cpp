// Problem: #10009. 「一本通 1.1 练习 5」钓鱼
// Contest: LibreOJ
// URL: https://loj.ac/p/10009
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-11 08:29:54

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, maxm = 110;
typedef long long LL;

int n, m;
LL f[maxn];
int s[maxm];
LL v[maxm][maxn], w[maxm][maxn];
int sta[maxm], delta[maxm], t[maxm];

signed main()
{
	cin >> n >> m;
	m *= 12;
	for(int i = 1 ; i <= n ; i ++)
		cin >> sta[i];
	for(int i = 1 ; i <= n ; i ++)
		cin >> delta[i];
	for(int i = 2 ; i <= n ; i ++)
		cin >> t[i];
	
	for(int i = 1 ; i <= n ; i ++)
	{
		v[i][1] += t[i];// + v[i-1][1];
		s[i] = 1;
		if(delta[i] != 0)
		{
			while(sta[i] > 0)
			{
				s[i] ++;
				v[i][s[i]] = v[i][s[i]-1] + 1;
				w[i][s[i]] = sta[i] + w[i][s[i]-1];
				sta[i] -= delta[i];
			}
		}
		else
		{
			for(int j = 1 ; j <= m+3 ; j ++)
			{
				s[i] ++;
				v[i][s[i]] = v[i][s[i]-1] + 1;
				w[i][s[i]] = sta[i] + w[i][s[i]-1];
			}
		}
	}
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m ; j >= 1 ; j --)
			for(int k = 1 ; k <= s[i] ; k ++)
				if(j >= v[i][k])
					f[j] = max(f[j], f[j-v[i][k]] + w[i][k]);
	
	cout << f[m];
}