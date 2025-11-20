// Problem: P11362 [NOIP2024] 遗失的赋值
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P11362?contestId=217331
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-18 15:38:52

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100, mod = 1e9+10;//debug!!!

int T;
int n, m, v;
int arr[maxn], lim[15];
int ans;

void getlimit(int &a, int &b, int type)
{
	if(type == 1)
		a = 1, b = 1;
	if(type == 2)
		a = 1, b = 2;
	if(type == 3)
		a = 2, b = 1;
	if(type == 4)
		a = 2, b = 2;
}

bool dfssol()
{
	// 11, 12, 21, 22
	int bkparr[maxn];
	memcpy(bkparr, arr, sizeof arr);
	
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		getlimit(a, b, lim[i]);
		
		if(arr[i] && arr[i] == a)
		{
			if(arr[i+1] && arr[i+1] != b)
				return false;
			arr[i] = a;// arr[i+1] = 3;
		}
	}
	
	memcpy(arr, bkparr, sizeof bkparr);
	return true;
}

void dfs(int u)
{
	if(u == n)
	{
		if(dfssol())
			ans = (ans + 1) % mod;
		
		return;
	}
	
	for(int i = 1 ; i <= 4 ; i ++)
	{
		lim[u] = i;
		dfs(u+1);
	}
}

void sol1()
{
	memset(arr, 0, sizeof arr);
	bool haveans = 1;
	for(int i = 1 ; i <= m ; i ++)
	{
		int x, y;
		cin >> x >> y;
		if(arr[x] && arr[x] != y)
		{
			haveans = 0;
			break;
		}
		arr[x] = y;
	}
	
	if(haveans)
		dfs(1);
	
	cout << ans << endl;
}

signed main()
{
	cin >> T;
	while(T --)
	{
		ans = 0;
		cin >> n >> m >> v;
		if(n <= 12 && v == 2)
			sol1();
	}
}