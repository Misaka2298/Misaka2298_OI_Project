// Problem: P1203 [USACO1.1] 坏掉的项链 Broken Necklace
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1203
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-10-21 19:26:11

#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int ans;

int right(char col, int pos)
{
	int res = 0;
	for(int j = pos ; (str[j] == col || str[j] == 'w') && j < str.size() ; j ++)
		res ++;
	return res;
}

int left(char col, int pos)
{
	int res = 0;
	for(int j = pos-1 ; (str[j] == col || str[j] == 'w') && j >= 0 ; j --)
		res ++;
	return res;
}

signed main()
{
	cin >> n >> str;
	str += str;
	
	for(int i = 0 ; i < str.size() ; i ++)
	{	
		
		char now = str[i], last = str[i-1];
		
		int res = 0;
		if(now != 'w') res += right(now, i);
		else res = max(right('r', i), right('b', i));
		
		if(last != 'w') res += left(last, i);
		else res = max(left('r', i), left('b', i));

		
		ans = max(ans, res);
	}
	
	
	
	cout << min(ans, n);
}