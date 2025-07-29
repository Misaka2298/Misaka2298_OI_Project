//https://www.luogu.com.cn/problem/P8218
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;

int n, m;
LL val[maxn], a[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> val[i];
		
	for(int i = 1 ; i <= n ; i++)
		a[i] = val[i] + a[i-1];
	
	/*	
	for(int i = 1 ; i <= n ; i++)
		cout << a[i] << ' ';
	cout << endl;
	*///debug
	
	cin >> m;
	int l, r;
	for(int i = 0 ; i < m ; i++)
	{
		cin >> l >> r;
		cout << a[r] - a[l-1] << endl;
	}
	return 0;
}