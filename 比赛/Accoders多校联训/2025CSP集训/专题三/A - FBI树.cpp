// A
// expect pts = 100
// expect diff = orange

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
string a;
string s[maxn];

char check(string x)
{
	bool isI = true, isB = true;
	for(int i = 0 ; i < x.size() ; i ++)
	{
		if(x[i] == '0')
			isI = 0;
		
		if(x[i] == '1')
			isB = 0;
	}
	
	if(isI)
		return 'I';
	if(isB)
		return 'B';
	return 'F';
}

void built(string num, int u)
{
	s[u] = num;
	if(num.size() == 1)
		return;
	
	built(num.substr(0, num.size()/2), u*2);
	built(num.substr(num.size()/2), u*2+1);
}

void search(int u)
{
	if(s[u].size() > 1)
	{
		search(u*2);
		search(u*2+1);
	}
	cout << check(s[u]);
}

signed main()
{
	freopen("fbi.in", "r", stdin);
	freopen("fbi.out", "w", stdout);
	cin >> n >> a;
	built(a, 1);
	
	//cout << check("1100");
	search(1);
	
	
}