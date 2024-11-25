#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10 , maxm = 2e5+10;

int n , m;
int e[maxm] , h[maxn] , ne[maxm] , idx;
int color[maxn];

void addedge(int a , int b)
{
	e[idx] = b ,ne[idx] = h[a] , h[a]=idx++;
}

bool dfs(int u , int c)
{
	color[u] = c;
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(!color[j])
		{
			if(!dfs(j , 3-c)) 
				return false;
		}
		if(color[j] == c) return false;
	}
	
	return true;
}

int main()
{
	memset(h , -1 , sizeof h);
	cin >> n >> m;
	int a, b;
	while(m--)
	{
		cin >> a >> b;
		addedge(a,b) , addedge(b,a);
	}
	
	bool flag = true;
	for(int i = 1 ; i <= n ; i++)
	{
		if(!color[i])
		{
			if(!dfs(i,1))
			{
				flag = false;
				break;
			}
		}
	}
	
	if(flag) cout << "Yes";
	else cout << "No";
	
	return 0;
}