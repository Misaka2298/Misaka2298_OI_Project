//T2
//I love C0ns1st, he is my gf
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;

int T, a[maxn], n, cnt[maxn];

signed main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		memset(cnt, 0, sizeof cnt);
		
		if(a[1] == 0 || a[1] == 1)
		{
			cout << "Bob" << endl;
			continue;
		}
		
		if(a[1] == 2 && a[2] == 1)
		{
			cout << "Bob" << endl;
			continue;
		}
		
		bool flag = false;
		for(int i = 2 ; i <= a[1] ; i ++)
			if(a[i] == 0 || a[i] == 1)
				flag = true;
		if(flag) 
		{
			cout << "Alice" << endl;
			continue;
		}
		
		flag = false;
		for(int i = 1 ; i <= a[i] ; i ++)
			if(a[i] != a[1])
				flag = true;
		if(flag)
		{
			cout << "Bob" << endl;
			continue;
		}
			
		
		vector<int> num;
		num.clear();
		bool st[maxn];
		memset(st, false, sizeof st);
		for(int i = 1 ; i <= n ; i ++)
			cnt[a[i]] ++, st[a[i]] = true;
		
		for(int i = 1 ; i <= n ; i ++)
			if(st[a[i]])
				num.push_back(a[i]);
		
		flag = false;
		for(int i = 0 ; i < num.size() ; i ++)
			if(num[i] == cnt[i])
				flag = true;
		if(flag)
		{
			cout << "Alice" << endl;
		}
		else
			cout << "Bob" << endl;
	}
	return 0;
}