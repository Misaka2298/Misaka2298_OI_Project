#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n , m ;
int e[maxn] , h[maxn] , ne[maxn] , idx;
int q[maxn] , tt , hh ,d[maxn] ,ans;

void addedge(int a , int b)
{
	e[idx] = b ,ne[idx] = h[a] ,h[a] = idx++;
}

int bfs()
{
	q[0] = 1;
	memset(d,-1,sizeof d);
	d[1] = 0;
	while(hh <= tt)
	{
		int t = q[hh++];
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(d[j] == -1)
			{
				d[j] = d[t] + 1;
				q[++tt] = j;
			}
		}
	}
	return d[n];
}

int main()
{
	cin >> n >> m;
	memset(h , -1 , sizeof h);
	int a,b;
	for(int i = 0 ; i < m ; i++)
	{
		scanf("%d%d" ,&a ,&b);
		addedge(a,b);
	}
	cout << bfs();
	return 0;
}
