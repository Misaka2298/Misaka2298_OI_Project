// Problem: P11231 [CSP-S 2024] 决斗
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P11231
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-10-25 10:46:43

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
int a[maxn], cnt[maxn], can[maxn];
int ans;
vector<int> pre;
bool st[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
		cnt[a[i]] ++;
		can[a[i]] ++;
		if(!st[a[i]])
			pre.push_back(a[i]), st[a[i]] = 1;
	}
	
	
	for(int i = 0 ; i < pre.size()-1 ; i ++)
	{
		int j = i + 1;
		int now = pre[i], ne = pre[j];
		if(ne == 0)
			break;
		//cout << now << ' ' << ne << endl;
		while(cnt[now] > 0)
		{
			ne = pre[j];
			int sub = min(cnt[now], can[ne]);
			cnt[now] -= sub;
			can[ne] -= sub;
				
			if(j+1 < pre.size()) j ++;
			else break;
		}
		//printf("%d %d %d %d\n", cnt[1], cnt[2], cnt[3], cnt[4]);
		//printf("%d %d %d %d\n\n", can[1], can[2], can[3], can[4]);
	}
	
	
	
	for(int i = 1 ; i <= 1e5+1 ; i ++)
		ans += cnt[i];
	
	cout << ans;	
	
}