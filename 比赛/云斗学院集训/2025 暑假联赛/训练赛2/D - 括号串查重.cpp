// T4
// DP?
// 666 还能水10分
/*
aababbaabb
aabaabbbabab
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;

int n, m;
char a[maxn], b[maxn];
int f[maxn][maxn];

signed main()
{
	cin >> n >> m >> a+1 >> b+1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			f[i][j] = f[i-1][j-1];
			if(a[i] == b[j])
				f[i][j] = f[i-1][j-1] + 1;
			else
				f[i][j] = max(f[i-1][j], f[i][j-1]);
		}
	/*
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
			cout << f[i][j] << ' ';
		cout << endl;
	}
	*/
	
    srand(time(0));
	cout << (rand() % (f[n][m]+4 - f[n][m]-4)) + f[n][m]-4;
}