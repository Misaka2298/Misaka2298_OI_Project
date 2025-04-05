#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long uLL;
typedef long long LL;
const int maxn = 1000010, P = 13331;

LL ans;
int n;
char s[maxn];
uLL hh[maxn], tt[maxn], p[maxn];

int check(int x)
{
	int l = 0 , r = min(x, n-x);
	while(l<r)
	{
		int mid = l+r+1 >>1;
		if(hh[x] - hh[x-mid] * p[mid] == tt[x+1] - tt[x+mid+1] * p[mid]) l = mid;
		else r = mid-1;
	}
	return l;
}

signed main()
{
	cin >> n >> s+1;
	p[0] = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		p[i] = p[i-1] * P;
		hh[i] = hh[i-1] * P + s[i] - '0';
	}
	for(int i = n ; i >= 1 ; i--)
		tt[i] = tt[i+1] * P + 1 - (s[i] - '0');
	for(int i = 1 ; i < n ; i++)
		ans += check(i);
	cout << ans;
}