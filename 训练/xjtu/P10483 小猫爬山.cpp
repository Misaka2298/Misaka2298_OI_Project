#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;

int n, W, w[maxn];
int ans;
bool st[maxn];
int weight[maxn];//weight[i] = 第i号缆车当前载重

void dfs(int u, int cnt)
{
	if(cnt >= ans)
		return;
	if(u == n)
	{
		ans = cnt;
		return;
	}
	
	for(int i = 0 ; i < cnt ; i++)
		if(weight[i] + w[u] <= W)
		{
			weight[i] += w[u];
			dfs(u+1, cnt);
			weight[i] -= w[u];
		}
		
	weight[cnt] = w[u];
	dfs(u+1, cnt+1);
	weight[cnt] = 0;
}

signed main()
{
	cin >> n >> W;
	for(int i = 0 ; i < n ; i++)
		cin >> w[i];
		
	ans = n;
	sort(w, w+n, greater<int>());
	dfs(0,0);
	cout << ans;
	
}