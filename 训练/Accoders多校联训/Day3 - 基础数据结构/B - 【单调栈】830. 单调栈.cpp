// B
// Problem: 单调栈
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/832/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-22 08:44:36

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n, stk[maxn], tail;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
	{
		int a;
		cin >> a;
		while(a <= stk[tail] && tail) tail --;
		if(!tail) cout << -1 << ' ';
		else cout << stk[tail] << ' ';
		stk[++tail] = a;
	}
}