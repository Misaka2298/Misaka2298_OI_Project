// B - baoli
// expect pts = 50
// expect diff = green
// 我这是在打高联吗。
// 做了半天没看懂题目在说什么
// 什么是矩阵中所有相邻数字xor和之和的平方。
// 你们怎么都开C题了 你们怎么都开C题了 你们怎么都开C题了 
// 不是兄弟 相邻是这个相邻啊。
 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10, mod = 1e9+7;
typedef long long LL;

int n, m, h, w;
LL g[maxn][maxn], f[maxn][maxn];
LL ans;

signed main()
{
	//freopen("matrix.in", "r", stdin);
	//freopen("matrix.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> h >> w;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> g[i][j];
	
	for(int i = 1 ; i <= n-h+1 ; i ++)
	{
		for(int j = 1 ; j <= m-w+1 ; j ++)
		{
			LL res = 0;
			for(int ii = i ; ii <= i+h-1 ; ii ++)
				for(int ij = j ; ij <= j+w-2 ; ij ++)
					res = (res + (g[ii][ij] ^ g[ii][ij+1])) % mod;
					
			for(int ii = i ; ii <= i+h-2 ; ii ++)
				for(int ij = j ; ij <= j+w-1 ; ij ++)
					res = (res + (g[ii][ij] ^ g[ii+1][ij])) % mod;
			
			//cout << res << endl;
			res = ((LL)res * (LL)res) % mod;
			ans = (res + ans) % mod;
		}
	}
		
	
	cout << ans;
}

/*
					//LL ires = g[ii][ij];
					cout << g[ii][ij] << ' ';
					if(ii-1 >= i) cout << g[ii-1][ij] << ' ';
					if(ii+1 <= i+h-1) cout << g[ii+1][ij] << ' ';
					if(ij-1 >= j) cout << g[ii][ij-1] << ' ';
					if(ij+1 <= j+w-1) cout << g[ii][ij+1] << ' ';
					cout << endl;
					
					LL ires = g[ii][ij];
					if(ii-1 >= i) ires ^= g[ii-1][ij];
					if(ii+1 <= i+h-1) ires ^= g[ii+1][ij];
					if(ij-1 >= j) ires ^= g[ii][ij-1];
					if(ij+1 <= j+w-1) ires ^= g[ii][ij+1];
*/