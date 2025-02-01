#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int d[maxn],h[maxn];//d为鸽子在的位置，h为鸽子数
int n, q, ans;
bool st[maxn];//为答案做了贡献？

signed main()
{
	cin >> n >> q;
	fill(h,h+n+1,1);
	for(int i = 1 ; i <= n ; i++)
		d[i] = i;
	
	while(q--)
	{
		int qq, a, b;
		cin >> qq;
		if(qq == 1)
		{
			cin >> a >> b;
			h[d[a]] --;
			h[b] ++;
			
			if(h[b] >= 2 && !st[b])
			{
				ans++;
				st[b] = true;
			}
			
			if(h[d[a]] <= 1 && st[d[a]])
			{
				ans--;
				st[d[a]] = false;
			}
			//cout << h[d[a]] << st[d[a]] << d[a]  << endl;
			d[a] = b;
			
		}
		if(qq == 2)
			cout << ans << endl;
	}
	
	return 0;
}