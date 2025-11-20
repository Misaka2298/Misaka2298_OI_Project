// Problem: B4218 [常州市赛 2023] ABC 字符串
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B4218
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-18 10:50:14

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ans;

vector<string> unsorted;
vector<string> sorted;

bool cmp(char A, char B)
{
	return A > B;
}

void init()
{
	string tmp;
	cin >> tmp;
	
	for(int i = 0 ; i < tmp.size() ; i ++)
	{
		if(tmp[i] == 'A' || (tmp[i] == 'B' && tmp[i+1] == 'C'))
		{
			string str;
			while(tmp[i] == 'A' || (tmp[i] == 'B' && tmp[i+1] == 'C'))
			{
				if(tmp[i] == 'A')
					str += 'A';
				else
				{
					str += 'X';
					i ++;
				}
				i ++;
			}
			unsorted.push_back(str);
			//sort(str.begin(), str.end(), cmp);
			//sorted.push_back(str);
		}
	}
}


void solve()
{
	for(auto str : unsorted)
	{
		LL cnt = 0, res = 0;
		reverse(str.begin(), str.end());
		for(int i = 0 ; i < str.size() ; i ++)
		{
			if(str[i] == 'A')
			{
				res += (i - cnt);
				cnt ++;
			}
		}
		ans += res;
	}
}

signed main()
{
	init();
	
	solve();
	
	cout << ans;
	
}