// Problem: #10001. 「一本通 1.1 例 2」种树
// Contest: LibreOJ
// URL: https://loj.ac/p/10001
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-10 09:18:32

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, q;
int a[maxn];
struct Range{
	int l, r, req;
}ranges[maxn];

bool cmp(Range a, Range b)
{
	return a.r < b.r;
}

signed main()
{
	cin >> n >> q;
	for(int i = 1 ; i <= q ; i ++)
	{
		int l, r, req;
		cin >> l >> r >> req;
		ranges[i] = {l, r, req};
	}
	
	sort(ranges+1, ranges+1+q, cmp);
	
	int ans = 0;
	for(int i = 1 ; i <= q ; i ++)
	{
		int l = ranges[i].l, r = ranges[i].r, req = ranges[i].req, cnt = 0;
		
		for(int j = l ; j <= r ; j ++)
			cnt += a[j];
		
		if(cnt < req)
		{
			int need = req - cnt;
			for(int j = r ; j >= l ; j --)
			{
				if(!a[j])
				{
					a[j] ++;
					ans ++;
					need --;
				}
				if(!need)
					break;
			}
		}
	}
	
	/*
	for(int i = 1 ; i <= n ; i ++)
		cout << a[i] << ' ';
	cout << endl;
	*/
	
	cout << ans;
	
	
	
	
	
	
	
}