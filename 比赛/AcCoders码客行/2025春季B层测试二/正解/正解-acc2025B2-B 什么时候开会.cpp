#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int n, req;
int freee[maxn];

signed main()
{
	cin >> n >> req;
	for(int i = 0 ; i < n ; i ++)
	{
		int day;
		cin >> day;
		while(day--)
		{
			int time;
			cin >> time;
			freee[time] ++;
		}
	}
	
	int maxtech = INT_MIN;
	for(int i = 0 ; i < 100 ; i ++)
		maxtech = max(maxtech, freee[i]);
	
	if(maxtech < req)
	{
		cout << 0;
		exit(0);
	}
	for(int i = 0 ; i < 100 ; i ++)
		if(freee[i] == maxtech)
		{
			cout << i;
			return 0;
		}
}