//T3
//expect pts = 100
//哥你别放了我错了。。。。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
#define endl '\n'

int n;
bool g[maxn][maxn];

signed main()
{
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	int glen = pow(2, n);
	memset(g, true, sizeof g);
	for(int k = 1 ; k <= n ; k ++)
	{
		int len = pow(2, k);
		int cut = len/2;
		
		for(int i = 1 ; i <= glen ; i += len)
			for(int j = 1 ; j <= glen ; j += len)
			{
				for(int ii = i ; ii < i+cut ; ii ++)
					for(int jj = j ; jj < j+cut ; jj++)
						g[ii][jj] = false;
			}
	}
	for(int i = 1 ; i <= glen ; i ++)
	{
		for(int j = 1 ; j <= glen ; j++)
			cout << g[i][j] << ' ';
		cout << endl;
	}
		
		
}