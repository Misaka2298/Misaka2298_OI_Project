#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
#define endl '\n'

int n = 1e5+5, m, idx;
bool st[maxn];
bool dst[10];
bool ansst[maxn];
int ans[maxn];

vector<int> prime;

void primesol()
{
	for(int i = 2 ; i <= n ; i ++)
	{
		if(!st[i])
			prime.push_back(i);
		for(auto pri_j : prime)
		{
			if(i * pri_j > n)
				break;
			st[i * pri_j] = 1;
			if(i % pri_j == 0)
				break;
		}
	}
	
	for(int i = 2 ; i <= n ; i++)
		if(!st[i])
		{
			memset(dst, false, sizeof dst);
			string str = to_string(i);
			bool flag = true;
			for(int k = 0 ; k < str.size() ; k ++)
			{
				int j = str[k] - '0';
				if(dst[j])
				{
					flag = 0;
					break;
				}
				dst[j] = 1;
			}
			if(flag)
				ansst[i] = 1;
		}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	//freopen("super.in", "r", stdin);
	//freopen("super.out", "w", stdout);
	cin >> m;
	primesol();
	for(int i = 1 ; i <= n ; i ++)
	{
		ans[i] = ans[i-1] + ansst[i];
	}
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		cout << ans[r] - ans[l-1] << endl;
	}
	return 0;
}