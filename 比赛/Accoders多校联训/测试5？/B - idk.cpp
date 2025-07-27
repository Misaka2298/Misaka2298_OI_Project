// T2
// expect pts = 100
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+10;

int n, a[maxn];
bool st[maxn];

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	bool spe = true;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		if(st[a[i]])
			spe = 0;
		else
			st[a[i]] = 1;
	}
	
	
	if(spe)
	{
		cout << n;
		exit(0);	
	}
	
	memset(st, false, sizeof st);
	
	int cnt = 0, opt = 0;
	while(cnt != n)
	{
		int minest = 1e9, ed = 1;
		for(int i = 1 ; i <= n ; i ++)
		{
			if(a[i] != 0)
			{
				for(int j = i ; j <= n ; j ++)
				{
					if(a[j] != 0)
						minest = min(minest, a[j]);
					if(a[j+1] == 0 || j == n)
					{
						ed = j;
						break;
					}	
				}
				for(int j = i ; j <= ed ; j ++)
					a[j] -= minest;
				opt ++;
				minest = 1e9;
				for(int j = i ; j <= n ; j ++)
					if(a[j] != 0)
						i = j;
			}
			else
				if(!st[i])
					st[i] = 1, cnt ++;
			/*
			for(int j = 1 ; j <= n ; j ++)
				cout << a[j] << ' ';
			cout << endl;
			*/
		}
	}
	cout << min(opt, n);
}