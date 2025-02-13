#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int n, m;
bool st[maxn];

signed main()
{
	cin >> n >> m;
	int a, cnt = 0;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> a;
		st[a] = true;
	}
	
	for(int i = 1 ; i <= n ; i++)
		if(!st[i]) cnt++;
		
	cout << cnt << endl;
	
	for(int i = 1 ; i <= n ; i++)
		if(!st[i])
			cout << i << ' ';
	return 0;
}

/*
signed main()
{
	cin >> n >> m;
	int a, cnt = n;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> a;
		st[a] = true;
		cnt--;
	}
	
	if(cnt != 0) cout << cnt << endl;
	for(int i = 1 ; i <= n ; i++)
		if(!st[i])
			cout << i << ' ';
	return 0;
}
*/