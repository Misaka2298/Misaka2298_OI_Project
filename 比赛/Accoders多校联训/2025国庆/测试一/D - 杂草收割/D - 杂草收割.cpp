// T4
// expect pts = idk
// expect diff = yellow

#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;

int n, m;
int ans;
bool g[maxn][maxn];
int maxr[maxn], minl[maxn];
int wcnt;

signed main()
{
	//freopen("grass.in", "r", stdin);
	//freopen("grass.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			char chr;
			cin >> chr;
			if(chr == 'W')
				g[i][j] = 1, wcnt++;
		}
	if(!wcnt)
		cout << 0, exit(0);
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
			if(g[i][j])
			{
				minl[i] = j;
				break;
			}
		for(int j = m ; j >= 1 ; j --)
			if(g[i][j])
			{
				maxr[i] = j;
				break;
			}	
	}
	
	int lst = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(i % 2 != 0)// right
		{
			ans += min(max(maxr[i], maxr[i+1]), m) - lst;
			lst = min(max(maxr[i], maxr[i+1]), m);
		}
		else
		{
			ans += lst - max(min(minl[i], minl[i+1]), 1);
			lst = max(min(minl[i], minl[i+1]), 1);
		}
		//cout << lst << ' ' << ans << endl;
		ans ++;
		//cout << lst << ' ' << ans << endl << endl;
	}	
	
	cout << ans - 1;//多下了一层
	
	
}