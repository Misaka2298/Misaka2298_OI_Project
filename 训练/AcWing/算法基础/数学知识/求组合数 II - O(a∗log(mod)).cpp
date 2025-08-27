// Problem: 求组合数 II - O(a∗log(mod))
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/888/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-08-27 20:40:04

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, mod = 1e9+7;
typedef long long LL;
#define endl '\n'

int n;
int fact[maxn], infact[maxn];

int qmi(int a, int b, int p)
{
	int res = 1 % p;
	while(b)
	{
		if(b & 1)
			res = (LL)res * a % p;
		a = a * (LL)a % p;
		b >>= 1;
	}
	return res;
}

signed main()
{
	cin >> n;
	fact[0] = infact[0] = 1;
	for(int i = 1 ; i < maxn ; i ++)
	{
		fact[i] = (LL)fact[i-1] * i % mod;
		infact[i] = (LL)infact[i-1] * qmi(i, mod-2, mod) % mod;
	}
	
	while(n--)
	{
		int a, b;
		cin >> a >> b;
		cout << (LL)fact[a] * infact[b] % mod * infact[a-b] % mod << endl;
	}
}






