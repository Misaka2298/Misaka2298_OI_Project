// Problem: T633434 「Cfz Round 6」Kyu-kurarin
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T633434?contestId=255793
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-07-27 15:08:46
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;


int n, k, minest;
int cnt[maxn];
bool st[maxn];

bool spe = true, k1;

signed main()
{
	cin >> n >> k;
	k1 = (k == 1);

	for(int i = 0 ; i < n ; i ++)
	{
		int a;
		cin >> a;
		if(i && !st[a])
			spe = false;
		st[a] = 1;
		cnt[a] ++;
	}
	
	if(spe)
	{
		
	}
}