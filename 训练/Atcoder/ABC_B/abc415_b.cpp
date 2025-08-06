// Problem: B - Pick Two
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2025#2 (AtCoder Beginner Contest 415)
// URL: https://atcoder.jp/contests/abc415/tasks/abc415_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Time: 2025-08-05 18:31:38

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

string s;

signed main()
{
	cin >> s;
	int tick = 1;
	for(int i = 0 ; i < s.size() ; i ++)
	{
		if(s[i] == '#')
		{
			if(tick == 1)
				cout << i+1 << ',', tick ++;
			else
				cout << i+1 << endl, tick = 1;
		}
	}
}