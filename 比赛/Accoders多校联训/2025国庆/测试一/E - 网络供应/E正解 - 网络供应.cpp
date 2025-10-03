// T5 正解
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int T;
int n;
int a[maxn], b[maxn];

signed main()
{
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		for(int i = 1 ; i <= n ; i ++)
			cin >> b[i];
		
		int remain = 0, sta = 1, i = 1;
		for(; i <= 2*n ; i ++)
		{
			int pos = (i - 1) % n + 1;
			if(remain + b[pos] < a[pos])
			{
				sta = i+1;
				remain = 0;
			}
			else
				remain = min(b[pos], remain + b[pos] - a[pos]);
		}
		
		if(i - sta >= n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}