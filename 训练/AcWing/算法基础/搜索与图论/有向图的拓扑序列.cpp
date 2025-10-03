#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int e[maxn], h[maxn], ne[maxn], idx;
int d[maxn], n, m;
queue<int> que;

void addedge(int a, int b)
{
	e[idx] = b , ne[idx] = h[a] , h[a] = idx++;
}

bool topsort()
{
	
	for(int i = 1 ; i <= n ; i++)
		if(!d[i])
			que.push(i);
	int cnt = n;
	
	while(que.size())
	{
		int t = que.front(); que.pop();
		cnt --;
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			d[j] --;
			if(d[j] == 0) que.push(j), cnt ++;
		}
	}
	
	return cnt == n-1;
}

signed main()
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
		while(que.size())
		{
			cout << que.front() << ' ';
			que.pop();
		}
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