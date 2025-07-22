//E
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

unordered_map<int,bool> mp;

int q;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> q;
	while(q--)
	{
		char opt;
		int x;
		cin >> opt >> x;
		if(opt == 'I')
		{
			mp[x] = 1;
		}
		else
		{
			if(mp[x] == true)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}