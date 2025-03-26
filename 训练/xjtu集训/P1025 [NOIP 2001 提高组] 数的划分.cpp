#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

int dfs(int last, int nownum, int utick)
{
	if(utick == 1)
		return 1;
	
	int cnt = 0;
	
	for(int i = last ; i <= nownum / utick; i++)
		cnt += dfs(i, nownum-i, utick-1);
	return cnt;
}

signed main()
{
	cin >> n >> k;
	cout << dfs(1,n,k);
	
}