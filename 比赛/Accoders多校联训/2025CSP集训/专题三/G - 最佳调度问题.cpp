// G
// expect pts = 50
// expect diff = yellow

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
#define endl '\n'

int n, k;
int tasks[maxn], machine[maxn];
int ans = 0x3f3f3f3f;

void dfs(int u)
{
	int now = 0;
	for(int i = 1 ; i <= k ; i ++)
		now = max(now, machine[i]);
	if(now > ans)
	{
		//cout << "cut" << endl;
		return;
	}
		
	
	if(u > n)
	{
		int res = 0;
		for(int i = 1 ; i <= k ; i ++)
			res = max(res, machine[i]);
		ans = min(ans, res);
		return;
	}
	
	for(int i = 1 ; i <= k ; i ++)
	{
		machine[i] += tasks[u];
		dfs(u+1);
		machine[i] -= tasks[u];
	}
}

signed main()
{
	freopen("work.in", "r", stdin);
	freopen("work.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> tasks[i];
	
	sort(tasks+1, tasks+1+n);
	dfs(1);
	
	cout << ans;
}