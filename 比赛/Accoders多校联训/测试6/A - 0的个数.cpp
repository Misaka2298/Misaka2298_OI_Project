// T1
// expect pts = 70

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n;
unsigned long long p = 1;

signed main()
{
	freopen("zero.in", "r", stdin);
	freopen("zero.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	unsigned long long a;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> a;
		if(a == 0)
		{
			cout << 1;
			exit(0);
		}
		p *= a;
		//cout << p << endl;
	}
	
	string str;
	str = to_string(p);
	//cout << p << ' ' << str << endl;
	int cnt = 0;
	for(int i = str.size()-1 ; i >= 0 ; i--)
	{
		if(str[i] == '0')
			cnt ++;
		else
			break;
	}
	cout << cnt;
	return 0;
}
