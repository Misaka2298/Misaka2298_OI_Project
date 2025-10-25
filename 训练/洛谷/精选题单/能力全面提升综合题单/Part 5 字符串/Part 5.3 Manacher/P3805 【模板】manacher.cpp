// Problem: P3805 【模板】manacher
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3805
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-10-25 08:27:14

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.2e7+10;

string cinstr, str;
int p[maxn], ans;

void manacher()
{
	int r = 0, c = 0;
	for(int i = 0 ; i < str.size() ; i ++)
	{
		if(i < r)
			p[i] = min(p[2*c-i], r-i);
		else
			p[i] = 1;
			
		while(i - p[i] >= 0 && i + p[i] < (int)str.size() && str[i-p[i]] == str[i+p[i]])
			p[i] ++;
		
		if(i + p[i] > r)
		{
			r = i + p[i];
			c = i;
		}
		ans = max(p[i]-1, ans);
	}
}

signed main()
{
	cin >> cinstr;
	
	for(char chr : cinstr)
	{
		str += '#';
		str += chr;
	}
	str += '#';
	//cout << str << endl;
	
	manacher();
	cout << ans;
}