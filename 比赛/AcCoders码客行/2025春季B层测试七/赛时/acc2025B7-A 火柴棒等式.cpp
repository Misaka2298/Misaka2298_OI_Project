//T1
#include <bits/stdc++.h>
using namespace std;

int n;
int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

signed main()
{
	cin >> n;
	n -= 4;//+ & = 's cost
	
	int ans = 0;
	for(int i = 0 ; i <= 9 ; i ++)
		for(int j = 0 ; j <= 9 ; j ++)
			if(n - cost[i] - cost[j] - cost[i-j] == 0 && i-j>=0)
				ans++;//cout << i-j << ' ' << j << ' ' << i << endl;// ans++;
	//可优化，但我懒得改。
	//C == i, B == j, A = i-j
	cout << ans;
}