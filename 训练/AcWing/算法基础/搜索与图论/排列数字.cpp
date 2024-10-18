#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;
int n , path[maxn];
bool isused[maxn];

void dfs(int u)
{
	if(u == n)
	{
		for(int i = 0 ; i < n ;i++) printf("%d ",path[i]);
		printf("\n");
		return;
	}
	
	for(int i = 1 ; i<=n ;i++)
	{
		if(!isused[i])
		{
			isused[i] = true;
			path[u] = i;
			dfs(u+1);
			isused[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	dfs(0);
	return 0;
}