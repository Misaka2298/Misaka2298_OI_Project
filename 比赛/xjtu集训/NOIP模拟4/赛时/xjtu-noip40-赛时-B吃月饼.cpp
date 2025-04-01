//T2
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, m, ne[maxn];
bool st[maxn];

signed main()
{
	cin >> n >> m;
	//m %= n;
	for(int i = 1 ; i <= n ; i++)
	{
		if(i == n)
			ne[n] = 1;
		else
			ne[i] = i + 1;
	}
	
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1 ; cnt2 != n-1 ; i = ne[i])
	{
		if(st[i]) continue;
		if(cnt1 != m && !st[i])
			cnt1 ++;
		if(cnt1 == m && !st[i])
		{
			st[i] = true;
			cnt1 = 0;
			cnt2++;
		}
	}
	
	for(int i = 1 ; i <= n ; i++)
		if(!st[i])
			cout << i;
	
	
}