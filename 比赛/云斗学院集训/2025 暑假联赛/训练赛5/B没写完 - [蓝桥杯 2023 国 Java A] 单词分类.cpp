// T2
// Who is NaiLoong?
// oh, It's C0ns1st!!!!!
// #define int long long
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10, mod = 1e9+7;
typedef long long LL;

int n, k;
int tire[maxn][26];
bool st[maxn];
char str[maxn]

void insert(char *a)
{
	int p = 0;
	for(int i = 0; a[i]; i++)
	{
		int u = a[i] - 'a';
		if(!tire[p][u]) 
			tire[p][u] = ++idx;
		
		p = tire[p][u];
	}
	st[p] = 1;
}

int query(char *a)
{
	int p = 0;
	for(int i = 0 ; a[i] ; i++)
	{
		int u = a[i] - 'a';
		if(!son[p][u]) return 0;
		p=son[p][u];
	}
	return cnt[p];
}

void sol()
{
	LL ans = 0;
	int p = 0;
	
}

signed main()
{
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> str;
		insert(str);
	}
	
	
	//sol();
}