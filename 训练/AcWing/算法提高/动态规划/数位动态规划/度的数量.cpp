// Problem: 度的数量
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1083/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-14 11:17:32

#include <bits/stdc++.h>
using namespace std;
const int maxn = 45;

int c[maxn][maxn];
int l, r, k, b;

void init()
{
	for(int i = 0 ; i < maxn ; i ++)
		for(int j = 0 ; j <= i ; j ++)
		{
			if(j == 0)
				c[i][j] = 1;
			else
				c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
}

int dp(int u)
{
	if(u == 0)
		return 0;
		
	vector<int> nums;
	
	while(u)
		nums.push_back(u%b), u /= b;
	
	int res = 0, last = 0;
	
	for(int i = nums.size()-1 ; i >= 0 ; i --)
	{
		int x = nums[i];
		if(x > 0)
		{
			res += c[i][k-last];
			if(x > 1)
			{
				if(k-last-1 >= 0)
					res += c[i][k-last-1];
				break;
			}
			else
			{
				last ++;
				if(last > k)
					break;
			}
		}
		if(i == 0 && last == k) res++; 
	}
	return res;
}

signed main()
{
	cin >> l >> r >> k >> b;
	init();
	
	cout << dp(r) - dp(l-1);
	
}