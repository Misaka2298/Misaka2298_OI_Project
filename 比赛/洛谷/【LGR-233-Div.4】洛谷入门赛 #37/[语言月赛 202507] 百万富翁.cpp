//T3
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, money, goal;
int cost[maxn], reward[maxn];

signed main()
{
	cin >> n >> money >> goal;
	for(int i = 1 ; i <= n ; i++)
		cin >> cost[i] >> reward[i];
	
	for(int i = 1 ; i <= n ; i ++)
	{
		if(money < cost[i])
			break;
		
		money -= cost[i];
		money += reward[i];
		
		if(money >= goal)
			break;
	}
	cout << money;
}