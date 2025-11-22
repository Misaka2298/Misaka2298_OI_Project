// Problem: P11361 [NOIP2024] 编辑字符串
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P11361
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-21 14:18:46

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int T;
int n;
bool s[3][maxn], st[3][maxn];

int idx[3];
struct Range{
	int l, r, cnt;
}ranges[3][maxn];
int ans = 0;

void init()
{
	cin >> n;
	string tmp;
	cin >> tmp;
	for(int i = 0 ; i < n ; i ++)
		s[0][i+1] = (tmp[i] - '0');
	cin >> tmp;
	for(int i = 0 ; i < n ; i ++)
		s[1][i+1] = (tmp[i] - '0');
	cin >> tmp;
	for(int i = 0 ; i < n ; i ++)
		st[0][i+1] = (tmp[i] - '0');
	cin >> tmp;
	for(int i = 0 ; i < n ; i ++)
		st[1][i+1] = (tmp[i] - '0');
	
	memset(idx, 0, sizeof idx);
	ans = 0;
}

void init_ranges(int layer)//s1 or s2
{
	Range u = {1, 0, 0};
	for(int i = 1 ; i <= n ; i ++)
	{
		if(!st[layer][i])
		{
			if(u.cnt)
				ranges[layer][++idx[layer]] = u;
			
			if(s[layer][i])
				ranges[layer][++idx[layer]] = {i, i, 1};
			u = {i+1, 0, 0};
		}
		else
		{
			u.r = i;
			u.cnt += s[layer][i];
		}
	}
	if(u.cnt)
		ranges[layer][++idx[layer]] = u;
}

int getcount(int layer)
{
	int res = 0;
	for(int i = 1 ; i <= n ; i ++)
		res += s[layer][i];
	return res;
}

void solve()
{
	int u = 0;
	ans = n - getcount(0) - getcount(1);
	
	for(int i = 1 ; i <= idx[1] ; i ++)
	{
		while(u <= idx[0] && ranges[0][u].r < ranges[1][i].l)
			u ++;
		
		if(u <= idx[0])
		{
			int t = u;
			
			while(t <= idx[0] && ranges[0][t].l <= ranges[1][i].r && ranges[1][i].cnt)
			{
				int len1 = ranges[0][t].r - ranges[1][i].l + 1;
				int len2 = ranges[1][i].r - ranges[0][t].l + 1;
				int sub = min({len1, len2, ranges[0][t].cnt, ranges[1][i].cnt});
				
				ans += sub * 2;
				ranges[0][t].cnt -= sub;
				ranges[1][i].cnt -= sub;
				t ++;
			}
			 
			while(u <= idx[0] && !ranges[0][u].cnt)
				u ++;
		}
	}
	cout << ans << endl;
}

signed main()
{
	cin >> T;
	for(int t = 1 ; t <= T ; t ++)
	{
		init();
		
		init_ranges(0);
		init_ranges(1);
		
		solve();
	}
}