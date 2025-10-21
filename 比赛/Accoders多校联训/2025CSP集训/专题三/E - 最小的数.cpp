// E
// expect pts = 100
// expect diff = orange

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ans = 0x3f3f3f3f3f3f3f3f;
char opt[4];

void dfs(int step, LL a[])
{
	if(step == 4)
	{
		/*
		for(int i = 1 ; i <= 4 ; i ++)
			cout << a[i] << ' ';
		cout << endl;
		*/
		
		if(a[1] != -1) ans = min(ans, a[1]);
		if(a[2] != -1) ans = min(ans, a[2]);
		if(a[3] != -1) ans = min(ans, a[3]);
		if(a[4] != -1) ans = min(ans, a[4]);
		return;
	}
	
	for(int i = 1 ; i <= 4 ; i ++)
	{
		if(a[i] == -1)
			continue;
		for(int j = 1 ; j <= 4 ; j ++)
		{
			if(i == j || a[j] == -1)
				continue;
			
			LL goal;
			if(opt[step] == '+')
				goal = a[i] + a[j];
			else
				goal = a[i] * a[j];
			int bkpi = a[i], bkpj = a[j];
			a[i] = -1, a[j] = goal;
			dfs(step+1, a);
			a[i] = bkpi, a[j] = bkpj;
		}
	}
}

signed main()
{
	freopen("minnum.in", "r", stdin);
	freopen("minnum.out", "w", stdout);
	LL a[] = {-1, 0, 0, 0, 0};
	cin >> a[1] >> a[2] >> a[3] >> a[4] >> opt[1] >> opt[2] >> opt[3];
	
	
	dfs(1, a);
	cout << ans;
}