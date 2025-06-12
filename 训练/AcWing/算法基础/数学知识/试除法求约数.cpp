//https://www.acwing.com/problem/content/871/
#include <bits/stdc++.h>
using namespace std;

int n, val;

void solve(int x)
{
	priority_queue<int,vector<int>,greater<int>>q;
	for(int i = 1 ; i <= x / i ; i++)
	{
		if(x % i == 0)
		{
			int a = x/i;
			q.push(i);
			if(i != a)
				q.push(a);
		}
	}
	while(q.size())
		cout << q.top() << ' ' , q.pop();
	cout << endl;
	return;
}

signed main()
{
	cin >> n;
	while(n--)
	{
		cin >> val;
		solve(val);
	}
	return 0;
}