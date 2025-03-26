#include <bits/stdc++.h>
using namespace std;
const int maxn = 70;

int n, a[maxn], sum, cnt, len;
bool used[maxn];

void dfs(int u, int cur, int start)
{
	if(u > cnt)
	{
		cout << len;
		exit(0);
	}
	
	if(cur == len)
	{
		dfs(u+1, 0, 1);
		return;
	}
	
	for(int i = start ; i <= n ; i++)
	{
		if(used[i] || cur + a[i] > len) continue;
		used[i] = true;
		dfs(u, cur + a[i], i+1);
		used[i] = false;
		
		
		if(cur == 0) return;
		if(cur + a[i] == len) return;
		while(i < n && a[i] == a[i+1]) i++;
	}
}

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	sort(a+1, a+n+1, greater<int>());
	
	for(len = a[1] ; ; len ++)
	{
		if(sum % len != 0) continue;
		cnt = sum / len;
		dfs(1, 0, 1);
	}
	return 0;
}