// T5
// expect pts = 0 ~ 100
// expect diff = yellow
// 写了个超级无敌假的做法，我祝愿它能过
// 我现在手握四题  我无敌了
// 你最好真的是 NOIP 模拟

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;
#define endl '\n'

int T;
int n;
LL need[maxn], have[maxn], rea[maxn];//real
bool can[maxn];
int remain[maxn];

signed main()
{
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		memset(can, 0, sizeof can);
		memset(need, 0, sizeof need);
		memset(have, 0, sizeof have);
		memset(rea, 0, sizeof rea);
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
			cin >> need[i];
		for(int i = 1 ; i <= n ; i ++)
			cin >> have[i], remain[i] = have[i] - need[i];
		
		int mx = 0;
		for(int i = 1 ; i <= n ; i ++)
			mx = max(mx, remain[i]);
		int sta = 0;
		for(int i = 1 ; i <= n ; i ++)
			if(remain[i] == mx)
				sta = i;
		
		for(int i = sta ; i <= sta+n-1 ; i ++)
		{
			int j = (i + 1) % n;
			if(!j) j = n;
			rea[i] = have[i] - need[i] + rea[i];

			rea[j] += max((LL)0, min(rea[i], have[i]));//debug//感觉好假。。。
		}
		for(int i = 1 ; i <= n ; i ++)
			if(rea[i] >= 0)
				can[i] = 1;
		
		int cnt = 0;
		for(int i = 1 ; i <= n ; i ++)
			if(can[i])
				cnt ++;
		if(cnt == n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}