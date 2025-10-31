// I
// expect pts = 100
// expect diff = idk 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010, mod = 1e9+7;
#define endl '\n'

int T;
int C[maxn][maxn];

void init()
{
	for(int i = 0 ; i < maxn ; i ++)
		for(int j = 0 ; j <= i ; j ++)
		{
			if(!j)
				C[i][j] = 1;
			else
				C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
		}
}

signed main()
{
	freopen("tot.in", "r", stdin);
	freopen("tot.out", "w", stdout);
	cin >> T;
	init();
	
	while(T --)
	{
		int a, b;
		cin >> a >> b;
		cout << C[a][b] << endl;
	}
	
	
	
	
	
	
	
}