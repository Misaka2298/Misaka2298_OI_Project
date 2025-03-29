#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;

long long n;
long long e[maxn], ne[maxn], h[maxn], idx;
long long q[maxn], hh, tt, d[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort()
{
	hh = 0, tt = -1;
	for(int i = 1 ; i <= n ; i++)
		if(!d[i])
			q[++tt] = i;
			
	while(hh <= tt)
	{
		int t = q[hh++];
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			d[j]--;
			if(d[j] == 0) q[++tt] = j;
		}
	}
}

signed main()
{
	cin >> n;
	int tmp;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i <= n ; i++)
		while(cin >> tmp && tmp != 0)
		{
			addedge(i, tmp);
			d[tmp] ++;
		}
		
	topsort();
	for(int i = 0 ; i < n ; i++)
		cout << q[i] << ' ';
}