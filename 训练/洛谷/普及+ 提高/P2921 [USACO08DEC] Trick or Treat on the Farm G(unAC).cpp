#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int n, ne[maxn];
bool st[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> ne[i];
	
	for(int i = 1 ; i <= n ; i++)
	{
		int cnt = 0;
		memset(st, false, sizeof st);
		for(int j = i ; !st[j] ; j = ne[j])
			cnt++, st[j] = true;
		cout << cnt << endl;
	}
}