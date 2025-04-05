#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10, mod = 23333;

int n;
int e[maxn], ne[maxn], h[maxn], idx;


void insert(int x)
{
	int hash = (x % mod + mod) % mod;
	e[idx] = x;
	ne[idx] = h[hash];
	h[hash] = idx++;
}

bool query(int x)
{
	int hash = (x % mod + mod) % mod;
	for(int i = h[hash] ; i != -1 ; i = ne[i])
		if(e[i] == x)
			return true;
	
	return false;	
}

signed main()
{
	cin.tie(0);
	memset(h, -1, sizeof h);
	cin >> n;
	int val = 0;
	int ans = 0;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> val;
		if(!query(val))
		{
			insert(val);
			ans ++;
		}
	}
	cout << ans;
	return 0;
}