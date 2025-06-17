#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int maxn = 1e6+10;
int n , m;
int h[maxn] , e[maxn] , ne[maxn] , w[maxn] ,idx;
int dist[maxn] , cnt[maxn];
bool st[maxn];

void addedge(int a , int b ,int c)
{
	e[idx] = b ,w[idx] = c,ne[idx]=h[a],h[a]=idx++;
}

bool spfa()
{
	queue<int>q;
	
	for(int i = 1 ; i <= n ; i ++)
	{
		q.push(i);
		st[i] = true;
	}
	
	while(q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if(cnt[j] >= n) return true;
				if(!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	
	return false;
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
	
	if(spfa()) cout << "Yes" ;
	else cout << "No" ; 
	
	return 0;
}