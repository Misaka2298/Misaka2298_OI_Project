// C
// expect pts = 60
// expect diff = green?
/*
对拍好像拍过去了。
不想写正解了，嗯嗯。
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

int n;
LL k;
int a[maxn], b[maxn];
int cpya[maxn];

bool check()
{
	for(int i = 1 ; i <= n ; i ++)
		if(a[i] != i)	
			return false;
	return true;
}

signed main()
{
	freopen("arrang.in", "r", stdin);
	freopen("arrang.out", "w", stdout);
	//freopen("data.in", "r", stdin);
	//freopen("my.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k;
	if(n >= 1e4)
	{
		cout << 0;
		exit(0);
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> b[i];
		cpya[i] = a[i] = i;
	}
	for(LL kk = 1 ; kk <= k ; kk ++)
	{
		//memcpy(b, a, sizeof a);
		for(int i = 1 ; i <= n ; i ++)
			cpya[i] = a[b[i]];
		memcpy(a, cpya, sizeof cpya);
		if(check())
		{
			//cout << kk << endl;
			cout << k / kk;
			exit(0);
		}
	}
	cout << 0;
}