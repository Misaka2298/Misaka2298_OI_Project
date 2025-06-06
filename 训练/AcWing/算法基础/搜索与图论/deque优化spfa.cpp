#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
int n , m;
int h[maxn] , e[maxn] , ne[maxn] , w[maxn] ,idx;
int dist[maxn];
bool st[maxn];

void addedge(int a , int b ,int c)
{
	e[idx] = b ,w[idx] = c,ne[idx]=h[a],h[a]=idx++;
}

void spfa()
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	
	deque<int>q;
	q.push_back(1);
	st[1] = true;
	
	while(q.size())
	{
		int t = q.front();
		q.pop_front();
		st[t] = false;
		
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!st[j])
				{
					if(q.size() && q.front() > dist[j]) q.push_back(j);
					else q.push_front(j);
					st[j] = true;
				}
			}
		}
	}
	
	if(dist[n] == 0x3f3f3f3f)
		cout << "impossible";
	else
		cout << dist[n];
	return;
}

int main()
{
	cin >> n >> m;
	int a , b , c;
	memset(h,-1,sizeof h);
	for(int i = 0 ; i < m ; i++)
	{
		cin >> a >> b >> c;
		addedge(a,b,c);
	}
	
	spfa();
	
	return 0;
}