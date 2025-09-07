#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+50;
int n, m;
int v[maxn], w[maxn];
int f[maxn];

signed main()
{
	cin >> n >> m;
	int cnt = 0;
	int a, b, s;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a >> b >> s;
		int k = 1;
		while(k <= s)
		{
			cnt ++;
			v[cnt] = a * k;
			w[cnt] = b * k;
			s -= k;
			k *= 2;
		}
		if(s > 0)
		{
			cnt ++;
			v[cnt] = a*s;
			w[cnt] = b*s;
		}
	}
	n = cnt;
		
	//01背包
	for(int i = 1; i <= n ; i++)
		for(int j = m ; j >=v[i] ; j --)
			f[j] = max(f[j], f[j-v[i]]+w[i]);
				
	cout << f[m];
	return 0;
}