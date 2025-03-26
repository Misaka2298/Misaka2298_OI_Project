#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;

int n, m, s[maxn], a[maxn];

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
	int opt, x, y, k;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
		
	while(m--)
	{
		cin >> opt >> x;
		if(opt == 1)
		{
			cin >> y >> k;
			change(x,k); change(y+1, -k);
		}
		else
		{
			cout << a[x] + query(x) << endl;
		}
	}
}