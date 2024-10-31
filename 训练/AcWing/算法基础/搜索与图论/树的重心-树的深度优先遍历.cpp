#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10 , maxm = 2e5+10;

int n;
int e[maxn] , h[maxm] , ne[maxm] , idx;
int ans = maxn ;

bool isSearched[maxn] = {false};

void addedge(int a , int b)
{
	//增加一条a→b的边
	e[idx] = b;
	ne[idx]=h[a];
	h[a] = idx++;
}

int dfs(int u)
{
	isSearched[u] = true;
	int sum = 1; // 当前子树大小
	int MaxBlockSize = 0; // 最大的联通块大小
	
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(!isSearched[j])
		{
			int s = dfs(j); //当前子树的子树大小
			MaxBlockSize = max(MaxBlockSize , s);
			sum += s;
		}
	}
	MaxBlockSize = max(MaxBlockSize , n-sum);
	ans = min(ans , MaxBlockSize);
	return sum;
}

int main()
{
	cin >> n;
	memset(h,-1,sizeof h);
	for(int i = 0 ; i < n-1 ; i++)
	{
		int a  , b;
		cin >> a >> b;
		addedge(a,b) , addedge(b,a);
	}
	dfs(1);
	cout << ans;
	return 0;
}