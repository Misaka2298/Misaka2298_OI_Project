#include <bits/stdc++.h>
using namespace std;

int T;
int l ,r;
int every[15];

void check(int x)
{
	int len = 0, cpyx = x;
	while(cpyx > 0)
	{
		every[len] = cpyx % 10;
		cpyx/=10;
		len++;
	}
	if(len % 2 == 0) return;
	if(len == 1)
	{
		cout << x << ' ';
		return;
	}
	int mid = len/2;
	if(every[len-1] == every[0] && every[0] == every[mid] && every[len-1] == every[mid])
	{
		cout << x;
		cout << ' ';
		return ;
	}
}

signed main()
{
	cin >> T;
	while(T--)
	{
		cin >> l >> r;
		for(int i = l ; i <= r ; i++)
			check(i);
		cout << endl;
	}
	return 0;
}