// D
// expect pts = 100
// expect diff = orange+, yellow-
// 怎么是二维前缀和。
// 好像不用按照二维前缀和来写，太好了。
// 前缀和完枚举两条线就好了应该。
// 不是，CSP真的是这个难度吗。

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef long long LL;

int n, m;
int g[maxn][maxn];
LL a, b, c;
LL ans;
LL col[maxn], line[maxn];
LL temp[maxn];

bool check(LL x, LL y, LL z)// 应该是这样，嗯。
{
	bool flag1 = (a==x && b==y && c==z);
	bool flag2 = (a==x && b==z && c==y);
	bool flag3 = (a==y && b==x && c==z);
	bool flag4 = (a==y && b==z && c==x);
	bool flag5 = (a==z && b==x && c==y);
	bool flag6 = (a==z && b==y && c==x);
	return (flag1 || flag2 || flag3 || flag4 || flag5 || flag6);
}

void init()
{
	memset(temp, 0, sizeof temp);
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			temp[i] += g[i][j];
	for(int i = 1 ; i <= n ; i ++)
		line[i] = line[i-1] + temp[i];
	
	memset(temp, 0, sizeof temp);
	for(int i = 1 ; i <= m ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			temp[i] += g[j][i];
	for(int i = 1; i <= m ; i ++)
		col[i] = col[i-1] + temp[i];
}

signed main()
{
	freopen("data.in", "r", stdin);
	freopen("user.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> g[i][j];
	init();
	
	cin >> a >> b >> c;
	// 横着切，对line加和
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i+1 ; j <= n ; j ++)
		{
			// 1~i, i+1~j, j+1~n
			int l1 = 1, r1 = i, l2 = i+1, r2 = j, l3 = j+1, r3 = n;
			LL sum1 = line[r1] - line[l1-1];
			LL sum2 = line[r2] - line[l2-1];
			LL sum3 = line[r3] - line[l3-1];
			if(check(sum1, sum2, sum3)) 
			{
				ans ++;
				//printf("line:%d %d %d %d %d %d\n", l1, r1, l2, r2, l3, r3);
			}
		}
	
	//竖着切
	for(int i = 1 ; i <= m ; i ++)
		for(int j = i+1 ; j <= m ; j ++)
		{
			//1~i, i+1~j, j+1~m
			int l1 = 1, r1 = i, l2 = i+1, r2 = j, l3 = j+1, r3 = m;
			LL sum1 = col[r1] - col[l1-1];
			LL sum2 = col[r2] - col[l2-1];
			LL sum3 = col[r3] - col[l3-1];
			if(check(sum1, sum2, sum3)) 
			{
				ans ++;
				//printf("col:%d %d %d %d %d %d\n", l1, r1, l2, r2, l3, r3);
			}
		}
	cout << ans;
	
	
}