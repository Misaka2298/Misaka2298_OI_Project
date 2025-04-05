#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m, arr[maxn], b[maxn];

void insert(int l, int r, int c)
{
	b[l] += c;
	b[r+1] -= c;
}

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> arr[i];
		
	for(int i = 1 ; i <= n ; i++)
		insert(i, i, arr[i]);
		
	int ll, rr, cc;
	while(m--)
	{
		cin >> ll >> rr >> cc;
		insert(ll, rr, cc);
	}
	
	for(int i = 1 ; i <= n ; i ++)
		b[i] += b[i-1];
		
	for(int i = 1 ; i <= n ; i++)
		cout << b[i] << ' ';
	
}