//T1
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
typedef long long LL;
typedef pair<long long, int> PLI;

int n, m;
LL k, a[maxn][maxn], mi[maxn];
PLI sum[maxn];

bool cmp(PLI a, PLI b)
{
	return a.first > b.first;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	memset(mi, 0x3f, sizeof mi);
	for(int i = 1 ; i <= m ; i ++)
		sum[i].second = i;
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j++)
		{
			cin >> a[i][j];
			mi[j] = min(mi[j], a[i][j]);
			sum[j].first += a[i][j];
		}
	
	for(int i = 1 ; i <= m ; i++)
		sum[i].first /= n;
	
	sort(sum+1, sum+m+1, cmp);
	
	
	for(int i = 1 ; i <= m ; i++)
		cout << sum[i].second << ' ' << sum[i].first << endl;
	
}