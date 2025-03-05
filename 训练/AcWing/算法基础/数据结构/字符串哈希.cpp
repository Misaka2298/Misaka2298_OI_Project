#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, base = 13331;
typedef unsigned long long uLL;

int n, m;
char str[maxn];
uLL p[maxn], h[maxn];

void init()
{
	p[0] = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		h[i] = h[i-1] * base + str[i];
		p[i] = p[i-1] * base;
	}
}

uLL get(int l, int r)
{
	return h[r] - h[l-1] * p[r-l+1];
}

signed main()
{
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i++)
		cin >> str[i];
		
	init();	
	
	
	int l1, r1, l2, r2;
	while(m --)
	{
		cin >> l1 >> r1 >> l2 >> r2;
		if(get(l1,r1) == get(l2,r2)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
