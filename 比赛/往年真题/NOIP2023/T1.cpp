#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000;
int n , m;
string str[maxn] , ustr[maxn]; // ustr内部是反字典序

signed main()
{
	cin >> n >> m;
	
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> str[i];
		sort(str[i].begin() , str[i].end());
		ustr[i] = str[i];
		reverse(ustr[i].begin() , ustr[i].end());
	}
		
	for(int i = 0 ; i < n ; i++)//当前为i时,i的字符串应该是最小的。
	{
		bool flag = true;
		for(int j = 0 ; j < n ; j++)
		{
			if(i == j) continue;
			if(str[i] > ustr[j]) flag = false;
		}
		cout << flag;
	}
	
	return 0;
}