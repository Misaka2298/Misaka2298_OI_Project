#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int,int> PII;

int n, ans;
PII upload[maxn];

signed main()
{
	cin >> n;
	int a, b;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a >> b;
		upload[i] = {a,b};
	}
	
	int flag = 0;
	sort(upload , upload + n);
	for(int i = 0 ; i < n ; i ++)
	{
		if(upload[i].second == 1)
		{
			ans += flag*20;
			flag = 0;
			ans += upload[i].first;
		} 
		else flag ++;
	}
	cout << ans;
	return 0;	
}