#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;

int n, m, s[maxn];

int lowbit(int x)
{
	return x & -x;
}

void change(int x, int k)
{
	while(x <= n) s[x] += k, x += lowbit(x);
}

int query(int x)
{
	int t = 0;
	while(x) t += s[x], x -= lowbit(x);
	return t;
}

signed main()
{
	cin >> n >> m;
	int opt, x, y;
	for(int i = 1 ; i <= n ; i++)
		cin >> y, change(i,y);
	
	while(m--)
	{
		cin >> opt >> x >> y;
		if(opt == 1)
			change(x,y);
		else
			cout << query(y) - query(x-1) << endl;
	}
}