// Problem: CF767A Snacktower
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF767A
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Time: 2025-10-28 20:03:35

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
#define endl '\n'

int n, k, x;
int a[maxn], b[maxn];
bool st[maxn];

bool cmp(int a, int b)
{
	return a > b;
}

signed main()
{
	cin >> n;
	k = n;
	for(int i = 1 ; i <= n ; i ++)
	{ 
		cin >> x;
		st[x] = 1; 
		if(x == k)
		{
			cout << k << ' ';
			k --;
			while(st[k])
			{
				cout << k << ' ';
				k --;
			}
		} 
		cout << endl;
	}
	return 0;

	
}