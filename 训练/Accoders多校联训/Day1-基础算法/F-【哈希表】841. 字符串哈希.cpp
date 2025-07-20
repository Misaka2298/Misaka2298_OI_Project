//F
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5+10, base = 13331;
typedef unsigned long long uLL;
#define endl '\n'

int n, q;
uLL hashval[maxn], bases[maxn];
char str[maxn];

void init()
{
	bases[0] = 1, hashval[0] = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		bases[i] = bases[i-1] * base;
		hashval[i] = hashval[i-1] * base + str[i];
	}
}

uLL getHash(int l, int r)
{
	return hashval[r] - hashval[l-1] * bases[r-l+1];
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);//fuck
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)
		cin >> str[i];
	
	init();
	
	while(q--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if(getHash(l1, r1) == getHash(l2, r2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}