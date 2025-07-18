//T8
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3+10;
#define endl '\n'

struct Dict{
	int id;
	string str;
}dicts[maxn];

int n, k, s;
string S;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k >> s;
	for(int i = 1 ; i <= k ; i++)
	{
		cin >> dicts[i].str;
		dicts[i].id = i;
	}
	cin >> S;
	
	string P;
	int len = S.length();
	for(int i = 0 ; i <= len-1 ; i++)
	{
		char c = S[i];
		string tmpp = P + c;
		bool flag = false;
		for(int i = 1 ; i <= k ; i++)
			if(tmpp == dicts[i].str)
			{
				flag = true;
				break;
			}
		if(flag)
		{
			P += c;
			continue;
		}
		else
		{
			dicts[++k].str = P+c;
			dicts[k].id = k;
			if(k == 1) cout << 1 << ' ';
			else
				for(int i = 1 ; i <= k ; i++)
					if(dicts[i].str == P)
					{
						cout << dicts[i].id << ' ';
						break;
					}
			P = c;
		}
	}
	
	for(int i = 1 ; i <= k ; i ++)
		if(dicts[i].str == P)
		{
			cout << dicts[i].id << ' ';
			break;
		}
	
	cout << endl << k << endl;
	for(int i = 1 ; i <= k ; i++)
		cout << dicts[i].str << endl;
}