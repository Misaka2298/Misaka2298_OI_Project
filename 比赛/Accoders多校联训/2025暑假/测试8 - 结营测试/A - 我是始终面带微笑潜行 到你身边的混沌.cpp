// T1
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6+10;
typedef long long LL;
#define endl '\n'

int n;
LL cnt[maxn];

bool check(LL l, LL r)
{
	
}

void init()
{
	freopen("sanchi.in", "r", stdin);
	freopen("sanchi.out", "w", stdout);
	string str;
	bool is2 = 0;
	for(int i = 0 ; i < maxn ; i ++)	
	{
		if(str[str.size()-1] == '1')
		{
			str[str.size()-1] = '2';
			is2 = 1;
			cnt[i] = cnt[i-1] + is2;
		}
		else if(str[str.size()-1] == '0')
		{
			str[str.size()-1] = '1';
			cnt[i] = cnt[i-1] + is2;
		}
		else
		{
			int l = -1;
			for(int j = str.size()-1 ; j >= 0 ; j --)
				if(str[j] != '2')
				{
					l = j;
					break;
				}
			if(l == -1)
			{
				for(int j = 0 ; j < str.size() ; j ++)
					str[j] = '0';
				str = '1' + str;
				is2 = 0;
			}
			else
			{
				if(str[l] == '1')
				{
					str[l] = '2';
					is2 = 1;
					cnt[i] = cnt[i-1] + is2;
				}
				else if(str[l] == '0')
				{
					str[l] = '1';
					cnt[i] = cnt[i-1] + is2;
				}
				
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	LL l, r;
	while(n--)
	{
		cin >> l >> r;
		check(l, r);
		
	}
}