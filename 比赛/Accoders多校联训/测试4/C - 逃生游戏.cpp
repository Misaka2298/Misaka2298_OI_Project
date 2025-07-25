// T3
// expect pts = >=10
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
#define endl '\n'
typedef long long LL;

int n;
int cnt[maxn];
LL score;

signed main()
{
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
	cin >> n;
	bool spe = true;
	for(int i = 0 ; i < n ; i ++)
	{
		int a;
		cin >> a;
		cnt[a] ++;
		if(a != 1)
			spe = false;
	}
	
	if(spe)
	{
		cout << n;
		exit(0);
	}
	
	for(int i = 1e6 ; i >= 1 ; i --)
	{
		LL nowpts = 0;
		if(cnt[i]*i > cnt[i-1]*(i-1) + cnt[i+1]*(i+1))
		{
			score += cnt[i] * i;
			cnt[i-1] = cnt[i] = cnt[i+1] = 0;
		}
	}
	cout << score;
}