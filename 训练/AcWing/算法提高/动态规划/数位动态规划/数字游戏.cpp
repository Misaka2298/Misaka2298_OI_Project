// Problem: 数字游戏
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1084/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-14 15:01:02

#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;

int l, r;
int f[maxn][maxn];

void init()
{
	for(int i = 0 ; i <= 9 ; i ++)
		f[1][i] = 1;
		
	for(int i = 2 ; i < maxn ; i ++)
		for(int j = 0 ; j <= 9 ; j ++)
			for(int k = j ; k <= 9 ; k ++)
				f[i][j] += f[i-1][k];
}

int dp(int u)
{
	if(!u)
		return 1;
	vector<int> nums;
	
	while(u)
		nums.push_back(u%10), u/=10;
	int res = 0, last = 0;
	
	for(int i = nums.size()-1 ; i >= 0 ; i --)
	{
		int x = nums[i];
		for(int j = last ; j < x ; j ++)
			res += f[i+1][j];
		
		if(x < last)
			break;
		last = x;
		
		if(!i)
			res ++;
	}
	return res;
		
}

signed main()
{
	init();
	while(cin >> l >> r)
		cout << dp(r) - dp(l-1) << endl;
}