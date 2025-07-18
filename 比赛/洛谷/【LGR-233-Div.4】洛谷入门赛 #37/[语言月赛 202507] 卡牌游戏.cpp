#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4+10;

int n, len;
int num[maxn];
bool st[maxn];

signed main()
{
	cin >> n >> len;
	for(int i = 1 ; i <= n ; i ++)
		cin >> num[i];
	
	
	for(int i = 1 ; i <= len ; i ++)
	{
		cout << num[i] << ' ' << num[len+i] << ' ';
		st[i] = st[len+i] = true;
	}
	
	for(int i = 1 ; i <= n ; i++)
		if(!st[i])
			cout << num[i] << ' ';
}