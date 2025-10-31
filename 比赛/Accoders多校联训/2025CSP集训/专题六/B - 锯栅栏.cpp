// B
// expect pts = 0
// expect diff = black

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;

int n;
priority_queue<LL, vector<LL>, greater<LL>> q;
LL ans = 0;

signed main()
{
	freopen("plank.in", "r", stdin);
	freopen("plank.out", "w", stdout);
	cin >> n;
	while(q.size())
		q.pop();
	
	LL x = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> x;
		q.push(x);
	}
	
	while(q.size() >= 2)
	{
		LL x = q.top(); q.pop();
		LL y = q.top(); q.pop();
		q.push(x + y);
		ans += x + y;
	}
	
	cout << ans;	
	
}