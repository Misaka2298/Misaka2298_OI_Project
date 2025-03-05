#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, base = 23333;

int n, e[maxn], ne[maxn], h[maxn], idx;

void insert(int x)
{
	int hash = (x % base + base) % base;
	e[idx] = x;
	ne[idx] = h[hash];
	h[hash] = idx++;
}

void query(int x)
{
	int hash = (x % base + base) % base;
	for(int i = h[hash] ; i != -1 ; i = ne[i])
		if(e[i] == x)
		{
			cout << "Yes" << endl;
			return;
		}	
	cout << "No" << endl;
	return ;
}

signed main()
{
	cin >> n;
	char opt[2];
	int a;
	memset(h, -1, sizeof h);
	while(n--)
	{
		cin >> opt >> a;
		if(*opt == 'I') insert(a);
		else query(a);
	}
}