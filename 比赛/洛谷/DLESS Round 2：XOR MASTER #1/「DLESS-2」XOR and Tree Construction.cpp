#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
typedef long long LL;

int T;
LL n, xorg[maxn][maxn], w[maxn];
bool st[maxn][maxn];

LL XOR(LL a, LL b)
{
	return a^b;
}


void init()
{
	memset(st, false, sizeof st);
}

signed main()
{
	cin >> T;
	while(T--)
	{
		init();
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
			{
				cin >> xorg[i][j];
				if(i == j)
				{
					w[i] = xorg[i][j];
					cout << w[i] << ' ';
				}
					
			}
		
		//for(int i = 1 ; i <= n ; i++)
			//cout << w[i] << ' ';
		cout << endl;
		
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
			{
				if(st[i][j] || st[j][i] || i == j)
					continue;
				if(XOR(w[i], w[j]) == xorg[i][j])
				{
					cout << i << ' ' << j << endl;
					st[i][j] = st[j][i] = true;
				}
			}	
	}
}