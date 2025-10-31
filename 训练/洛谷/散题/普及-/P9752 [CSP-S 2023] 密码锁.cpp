// Problem: P9752 [CSP-S 2023] 密码锁
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P9752
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-10-26 14:54:56

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n;
int a[10];
int ans;

unordered_map<string, int> cnt;
unordered_set<string> st;

string getstr()
{
	string res = "";
	for(int i = 1 ; i <= 5 ; i ++)
		res += to_string(a[i]);
	return res;
}

string getnum(int x)
{
	string res = to_string(x);
	if(res.size() == 5)
		return res;
	reverse(res.begin(), res.end());
	while(res.size() != 5)
		res += '0';
	reverse(res.begin(), res.end());
	return res;
}

signed main()
{
	cin >> n;
	for(int ii = 1 ; ii <= n ; ii ++)
	{
		for(int i = 1 ; i <= 5 ; i ++)
			cin >> a[i];
		st.insert(getstr());
		
		for(int i = 1 ; i <= 5 ; i ++)
		{
			int bkp = a[i];
			for(int j = 0 ; j <= 9 ; j ++)
			{
				a[i] = (a[i] + j) % 10;
				if(!st.count(getstr()))
				{
					cnt[getstr()] ++;
					//cout << getstr() << endl;
				}
				a[i] = bkp;
			}
			a[i] = bkp;
		}
		
		for(int i = 1 ; i < 5 ; i ++)
		{
			int bkpi = a[i], bkpii = a[i+1];
			for(int j = 0 ; j <= 9 ; j ++)
			{
				a[i] = (a[i] + j) % 10;
				a[i+1] = (a[i+1] + j) % 10;
				if(!st.count(getstr()))
				{
					cnt[getstr()] ++;
					//cout << getstr() << endl;
				}
				a[i] = bkpi;
				a[i+1] = bkpii;
			}
			a[i] = bkpi;
			a[i+1] = bkpii;
		}
		
		
		
	}
	
	for(int i = 0 ; i <= 99999 ; i ++)
			if(cnt[getnum(i)] == n)
				ans ++;
	cout << ans;
}