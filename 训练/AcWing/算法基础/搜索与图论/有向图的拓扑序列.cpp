#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int e[maxn] , h[maxn] , ne[maxn] ,idx;
int q[maxn] , d[maxn] , n , m;

void addedge(int a , int b)
{
	e[idx] = b , ne[idx] = h[a] , h[a] = idx++;
}

bool topsort()
{
	int hh = 0 , tt = -1;
	for(int i = 1 ; i <= n ; i++)
		if(!d[i])
			q[++tt] = i;
	
	while(hh <= tt)
	{
		int t = q[hh++];
		
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			d[j] --;
			if(d[j] == 0) q[++tt] = j;
		}
	}
	
	return tt == n-1;
}

int main()
{
	memset(h,-1,sizeof h);
	cin >> n >> m;
	int a , b;
	for(int i = 0 ; i < m ; i++)
	{
		scanf("%d%d",&a ,&b);
		addedge(a,b);
		d[b]++;
	}
	
	if(topsort())
	{
		for(int i = 0 ; i < n ; i ++)
			cout << q[i] << ' ';
		cout << endl;
	}
	else cout << -1;
	return 0;
}

/*
3 3
1 2
2 3
1 3

1 2 3
*/