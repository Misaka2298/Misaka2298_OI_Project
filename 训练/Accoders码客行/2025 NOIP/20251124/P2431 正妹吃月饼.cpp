// Problem: P2431 正妹吃月饼
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2431
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-24 14:37:44

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

__int128 lima, limb;

void init()
{
	string a, b;
	cin >> a >> b;
	for(int i = 0 ; i < a.size() ; i ++)
		lima *= 10, lima += a[i] - '0';
	for(int i = 0 ; i < b.size() ; i ++)
		limb *= 10, limb += b[i] - '0';
}

void out(__int128 x)
{
	vector<int> nums;
	while(x)
	{
		nums.push_back(x % 10);
		x /= 10;
	}
	reverse(nums.begin(), nums.end());
	for(int i : nums)
		cout << i;
}

void solve()
{
	__int128 cake = 1, now = 0;
	LL ans = 0;
	stack<__int128> stk;
	while(now + cake <= limb)
	{
		now += cake;
		stk.push(cake);
		cake *= 2;
		ans ++;
	}
	if(now >= lima && now <= limb)
	{
		cout << ans;
		return ;
	}
	while(now + cake > limb)
	{
		now -= stk.top();
		stk.pop();
		ans --;
	}
	cout << ans+1;
}

signed main()
{
	init();
	solve();
	
}