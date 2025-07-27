// Problem: T633432 「Cfz Round 6」Yumemi
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T633432?contestId=255793
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-07-27 14:01:12
// expect pts = 100

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string str;
int n;
unsigned long long goal;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> goal;
	while(n--)
	{
		cin >> str;
		bool isspe = false;
		for(int i = 0 ; i < str.size() ; i ++)
			if(str[i] == '0')
			{
				cout << "kawaii" << endl;
				isspe = true;
				break;
			}
		if(isspe)
			continue;
		bool flag = true;
		unsigned long long pow = 1;
		for(int i = 0 ; i < str.size() ; i ++)
		{
			char now = str[i];
			pow *= ((unsigned long long)now-48);
			if(pow > goal)
			{
				cout << "dame" << endl;
				flag = false;
				break;
			}
		}
		if(flag) cout << "kawaii" << endl;
	}
}