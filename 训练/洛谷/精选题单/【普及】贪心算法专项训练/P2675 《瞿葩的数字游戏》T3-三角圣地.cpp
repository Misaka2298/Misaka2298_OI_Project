// Problem: P2675 《瞿葩的数字游戏》T3-三角圣地
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2675
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-11-22 10:04:46

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010, mod = 10007;

int n;
vector<int> l, r;
int arr[maxn][maxn];
int idx = 0;

signed main()
{
	cin >> n;
	bool flag = 0;
	for(int i = 1 ; i <= n ; i ++, flag ^= 1)
	{
		if(flag)
			l.push_back(i);
		else
			r.push_back(i);
	}
	reverse(r.begin(), r.end());
	
	for(auto x : l)
		arr[1][++idx] = x;
	for(auto x : r)
		arr[1][++idx] = x;
	
	for(int i = 2 ; i <= idx ; i ++)
	{
		for(int j = 1 ; j <= idx-i+1 ; j ++)
			arr[i][j] = (arr[i-1][j] + arr[i-1][j+1]) % mod;
	}
	
	cout << arr[n][1];
}