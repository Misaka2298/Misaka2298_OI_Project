//T1正解
#include <bits/stdc++.h>
using namespace std;

int n;
int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int getsum(int x)
{
	int sum = 0;
	if(x<10)
		return cost[x];
	else
	{
		while(x != 0)
		{
			sum += cost[x % 10];
			x /= 10;
		}
	}
	return sum;
}

signed main()
{
	cin >> n;
	int ans = 0;
	for(int i = 0 ; i <= 1000; i++)
		for(int j = 0 ; j <= 1000 ; j++)
			if(getsum(i) + getsum(j) + getsum(i+j) + 4 == n)
				ans++;
	cout << ans;
}