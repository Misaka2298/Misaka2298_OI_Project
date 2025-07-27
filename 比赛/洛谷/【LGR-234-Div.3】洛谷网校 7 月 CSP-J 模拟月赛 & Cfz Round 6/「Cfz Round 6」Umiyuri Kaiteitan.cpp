// Problem: T633433 「Cfz Round 6」Umiyuri Kaiteitan
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T633433?contestId=255793
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-07-27 14:25:08
// expect pts = 100

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;

int n, m;
bool st[maxn];
long long latestsize = -1;//first space-key epsilon
long long sz[maxn];

signed main()
{
	//freopen("list.in", "r", stdin);
	//freopen("list.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	string tmp;
	while(n--)
	{
		int a;
		cin >> a;
		tmp = to_string(a);
		if(!st[a])
		{
			st[a] = true;
			latestsize += 1 + tmp.size();
		}
		sz[a] = latestsize;
		//cout << tmp.size() << ' ';
	}
	//cout << endl;
	for(int i = 1 ; i <= m ; i ++)
		cout << sz[i] << ' ';
}