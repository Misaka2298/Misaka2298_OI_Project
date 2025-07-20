//G
#include <bits/stdc++.h>
using namespace std;

int q;

int onecount(int x)
{
	int cnt = 0;
	for(int i = 0 ; i < 32 ; i ++)
	{
		if((x >> i) & 1 == 1)
			cnt ++;
	}
	return cnt;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		cout << onecount(x) << ' ';
	}
}