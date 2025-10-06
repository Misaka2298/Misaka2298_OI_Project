// B
// expect pts = 50
// expect diff = green
// 我这是在打高联吗。
// 做了半天没看懂题目在说什么
// 什么是矩阵中所有相邻数字 xor 和之和的平方。
// 你们怎么都开C题了 你们怎么都开C题了 你们怎么都开C题了 
// 不是兄弟 相邻是这个相邻啊。
// 兄弟 你看起来真的好二维前缀和。
// 怎么那个很高冷的姐也用上 bongocat 了，全世界都在用 bongocat

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10, mod = 1e9+7;
typedef long long LL;

int n, m, h, w;
LL g[maxn][maxn], line[maxn][maxn], col[maxn][maxn];
LL lines[maxn][maxn], cols[maxn][maxn];
LL ans; 

signed main()
{
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	cin >> n >> m >> h >> w;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> g[i][j];
			
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			line[i][j] = (g[i][j] ^ g[i][j+1]) % mod;
			//Rcout << line[i][j] << ' ';
		}
		//cout << endl;
	}
	//cout << endl;
		
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			lines[i][j] = (lines[i][j-1] + line[i][j]) % mod;
			//cout << lines[i][j] << ' ';
		}
		//cout << endl;
	}
	
	///cout << endl;
			
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			col[i][j] = (g[i][j] ^ g[i+1][j]) % mod;
			//cout << col[i][j] << ' ';
		}
		//cout << endl;
	}
		
		
	//cout << endl;
	
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			cols[i][j] = (cols[i-1][j] + col[i][j]) % mod;
			//cout << cols[i][j] << ' ';
		}
		//cout << endl;
	}
	
	for(int i = 1 ; i <= n-h+1 ; i ++)//n-h+1
	{
		for(int j = 1 ; j <= m-w+1 ; j ++)//m-w+1
		{
			LL res = 0;
			
			for(int ii = i ; ii <= i+h-1 ; ii ++)
				res = (res + lines[ii][j+w-2] - lines[ii][j-1]) % mod;
			for(int jj = j ; jj <= j+w-1 ; jj ++)
				res = (res + cols[i+h-2][jj] - cols[i-1][jj]) % mod;
			
			res = ((LL)res * (LL)res) % mod;
			ans = (res + ans) % mod;
		}
	}
		
	
	cout << ans;
}

/*
			for(int ii = i ; ii <= i+h-1 ; ii ++)
				for(int ij = j ; ij <= j+w-2 ; ij ++)
					res = (res + line[ii][ij]) % mod;
					
			for(int ii = i ; ii <= i+h-2 ; ii ++)
				for(int ij = j ; ij <= j+w-1 ; ij ++)
					res = (res + col[ii][ij]) % mod;
*/