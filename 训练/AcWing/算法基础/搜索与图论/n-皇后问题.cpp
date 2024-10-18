#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;

int n;
bool col[maxn] , dg[maxn] ,udg[maxn] ;
char a[maxn][maxn];

void dfs(int u)
{
	if(u == n)
	{
		for(int i = 0 ; i<n ; i++) puts(a[i]);
		puts("");
		return;
	}
	for(int i = 0; i<n ;i++)
	{
		if(!col[i] && !dg[i-u+n] && !udg[i+u])
		{
			col[i] = dg[i-u+n] = udg[i+u] = true;
			a[u][i]='Q';
			dfs(u+1);
			col[i] = dg[i-u+n] = udg[i+u] = false;
			a[u][i]='.';
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0 ; i<n ;i++)
		for(int j = 0 ; j<n ;j++)
			a[i][j]='.';
			
	dfs(0);
	return 0;
}