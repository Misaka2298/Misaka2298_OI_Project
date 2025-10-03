//Tree1-B
#include <bits/stdc++.h>
using namespace std;

string midstr, behstr;

void div(string mid, string beh)
{
	if(mid.size() > 0)
	{
		char rt = beh[beh.size() - 1];
		cout << rt;
		int u = mid.find(rt);
		div(mid.substr(0, u), beh.substr(0, u));
		div(mid.substr(u+1), beh.substr(u, mid.size()-u-1));
	}
}

signed main()
{
	cin >> midstr >> behstr;
	
	div(midstr, behstr);
}