//T1
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef unsigned long long uLL;

int n;
uLL a[maxn], res;
string str;

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0);cout.tie(0);
	
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(int i = 2 ; i <= n ; i++)
		a[i] *= a[i-1];
	
	
	str = to_string(a[n]);
	//cout << str << endl;
	for(int i = str.length()-1 ; i >= 0 ; i--)
	{
		if(str[i] == '0')
			res++;
		else
			break;
	}
		
	cout << res;
	
}