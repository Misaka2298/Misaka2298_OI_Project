// Problem: P2675 《瞿葩的数字游戏》T3-三角圣地
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2675
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-11-22 10:04:46

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10, p = 10007;
typedef long long LL;

int n, ans;
int l[maxn], r[maxn];
int arr[maxn];
int fac[maxn];
int idx = 0;

int qmi(int a, int b)
{
	int res = 1 % p;
	while(b)
	{
		if(b & 1)
			res = (LL)res * a % p;
		a = (LL)a * a % p;
		b >>= 1;
	}
	return res;
}

int infac(int a)
{
	return qmi(fac[a], p-2);
}

int C(int a, int b)
{
	if(b > a)
		return 0;
	return (fac[a] * infac(b) % p) * infac(a-b) % p;
}

LL lucas(LL a, LL b)
{
	if(!b)
		return 1;
	if(a < p && b < p)
		return C(a, b);
	return (LL)(C(a%p, b%p) * lucas(a/p, b/p)) % p;
}

void init()
{
	cin >> n;
	bool flag = 0;
	int lidx = 0, ridx = 0;
	for(int i = 1 ; i <= n ; i ++, flag ^= 1)
	{
		if(flag)
			l[++lidx] = i;
		else
			r[++ridx] = i;
	}
	
	for(int i = 1 ; i <= lidx ; i ++)
		arr[++idx] = l[i] % p;
	for(int i = ridx ; i >= 1 ; i --)
		arr[++idx] = r[i] % p;
		
	fac[0] = 1;
	for(int i = 1 ; i < p ; i ++)
		fac[i] = fac[i-1] * i % p;
}

void solve()
{
	for(int i = 1 ; i <= n ; i ++)
		ans = (ans % p + (arr[i] * lucas(n-1, i-1) % p) % p) % p;
	
	cout << ans;
}

signed main()
{
	init();
	
	solve();
}

